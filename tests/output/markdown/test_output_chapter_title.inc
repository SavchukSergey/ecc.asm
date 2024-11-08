test_output_chapter_title:
    push    rcx
    mov     rsi, .prefix
    call    Console_WriteString
    pop     rcx

    mov     rsi, rcx
    call    Console_WriteString

    mov     rsi, .suffix
    call    Console_WriteString

    ret

.prefix db '## ', 0
.suffix db 13, 10, 0
