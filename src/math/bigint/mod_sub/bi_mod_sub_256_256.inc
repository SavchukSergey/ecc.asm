if ~ definite bi_mod_sub_256_256

;Subtracts two bi256 values
;input:
;  rcx - pointer to left bi256 value
;  rdx - pointer to right bi256 value
;  r8 - pointer to bi256 modulus
;  r9  - pointer to result bi256 value
bi_mod_sub_256_256:
        CheckRegAligned rcx, 'bi_mod_sub_256_256 rcx'
        CheckRegAligned rdx, 'bi_mod_sub_256_256 rdx'
        CheckRegAligned r8, 'bi_mod_sub_256_256 r8'
        CheckRegAligned r9, 'bi_mod_sub_256_256 r9'

        vmovdqu ymm1, [rcx]
        vmovdqu [r9], ymm1
        mov     rcx, r9

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