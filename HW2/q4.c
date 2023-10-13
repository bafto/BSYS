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
        execl("/bin/ls", "/bin/ls", "-l", NULL);
        return 0;
    }
    int exit_code;
    waitpid(pid, &exit_code, 0);
    return 0;
}