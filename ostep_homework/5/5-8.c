#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 100

int main()
{
    int pdf[2];

    if (pipe(pdf) == -1) printf("failed to create a pipe\n");

    switch (fork()) {
        case -1: 
            fprintf(stderr, "failed to create a process\n");
            exit(1);

        case 0:
            if (close(pdf[1]) == -1) exit(1);

            char read_buff[N];

            read(pdf[0], read_buff, sizeof(read_buff));

            printf("%s\n", read_buff);
    }

    if (close(pdf[0]) == -1) exit(1);

    char write_buff[N] = "hello world!";

    write(pdf[1], write_buff, sizeof(write_buff));
    
    return 0;
}
