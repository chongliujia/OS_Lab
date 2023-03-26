#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void execl_call()
{
    execl("/bin/ls", "ls", NULL);
}

void execlp_call()
{
    execlp("ls", "ls", "-a", "-l", NULL);
}

void execv_call()
{
    char* argv[] = {"ls", "-al", "/etc/passwd"};
    execv("bin/ls", argv);
}

void execvp_call()
{
    char* argv[] = {"ls", "-l", "-a", NULL};
    execvp("bin/ls", argv);
    printf("\n");
}

int main()
{
    int rc = fork();

    if (rc < 0) {
        printf("error\n");
        exit(0);
    }
    else if (rc == 0) {
        execv_call();
        printf("child: (PID: %d)\n", (int) getpid());
    }
    else {
        printf("father: (PID: %d)\n", (int) getpid());
    }

    return 0;
}
