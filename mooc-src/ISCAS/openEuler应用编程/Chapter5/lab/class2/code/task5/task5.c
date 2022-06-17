#include<pthread.h>

#include<stdio.h>

#include<errno.h>

#include<stdlib.h>

#include<string.h>

Void * thread_start(void * arg) {
  printf("子线程在运行\n");
  return 0;
}
int main() {
  pthread_attr_t attr;
  pthread_t thread;

  if (
    pthread_attr_init( & attr) ||
    pthread_attr_setdetachstate( & attr, PTHREAD_CREATE_DETACHED) ||
    pthread_create( & thread, & attr, thread_start, NULL)
  ) {
    fprintf(stderr, "fault!\n");
    return 1;
  }

  if (pthread_join(thread, 0)) {
    fprintf(stderr, "成功返回\n%s\n", strerror(errno));
  } else {
    fprintf(stderr, "返回失败n");
    return 2;
  }
  sleep(1);

  return 0;
}
