#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <fcntl.h>

#define N 100000

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

int main(int argc, char* argv[]) {
    struct timespec diff_all[N];
    struct timespec diff_avg;
    for (int i = 0; i < N; i++) {
        struct timespec start;
        timespec_get(&start, TIME_UTC);
        read(0, NULL, 0);
        struct timespec end;
        timespec_get(&end, TIME_UTC);
        diff_avg.tv_nsec += end.tv_nsec - start.tv_nsec;
        diff_avg.tv_sec += end.tv_sec - start.tv_sec;
        diff_all[i].tv_nsec = end.tv_nsec - start.tv_nsec;
        diff_all[i].tv_sec = end.tv_sec - start.tv_sec;
    }
    diff_avg.tv_nsec /= N;
    diff_avg.tv_sec /= N;

    qsort(diff_all, N, sizeof(struct timespec), compare_timespec);

    printf("N=%d\n", N);
    printf("Average time: %lds.%ldns\n", diff_avg.tv_sec, diff_avg.tv_nsec);
    printf("Median time: %lds.%ldns\n", diff_all[N / 2].tv_sec, diff_all[N / 2].tv_nsec);

    return EXIT_SUCCESS;
}