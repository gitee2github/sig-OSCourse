ifneq ($(KERNELRELEASE),)
	obj-m := sigkill.o
else
	KERNELDIR ?=/root/raspberrypi-kernel
	PWD := $(shell pwd)
	CONFIG_MODULE_SIG=n
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
.PHONY:clean
clean:
	-rm *.mod.c *.o *.order *.symvers *.ko
