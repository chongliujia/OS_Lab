#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int x = 100;

    printf("x = %d, (pid:%d)\n", x, (int) getpid());

    x = fork();

    if (x < 0) {
        fprintf(stderr, "fork failed\n");
        exit(1);
    }
    else if (x == 0) {
        printf("x = %d, child (pid:%d)\n", x, (int) getpid());
    }
    else {
        printf("x = %d, parent (pid:%d)\n", x, (int) getpid());
    }
    return 0;
}
