/*
 * 实训4 子任务2
 * Client
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


#define QUESIZE 4
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
volatile int count;

pthread_mutex_t cntlock;
pthread_cond_t cntwait;

void * work(void * args) {
  struct msg * m;
  char * file_path, * file_name, * tmp;
  FILE * file;
  int alive = 1;
  int datalen;
  int i = 0;

  file_path = (char * ) args;
  //从文件完整路径中截取文件名
  tmp = strrchr(file_path, '/');
  file_name = tmp ? (tmp + 1) : file_path;

  file = fopen(file_path, "r");
  if (file == NULL) {
    printf("fopen error=%d\n", errno);
  }

  //创建MSG_FILENAME
  m = (struct msg * ) bufs[rear]; //获得空闲缓冲区
  m -> data_len = strlen(file_name);
  m -> type = MSG_FILENAME;
  memcpy(m -> data, file_name, m -> data_len);
  //更新队列状态
  rear = (rear + 1) % QUESIZE;
  pthread_mutex_lock( & cntlock);
  count++;
  //检查是否满足条件，以唤醒其他线程
  if (count == 1) {
    pthread_cond_signal( & cntwait);
  }
  pthread_mutex_unlock( & cntlock);

  while (alive) {
    pthread_mutex_lock( & cntlock);
    while (head == rear && count >= QUESIZE) {
      pthread_cond_wait( & cntwait, & cntlock);
    }
    pthread_mutex_unlock( & cntlock);

    m = (struct msg * ) bufs[rear]; //获得空闲缓冲区

    //读文件
    datalen = fread(m -> data, 1, BLKSIZE, file);
    if (datalen <= 0) {
      m -> data_len = 0;
      if (feof(file)) { //文件结束
        m -> type = MSG_DONE;
      } else if (ferror(file)) { //读文件错误
        printf("fread error=%d\n", errno);
        m -> type = MSG_EXCEPTION;
      }
      alive = 0;
    } else {
      m -> data_len = datalen;
      m -> type = MSG_CONTENT;
    }
    //更新队列状态
    rear = (rear + 1) % QUESIZE;
    pthread_mutex_lock( & cntlock);
    count++;
    //检查是否满足条件，以唤醒其他线程
    if (count == 1) {
      pthread_cond_signal( & cntwait);
    }
    pthread_mutex_unlock( & cntlock);
  }

  fclose(file);
}

void print_usage() {
  printf("usage:\n"
    "\tclient {server_ip} {server_port} {file_path}\n");
}

int main(int argc, char * argv[]) {
  struct msg * m;
  char * ip, * port, * file_path;
  int clientsock;
  struct sockaddr_in server_addr;
  int ret = 0;
  int msglen;
  time_t start_time, end_time;
  int i = 0;
  pthread_t worker;

  if (argc < 4) {
    print_usage();
    return -1;
  }

  ip = argv[1];
  port = argv[2];
  file_path = argv[3]; //文件完整路径

  head = 0;
  rear = 0;
  count = 0;

  //申请缓冲区
  for (i = 0; i < QUESIZE; i++) {
    bufs[i] = malloc(BUFSIZE);
    if (bufs[i] == NULL) {
      printf("malloc failed\n");
    }
  }

  //初始化互斥锁
  pthread_mutex_init( & cntlock, 0);
  //初始化条件变量
  pthread_cond_init( & cntwait, NULL);

  //创建线程
  ret = pthread_create( & worker, NULL, work, file_path);
  if (ret != 0) {
    printf("pthread_create error=%d\n", ret);
    ret = -8;
    goto exit2;
  }

  //建立socket连接
  memset( & server_addr, 0, sizeof(struct sockaddr_in));
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = inet_addr(ip);
  server_addr.sin_port = htons(atoi(port));

  clientsock = socket(AF_INET, SOCK_STREAM, 0);
  if (clientsock < 0) {
    printf("socket create error=%d\n", errno);
    ret = -2;
    goto exit2;
  }

  if (connect(clientsock, (struct sockaddr * ) & server_addr, sizeof(struct sockaddr_in)) < 0) {
    printf("connect error=%d\n", errno);
    ret = -3;
    goto exit1;
  }

  start_time = time(NULL); //开始时间

  while (1) {

    pthread_mutex_lock( & cntlock);
    while (head == rear && count <= 0) {
      pthread_cond_wait( & cntwait, & cntlock);
    }
    pthread_mutex_unlock( & cntlock);

    m = (struct msg * ) bufs[head]; //获得缓冲区
    //发送消息
    msglen = sizeof(struct msg) + m -> data_len;
    if (send(clientsock, m, msglen, 0) < 0) {
      printf("send error=%d\n", errno);
      ret = -4;
      goto exit1;
    }
    if (m -> type == MSG_DONE || m -> type == MSG_EXCEPTION) {
      printf("send MSG_DONE\n");
      goto exit0;
    }
    //更新队列状态
    head = (head + 1) % QUESIZE;
    pthread_mutex_lock( & cntlock);
    count--;
    //检查是否满足条件，以唤醒其他线程
    if (count == QUESIZE - 1) {
      pthread_cond_signal( & cntwait);
    }
    pthread_mutex_unlock( & cntlock);
  }

  exit0:
    end_time = time(NULL); //结束时间
  printf("Use time: %ld s\n", end_time - start_time);

  exit1:
    close(clientsock);

  exit2:

    pthread_cond_destroy( & cntwait);
  pthread_mutex_destroy( & cntlock);

  //释放缓冲区
  for (i = 0; i < QUESIZE; i++) {
    free(bufs[i]);
  }

  return ret;
}
