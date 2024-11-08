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