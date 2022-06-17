#include <stdio.h>

#include <sys/types.h>

#include <sys/stat.h>

#include <string.h>

int main(int argc, char * argv[]) {
  if (argc < 3) {
    printf("ERROR:Please input the file name.\n");
    return 0;
  }

  struct stat buf;
  char * path = argv[1];
  int ret;
  char * pnewname = "testfile_chg";
  FILE * fp;
  fp = fopen(argv[1], "a+");
  if (fp == NULL) {
    printf("fopen error\n");
  }
  if ((int) fwrite(argv[2], 1, (size_t) strlen(argv[2]), fp) < 0) {
    printf("write error\n");
    return -1;
  }
  printf("write over\n");
  fclose(fp);
  printf("chang file name over\n");
  rename(path, pnewname);
  if (ret = stat(pnewname, & buf) != 0) {
    printf("ERROR: execute stat function error.\n");
    return 0;
  }
  buf.st_mode &= ~S_IWGRP;
  buf.st_mode &= ~S_IWOTH;
  if (ret = chmod(pnewname, buf.st_mode) != 0) {
    printf("ERROR: execute chmod function error.\n");
    return 0;
  }
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

  return 0;
}
