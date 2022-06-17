ifneq ($(KERNELRELEASE),)
	obj-m :=spinlock.o
else
	KERNELDIR ?=/root/raspberrypi-kernel
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
.PHONY:clean
install:
	insmod spinlock.ko
uninstall:
	rmmod spinlock
clean:
	-rm *.mod.c *.o *.order *.symvers *.ko
