if ~ definite ec_projective_mont_point_256_assert_equal

;Asserts two ECProjectiveMontgomeryPoint256 values to be equal
;input
; rcx - pointer to expected ECProjectiveMontgomeryPoint256
; rdx - pointer to actual ECProjectiveMontgomeryPoint256
ec_projective_mont_point_256_assert_equal:
virtual at rsp
  label .locals_start
    .expected rq 1
    .actual rq 1
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned 'ec_projective_mont_point256_assert_assert_equal_hex'
        mov     [.expected], rcx
        mov     [.actual], rdx

        mov     rcx, [.expected]
        mov     rcx, [.actual]
        call    bi_cmp_256_256
        jnz     .fail

        mov     rcx, [.expected]
        add     rcx, ECProjectiveMontgomeryPoint256.y
        mov     rdx, [.actual]
        add     rdx, ECProjectiveMontgomeryPoint256.y
        call    bi_cmp_256_256
        jnz     .fail

        mov     rcx, [.expected]
        add     rcx, ECProjectiveMontgomeryPoint256.z
        mov     rdx, [.actual]
        add     rdx, ECProjectiveMontgomeryPoint256.z
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
        call    Console_WriteECProjectiveMontgomeryPoint256Hex

        push    rsi
        lea     rsi, [.msg_2]
        call    Console_WriteString
        pop     rsi

        mov     rcx, [.expected]
        call    Console_WriteECProjectiveMontgomeryPoint256Hex
        
        push    rsi
        lea     rsi, [.msg_3]
        call    Console_WriteString
        pop     rsi

        add     rsp, .locals_end - .locals_start

        stc
        ret

.msg_1 db TEXT_COLOR_ERROR, 'Expected ECProjectiveMontgomeryPoint256:', 13, 10, 'A: ', 0
.msg_2 db 13, 10, 'E: ', 0
.msg_3 db 13, 10, 0

end if