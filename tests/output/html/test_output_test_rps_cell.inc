test_output_test_rps_cell:
    push    rcx
    mov     rsi, .prefix
    call    Console_WriteString
    pop     rcx
    call    test_output_rps
    mov     rsi, .suffix
    call    Console_WriteString
    ret

.prefix db '    <td class="text-end">', 13, 10, 0
.suffix db 13, 10, '    </td>', 13, 10, 0