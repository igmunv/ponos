ENTRY(_start)

SECTIONS
{

    . = 0x50000;

    .header : {
        *(.header)
    }

    .name : {
        *(.name)
    }

    .text : {
    *(.text.start)
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

}
