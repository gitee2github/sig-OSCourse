#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
int glob = 6;
char buf[] = "a write to stdout\n";
int main()
{
    int var;
    pid_t pid;
    var = 88;
    fprintf(stderr, "%s", buf);
    printf("before fork\n");
    if(( pid = fork() ) < 0 )
    {
        fprintf(stderr, "fork error\n");
    }
    else if(pid == 0)
    {
        glob++;
        var++;
        printf("child process\n");
        printf("pid = %d, father pid = %d, glob = %d, var = %d\n", getpid(), getppid(), glob, var);
        exit(0);
    }
    else
    {
        sleep(2);
        printf("father process\n");
        printf("pid = %d, father pid = %d, glob = %d, var = %d\n", getpid(), getppid(), glob, var);
    }
    return 0;
}
