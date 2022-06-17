gcc -E main1.c -o main1.i
gcc -S main1.i -o main1.s
gcc -c main1.s -o main1.o
cat main1.o
