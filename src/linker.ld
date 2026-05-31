ENTRY(kmain)

SECTIONS
{

    /* Для GRUB */
    .multiboot :{
    *(.multiboot)
    }

    /* Основной код и данные ОС */
    . = 0x10000;
    .text : {
    *(.text)
    }

    .rodata : {
    *(.rodata*)
    }

    .data : {
    *(.data)
    }

    .bss : {
    *(.bss)
    *(COMMON)
    }

    . = 0x50000;
    .program_area : {
    *(.program_area)
    }

}
