#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv, char **env) {
    printf("parent started, pid=%d\n", getpid());

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        return 0;
    }

    if (pid == 0) {
        printf("child, pid=%d\n", getpid());
        int * test = 0;
        printf("test = %d \n", *test);
        
    } else {
        printf("parent, child pid=%d\n", pid);
    }


    return 0;
}
