if ~ definite bi_mod_add_assign_256_256

include '../add/bi_add_assign_256_256.inc'
include '../sub/bi_sub_assign_256_256.inc'
include '../cmp/bi_cmp_256_256.inc'

;Adds two bi256 values
;input:
;  rcx - left value. The modified value
;  rdx - right value
;  r8 - modulus
bi_mod_add_assign_256_256:
        push    rdx
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