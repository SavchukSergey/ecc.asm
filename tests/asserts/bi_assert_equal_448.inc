if ~ definite bi_assert_equal_448

;Asserts two bi448 values to be equal
;input
; rcx - expected
; rdx - actual
bi_assert_equal_448:
        push    rax rsi
        call    bi_cmp_448_448
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
        call    Console_WriteUInt448Hex
        pop     rcx

        lea     rsi, [.msg_2]
        call    Console_WriteString

        call    Console_WriteUInt448Hex

        lea     rsi, [.msg_3]
        call    Console_WriteString
        stc
.end:
        pop     rsi rax
        ret

.msg_1 db TEXT_COLOR_ERROR, 'Expected bi448:', 13, 10, 'A: ', 0
.msg_2 db 13, 10, 'E: ', 0
.msg_3 db 13, 10, 0

end if