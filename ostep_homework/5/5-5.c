#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        int rc_wait = waitpid(NULL);
        printf("child (PID: %d)\n", (int) getpid());
    }
    else {
        printf("parent (PID: %d)\n", (int) getpid());
    }

    return 0;
}
