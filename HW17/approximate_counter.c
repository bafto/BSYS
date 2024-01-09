#define _GNU_SOURCE
#include <pthread.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int stick_this_thread_to_core(int core_id) {
   cpu_set_t cpuset;
   CPU_ZERO(&cpuset);
   CPU_SET(core_id, &cpuset);

   pthread_t current_thread = pthread_self();    
   return pthread_setaffinity_np(current_thread, sizeof(cpu_set_t), &cpuset);
}

#define N 10
#define NUM_CPUS 8

typedef struct {
	int global_counter;
	pthread_mutex_t global_lock;
	int local_counter[NUM_CPUS];
	pthread_mutex_t local_locks[NUM_CPUS];
	int threshhold;
} approx_counter_t;

typedef struct {
	int n;
	approx_counter_t *counter;
	int cpu;
} thread_arg_t;

void *thread(void *arg) {
	thread_arg_t *thread_arg = (thread_arg_t *)arg;
	approx_counter_t *counter = thread_arg->counter;
	int cpu = thread_arg->cpu;

	if (stick_this_thread_to_core(cpu) != 0) {
		printf("Failed to stick thread to core %d\n", cpu);
		return NULL;
	}

	for (int i = 0; i < thread_arg->n; i++) {
		pthread_mutex_lock(&counter->local_locks[cpu]);
		counter->local_counter[cpu]++;
		if (counter->local_counter[cpu] >= counter->threshhold) {
			pthread_mutex_lock(&counter->global_lock);
			counter->global_counter += counter->local_counter[cpu];
			pthread_mutex_unlock(&counter->global_lock);
			counter->local_counter[cpu] = 0;
		}
		pthread_mutex_unlock(&counter->local_locks[cpu]);
	}
	return NULL;
}

int main(int argc, char *argv[]) {
	if (argc != 4) {
		printf("Usage: %s <num_threads> <count> <threshhold>\n", argv[0]);
		return 1;
	}
	long num_threads = atol(argv[1]);
	long count = atol(argv[2]);
	int threshhold = atoi(argv[3]);

	unsigned long long measurements[N];
	for (int i = 0; i < N; i++) {
		pthread_t threads[num_threads];

		approx_counter_t counter;
		counter.global_counter = 0;
		pthread_mutex_init(&counter.global_lock, NULL);
		for (int i = 0; i < NUM_CPUS; i++) {
			counter.local_counter[i] = 0;
			pthread_mutex_init(&counter.local_locks[i], NULL);
		}
		counter.threshhold = threshhold;

		thread_arg_t thread_arg;
		thread_arg.n = count;
		thread_arg.counter = &counter;

		struct timeval before, after;
		gettimeofday(&before, NULL);

		for (long i = 0; i < num_threads; i++) {
			thread_arg_t this_arg = thread_arg;
			this_arg.cpu = i % NUM_CPUS;
			pthread_create(&threads[i], NULL, thread, (void *)&thread_arg);
		}
		for (long i = 0; i < num_threads; i++) {
			pthread_join(threads[i], NULL);
		}

		// flush local counters
		for (int i = 0; i < NUM_CPUS; i++) {
			pthread_mutex_lock(&counter.global_lock);
			counter.global_counter += counter.local_counter[i];
			pthread_mutex_unlock(&counter.global_lock);
		}

		gettimeofday(&after, NULL);

		pthread_mutex_destroy(&counter.global_lock);
		for (int i = 0; i < NUM_CPUS; i++) {
			pthread_mutex_destroy(&counter.local_locks[i]);
		}

		printf("counter: %d\n", counter.global_counter);
		printf("time: %ld usec\n", (after.tv_sec - before.tv_sec) * 1000000 +
				(after.tv_usec - before.tv_usec));
		measurements[i] = (after.tv_sec - before.tv_sec) * 1000000 +
			(after.tv_usec - before.tv_usec);
	}
	// print average
	unsigned long long sum = 0;
	for (int i = 0; i < N; i++) {
		sum += measurements[i];
	}
	printf("average: %llu usec\n", sum / N);
	return 0;
}
