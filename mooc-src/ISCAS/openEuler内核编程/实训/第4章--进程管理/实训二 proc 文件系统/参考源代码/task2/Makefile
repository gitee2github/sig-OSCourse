ifneq ($(KERNELRELEASE),)
	obj-m := proc_time.o
else
	KERNELDIR ?=/root/raspberrypi-kernel
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
install:
	insmod proc_time.ko
uninstall:
	rmmod proc_time
.PHONY:clean
clean:
	-rm *.mod.c *.o *.order *.symvers *.ko
