ifneq ($(KERNELRELEASE),)
	obj-m := kth_bindCPU.o
else
	KERNELDIR ?=/root/raspberrypi-kernel
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
.PHONY:clean
install:
	insmod kth_bindCPU.ko
uninstall:
	rmmod kth_bindCPU
clean:
	-rm *.mod.c *.o *.order *.symvers *.ko
