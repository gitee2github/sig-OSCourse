vpath %.h ./include
vpath %.c ./src
vpath %.o ./src
vpath %.o ./
CFLAGS = -g -Wall -I./include
hello : hello.o myfun.o
	gcc hello.o ./src/myfun.o  -o  $@
hello.o : hello.c
	gcc $(CFLAGS) -c $< -o $@
myfun.o : myfun.c 
	cd src;make 
clean :
	rm -f *.o hello
	cd src;make clean

