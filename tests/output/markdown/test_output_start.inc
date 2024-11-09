test_output_start:
    mov     rsi, .msg
    call    Console_WriteString

    mov     rsi, .cpu_info
    call    Console_WriteString

    call    test_output_cpu_name
    ret

.msg db '# ecc.asm tests', 13, 10, 13, 10, 0
.cpu_info db '# Cpu Info', 13, 10, 13, 10, 0
