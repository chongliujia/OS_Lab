#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    //int x = 100;

    //printf("x = %d, (pid = %d)\n", x, (int) getpid());

    int rc = fork();

    int x = 100;

    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (rc == 0) {
        x = 101;
        printf("x = %d, child (pid:%d)\n", x, (int) getpid());
    }
    else {
        x = 99;
        printf("x = %d, parent (pid:%d)\n", x, (int) getpid());
    }

    return 0;

}
