#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv){
  if(2 != argc){
	printf("input error\n");
	return -1;
	}
  FILE* test = fopen(argv[1], "r");
  char *buf = NULL;
  size_t len  = 0;
  int num;
  while( (num = getline(&buf, &len, test) ) != -1){
    printf("%s", buf);

  }
  fclose(test);
  return 0;

}
