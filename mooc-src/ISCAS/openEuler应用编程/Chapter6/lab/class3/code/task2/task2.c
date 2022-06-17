#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int main() {
  char buf[100][100];
  int i;
  int num = 0;
  printf("please input num\n");
  scanf("%d", & num);

  for (i = 0; i < num; i++) {
    scanf("%s", (char * ) & buf[i]);
  }
  printf("you input :\n");
  for (i = 0; i < num; i++)
    printf("%s\n", buf[i]);
  return 0;
}
