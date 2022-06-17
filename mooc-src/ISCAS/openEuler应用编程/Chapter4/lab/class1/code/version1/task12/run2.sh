gcc -fPIC -shared -I./include lib/add.c -o lib/libadd.so
gcc -o main2 main.c -I./include -L./lib/ -Wl,-rpath=lib/ -ladd
./main2 3 5
