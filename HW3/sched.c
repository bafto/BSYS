#define _POSIX_C_SOURCE 199309L
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sched.h>
#include <sys/wait.h>

int compare_timespec(const void* a, const void* b) {
    struct timespec* ta = (struct timespec*) a;
    struct timespec* tb = (struct timespec*) b;
    if (ta->tv_sec < tb->tv_sec) {
        return -1;
    } else if (ta->tv_sec > tb->tv_sec) {
        return 1;
    } else {
        if (ta->tv_nsec < tb->tv_nsec) {
            return -1;
        } else if (ta->tv_nsec > tb->tv_nsec) {
            return 1;
        } else {
            return 0;
        }
    }
}

#define N 10000
#define CORE 7
#define R 0
#define W 1

int main(int argc, char* argv[]) {
    int to_child[2];
    if (pipe(to_child) < 0) {
        perror("pipe");
        exit(1);
    }
    int to_parent[2];
    if (pipe(to_parent) < 0) {
        perror("pipe");
        exit(1);
    }

    pid_t p = fork();
    if (p < 0) {
        perror("fork");
        exit(1);
    }

    cpu_set_t set;
    CPU_ZERO(&set);
    CPU_SET(CORE, &set);
    if (sched_setaffinity(getpid(), sizeof(cpu_set_t), &set) < 0) {
        perror("sched_setaffinity");
        exit(1);
    }

    struct timespec sent_parent[N];
    struct timespec received_child[N];
    struct timespec received_parent[N];

    switch (p) {
    case 0: {
        close(to_child[W]);
        close(to_parent[R]);

        struct timespec received;
        for (int i = 0; i < N; i++) {
            if (read(to_child[R], &received, sizeof(struct timespec)) < 0) {
                perror("read");
            }
            timespec_get(&received, TIME_UTC);
            if (write(to_parent[W], &received, sizeof(struct timespec)) < 0) {
                perror("write");
            }
        }

        close(to_child[R]);
        close(to_parent[W]);
        return 0;
    }
    default: {
        close(to_child[R]);
        close(to_parent[W]);

        for (int i = 0; i < N; i++) {
            timespec_get(&sent_parent[i], TIME_UTC);
            if (write(to_child[W], &sent_parent[i], sizeof(struct timespec)) < 0) {
                perror("write");
            }
            if (read(to_parent[R], &received_child[i], sizeof(struct timespec)) < 0) {
                perror("read");
            }
            timespec_get(&received_parent[i], TIME_UTC);
        }

        close(to_child[W]);
        close(to_parent[R]);
    }
    }

    if (wait(NULL) < 0) {
        perror("wait");
        exit(1);
    }

    struct timespec parent_child_diff[N];
    struct timespec child_parent_diff[N];
    struct timespec parent_parent_diff[N];

    for (int i = 0; i < N; i++) {
        parent_child_diff[i].tv_nsec = received_child[i].tv_nsec - sent_parent[i].tv_nsec;
        parent_child_diff[i].tv_sec = received_child[i].tv_sec - sent_parent[i].tv_sec;
        child_parent_diff[i].tv_nsec = received_parent[i].tv_nsec - received_child[i].tv_nsec;
        child_parent_diff[i].tv_sec = received_parent[i].tv_sec - received_child[i].tv_sec;
        parent_parent_diff[i].tv_nsec = received_parent[i].tv_nsec - sent_parent[i].tv_nsec;
        parent_parent_diff[i].tv_sec = received_parent[i].tv_sec - sent_parent[i].tv_sec;
    }


    qsort(parent_child_diff, N, sizeof(struct timespec), compare_timespec);
    qsort(child_parent_diff, N, sizeof(struct timespec), compare_timespec);
    qsort(parent_parent_diff, N, sizeof(struct timespec), compare_timespec);

    struct timespec parent_child_diff_avg;
    struct timespec child_parent_diff_avg;
    struct timespec parent_parent_diff_avg;

    for (int i = 0; i < N; i++) {
        parent_child_diff_avg.tv_nsec += parent_child_diff[i].tv_nsec;
        parent_child_diff_avg.tv_sec += parent_child_diff[i].tv_sec;
        child_parent_diff_avg.tv_nsec += child_parent_diff[i].tv_nsec;
        child_parent_diff_avg.tv_sec += child_parent_diff[i].tv_sec;
        parent_parent_diff_avg.tv_nsec += parent_parent_diff[i].tv_nsec;
        parent_parent_diff_avg.tv_sec += parent_parent_diff[i].tv_sec;
    }

    parent_child_diff_avg.tv_nsec /= N;
    parent_child_diff_avg.tv_sec /= N;
    child_parent_diff_avg.tv_nsec /= N;
    child_parent_diff_avg.tv_sec /= N;
    parent_parent_diff_avg.tv_nsec /= N;
    parent_parent_diff_avg.tv_sec /= N;

    printf("N=%d\n", N);   
    printf("Avrg parent-child: %lds.%ldns\n", parent_child_diff_avg.tv_sec, parent_child_diff_avg.tv_nsec);
    printf("Median parent-child: %lds.%ldns\n", parent_child_diff[N / 2].tv_sec, parent_child_diff[N / 2].tv_nsec);
    printf("Avrg child-parent: %lds.%ldns\n", child_parent_diff_avg.tv_sec, child_parent_diff_avg.tv_nsec);
    printf("Median child-parent: %lds.%ldns\n", child_parent_diff[N / 2].tv_sec, child_parent_diff[N / 2].tv_nsec);
    printf("Avrg parent-parent: %lds.%ldns\n", parent_parent_diff_avg.tv_sec, parent_parent_diff_avg.tv_nsec);
    printf("Median parent-parent: %lds.%ldns\n", parent_parent_diff[N / 2].tv_sec, parent_parent_diff[N / 2].tv_nsec);

    return EXIT_SUCCESS;
}