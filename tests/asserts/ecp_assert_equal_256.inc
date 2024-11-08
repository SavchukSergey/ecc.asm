if ~ definite ecp_assert_equal_256

;Asserts two ecp256 values to be equal
;input
; rcx - expected
; rdx - actual
ecp_assert_equal_256:
        call    bi_cmp_256_256
        jnz     .fail
        add     rcx, ECPoint256.y
        add     rdx, ECPoint256.y
        call    bi_cmp_256_256
        jnz     .fail
        clc
        ret
        
.fail:
        call    test_context_assert_fail
        push    rsi
        lea     rsi, [.msg_1]
        call    Console_WriteString

        push    rcx
        mov     rcx, rdx
        call    Console_WriteECP256Hex
        pop     rcx

        lea     rsi, [.msg_2]
        call    Console_WriteString

        call    Console_WriteECP256Hex
        
        lea     rsi, [.msg_3]
        call    Console_WriteString

        pop      rsi

        stc
        ret

.msg_1 db TEXT_COLOR_ERROR, 'Expected ecp256:', 13, 10, 'A: ', 0
.msg_2 db 13, 10, 'E: ', 0
.msg_3 db 13, 10, 0

end if