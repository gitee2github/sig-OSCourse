#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main()
{
  int fd;
  FILE *fileA;

  fd=open("lockfile",O_RDWR|O_CREAT|O_EXCL,0644);
  if(fd==-1&&errno==EEXIST)
  { printf("File A is already locked!\n");
    return -1;
  }

  char buf[30]="secret data from process2";
  fileA=fopen("fileA.txt","ab+");
  fwrite(buf,24,1,fileA);
  fclose(fileA);  
  
  unlink("lockfile");  

  return 0;
}

