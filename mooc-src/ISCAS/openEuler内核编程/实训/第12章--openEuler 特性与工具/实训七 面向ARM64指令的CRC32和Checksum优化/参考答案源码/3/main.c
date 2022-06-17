#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>
#include <sys/stat.h>

unsigned int kunpeng_crc32(unsigned int crc_init,
    unsigned char *s, unsigned int n);

/*
 * 使用举例:
 * 1. 由程序生成指定长度随机数据进行测试./crc32 random 1000000
 */
#define CRC32_MAX_LEN 0xffffffff
int main(int argc, char *argv[])
{
    unsigned int ans = 0;
    struct timeval time1, time2, seed;
    char *buf = NULL;
    unsigned int testlen = 0;
    FILE *fp = NULL;

        /* 随机测试数据准备 */
        /* 最大为4G此处不做限制请注意机器内存 */
        testlen = atoi(argv[2]);
        buf = (char *)malloc(testlen);
        if (buf == NULL) {
            return -1;
        }
        gettimeofday(&seed, NULL);
        srand(seed.tv_usec);
        for (int i = 0; i < testlen; i++) {
            buf[i] = (char)rand();
        }
    
    /* 开始进行CRC32校验和计算对比 */
    unsigned long cost = 0;
    printf("Test data length: %lu.\n", testlen);
    gettimeofday(&time1,NULL);
    /* 鲲鹏加速指令实现的CRC32校验和 */
    ans = kunpeng_crc32(0, buf, testlen);
    gettimeofday(&time2,NULL);
    cost = (time2.tv_sec-time1.tv_sec)*1000000+(time2.tv_usec-time1.tv_usec);
    printf("\nKunpeng accelerator result : 0x%x.\n", ans);
    printf("Time used: %ld us, rate: %.2lf Mb/s\n", cost, (cost == 0) ? 0 : (double)testlen/(double)cost);

    free(buf);
    return 0;
}
