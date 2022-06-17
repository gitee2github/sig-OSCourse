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
  Book_struc book1 = {
    0
  }, book2 = {
    0
  };
  Book_struc * paddr = NULL, * paddr2 = NULL;
  key_t key;

  int shm_id;
  strcpy((char * ) book1.no, "01");
  strcpy((char * ) book1.name, "book1");
  book1.price = 54.5;

  strcpy(book2.no, "02");
  strcpy(book2.name, "book2");
  book2.price = 64.5;

  key = ftok("tmp", 0x03);
  if (key < 0) {
    perror("ftok error");
    return -1;
  }
  printf("key=%d\n", key);

  shm_id = shmget(key, SIZE, PERM);
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

  memset(paddr, 0, SIZE);
  memcpy(paddr, (const char * ) & book1, sizeof(Book_struc));

  printf("now book1 is\n");
  printf("%s %s %f\n", paddr -> no, paddr -> name, paddr -> price);

  paddr2 = paddr + sizeof(Book_struc);
  memcpy(paddr + sizeof(book1), (const char * ) & book2, sizeof(book2));

  printf("now book2 is\n");
  printf("%s %s %f\n", paddr2 -> no, paddr2 -> name, paddr2 -> price);

  shmdt(paddr);
}
