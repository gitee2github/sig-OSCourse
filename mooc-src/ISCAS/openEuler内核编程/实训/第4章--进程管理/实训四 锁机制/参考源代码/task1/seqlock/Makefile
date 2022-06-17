ifneq ($(KERNELRELEASE),)
	obj-m :=seqlock.o
else
	KERNELDIR ?=/root/raspberrypi-kernel
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
.PHONY:clean
install:
	insmod seqlock.ko
uninstall:
	rmmod seqlock
clean:
	-rm *.mod.c *.o *.order *.symvers *.ko
