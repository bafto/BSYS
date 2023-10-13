#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {
    int fd = open("q2.test.txt", O_WRONLY|O_TRUNC|O_CREAT, 0666);
    pid_t pid = fork();
    switch (pid) {
    case -1:
        perror("fork\n");
        exit(1);
    case 0:
        write(fd, "child", 5);
        write(fd, "child2", 6);
        write(fd, "child3", 6);
        printf("I am the child!\n");
        return 0;
    }
    write(fd, "parent", 6);
    write(fd, "parent2", 7);
    write(fd, "parent3", 7);
    printf("I am the parent!\n");
    close(fd);
    int exit_code;
    waitpid(pid, &exit_code, 0);
    printf("child finished!\n");
    open("q2.test.txt", O_RDONLY);
    char buf[100];
    read(fd, buf, 100);
    printf("q2.test.txt: %s\n", buf);
    return 0;
}