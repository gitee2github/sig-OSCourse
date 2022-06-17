#include <stdio.h>

#include <stdlib.h>

#include <sys/shm.h>

#include <sys/stat.h>

#include <string.h>

#include <sys/ipc.h>

#include <sys/types.h>

#include <unistd.h>

#define PERM IPC_CREAT | S_IRUSR | S_IWUSR
#define SIZE 1024
typedef struct {

  char no[8];

  char name[8];

  double price;

}
Book_struc;
int main() {
  Book_struc * preadBook;
  Book_struc * paddr = NULL, * paddr2 = NULL;
  key_t key;

  int shm_id;

  key = ftok("tmp", 0x03);
  if (key < 0) {
    perror("ftok error");
    return -1;
  }
  printf("key=%d\n", key);

  shm_id = shmget(key, 0, 0);
  if (shm_id < 0) {
    perror("creat shm error");

    return -1;
  }
  printf("shm_id is %d\n", shm_id);

  paddr = (Book_struc * ) shmat(shm_id, NULL, 0);
  if ((intptr_t) paddr == -1) {
    perror("shmat error");
    return -1;
  }
  printf("book1 is \n");
  printf("%s %s %f \n", paddr -> no, paddr -> name, paddr -> price);
  paddr2 = paddr + sizeof(Book_struc);

  printf("book2 is \n");
  printf("%s %s %f \n", paddr2 -> no, paddr2 -> name, paddr2 -> price);

  if (shmdt(paddr) == -1) {
    perror("detach error");
    return -1;
  }

  if (shmctl(shm_id, IPC_RMID, NULL) < 0) {
    perror("shmctl error");
    return -1;
  }
  return 0;

}
