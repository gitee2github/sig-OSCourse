#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const uint32_t Polynomial = 0xEDB88320;
const size_t NumBytes = 1024*1024*1024;

uint32_t crc32_bitwise(const void* data, size_t length, uint32_t previousCrc32 = 0)
{
  uint32_t crc = ~previousCrc32; // same as previousCrc32 ^ 0xFFFFFFFF
  unsigned char* current = (unsigned char*) data;
  while (length--)
  {
    crc ^= *current++;
    for (unsigned int j = 0; j < 8; j++)
      if (crc & 1)
        crc = (crc >> 1) ^ Polynomial;
      else
        crc =  crc >> 1;
  }
  return ~crc; // same as crc ^ 0xFFFFFFFF
}

int main(){
    uint32_t randomNumber = 0x27121978;
    char* data = new char[NumBytes];
    for (size_t i = 0; i < NumBytes; i++)
    {
        data[i] = char(randomNumber & 0xFF);
        // simple LCG, see http://en.wikipedia.org/wiki/Linear_congruential_generator
        randomNumber = 1664525 * randomNumber + 1013904223;
    }
    uint32_t crc;
    // startTime = seconds();
    crc = crc32_bitwise(data, NumBytes);
    // duration  = seconds() - startTime;
    printf("bitwise          : CRC=%08X\n", crc);
    return 0;
}
