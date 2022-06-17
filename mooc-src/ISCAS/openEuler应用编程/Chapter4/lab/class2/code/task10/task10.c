#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include  <stdlib.h>
#include <string.h>

int main() {
  int i;
  int fp_src = 0, fp_bak;
  int len = 0;
  char buf[21] = {
    0
  }, buf_t[21] = {
    0
  };
  if ((fp_src = open("file_src", O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0) {

    printf("create file_src error\n");
    return -1;
  }

  for (i = 0; i < 20; i++) {
    buf[i] = 'S';
  }
  len = write(fp_src, buf, 20);

  if (len < 0) {
    printf("write file error !\n");
  }
  if ((fp_bak = open("file_bak", O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0) {
    printf("create file_bak error\n");
    return -1;
  }
  system("cp file_src file_bak");
  printf("----this is file_src---------\n");
  system("cat file_src");
  printf("\n");
  printf("------this is file_bak--------\n");
  system("cat file_bak");
  printf("\n");
  printf("-------after change file_bak------\n");
  system("cp file_bak file_tmp;cat file_tmp|tr '[A-Z]' '[a-z]' >file_bak");
  system("cat file_bak");
  printf("\n");
  printf("-------after merger to file------\n");
  system("cat file_src >> file;cat file_bak >> file");
  system("cat file");
  printf("\n");
  close(fp_src);
  close(fp_bak);
  return 0;
}

//method2
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include  <stdlib.h>
#include <string.h>

#define FILENAME_SRC "file_src"
#define FILENAME_BAK "file_bak"
#define FILENAME_MERGE "file"
#define FILE_LEN 20

int main() {
  int i;
  int fp_src = -1, fp_bak = -1, fp_merge = -1;
  int len = 0;
  char buf[21] = {
    0
  };

  if ((fp_src = open(FILENAME_SRC, O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0) {
    printf("create file_src error\n");
    return -1;
  }

  for (i = 0; i < FILE_LEN; i++) {
    buf[i] = 'S';
  }
  len = write(fp_src, buf, strlen(buf));

  if (len < 0) {
    printf("write file error !\n");
  }

  if ((fp_bak = open(FILENAME_BAK, O_RDWR | O_CREAT | O_TRUNC, 0644)) < 0) {
    printf("create file_bak error\n");
    return -1;
  }

  len = write(fp_bak, buf, strlen(buf));
  if (len < 0) {
    printf("write file_bak error\n");
    return -1;
  }

  printf("----this is file_src---------\n");
  system("cat file_src");
  printf("\n");
  printf("------this is file_bak--------\n");
  system("cat file_bak");
  printf("\n");
  printf("-------after change file_bak------\n");

  for (i = 0; i < FILE_LEN; i++) {
    buf[i] = 's';
  }
  lseek(fp_bak, 0, SEEK_SET);
  len = write(fp_bak, buf, strlen(buf));
  if (len < 0) {
    printf("when change file_bak  write error\n");
  }

  system("cat file_bak");
  printf("\n");
  printf("-------after merger to file------\n");

  fp_merge = open(FILENAME_MERGE, O_RDWR | O_APPEND | O_CREAT);
  if (fp_merge < 0) {
    printf("open file error\n");
  }
  lseek(fp_src, 0, SEEK_SET);
  if (read(fp_src, buf, FILE_LEN) > 0 && write(fp_merge, buf, FILE_LEN) > 0) {
    lseek(fp_bak, 0, SEEK_SET);
    if (read(fp_bak, buf, FILE_LEN) > 0 && write(fp_merge, buf, FILE_LEN)) {
      system("cat file");
    }

  }
  printf("\n");
  close(fp_src);
  close(fp_bak);
  close(fp_merge);
  return 0;
}
