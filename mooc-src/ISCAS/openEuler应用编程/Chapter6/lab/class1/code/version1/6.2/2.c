#include <stdio.h>
#include <string.h>

int main (int argc, char* argv[])
{
   if(argc < 3)
   {
      printf("ERROR: Invalid argument number.\n");
      return 0;
   }
   FILE *fp;
   char* filename = argv[1];
   fp = fopen( filename , "a+" );
   if(fp == NULL)
   {
      printf("ERROR: Cannot open file: %s.\n", filename);
      return 0;
   }
   //在程序内编写要写入的字符串
   char s[] = "hello world";   
   fwrite(s,sizeof(s)-1,1,fp);

   // 参数输入要写入的字符串
   char* str = argv[2];
   fwrite(str, sizeof(char), strlen(str), fp);	
   fclose(fp);
   return(0);
}
