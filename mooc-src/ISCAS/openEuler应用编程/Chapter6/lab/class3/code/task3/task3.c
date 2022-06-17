#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#define SIZE 100
int main() {
  int strNum = 0;
  char ** strArray = NULL;
  int i = 0;
  char buf[SIZE];
  printf("please input the num of string \n");
  scanf("%d", & strNum);

  strArray = (char ** ) malloc(strNum * sizeof(char * ));
  if (NULL == strArray) {
    perror("allocate memory failed");
    exit(2);
  }
  for (i = 0; i < strNum; i++) {
    strArray[i] = (char * ) malloc(SIZE * sizeof(char));
    if (NULL == strArray[i]) {
      perror("allocate memory failed");
      exit(2);
    }
    memset(buf, '\0', sizeof(buf));
    printf("input the %d str:\n", i + 1);
    scanf("%s", buf);
    strcpy(strArray[i], buf);

  }
  printf("now, printf all strings\n");
  for (i = 0; i < strNum; i++) {

    memset(buf, '\0', sizeof(buf));
    strcpy(buf, strArray[i]);
    printf("%s\n", buf);
    free(strArray[i]);
  }
  free(strArray);
  return 0;
}
