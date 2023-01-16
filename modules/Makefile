ifneq	($(KERNELRELEASE),)
	obj-m := driverHygro.o
else 
	KERN_DIR ?= /usr/src/linux-headers-$(shell uname -r)
	PWD := $(shell pwd)
all:
	$(MAKE) -C $(KERN_DIR) M=$(shell pwd) modules
#    rm -r -f .tmp_versions *.mod.c .*.cmd *.o *.symvers
endif

clean:
	rm -rf *.o *.ko *.mod.c *.order *.symvers .*.cmd .tmp_versions
.PHONY:clean
