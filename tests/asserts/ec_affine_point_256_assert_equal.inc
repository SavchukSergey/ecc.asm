if ~ definite ec_affine_point_256_assert_equal

;Asserts two ECAffinePoint256 values to be equal
;input
; rcx - pointer to expected ECAffinePoint256
; rdx - pointer to actual ECAffinePoint256
ec_affine_point_256_assert_equal:
virtual at rsp
  label .locals_start
    .expected rq 1
    .actual rq 1
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned 'ec_affine_point256_assert_assert_equal_hex'
        mov     [.expected], rcx
        mov     [.actual], rdx

        mov     rcx, [.expected]
        mov     rcx, [.actual]
        call    bi_cmp_256_256
        jnz     .fail

        mov     rcx, [.expected]
        add     rcx, ECAffinePoint256.y
        mov     rdx, [.actual]
        add     rdx, ECAffinePoint256.y
        call    bi_cmp_256_256
        jnz     .fail

        add     rsp, .locals_end - .locals_start

        clc
        ret
        
.fail:
        call    test_context_assert_fail

        push    rsi
        lea     rsi, [.msg_1]
        call    Console_WriteString
        pop     rsi

        mov     rcx, [.actual]
        call    Console_WriteECAffinePoint256Hex

        push    rsi
        lea     rsi, [.msg_2]
        call    Console_WriteString
        pop     rsi

        mov     rcx, [.expected]
        call    Console_WriteECAffinePoint256Hex
        
        push    rsi
        lea     rsi, [.msg_3]
        call    Console_WriteString
        pop     rsi

        add     rsp, .locals_end - .locals_start

        stc
        ret

.msg_1 db TEXT_COLOR_ERROR, 'Expected ECAffinePoint256:', 13, 10, 'A: ', 0
.msg_2 db 13, 10, 'E: ', 0
.msg_3 db 13, 10, 0

end if