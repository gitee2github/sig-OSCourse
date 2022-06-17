#include <stdlib.h>
#include <stdio.h>
int main(void){
  pid_t pid;
  printf("call for fork\n"); 
  pid=fork();
  if(pid<0)
      { perror("fork fail\n"); exit(1);}  
  else if(pid==0)
       { printf("It's Child process, pid is %d\n",getpid()); exit(1);}
  else if(pid>0)
       { printf("I am the parent process, Child has pid %d\n",pid);  }

  printf("This process id is %d\n",getpid());

  return 0;

}
