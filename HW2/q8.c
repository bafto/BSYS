#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

int main(int argc, char* argv[]) {
    int pipefd[2];
    if (pipe(pipefd) != 0) exit(1);

    pid_t pid = fork();
    switch (pid) {
    case -1:
        perror("fork\n");
        return 1;
    case 0:
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);
        printf("Hello\n");
        return 0;
    default:
        break;
    }

    pid_t pid2 = fork();
    switch (pid2) {
    case -1:
        perror("fork\n");
        return 1;
    case 0:
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);
        close(pipefd[0]);
        char buff[100];
        scanf("%s", buff);
        printf("%s\n", buff);
        return 0;
    default:
        break;
    }

    close(pipefd[0]);
    close(pipefd[1]);
    int p;
    while ((p = wait(NULL)) != -1) {
        printf("child %d exited\n", p);
    }
    printf("all children finished\n");
    return 0;
}