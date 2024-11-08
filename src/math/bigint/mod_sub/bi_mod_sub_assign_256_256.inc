if ~ definite bi_mod_sub_assign_256_256

;Subtracts two bi256 values
;input:
;  rcx - left value. The modified value.
;  rdx - right value
;  r8 - modulus
bi_mod_sub_assign_256_256:
        CheckRegAligned rcx, 'bi_mod_sub_assign_256_256 rcx'
        CheckRegAligned rdx, 'bi_mod_sub_assign_256_256 rdx'
        CheckRegAligned r8, 'bi_mod_sub_assign_256_256 r8'

        call    bi_sub_assign_256_256
        jc      .fix
        ret
.fix:
        push    rdx
        mov     rdx, r8
        call    bi_add_assign_256_256
        pop     rdx
        ret
end if