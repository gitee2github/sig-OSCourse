ifneq ($(KERNELRELEASE),)
	obj-m := kthread_sleep.o
else
	KERNELDIR ?=/root/raspberrypi-kernel
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
.PHONY:clean
install:
	insmod kthread_sleep.ko
uninstall:
	rmmod kthread_sleep
clean:
	-rm *.mod.c *.o *.order *.symvers *.ko
