#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{
    int rc = fork();

    char output_message[100] = "hello world";

    if (rc < 0) {
        fprintf(stderr, "error\n");
        exit(1);
    }
    else if (rc == 0) {
        printf("Children: (PID: %d)\n", (int) getpid());
        write(STDOUT_FILENO, output_message, sizeof(output_message));
        printf("\n");
        printf("Children: (PID: %d)\n", (int) getpid());
    }
    else {
        //printf("Parent: (PID: %d)\n", (int) getpid());
    }

    return 0;
}
