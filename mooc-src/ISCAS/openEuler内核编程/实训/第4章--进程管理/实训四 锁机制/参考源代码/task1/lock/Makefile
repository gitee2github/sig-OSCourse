ifneq ($(KERNELRELEASE),)
	obj-m :=lock.o
else
	KERNELDIR ?=/root/raspberrypi-kernel
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
.PHONY:clean
install:
	insmod lock.ko
uninstall:
	rmmod lock
clean:
	-rm *.mod.c *.o *.order *.symvers *.ko
