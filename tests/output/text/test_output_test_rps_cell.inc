test_output_test_rps_cell:
    push    rcx
    mov     rsi, .prefix
    call    Console_WriteString
    pop     rcx
    call    test_output_rps
    mov     rsi, .suffix
    call    Console_WriteString
    ret

.prefix db 0x1b, '[77G', 0
.suffix db 0x1b, '[89G |', 0
