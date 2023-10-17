#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    pid_t pid = fork();
    switch (pid) {
    case -1:
        perror("fork\n");
        exit(1);
    case 0:
        printf("%d waiting in child\n", wait(NULL));
        return 0;
    }
    printf("child: %d\n", pid);
    int exit_code;
    pid_t returned = wait(&exit_code);
    printf("%d returned\n", returned);
    return 0;
}