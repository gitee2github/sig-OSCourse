#include <stdio.h>
#include <sys/wait.h>

static void pr_exit(int status);

int main(int argc, char *argv[])
{
    pid_t    pid;
    int        status;

    if ((pid = fork()) < 0){
        printf("fork error");
    }else if(pid == 0){
        //child
        exit(7);
    }

    /*
     * wait for child and print its status
     */
    if (wait(&status) != pid){
        printf("wait error");
    }

    pr_exit(status);

    /*
     * child generates SIGABRT
     */
    if ((pid = fork()) < 0){
        printf("fork_error");
    }else if (pid == 0){
        abort();
    }

    /*
     * wait for child and print its status
     */
    if (wait(&status) != pid){
        printf("wait error");
    }

    pr_exit(status);

    if ((pid = fork()) < 0){
        printf("fork error");
    }else if(pid == 0){
        // child divide by 0 generates SIGFPE
        status/=0;
    }

    /*
     * wait for child and print its status
     */
    if (wait(&status) != pid){
        printf("wait error");
    }

    pr_exit(status);
}

static void pr_exit(int status)
{
    if (WIFEXITED(status)){
        printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
    }else if (WIFSIGNALED(status)){
        printf("abnormal termination, signal number=%d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
        WCOREDUMP(status) ? " (core file generated )" : "");
#else
        "");
#endif
    }else if(WIFSTOPPED(status)){
            printf("child stopped, signal number=%d\n", WSTOPSIG(status));
        }
}
