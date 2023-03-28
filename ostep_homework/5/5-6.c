#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "error");
        exit(1);
    }
    else if (rc == 0) {
        pid_t wpid;
        wpid = waitpid(rc, NULL, WNOHANG);
        printf("child (PID:%d)\n", (int) getpid());
        //printf("wpid: %d\n", wpid);
    }
    else {
        sleep(3);
        printf("parent (PID:%d)\n", (int) getpid());
    }
    return 0;
}
