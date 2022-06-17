#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
  struct timeval tv;
  fd_set readfds;
  int ret;
  
  FD_ZERO(&readfds);
  FD_SET(STDIN_FILENO,&readfds);

  tv.tv_sec=5;
  tv.tv_usec=0;

  ret=select(STDIN_FILENO+1,&readfds,NULL,NULL,&tv);
  printf("ret=%d\n",ret);

  if(ret==-1)
    {  perror("select error\n"); exit(1); }
  else if(ret>0)
     { 
       if(FD_ISSET(STDIN_FILENO,&readfds))
        { char buf[100];
          read(STDIN_FILENO,buf,100);
          printf("read from stdin msg:%s\n",buf);
        }
      }
   else
     { printf("timeout\n");}

  return 0;
}
