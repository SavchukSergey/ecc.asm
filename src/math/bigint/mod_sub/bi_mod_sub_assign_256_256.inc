;Subtracts two bi256 values
;input:
;  rcx - pointer to left bi256 value. The modified value.
;  rdx - pointer to right bi256 value
;  r8 - pointer to bi256 modulus
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