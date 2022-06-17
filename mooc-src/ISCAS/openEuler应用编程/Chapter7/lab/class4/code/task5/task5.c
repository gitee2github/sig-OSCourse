/*
 * 实训4 子任务5
 * Server
 *
 */

#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <string.h>

#include <errno.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#include <arpa/inet.h>

#include <sys/time.h>

#include <pthread.h>

#include <semaphore.h>

#define QUESIZE 4
#define BACKLOG 64
#define BLKSIZE 2048
#define BUFSIZE 2056

#define MSG_FILENAME 1
#define MSG_CONTENT 2
#define MSG_ACK 3
#define MSG_DONE 4
#define MSG_EXCEPTION 5

struct msg {
  int32_t type;
  int32_t data_len;
  char data[];
};

char * bufs[QUESIZE];
volatile int head;
volatile int rear;
sem_t count, empty_count;

void * work(void * args) {
  struct msg * m;
  char file_path[256];
  FILE * file = NULL;
  time_t start_time, end_time;

  while (1) {
    sem_wait( & count);

    m = (struct msg * ) bufs[head]; //获得缓冲区

    //处理消息
    if (m -> type == MSG_FILENAME) {

      start_time = time(NULL); //开始时间

      //获取文件名
      memcpy(file_path, m -> data, m -> data_len);
      file_path[m -> data_len] = 0;
      //打开文件
      file = fopen(file_path, "w");
      if (file == NULL) {
        printf("fopen error=%d\n", errno);
        return;
      }
    } else if (m -> type == MSG_CONTENT) {
      fwrite(m -> data, 1, m -> data_len, file);
    } else if (m -> type == MSG_DONE) {
      printf("MSG_DONE\n");
      goto exit0;
    } else if (m -> type == MSG_EXCEPTION) {
      printf("MSG_EXCEPTION\n");
      goto exit0;
    }

    //更新队列状态
    head = (head + 1) % QUESIZE;
    sem_post( & empty_count);
  }
  exit0:
    fflush(file);
  end_time = time(NULL); //结束时间
  printf("Use time: %ld s\n", end_time - start_time);
  fclose(file);
}

void print_usage() {
  printf("usage:\n"
    "\tserver {listen_port}\n");
}

int main(int argc, char * argv[]) {
  char buf[BUFSIZE];
  char * ip, * port;
  struct msg * m;
  struct sockaddr_in server_addr, client_addr;
  int listensock, clientsock;
  int ret = 0;
  int addrlen;
  int datalen;
  int headlen;
  int i = 0;
  pthread_t worker;
  int alive = 1;

  if (argc < 2) {
    print_usage();
    return -1;
  }

  port = argv[1];

  head = 0;
  rear = 0;

  //申请缓冲区
  for (i = 0; i < QUESIZE; i++) {
    bufs[i] = malloc(BUFSIZE);
    if (bufs[i] == NULL) {
      printf("malloc failed\n");
    }
  }

  //初始化信号量
  sem_init( & count, 0, 0);
  sem_init( & empty_count, 0, QUESIZE);

  //创建线程
  ret = pthread_create( & worker, NULL, work, NULL);
  if (ret != 0) {
    printf("pthread_create error=%d\n", ret);
    ret = -8;
    goto exit3;
  }

  //建立socket连接
  memset( & server_addr, 0, sizeof(struct sockaddr_in));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(atoi(port));

  listensock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (listensock < 0) {
    printf("socket create error=%d\n", errno);
    ret = -2;
    goto exit3;
  }

  if (bind(listensock, (struct sockaddr * ) & server_addr, sizeof(struct sockaddr_in)) < 0) {
    printf("bind error=%\n", errno);
    ret = -3;
    goto exit2;
  }

  if (listen(listensock, BACKLOG) < 0) {
    printf("listen error=%d\n", errno);
    ret = -4;
    goto exit2;
  }

  addrlen = sizeof(struct sockaddr_in);
  clientsock = accept(listensock, (struct sockaddr * ) & client_addr, & addrlen);
  if (clientsock < 0) {
    printf("accept error=%d\n", errno);
    ret = -5;
    goto exit2;
  }

  printf("--%s:%d--\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

  //接收消息
  while (alive) {

    sem_wait( & empty_count);

    m = (struct msg * ) bufs[rear]; //获得空闲缓冲区

    //接收消息头
    headlen = recv(clientsock, m, sizeof(struct msg), 0);
    if (headlen <= 0) {
      goto exit1;
    }

    //接收消息数据
    if (m -> data_len > 0) {
      datalen = 0;
      while (datalen < m -> data_len) {
        datalen += recv(clientsock, m -> data + datalen, m -> data_len - datalen, 0);
      }
    }

    //更新队列状态
    rear = (rear + 1) % QUESIZE;
    sem_post( & count);
  }

  pthread_join(worker, NULL);

  exit1:
    close(clientsock);

  exit2:
    close(listensock);

  exit3:

    //销毁信号量
    sem_destroy( & count);
  sem_destroy( & empty_count);

  //释放缓冲区
  for (i = 0; i < QUESIZE; i++) {
    free(bufs[i]);
  }

  return ret;
}
