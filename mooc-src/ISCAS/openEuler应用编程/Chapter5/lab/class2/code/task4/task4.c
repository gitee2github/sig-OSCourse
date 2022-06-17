#include<pthread.h>

#include<unistd.h>

#include<stdio.h>

#include<stdlib.h>

int tickNo;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void * thread_start(void * arg) {

  for (; tickNo < 30;) {
    pthread_mutex_lock( & mutex);
    printf("Child Get Tick%d\n", ++tickNo);
    pthread_mutex_unlock( & mutex);
    sleep(1);
  }

  return 0;
}

int main() {
  pthread_t tid;

  pthread_create( & tid, NULL, thread_start, NULL);

  for (; tickNo < 30;) {
    pthread_mutex_lock( & mutex);
    printf("Main Get Tick%d\n", ++tickNo);
    pthread_mutex_unlock( & mutex);
    sleep(1);
  }

  pthread_mutex_destroy( & mutex);

  return 0;
}
