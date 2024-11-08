if ~ definite bi_assert_equal_256

;Asserts two bi256 values to be equal
;input
; rcx - expected
; rdx - actual
bi_assert_equal_256:
        push    rax rsi
        call    bi_cmp_256_256
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
        call    Console_WriteUInt256Hex
        pop     rcx

        lea     rsi, [.msg_2]
        call    Console_WriteString

        call    Console_WriteUInt256Hex

        lea     rsi, [.msg_3]
        call    Console_WriteString
        stc
.end:
        pop     rsi rax
        ret

.msg_1 db TEXT_COLOR_ERROR, 'Expected bi256:', 13, 10, 'A: ', 0
.msg_2 db 13, 10, 'E: ', 0
.msg_3 db 13, 10, 0

end if