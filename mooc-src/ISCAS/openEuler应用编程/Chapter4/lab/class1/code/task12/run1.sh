gcc -fPIC -shared -I./include lib/add.c -o lib/libadd.so
gcc -o main1 main.c -I./include lib/libadd.so
./main1 3 5
