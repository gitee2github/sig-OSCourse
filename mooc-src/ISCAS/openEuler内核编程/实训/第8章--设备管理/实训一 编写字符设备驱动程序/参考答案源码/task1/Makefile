ifneq ($(KERNELRELEASE),)
	obj-m := GlobalCharDev.o
else
	KERNELDIR ?=/usr/lib/modules/4.19.90-g7d1ed3ae1110/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
.PHONY:clean
clean:
	-rm *.mod.c *.o *.order *.symvers *.ko
