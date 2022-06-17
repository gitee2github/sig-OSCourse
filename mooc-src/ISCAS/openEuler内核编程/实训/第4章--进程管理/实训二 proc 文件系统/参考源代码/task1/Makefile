ifneq ($(KERNELRELEASE),)
	obj-m := proc_parser.o
else
	KERNELDIR ?=/root/raspberrypi-kernel
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
install:
	insmod proc_parser.ko
uninstall:
	rmmod proc_parser
.PHONY:clean
clean:
	-rm *.mod.c *.o *.order *.symvers *.ko
