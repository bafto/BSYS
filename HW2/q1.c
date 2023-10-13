#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int x = 100;
    pid_t pid = fork();
    switch (pid) {
    case -1:
        perror("fork\n");
        exit(1);
    case 0:
        printf("I am the child, my x is %d\n", x);
        x = 50;
        printf("Now x is %d\n", x);
        return 0;
    }

    printf("I am the parent, my x is %d\n", x);
    x = 25;
    printf("Now x is %d\n", x);
    int exit_code;
    waitpid(pid, &exit_code, 0);
    printf("child finished, x is: %d\n", x);
    return 0;
}