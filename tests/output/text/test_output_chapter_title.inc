include '../../console/write_line.inc'
include '../../console/write_string.inc'

test_output_chapter_title:
    mov     rsi, rcx
    call    Console_WriteString
    call    Console_WriteLine

    ret

