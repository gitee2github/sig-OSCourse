#include <stdio.h>

#include <string.h>

#include <sys/ipc.h>

#include <sys/shm.h>

#include <sys/types.h>

#include <unistd.h>

typedef struct {

  char no[8];

  char name[8];

  double price;

}
book;

int main(int argc, char ** argv) {

  int shm_id, i;

  key_t key;

  book * shmaddr;

  char pathname[30];

  strcpy(pathname, "/tmp");

  key = ftok(pathname, 0x03);

  if (key == -1)

  {

    perror("ftok error");

    return -1;

  }

  printf("key=%d\n", key);

  shm_id = shmget(key, 0, 0);

  if (shm_id == -1)

  {

    perror("shmget error");

    return -1;

  }

  printf("shm_id=%d\n", shm_id);

  shmaddr = (book * ) shmat(shm_id, NULL, 0);

  printf("Book Information:\n");

  for (i = 0; i < 2; i++)

  {

    printf("no:%s", ( * (shmaddr + i)).no);

    printf("   name:%s", ( * (shmaddr + i)).name);

    printf("   price:%f\n", ( * (shmaddr + i)).price);

  }

  if (shmdt(shmaddr) == -1)

  {

    perror("detach error");

    return -1;

  }
  if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
    perror("shmctl error");
    return -1;
  }

  return 0;

}
