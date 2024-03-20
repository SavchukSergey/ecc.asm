if ~ definite bi_mod_double_assign_256_256

include '../shl/bi_shl_assign_256_1.inc'
include '../sub/bi_sub_assign_256_256.inc'
include '../cmp/bi_cmp_256_256.inc'

;Doubles bi256 value
;input:
;  rcx - left value. The modified value
;  rdx - modulus
bi_mod_double_assign_256_256:
        call    bi_shl_assign_256_1
        jc      .fix
        
        call    bi_cmp_256_256
        jae     .fix

        ret
.fix:
        call    bi_sub_assign_256_256
        ret
end if