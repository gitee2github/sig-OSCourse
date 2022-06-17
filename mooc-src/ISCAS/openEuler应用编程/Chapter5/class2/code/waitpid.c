#include <stdlib.h>
#include <stdio.h>

int main(void)
{
   pid_t pid;
   int status,exit_status;

   if((pid=fork())<0)
      { perror("fork error");}
   else if(pid==0)
        { printf("Child sleeping..."); 
          sleep(4);exit(0);
        }

    while(waitpid(pid,&status,WNOHANG)==0)
    { printf("Still waiting...\n");sleep(1); }

    if(WIFEXITED(status))
    { exit_status=WEXITSTATUS(status);
      printf("Exit status from %d was %d\n",pid,exit_status);  }

    exit(0);
}
