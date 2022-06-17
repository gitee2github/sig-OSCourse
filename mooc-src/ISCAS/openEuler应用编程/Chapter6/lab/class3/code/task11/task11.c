#include <stdio.h>

#include <stdlib.h>

#include <string.h>

int main() {
  FILE * fp = NULL, * fpwrite = NULL;
  char * buf = NULL;
  size_t len = 0;
  int num;
  char * pstr;
  char strname[50] = {
    0
  };
  int sublen = 0;
  fp = fopen("/etc/passwd", "r");
  fpwrite = fopen("user_name", "w");
  if (fp == NULL || fpwrite == NULL) {
    printf("fopen error\n");
    return -1;
  }
  fseek(fp, 0 L, SEEK_SET);
  while ((num = getline( & buf, & len, fp)) != -1) {

    //printf("%s\n",buf);
    pstr = strchr(buf, ':');
    sublen = pstr - buf;
    //printf("sublen=%d\n",sublen);
    memset(strname, 0, 50);
    strncpy(strname, buf, sublen);
    printf("%s\n", strname);
    strcat(strname, "\n");
    fwrite(strname, 1, strlen(strname), fpwrite);

  }
  free(buf);
  fclose(fp);
  fclose(fpwrite);
  return 0;
}
