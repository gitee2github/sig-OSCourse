gcc -fPIC -shared -I./include lib/add.c -o lib/libadd.so
LD_LIBRARY_PATH=./lib/ ../task12/main 3 5
