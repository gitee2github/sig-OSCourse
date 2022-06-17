#include <stdio.h>

#include <sys/stat.h>

#include <utime.h>

#include <time.h>

int main(int argc, char * argv[]) {
  if (argc < 2) {
    printf("ERROR:Please input the file name.\n");
    return 0;
  }

  struct stat buf;
  char * path = argv[1];
  int ret;
  if (ret = stat(path, & buf) != 0) {
    printf("ERROR: execute stat function error.\n");
    return 0;
  }
  printf("last access time before change is: %s\n", ctime( & (buf.st_atime)));
  printf("last modify time before change is: %s\n", ctime( & (buf.st_mtime)));

  if (ret = utime(path, NULL) != 0) {
    printf("ERROR: execute utime function error.\n");
    return 0;
  }
  if (ret = stat(path, & buf) != 0) {
    printf("ERROR: execute stat function error.\n");
    return 0;
  }
  printf("last access time after change is: %s\n", ctime( & (buf.st_atime)));
  printf("last modify time after change is: %s\n", ctime( & (buf.st_mtime)));

  return 0;
}
