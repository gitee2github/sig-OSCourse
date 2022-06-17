ifneq ($(KERNELRELEASE),)
	obj-m := main.o
else
	KERNELDIR ?= /usr/lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
install:
	insmod main.ko
uninstall:
	rmmod main
.PHONY:clean
clean:
	-rm *.mod.c *.o *.order *.symvers *.ko
