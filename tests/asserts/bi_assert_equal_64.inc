include '../src/console/write_u64_hex.inc'

if ~ definite bi_assert_equal_64

;Asserts two u64 values to be equal
;input
; rcx - expected
; rdx - actual
bi_assert_equal_64:
        push    rax rsi
        cmp     rcx, rdx
        jz      .end
.fail:
        lea     rsi, [.msg_1]
        call    Console_WriteString

        push    rcx
        mov     rcx, rdx
        call    Console_WriteUInt64Hex
        pop     rcx

        lea     rsi, [.msg_2]
        call    Console_WriteString

        call    Console_WriteUInt64Hex

        lea     rsi, [.msg_3]
        call    Console_WriteString
.end:
        pop     rsi rax
        ret

.msg_1 db TEXT_COLOR_ERROR, 'Expected u64:', 13, 10, 'A: ', 0
.msg_2 db 13, 10, 'E: ', 0
.msg_3 db 13, 10, 0

end if