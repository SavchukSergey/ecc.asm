include 'output/text/test_output_chapter_title.inc'
include 'output/text/test_output_end_chapter.inc'
include 'output/text/test_output_end.inc'
include 'output/text/test_output_start_chapter.inc'
include 'output/text/test_output_start.inc'
include 'output/text/test_output_test_max_ticks_cell.inc'
include 'output/text/test_output_test_min_ticks_cell.inc'
include 'output/text/test_output_test_status_cell.inc'


test_output_start_chapter_table:
    mov     rsi, .msg
    call    Console_WriteString

    ret
.msg db \
'+--------------------------------+--------+---------------+---------------+', 13, 10, \
'| Name                           | Status | Min CPU ticks | Max CPU ticks |', 13, 10, \
'+--------------------------------+--------+---------------+---------------+', 13, 10, \
0

test_output_end_chapter_table:
    mov     rsi, .msg
    call    Console_WriteString
    ret
.msg db \
'+--------------------------------+--------+---------------+---------------+', 13, 10, \
0


test_output_start_test:
    mov     rsi, .msg
    call    Console_WriteString

    ret
.msg db 0

test_output_end_test:
    call    Console_WriteLine
    ret

test_output_test_name_cell:
    push    rcx
    mov     rsi, .test_name_prefix
    call    Console_WriteString
    pop     rsi
    call    Console_WriteString
    mov     rsi, .test_name_suffix
    call    Console_WriteString
    ret

.test_name_prefix db '| ', 0
.test_name_suffix db 0x1b, '[33G', ' |', 0





