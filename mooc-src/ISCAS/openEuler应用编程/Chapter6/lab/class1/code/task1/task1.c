#include <stdio.h>

#include <sys/stat.h>

#include <unistd.h>

int main(int argc, char * argv[]) {
  if (argc < 2) {
    printf("ERROR:Please input the file name.\n");
    return 0;
  }

  struct stat buf;
  char * path = argv[1];
  int ret;
  FILE * fp = fopen(argv[1], "w+");
  if (fp == NULL) {
    printf("open error\n");
    return -1;
  }
  printf("creat success\n");
  fclose(fp);
  if (ret = stat(path, & buf) != 0) {
    printf("ERROR: execute stat function error.\n");
    return 0;
  } else {
    if (buf.st_mode & S_IRUSR)
      printf("user read\n");
    if (buf.st_mode & S_IWUSR)
      printf("user write\n");
    if (buf.st_mode & S_IXUSR)
      printf("user exe\n");
    if (buf.st_mode & S_IRGRP)
      printf("GRP read\n");
    if (buf.st_mode & S_IWGRP)
      printf("GRP write\n");
    if (buf.st_mode & S_IXGRP)
      printf("GRP exe\n");
    if (buf.st_mode & S_IROTH)
      printf("OTH read\n");
    if (buf.st_mode & S_IWOTH)
      printf("OTH write\n");
    if (buf.st_mode & S_IXOTH)
      printf("OTH exe\n");

    printf("=============================================\n"); // 以rwx方式表示	
    printf("The file authority is: ");
    int i;
    for (i = 2; i >= 0; i--) {
      if (buf.st_mode & 1 << (i * 3 + 2))
        printf("r");
      else
        printf("-");

      if (buf.st_mode & 1 << (i * 3 + 1))
        printf("w");
      else
        printf("-");

      if (buf.st_mode & 1 << (i * 3 + 0))
        printf("x");
      else
        printf("-");

    }
    printf("\n");

    printf("=============================================\n"); // 以数字方式表示
    printf("The file authority is: 0%o\n", buf.st_mode & (S_IRUSR | S_IWUSR | S_IXUSR | S_IRGRP | S_IWGRP | S_IXGRP | S_IROTH | S_IWOTH | S_IXOTH));

  }
  return 0;
}
