#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include "common_threads.h"

//
// Here, you have to write (almost) ALL the code. Oh no!
// How can you show that a thread does not starve
// when attempting to acquire this mutex you build?
//

typedef struct __ns_mutex_t {
	sem_t lock;
} ns_mutex_t;

void ns_mutex_init(ns_mutex_t *m) {
	Sem_init(&m->lock, 1);
}

void ns_mutex_acquire(ns_mutex_t *m) {
	sem_wait(&m->lock);
}

void ns_mutex_release(ns_mutex_t *m) {
	sem_post(&m->lock);
}

ns_mutex_t m;
int loop;

void *worker(void *arg) {
	int tid = (int) arg;
	for (int i = 0; i < loop; i++) {
		ns_mutex_acquire(&m);
		printf("loop %d: thread %d\n", i, tid);
		ns_mutex_release(&m);
	}
    return NULL;
}

int main(int argc, char *argv[]) {
    printf("parent: begin\n");
	assert(argc == 3);
	int num_threads = atoi(argv[1]);
	loop = atoi(argv[2]);

	pthread_t p[num_threads];
	ns_mutex_init(&m);

	for (int i = 0; i < num_threads; i++) {
		Pthread_create(&p[i], NULL, worker, (void *) i);
	}

	for (int i = 0; i < num_threads; i++) {
		Pthread_join(p[i], NULL);
	}

    printf("parent: end\n");
    return 0;
}

