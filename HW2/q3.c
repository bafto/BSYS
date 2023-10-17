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
        exit(1);
    case 0:
        close(pipefd[R]);
        printf("Hello\n");
        close(pipefd[W]);
        return 0;
    }
    close(pipefd[W]);
    char buf[1];
    read(pipefd[R], buf, 1);
    close(pipefd[R]);
    printf("Goodbye\n");
    return 0;
}