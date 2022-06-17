#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* OpenSSL headers */
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/engine.h>
#include <openssl/aes.h>
#include <openssl/pkcs7.h>
#ifndef uchar
#define uchar unsigned char
#endif

int aes_encrypt(char* in, char* key, char* out, int olen)  
{  
    if(!in || !key || !out) return 0;  
    AES_KEY aes;  
    if(AES_set_encrypt_key((unsigned char*)key, 128, &aes) < 0)  
    {  
        return 0;  
    }  
    int len=strlen(in), en_len=0;  
    while(en_len<len) 
    {  
        AES_encrypt((unsigned char*)in, (unsigned char*)out, &aes);  
        in+=AES_BLOCK_SIZE;  
        out+=AES_BLOCK_SIZE;  
        en_len+=AES_BLOCK_SIZE;  
    }  
    return 1;  
} 

int aes_decrypt(char* in, char* key, char* out)  
{  
    if(!in || !key || !out) return 0;  
    AES_KEY aes;  
    if(AES_set_decrypt_key((unsigned char*)key, 128, &aes) < 0)  
    {  
        return 0;  
    }  
    int len=strlen(in), en_len=0;  
    while(en_len<len)  
    {  
        AES_decrypt((unsigned char*)in, (unsigned char*)out, &aes);  
        in+=AES_BLOCK_SIZE;  
        out+=AES_BLOCK_SIZE;  
        en_len+=AES_BLOCK_SIZE;  
    }  
    return 1;  
}  

int main(int argc, char **argv)
{
time_t c_start, c_end;
c_start = clock();
int i=0;
printf("Begin at  %f .\n",c_start);
for(;i<100;i++){
    char *_key = "jkl;!@#$";
    char *_str = "qazwsxedcrfv123456!@#"; 
    char *_strout =  UI_null;

    aes_encrypt(_str,_key,&_strout,21) ;
    char *_strin =  UI_null;
    aes_decrypt(_strout,_key,&_strin);

    printf( "final: %s\n", _strin );
    free(_strin);
    free(_strout);
    return 0;
}
c_end = clock();
printf("AES used %f ms .\n",difftime(c_end,c_start));

}
