include 'output/html/test_output_chapter_title.inc'
include 'output/html/test_output_end_chapter_table.inc'
include 'output/html/test_output_end_chapter.inc'
include 'output/html/test_output_end.inc'
include 'output/html/test_output_start_chapter_table.inc'
include 'output/html/test_output_start_chapter.inc'
include 'output/html/test_output_start.inc'










test_output_start_test:
    mov     rsi, .msg
    call    Console_WriteString

    ret
.msg db \
'  <tr>', 13, 10, 0

test_output_end_test:
    mov     rsi, .msg
    call    Console_WriteString
    ret
.msg db \
'  </tr>', 13, 10, 0


test_output_test_name_cell:
    push    rcx
    mov     rsi, .test_name_prefix
    call    Console_WriteString
    pop     rsi
    call    Console_WriteString
    mov     rsi, .test_name_suffix
    call    Console_WriteString
    ret

.test_name_prefix db '    <td>', 13, 10, 0
.test_name_suffix db 13, 10, '    </td>', 13, 10, 0

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
.failed db '    <td class="text-center"><span class="badge text-bg-danger">FAILED</span></td>', 13, 10, 0
.passed db '    <td class="text-center"><span class="badge text-bg-success">PASSED</span></td>', 13, 10, 0


test_output_test_min_ticks_cell:
    push    rcx
    mov     rsi, .prefix
    call    Console_WriteString
    pop     rcx
    call    Console_WriteUInt64
    mov     rsi, .suffix
    call    Console_WriteString
    ret

.prefix db '    <td class="text-end">', 13, 10, 0
.suffix db 13, 10, '    </td>', 13, 10, 0


test_output_test_max_ticks_cell:
    push    rcx
    mov     rsi, .prefix
    call    Console_WriteString
    pop     rcx
    call    Console_WriteUInt64
    mov     rsi, .suffix
    call    Console_WriteString
    ret

.prefix db '    <td class="text-end">', 13, 10, 0
.suffix db 13, 10, '    </td>', 13, 10, 0

