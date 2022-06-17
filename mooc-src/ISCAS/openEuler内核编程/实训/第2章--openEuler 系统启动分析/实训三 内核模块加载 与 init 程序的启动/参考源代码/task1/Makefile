obj-m:=hello.o
KERNELBUILD :=/root/raspberrypi-kernel
default: 
	make -C $(KERNELBUILD) M=$(shell pwd) modules
	echo insmod ./hello.ko to turn it on
clean:
	rm -rf *.o *.ko *.mod.c .*.cmd *.markers *.order *.symvers .tmp_versions

