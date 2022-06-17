ifneq ($(KERNELRELEASE),)
	obj-m :=rwspin.o
else
	KERNELDIR ?=/root/raspberrypi-kernel
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
.PHONY:clean
install:
	insmod rwspin.ko
uninstall:
	rmmod rwspin
clean:
	-rm *.mod.c *.o *.order *.symvers *.ko
