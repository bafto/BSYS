#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 10

int counter = 0;
pthread_mutex_t lock;

void *thread(void *arg) {
  long count = (long)arg;
  for (int i = 0; i < count; i++) {
    pthread_mutex_lock(&lock);
    counter++;
    pthread_mutex_unlock(&lock);
  }
  return NULL;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <num_threads> <count>\n", argv[0]);
    return 1;
  }
  long num_threads = atol(argv[1]);
  long count = atol(argv[2]);
  counter = 0;

  unsigned long long measurements[N];
  for (int i = 0; i < N; i++) {
    pthread_t threads[num_threads];

    pthread_mutex_init(&lock, NULL);
    struct timeval before, after;
    gettimeofday(&before, NULL);

    for (long i = 0; i < num_threads; i++) {
      pthread_create(&threads[i], NULL, thread, (void *)count);
    }
    for (long i = 0; i < num_threads; i++) {
      pthread_join(threads[i], NULL);
    }
    gettimeofday(&after, NULL);
    pthread_mutex_destroy(&lock);

    printf("counter: %d\n", counter);
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
