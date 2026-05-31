

OBJS := $(shell mkdir -p ../output/term; find ../output/term -name '*.o')

CC = i386-elf-gcc
CFLAGS = -w -ffreestanding -m32 -fno-pie -nostdlib


all:
	$(MAKE) build


program:
	mkdir -p ../output/term/
	$(CC) $(CFLAGS) -c term.c -o ../output/term/term.o


link:
	i386-elf-ld -m elf_i386 -T linker.ld --oformat elf32-i386 -o ../output/term/term.elf $(OBJS)
	i386-elf-objcopy -O binary ../output/term/term.elf ../output/term/term.bin


clean:
	rm -rf ../output/term/


build:
	echo "\n --- --- clean --- --- \n"
	$(MAKE) clean
	echo "\n --- --- program --- --- \n"
	$(MAKE) program
	echo "\n --- --- link --- --- \n"
	$(MAKE) link


