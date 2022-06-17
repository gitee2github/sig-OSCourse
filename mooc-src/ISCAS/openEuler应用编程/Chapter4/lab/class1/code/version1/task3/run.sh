gcc -E main1.c -o main1.i
gcc -S main1.i -o main1.s
cat main1.s
