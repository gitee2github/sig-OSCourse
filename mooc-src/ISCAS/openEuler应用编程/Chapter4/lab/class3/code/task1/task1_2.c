#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
  int fp=-1,fpnew=-1,fpnewhalf=-1;
  int num=0;
  int file_len=0;
  char buf[2000]={0},bufhalf[2000]={0};
  if((fp=open("/etc/passwd",O_RDONLY))<0)
  {
   printf("open error\n");
   return -1;
  }
if((fpnew=open("./passwd",O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IROTH))<0)
  {
   printf("create new  file error\n");
   return -1;
  }
if((fpnewhalf=open("./passwdhalf",O_CREAT|O_WRONLY,S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IROTH))<0)
  {
   printf("create half file error\n");
   return -1;
  }
printf("-------now copy whole  file to  passwd—-------\n");
 while((num=read(fp,buf,1000))>0)
  {
     printf("%s",buf);
   if((write(fpnew,buf,num))<0)
    {
     printf("write error.\n");
     return -1;
    }
  }
  close(fpnew);
  lseek(fp,0,SEEK_SET);
  file_len=lseek(fp,0,SEEK_END);
  lseek(fp,0,SEEK_SET);
  printf("-------now copy half file to file passwd_half—-------\n");
  if((num=read(fp,bufhalf,file_len/2))>0)
  {
     printf("%s",bufhaf);
    if(write(fpnewhalf,bufhalf,num)<0)
    {
      printf("write error\n");
      return -1;
     }
close(fpnewhalf);
close(fp);
return 0;
}
