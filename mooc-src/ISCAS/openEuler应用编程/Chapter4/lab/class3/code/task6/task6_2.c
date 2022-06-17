#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#define FILE_ORG  0
#define FILE_CHG  1
void file_attr(mode_t  mode);
void showfileinfo(char *filename,int printflag);
int chgfileattr(char * filename ,int chmode);

void file_attr(mode_t  mode)
{
  if((mode &  S_IRUSR)== S_IRUSR)
  {
    printf("usr can read file \n");
  }
  if((mode & S_IWUSR)==S_IWUSR)
  {
    printf("usr can write file \n");
  }
  if((mode & S_IXUSR)==S_IXUSR)
  {
   printf("usr can  execute file \n");
  }

   if((mode &  S_IRGRP)== S_IRGRP)
  {
    printf("group can read file \n");
  }
  if((mode & S_IWGRP)==S_IWGRP)
  {
    printf("group can write file \n");
  }
  if((mode & S_IXGRP)==S_IXGRP)
  {
   printf("group can  execute file \n");
  }

  if((mode & S_IROTH)==S_IROTH)
  {
   printf("other can read file \n");
  }
  if((mode & S_IWOTH)==S_IWOTH)
  {
   printf("other can write file \n");
  }
  if((mode & S_IXOTH)==S_IXOTH)
  {
   printf("other can execute file \n");
  }

  
}

void showfileinfo(char *filename,int printflag)
{
  struct stat buf;
  if(printflag==FILE_ORG)
  {
    printf("------now %s's attr is-------\n",filename);  
  }
  else
  { 
  printf("------after change mode,%s's attr is-----\n",filename);
  }
  stat(filename,&buf);
  file_attr(buf.st_mode);
}

int chgfileattr(char * filename ,int chmode)
{
   if(chmod(filename,chmode)<0)
    {
     printf("chang %s file mode error\n",filename);
     return -1;   
    }
   return 1;
}


int file_chg_show(char *filename,int chmode)
{
   showfileinfo(filename,FILE_ORG);
   chgfileattr(filename,chmode);
   showfileinfo(filename,FILE_CHG);
   return 0;
}

int main()
{
  int result=0;
  struct stat buf;
  system("if -e test*;rm test*");
  system("touch test1 test2 test3");

  file_chg_show("test1",S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH);
  file_chg_show("test2",S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH);
  file_chg_show("test3",S_IRUSR|S_IWUSR|S_IWGRP|S_IWOTH);

  return 0;
}

