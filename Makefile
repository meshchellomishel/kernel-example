EXTRA_CFLAGS=-Wall -g
PWD := $(CURDIR)
kernel=$(shell uname -r)

obj-m += example.o

all: example.ko

example.ko: example.c
	make -C /lib/modules/$(kernel)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(kernel)/build M=$(PWD) clean

.PHONY: all clean

