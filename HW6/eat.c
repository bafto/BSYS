#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define MAX 10000

int main(int argc, char* argv[]) {
    int mb = atoi(argv[1]);
    int ms = atoi(argv[2]);

    char* mem[MAX];
    printf("eating %dmb\n", mb);
    for (int i = 0; i < mb; i++) {
        if (!(mem[i] = malloc(1024 * 1024))) {
            printf("Failed to allocate\n");
            return 1;
        }
    }
    while(clock() / CLOCKS_PER_SEC * 1000 < ms ) {
        for (int i = 0; i < mb; i++) {
            for (int j = 0; j < 1024 * 1024; j++) {
                mem[i][j] = 0;
            }
        }
    }
    return 0;
}