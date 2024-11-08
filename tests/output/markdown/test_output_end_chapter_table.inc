test_output_end_chapter_table:
    mov     rsi, .msg
    call    Console_WriteString
    ret
.msg db \
13, 10, \
0
