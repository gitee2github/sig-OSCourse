#include <stdio.h>
#include <sys/wait.h>

int
main(void)
{
        pid_t pid;

        if ((pid = fork()) < 0)
        {
                printf("fork error");
        }
        else if (pid == 0)              /* first child */
        {
                if ((pid = fork()) < 0)
                        printf("fork error");
                else if (pid > 0)
                        exit(0);        /* parent from second fork == first child */
                sleep(2);
                printf("second child, parent pid = %d\n", getppid());
                exit(0);
        }
        if (waitpid(pid, NULL, 0) != pid)       /* wait for first child */
                printf("waitpid error");
        exit(0);
}
