#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define LINENUM 4096 

int cmpstring(const void * a, const void * b)
{
  char * str1 = *(char **)a;
  char * str2 = *(char **)b;
  return strcmp(str1, str2);
}


int main(int argc, char **argv)
{
  char *buf = NULL;
  size_t len = 0;
  int num;
  if(argc != 2){
    printf("the arguments is wrong! \n usage: readfile filename\n");
    return -1;
  }

  char * filename = argv[1];
  FILE *test = fopen(filename, "r");
  if ( test == NULL){
    printf("the file %s doesn't exist!\n", filename);
  }

  //allocate the memory to store the content in the file
  char **lines = (char **)malloc( LINENUM * sizeof(char*));
  int lineno = 0;
  while ( (num = getline ( &buf, &len, test )) != -1){
      //copy the content in buf to lines
      lines[lineno]= (char*)malloc(len * sizeof(char));
      strcpy(lines[lineno], buf);
      lineno ++;
  }
  //sort the string lines according to the alphabet sort
  qsort(lines, lineno, sizeof(char *), cmpstring);
 
  int i = 0;
  for(i=0; i < lineno; i++){
    printf("%s",lines[i]);
  }
  
}
