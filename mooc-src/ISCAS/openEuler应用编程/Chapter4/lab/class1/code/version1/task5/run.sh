gcc -E main1.c -o main1.i
gcc -S main1.i -o main1.s
gcc -c main1.s -o main1.o
#cc main1.o -o main1
ld -static /usr/lib/i386-linux-gnu/crt1.o /usr/lib/i386-linux-gnu/crti.o /usr/lib/gcc/i686-linux-gnu/4.7/crtbeginT.o -L/usr/lib/gcc/i686-linux-gnu/4.7 -L/usr/lib -L/lib main1.o --start-group -lgcc -lgcc_eh -lc --end-group /usr/lib/gcc/i686-linux-gnu/4.7/crtend.o /usr/lib/i386-linux-gnu/crtn.o -o main1
file main1
objdump -x main1
