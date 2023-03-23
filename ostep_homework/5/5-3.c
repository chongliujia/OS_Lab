#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int rc = fork();

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        printf("hello child (pid:%d)\n", (int) getpid());
    }
    else {
        sleep(1);
        printf("goodbyte parent (pid:%d)\n", (int) getpid());
    }

    return 0;
}
