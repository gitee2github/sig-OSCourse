#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>

int main(void)
{
  struct stat st;
  char *p;
  int fd,i;

  fd=open("a.txt",O_RDWR);
  if(fd==-1||fstat(fd,&st)==-1||!S_ISREG(st.st_mode)==-1)
   { return 1; }

  p=mmap(0,st.st_size,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
  if(p==MAP_FAILED)
  { return 1;  }
  
  for(i=0;i<st.st_size;i++)
     putchar(p[i]);
  
  memcpy(p,"test data",50);
  printf("after write:%s\n",p); 

  munmap(p,st.st_size);

  close(fd);
  return 0;
}
