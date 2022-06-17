#include <stdio.h>

#include <sys/select.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <fcntl.h>

#include <unistd.h>

int main() {
  int keyboard;
  int ret;
  fd_set readfds;
  char key;
  struct timeval timeout;

  char * path = "/dev/tty";
  keyboard = open(path, O_RDONLY | O_NONBLOCK); //打开键盘文件
  if (keyboard < 0) {
    printf("open error!\n");
    return 1;
  }

  printf("keyboard is %d\n", keyboard);

  timeout.tv_sec = 0; //无阻塞
  timeout.tv_usec = 0;

  //无阻塞检测输入
  while (1) {
    FD_ZERO( & readfds); //每次循环都要清空集合，select检测描述文件中是否有可读的，从而能检测描述符变化 
    FD_SET(keyboard, & readfds);

    ret = select(keyboard + 1, & readfds, NULL, NULL, & timeout); //select检测描述文件中是否有可读的
    if (ret < 0) {
      printf("select error!\n");
      return 1;
    }
    //检测读文件描述符集合，一直在循环，监视描述符的变化
    ret = FD_ISSET(keyboard, & readfds);
    if (ret > 0) {
      read(keyboard, & key, 1);
      if ('\n' == key)
        continue;
      printf("the input is %c\n", key);
      if ('q' == key)
        break;
    }
  }

  return 0;
}
