if ~ definite bi_mod_double_assign_256

include '../shl/bi_shl_assign_256_1.inc'
include '../sub/bi_sub_assign_256_256.inc'
include '../cmp/bi_cmp_256_256.inc'

;Doubles bi256 value
;input:
;  rcx - pointer to left bi256 value. The modified value
;  rdx - pointer to bi256 modulus
bi_mod_double_assign_256:
        sub     rsp, 8
    PrologCheckStackAligned 'bi_mod_double_assign_256'
    CheckRegAligned rcx, 'bi_mod_double_assign_256 rcx'
    CheckRegAligned rdx, 'bi_mod_double_assign_256 rdx'

        call    bi_shl_assign_256_1
        jc      .fix
        
        call    bi_cmp_256_256
        jae     .fix

        add     rsp, 8
        ret
.fix:
        call    bi_sub_assign_256_256
        add     rsp, 8
        ret
end if