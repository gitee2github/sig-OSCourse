#include <stdio.h>
#include <string.h>

void function(char *str)
{
  char buffer[16];
  strcpy(buffer,str);
}

void main(int argc,char **argv)
{
  if(argc>1)
    function(argv[1]);

}

