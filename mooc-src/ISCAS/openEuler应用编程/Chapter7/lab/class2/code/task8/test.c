#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
int status,exit_status;
int pr_exit()
{

    if(WIFEXITED(status)) //判断是否正常退出
    {
        printf("子进程正常退出\n");
        exit_status=WEXITSTATUS(status);
        printf("child process exit status  was %d\n",exit_status);
    }
    if(WIFSIGNALED(status))//异常终止子进程
    {
        printf("异常终止子进程\n");
        exit_status=WTERMSIG(status);
        printf("child process exit status was %d\n",exit_status);
    }
    if(WIFSTOPPED(status))//暂停子进程
    {
        printf("当前暂停子进程\n");
        exit_status=WSTOPSIG(status);
        printf("child process exit status was %d\n",exit_status);

    }
    if( WIFCONTINUED(status))
    {
        printf("暂停后子进程返回了状态\n");
    }
    return 0;

}
int main(void)
{
    pid_t pid;
    if((pid=fork())<0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        printf("子进程的pid=%d\n",getpid());
        //sleep(3);
        exit(3);
    }
    kill(pid,SIGSTOP);
    sleep(3);
    if((pid=waitpid(pid,&status,WUNTRACED)) == -1)
    {
        perror("wait");
        exit(2);
    }
    printf("pid=%d,ppid=%d\n",getpid(),getppid());
    pr_exit();
    return 0;
}

