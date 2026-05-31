

OBJS := $(shell mkdir -p ../output/colorama; find ../output/colorama -name '*.o')

CC = i386-elf-gcc
CFLAGS = -w -ffreestanding -m32 -fno-pie -nostdlib


all:
	$(MAKE) build


program:
	mkdir -p ../output/colorama/
	$(CC) $(CFLAGS) -c colorama.c -o ../output/colorama/colorama.o


link:
	i386-elf-ld -m elf_i386 -T linker.ld --oformat elf32-i386 -o ../output/colorama/colorama.elf $(OBJS)
	i386-elf-objcopy -O binary ../output/colorama/colorama.elf ../output/colorama/colorama.bin


clean:
	rm -rf ../output/colorama/


build:
	echo "\n --- --- clean --- --- \n"
	$(MAKE) clean
	echo "\n --- --- program --- --- \n"
	$(MAKE) program
	echo "\n --- --- link --- --- \n"
	$(MAKE) link


