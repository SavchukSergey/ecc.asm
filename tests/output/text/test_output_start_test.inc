test_output_start_test:
    mov     rsi, .msg
    call    Console_WriteString

    ret
.msg db 0
