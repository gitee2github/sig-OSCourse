#include <stdio.h>

#include <unistd.h>

#include <string.h>

#include <sys/ipc.h>

#include <sys/shm.h>

#include <error.h>

#define SIZE 1024
int main(int argc, char * argv[]) {
  int shmid;
  char * shmaddr;
  struct shmid_ds buf;
  int flag = 0;
  int pid;
  shmid = shmget(IPC_PRIVATE, SIZE, IPC_CREAT | 0600);
  if (shmid < 0) {
    perror("get shm  ipc_id error");
    return -1;
  }
  pid = fork();
  if (pid == 0) {

    printf("this is child.\n");
    return 0;
  } else if (pid > 0) {
    wait(NULL);
    printf("this is parent.\n");
  } else {
    perror("fork error");
    shmctl(shmid, IPC_RMID, NULL);
  }
  return 0;
}
