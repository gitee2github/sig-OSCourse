#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* OpenSSL headers */
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/engine.h>

int main(int argc, char **argv)
{

time_t c_start, c_end;
c_start = clock();
int i=0;
printf("Begin at  %f .\n",c_start);
for(;i<100;i++){
  // 产生RSA密钥对
  RSA *rsaKey = RSA_generate_key(1024, 65537, NULL, NULL);

        int keySize = RSA_size(rsaKey);

        char fData[]="aaabbbccdskjkfd";
        char tData[128];

        int  flen = strlen(fData);
        //flen = 15

        int ret =  RSA_public_encrypt(flen, (unsigned char *)fData, (unsigned char *)tData, rsaKey,  RSA_PKCS1_PADDING);
        //ret = 128

        ret = RSA_private_decrypt(128, (unsigned char *)tData, (unsigned char *)fData, rsaKey, RSA_PKCS1_PADDING);
        //ret = 15

        RSA_free(rsaKey);
}
c_end = clock();
printf("RSA used %f ms .\n",difftime(c_end,c_start));

}
