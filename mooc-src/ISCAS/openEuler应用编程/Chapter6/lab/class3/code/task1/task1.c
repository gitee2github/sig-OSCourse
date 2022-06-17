#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define MAXSIZE 500
int main(int argc, char * argv[]) {
  FILE * fp = NULL, * fpread;
  char * buf = NULL;
  size_t len = 0;
  int num;
  char szbuf[MAXSIZE + 2] = {
    0
  }, readbuf[MAXSIZE + 2] = {
    0
  };
  int i, maxsize_len = 0;
  if (argc != 3) {
    printf("pls input filename and size\n");
    return 0;
  }
  fp = fopen(argv[1], "w+");
  if (fp == NULL) {
    printf("open error\n");
    return -1;
  }
  maxsize_len = atoi(argv[2]);
  for (i = 0; i < maxsize_len; i++) {
    szbuf[i] = 'a';
  }
  printf("szbuf=%s\n", szbuf);
  if (fwrite(szbuf, 1, strlen(szbuf), fp) < 0) {
    printf("write error\n");
    return -1;
  }
  fclose(fp);
  fpread = fopen(argv[1], "r");
  if (fpread == NULL) {
    printf("fopen error\n");
    return -1;
  }
  fread(readbuf, 1, sizeof(readbuf), fpread);

  printf("read buf is %s\n", readbuf);
  fseek(fpread, 0 L, SEEK_SET);
  while ((num = getline( & buf, & len, fpread)) != -1) {
    printf("num=%d,len=%d,content=%s\n", num, (int) len, buf);
  }
  //fclose(fp);
  free(buf);
  fclose(fpread);
  return 0;
}
