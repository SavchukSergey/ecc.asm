if ~ definite bi_mod_add_256_256

;Adds two bi256 values
;input:
;  rcx - pointer to left bi256 value
;  rdx - pointer to right bi256 value
;  r8 - pointer to bi256 modulus
;  r9  - pointer to result bi256 value
bi_mod_add_256_256:
        push    rdx

        PrologCheckStackAligned 'bi_mod_add_256_256'
        CheckRegBi256Alignment rcx, 'bi_mod_add_256_256 rcx'
        CheckRegBi256Alignment rdx, 'bi_mod_add_256_256 rdx'
        CheckRegBi256Alignment r8, 'bi_mod_add_256_256 r8'
        CheckRegBi256Alignment r9, 'bi_mod_add_256_256 r9'

        vmovdqu ymm1, [rcx]
        vmovdqu [r9], ymm1
        mov     rcx, r9

        call    bi_add_assign_256_256
        jc      .fix

        mov     rdx, r8
        call    bi_cmp_256_256
        jae     .fix

        pop     rdx
        ret
.fix:
        mov     rdx, r8
        call    bi_sub_assign_256_256

        pop     rdx
        ret
end if