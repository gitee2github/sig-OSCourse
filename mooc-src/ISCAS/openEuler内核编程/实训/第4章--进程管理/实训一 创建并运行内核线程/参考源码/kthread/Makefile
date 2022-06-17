ifneq ($(KERNELRELEASE),)
	obj-m := kthread.o
else
	KERNELDIR ?=/root/raspberrypi-kernel
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
.PHONY:clean
install:
	insmod kthread.ko
uninstall:
	rmmod kthread
clean:
	-rm *.mod.c *.o *.order *.symvers *.ko
