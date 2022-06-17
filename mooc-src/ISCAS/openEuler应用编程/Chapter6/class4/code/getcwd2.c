#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
   char *cwd;
   cwd  = getcwd(NULL,0);
   if(!cwd)
  {
     printf("error:getcwd fail");
     return 0;
  }
  printf("path from cwd=%s\n",cwd);
  free(cwd);
  return 0;
}
