include '../../console/write_string.inc'
include '../../console/write_u64.inc'

test_output_test_min_ticks_cell:
    push    rcx
    mov     rsi, .prefix
    call    Console_WriteString
    pop     rcx
    call    Console_WriteUInt64
    mov     rsi, .suffix
    call    Console_WriteString
    ret

.prefix db 0x1b, '[45G', 0
.suffix db 0x1b, '[58G |', 0
