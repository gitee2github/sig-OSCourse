#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINENUM 4096

int main(int argc, char ** argv)
{
  if ( argc != 3){
    printf("usage: jbcset file1 file2\n");
    return -1;
  }

  char * file1name = argv[1];
  char * file2name = argv[2];

  FILE * file1 = fopen(file1name, "r");
  FILE * file2 = fopen(file2name, "r");

  FILE * cfile= fopen("file1_c_file2", "w ");

  char *buf1 = NULL, *buf2 = NULL;
  size_t len1 = 0, len2 = 0;
  int num1, num2;
  int cmprel;
  num1 = getline( &buf1, &len1, file1);
  num2 = getline( &buf2, &len2, file2);
  while( num1 != -1 && num2 != -1){

    cmprel = strcmp(buf1, buf2); 
    if( cmprel < 0 ){
      fwrite(buf1, 1, strlen(buf1), cfile);
      num1 = getline( &buf1, &len1, file1); 
    }
    else if( cmprel > 0 ){
      num2 = getline( &buf2, &len2, file2);
    }
    else {
      num1 = getline( &buf1, &len1, file1);
      num2 = getline( &buf2, &len2, file2);
    }
  }
  
  while(num1 != -1){
    fwrite(buf1, 1, strlen(buf1), cfile);
    num1 = getline( &buf1, &len1, file1); 
  }

  free(buf1);
  free(buf2);
  fclose(file1);
  fclose(file2);
  fclose(cfile);

}
