#include <stdio.h>
#include <string.h>

int main()
{
  char name[8];
  printf("Please type your name:");

  gets(name);

  printf("Hello,%sd!\n",name);
  return 0;
}
