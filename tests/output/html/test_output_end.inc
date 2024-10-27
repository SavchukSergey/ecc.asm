include '../../console/write_string.inc'

test_output_end:
    mov     rsi, .msg
    call    Console_WriteString

    ret
.msg db \
'</body>', 13, 10, \
'</html>', 13, 10, 0