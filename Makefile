EXTRA_CFLAGS=-Wall -g
PWD := $(CURDIR)
kernel=$(shell uname -r)

obj-m += example.o

all: example.ko

example.ko: example.c
	make -C /lib/modules/$(kernel)/build M=$(PWD) modules

install: example.ko
	insmod example.ko

uninstall:
	rmmod example

clean:
	make -C /lib/modules/$(kernel)/build M=$(PWD) clean

.PHONY: all clean uninstall install

