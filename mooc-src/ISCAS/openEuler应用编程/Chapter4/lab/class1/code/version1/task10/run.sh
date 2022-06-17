gcc -c -I./include lib/add.c -o lib/add.o
ar -rsv lib/libadd.a lib/add.o
gcc -o main main.c -I./include -L./lib/ -ladd
./main 3 5
