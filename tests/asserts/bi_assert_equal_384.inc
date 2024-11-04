include '../../src/math/bigint/cmp/bi_cmp_384_384.inc'
include '../console/write_u384_hex.inc'

if ~ definite bi_assert_equal_384

;Asserts two bi384 values to be equal
;input
; rcx - expected
; rdx - actual
bi_assert_equal_384:
        push    rax rsi
        call    bi_cmp_384_384
        test    rax, rax
        jnz     .fail
        clc
        jmp     .end
.fail:
        call     test_context_assert_fail
        lea     rsi, [.msg_1]
        call    Console_WriteString

        push    rcx
        mov     rcx, rdx
        call    Console_WriteUInt384Hex
        pop     rcx

        lea     rsi, [.msg_2]
        call    Console_WriteString

        call    Console_WriteUInt384Hex

        lea     rsi, [.msg_3]
        call    Console_WriteString
        stc
.end:
        pop     rsi rax
        ret

.msg_1 db TEXT_COLOR_ERROR, 'Expected bi384:', 13, 10, 'A: ', 0
.msg_2 db 13, 10, 'E: ', 0
.msg_3 db 13, 10, 0

end if