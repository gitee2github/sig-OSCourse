#include <stdio.h>

#include <stdlib.h>

#include <sys/types.h>

#define SIZE 128
int main() {
  int fd[2];
  pid_t pid;
  char szout[SIZE];
  char szin[SIZE];
  printf("input str:\n");
  fgets(szin, 100, stdin);

  pipe(fd);
  while ((pid = fork()) < 0);
  if (pid == 0) {
    close(fd[1]);
    read(fd[0], szout, SIZE);
    fprintf(stdout, "I am child,out:%s\n", szout);
    exit(0);
  } else {
    close(fd[0]);
    write(fd[1], szin, SIZE);
    printf("I am parent,in:%s\n", szin);
    sleep(1);
  }
  return 0;
}
