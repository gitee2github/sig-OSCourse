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
  char tmpbuf[SIZE];
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
    printf("please input something:\n");

    fgets(tmpbuf, SIZE, stdin);
    strncpy(shmaddr, tmpbuf, strlen(tmpbuf));
    //printf("this is child.\ninput sth to shm.\nyour input string is :  %s\n", shmaddr);*/
    shmdt(shmaddr);
    return 0;
  } else if (pid > 0) {
    wait(NULL);
    flag = shmctl(shmid, IPC_STAT, & buf);
    if (flag == -1) {
      perror("shmctl shm error");
      return -1;
    }
    //printf("\nthis is parent.\n");
    printf("the size of shared memory is %d bytes\n", buf.shm_segsz);
    // printf("parent pid is %d\n", getpid()) ;
    //printf("chlid pid is %d\n",pid) ;
    shmaddr = (char * ) shmat(shmid, NULL, 0);
    if ((intptr_t) shmaddr == -1) {
      perror("shmat addr error");
      return -1;
    }
    printf("your input string is :  %s", shmaddr);
    shmdt(shmaddr);
    shmctl(shmid, IPC_RMID, NULL);
  } else {
    perror("fork error");
    shmctl(shmid, IPC_RMID, NULL);
  }
  return 0;
}
