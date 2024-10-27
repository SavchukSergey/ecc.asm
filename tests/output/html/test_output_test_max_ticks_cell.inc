include '../../console/write_string.inc'
include '../../console/write_u64_hex.inc'

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
