include '../../console/write_string.inc'

test_output_end_test:
    mov     rsi, .msg
    call    Console_WriteString
    ret
.msg db \
'  </tr>', 13, 10, 0
