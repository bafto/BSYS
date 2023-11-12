#include <stdlib.h>

int main() {
    int *p = malloc(100);
    p[100] = 0;
    free(p);
    return 0;
}