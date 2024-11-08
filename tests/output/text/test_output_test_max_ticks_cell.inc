test_output_test_max_ticks_cell:
    push    rcx
    mov     rsi, .prefix
    call    Console_WriteString
    pop     rcx
    call    Console_WriteUInt64
    mov     rsi, .suffix
    call    Console_WriteString
    ret

.prefix db 0x1b, '[60G ', 0
.suffix db 0x1b, '[74G |', 0
