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
        exit(1);
    case 0:
        close(pipefd[0]);
        printf("Hello\n");
        close(pipefd[1]);
        return 0;
    }
    close(pipefd[1]);
    char buf[1];
    read(pipefd[0], buf, 1);
    close(pipefd[0]);
    printf("Goodbye\n");
    return 0;
}