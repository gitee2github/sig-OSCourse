all: crc32

crc32: crc32_kunpeng.o main.o
        @gcc -g $^ -o $@

crc32_kunpeng.o: crc32_kunpeng.c
        @gcc -g -c $^ -o $@ -march=armv8-a+crc

main.o: main.c
        @gcc -g -c $^ -o $@
