global gdt_init


section .data


gdt:

gdt_null:
    dd 0x00000000
    dd 0x00000000

gdt_code:
    dd 0x0000FFFF
    dd 0x00CF9A00

gdt_data:
    dd 0x0000FFFF
    dd 0x00CF9200

gdt_end:


gdt_desc:
   dw gdt_end - gdt - 1
   dd gdt


section .text

gdt_init:

    lgdt [gdt_desc]

    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    jmp 0x08:.clean_pipe


.clean_pipe:
    ret


