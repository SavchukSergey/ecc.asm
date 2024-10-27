include 'output/text/test_output_start.inc'

test_output_end:
    mov     rsi, .msg
    call    Console_WriteString

    ret
.msg db 'finished', 13, 10, 0


test_output_start_chapter:
    ret

test_output_end_chapter:
    ret

test_output_chapter_title:
    mov     rsi, rcx
    call    Console_WriteString
    call    Console_WriteLine

    ret

test_output_start_chapter_table:
    mov     rsi, .msg
    call    Console_WriteString

    ret
.msg db \
'+------------------------+--------+---------------+---------------+', 13, 10, \
'| Name                   | Status | Min CPU ticks | Max CPU ticks |', 13, 10, \
'+------------------------+--------+---------------+---------------+', 13, 10, \
0

test_output_end_chapter_table:
    mov     rsi, .msg
    call    Console_WriteString
    ret
.msg db \
'+------------------------+--------+---------------+---------------+', 13, 10, \
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
.test_name_suffix db 0x1b, '[25G', ' |', 0



; rcx - non zero if test is failed
test_output_test_status_cell:
    test    rcx, rcx
    je      .test_ok
.test_fail:
    mov     rsi, .failed
    call    Console_WriteString
    ret
.test_ok:
    mov     rsi, .passed
    call    Console_WriteString
    ret
.failed db TEXT_COLOR_ERROR, ' FAILED ', TEXT_COLOR_DEFAULT, '|', 0
.passed db TEXT_COLOR_SUCCESS, ' PASSED ', TEXT_COLOR_DEFAULT, '|', 0


test_output_test_min_ticks_cell:
    push    rcx
    mov     rsi, .prefix
    call    Console_WriteString
    pop     rcx
    call    Console_WriteUInt64
    mov     rsi, .suffix
    call    Console_WriteString
    ret

.prefix db 0x1b, '[37G', 0
.suffix db 0x1b, '[50G |', 0


test_output_test_max_ticks_cell:
    push    rcx
    mov     rsi, .prefix
    call    Console_WriteString
    pop     rcx
    call    Console_WriteUInt64
    mov     rsi, .suffix
    call    Console_WriteString
    ret

.prefix db 0x1b, '[52G ', 0
.suffix db 0x1b, '[66G |', 0
