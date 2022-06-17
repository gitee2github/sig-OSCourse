#include <stdio.h>

#include <stdlib.h>

#include <sys/stat.h>

#include <time.h>

#include <string.h>

int main(int argc, char * argv[]) {
  struct stat buf;
  char * pnewfile = "testfile_bak";
  char szbuf[100] = {
    0
  };
  FILE * fpold = NULL, * fpnew = NULL;
  int len = 0;
  if (argc < 2) {
    printf("arg error\n");
  }
  fpold = fopen(argv[1], "r");

  if (stat(argv[1], & buf) != 0) {
    printf("stat error\n");
  }
  printf("user gid is %d,grp id is %d\n", buf.st_uid, buf.st_gid);
  printf("visi time is %ld,last time is %ldo\n", buf.st_atime, buf.st_mtime);
  printf("vist time is %s,last time is %s\n", ctime((const time_t * ) & buf.st_atime), ctime((const time_t * ) & buf.st_mtime));

  if (fpold == NULL) {
    printf("open file %s error\n", argv[1]);
    return -1;
  }

  if ((fpnew = fopen(pnewfile, "w+")) == NULL) {
    printf("open file %s error\n", pnewfile);
    return -1;
  }
  if ((len = fread(szbuf, 1, sizeof(szbuf), fpold)) < 0) {
    printf("fread error\n");
    return -1;
  }
  if (fwrite(szbuf, 1, len, fpnew) < 0) {
    printf("write error\n");
    return -1;
  }
  printf("rewrite over\n");
  fclose(fpold);
  fclose(fpnew);
  if (remove(argv[1]) == 0) {
    printf("delete file %s\n", argv[1]);
  }

  return 0;

}
