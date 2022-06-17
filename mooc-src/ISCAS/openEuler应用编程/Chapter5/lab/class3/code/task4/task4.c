#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <unistd.h>

#define SIZE 128
int main() {
  int fd[2];
  pid_t pid;
  char szout[SIZE];
  char szin[SIZE];

  memset((void * ) szout, 0, (size_t) SIZE);
  memset((void * ) szin, 0, (size_t) SIZE);
  printf("input arg:\n");
  scanf("%s", szin);
  pipe(fd);
  pid = fork();
  if (pid == 0) {
    close(fd[1]);
    read(fd[0], szout, SIZE);
    execl("/bin/ls", "ls", (const char * ) szout, NULL);
    sleep(2);
    exit(0);
  } else if (pid > 0) {
    close(fd[0]);
    write(fd[1], szin, SIZE);
    sleep(3);
    exit(0);
  }

  return 0;
}
