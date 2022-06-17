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
    shmaddr = (char * ) shmat(shmid, NULL, 0);
    if ((intptr_t) shmaddr == -1) {
      perror("shmat addr error");
      return -1;
    }
    strcpy(shmaddr, argv[1]);
    printf("this is child.\nwrite argv[1] to shm.\nyour input string is \'%s\'\n", shmaddr);
    shmdt(shmaddr);
    return 0;
  } else if (pid > 0) {
    wait(NULL);
    printf("this is parent.\n");
    shmctl(shmid, IPC_STAT, & buf);
    printf("the size of new buf is %d bytes %d\n", (int) buf.shm_segsz, (int) buf.shm_cpid);
    printf("parent pid is %d\n", getpid());
    printf("chlid pid is %d\n", pid);

  } else {
    perror("fork error");
    shmctl(shmid, IPC_RMID, NULL);
  }
  return 0;
}
