ifneq ($(KERNELRELEASE),)
	obj-m := vmalloc.o
else
	KERNELDIR ?= /root/raspberrypi-kernel
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
.PHONY:clean
clean:
	-rm *.mod.c *.o *.order *.symvers *.ko

