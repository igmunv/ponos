

OBJS := $(shell mkdir -p output; find output -name '*.o')

CC = i386-elf-gcc
CFLAGS = -w -ffreestanding -m32 -fno-pie -nostdlib

NS = nasm
NSFLAGS = -f elf32

FILES_C    := $(shell find src/ -name *.c)
FILES_ASM    := $(shell find src/ -name *.asm)


define build-rule
    for src in $(1); do \
        obj=$$(echo $$src | sed 's|$(2)|$(3)|' | sed 's|$(4)$$|$(5)|'); \
        echo "Building $$src -> $$obj"; \
        mkdir -p $$(dirname $$obj); \
        if echo $$src | grep -q "\.c$$"; then \
            $(6) $(7) -c $$src -o $$obj; \
        else \
            $(6) $(7) $$src -o $$obj; \
        fi; \
    done
endef


all:
	$(MAKE) build
	$(MAKE) make_iso
	$(MAKE) run


kernel:
	mkdir -p output/kernel/
	$(call build-rule,$(FILES_C),src/,output/,.c,.o,$(CC),$(CFLAGS))
	$(call build-rule,$(FILES_ASM),src/,output/,.asm,.o,$(NS),$(NSFLAGS))

link:
	i386-elf-ld -m elf_i386 -T src/linker.ld --oformat elf32-i386 -o output/kernel.elf $(OBJS)

clean:
	rm -rf output/

build:
	echo "\n --- --- clean --- --- \n"
	$(MAKE) clean
	echo "\n --- --- kernel --- --- \n"
	$(MAKE) kernel
	echo "\n --- --- link --- --- \n"
	$(MAKE) link


make_iso:
	# Make ISO
	cp output/kernel.elf iso/boot/
	grub-mkrescue -o output/kernel.iso ./iso/


run:
	qemu-system-i386 -no-reboot -no-shutdown -monitor stdio \
	-drive file=output/kernel.iso,format=raw,if=ide,index=1,media=cdrom \
	-d int,cpu_reset -D qemu.log \
	-boot d
