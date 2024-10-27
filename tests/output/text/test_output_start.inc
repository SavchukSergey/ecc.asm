include '../../console/write_string.inc'

test_output_start:
    mov     rsi, .msg
    call    Console_WriteString

    ret
.msg db 'ecc.js tests', 13, 10, 0
