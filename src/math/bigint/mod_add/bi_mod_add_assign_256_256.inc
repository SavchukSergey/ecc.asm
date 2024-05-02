if ~ definite bi_mod_add_assign_256_256

include '../add/bi_add_assign_256_256.inc'
include '../sub/bi_sub_assign_256_256.inc'
include '../cmp/bi_cmp_256_256.inc'

;Adds two bi256 values
;input:
;  rcx - pointer to left bi256 value. The modified value
;  rdx - pointer to right bi256 value
;  r8 - pointer to bi256 modulus
bi_mod_add_assign_256_256:
        push    rdx

        PrologCheckStackAligned 'bi_mod_add_assign_256_256'
        CheckRegBi256Alignment rcx, 'bi_mod_add_assign_256_256 rcx'
        CheckRegBi256Alignment rdx, 'bi_mod_add_assign_256_256 rdx'
        CheckRegBi256Alignment r8, 'bi_mod_add_assign_256_256 r8'

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