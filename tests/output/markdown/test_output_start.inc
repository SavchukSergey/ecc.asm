test_output_start:
    mov     rsi, .msg
    call    Console_WriteString

    ret

.msg db '# ecc.asm tests', 13, 10, 13, 10, 0
