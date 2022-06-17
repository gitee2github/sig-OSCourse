#include <stdio.h>
#include <dlfcn.h>
#include "ctest.h"

int main(int argc,char **argv)
{
  void *lib_handle;
  int (*fn)();
  char *error;

  lib_handle=dlopen("libctest.so",RTLD_LAZY);
  if(!lib_handle)
  {
    fprintf(stderr,"%s\n",dlerror());
    return 1;
  }

  fn=dlsym(lib_handle,"test1");
  if((error=dlerror())!=NULL)
  {
    fprintf(stderr,"%s\n",error);
    return 1;
  }
  int y=fn();

  printf("y=%d\n",y);

  dlclose(lib_handle);

  return 0;
}
