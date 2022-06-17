#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>
#include <arm_acle.h>
#include <arm_neon.h>

typedef unsigned int uint32_t;
typedef unsigned short uint16_t;
typedef unsigned char uint8_t;
typedef unsigned long uint64_t;

unsigned int kunpeng_crc32(unsigned int crc_init,
    unsigned char *s, unsigned int n)
{
    register uint32_t crc_result;
    register const uint8_t  *buf1;
    register const uint16_t *buf2;
    register const uint32_t *buf4;
    register const uint64_t *buf8;
    int length = (int)n;
    buf8 = (const  uint64_t *)(const void *)s;

    crc_result = crc_init ^ 0xffffffffUL;

    while(length >= sizeof(uint64_t)) {
        crc_result = __crc32d(crc_result, *buf8++);
        length -= sizeof(uint64_t);
    }

    buf4 = (const uint32_t *)(const void *)buf8;
    if (length >= sizeof(uint32_t)) {
        crc_result = __crc32w(crc_result, *buf4++);
        length -= sizeof(uint32_t);
    }

    buf2 = (const uint16_t *)(const void *)buf4;
    if(length >= sizeof(uint16_t)) {
        crc_result = __crc32h(crc_result, *buf2++);
        length -= sizeof(uint16_t);
    }

    buf1 = (const uint8_t *)(const void *)buf2;
    if (length >= sizeof(uint8_t)) {
        crc_result = __crc32b(crc_result, *buf1);
        length -= sizeof(uint8_t);
    }

    return (crc_result ^ 0xffffffffL);
}
