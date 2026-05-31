global keyboard_intr_handler_asm

extern keyboard_intr_handler


keyboard_intr_handler_asm:
    pusha
    call keyboard_intr_handler
    popa
    iret
