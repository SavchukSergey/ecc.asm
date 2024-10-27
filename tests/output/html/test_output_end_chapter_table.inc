include '../../console/write_string.inc'

test_output_end_chapter_table:
    mov     rsi, .msg
    call    Console_WriteString
    ret
.msg db \
'  </tbody>', 13, 10, \
'</table>', 13, 10, 0
