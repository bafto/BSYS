#include <stdlib.h>
#include <stdio.h>

int main() {
    int *p = malloc(100);
    p[10] = 27;
    free(p);
    printf("%d\n", p[10]);
    return 0;
}