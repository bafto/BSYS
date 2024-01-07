#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main() {
	struct timeval tv;
	gettimeofday(&tv, NULL);
	printf("tv_sec: %ld\n", tv.tv_sec);
	printf("tv_usec: %ld\n", tv.tv_usec);

	struct timeval before, after;
	gettimeofday(&before, NULL);
	for (int i = 0; i < 10000; i++) {
		;
	}
	gettimeofday(&after, NULL);
	printf("10000 loops took %ld nsec\n", (after.tv_sec - before.tv_sec) * 1000000000 + (after.tv_usec - before.tv_usec) * 1000);

	// same with 20000 loops
	gettimeofday(&before, NULL);
	for (int i = 0; i < 20000; i++) {
		;
	}
	gettimeofday(&after, NULL);
	printf("20000 loops took %ld nsec\n", (after.tv_sec - before.tv_sec) * 1000000000 + (after.tv_usec - before.tv_usec) * 1000);

	// check the smallest measurable time from gettimeofday
	gettimeofday(&before, NULL);
	gettimeofday(&after, NULL);
	printf("smallest measurable time: %ld nsec\n", (after.tv_sec - before.tv_sec) * 1000000000 + (after.tv_usec - before.tv_usec) * 1000);

	return 0;
}
