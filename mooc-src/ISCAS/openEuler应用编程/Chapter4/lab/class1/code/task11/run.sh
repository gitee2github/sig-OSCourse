gcc -fPIC -shared -I./include lib/add.c -o lib/libadd.so
gcc -o main main.c -I./include -L./lib/ -ladd
LD_LIBRARY_PATH=./lib ./main 3 5
