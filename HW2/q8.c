#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

#define R 0
#define W 1

int main(int argc, char* argv[]) {
    int pipefd[2];
    if (pipe(pipefd) != 0) exit(1);

    pid_t pid = fork();
    switch (pid) {
    case -1:
        perror("fork\n");
        return 1;
    case 0:
        close(pipefd[R]);
        dup2(pipefd[W], STDOUT_FILENO);
        close(pipefd[W]);
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
        close(pipefd[W]);
        dup2(pipefd[R], STDIN_FILENO);
        close(pipefd[R]);
        char buff[100];
        scanf("%s", buff);
        printf("child1 sent: %s\n", buff);
        return 0;
    default:
        break;
    }

    close(pipefd[R]);
    close(pipefd[W]);
    int p;
    while ((p = wait(NULL)) != -1) {
        printf("child %d exited\n", p);
    }
    printf("all children finished\n");
    return 0;
}