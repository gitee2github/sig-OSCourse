#include <stdio.h>
#include <unistd.h>
int main()
{
   char *cwd;
   char buf[256];
   cwd  = getcwd(buf,256);
   if(!cwd)
  {
     printf("error:getcwd fail");
     return 0;
  }
  printf("path from buf  = %s\n path from cwd=%s\n",buf,cwd);
  return 0;
}
