if ~ definite bi_mod_half_assign_256

;Halfs bi256 value
;input:
;  rcx - pointer to left bi256 value. The modified value
;  rdx - pointer to bi256 modulus
bi_mod_half_assign_256:
        bt      qword [rcx + 0], 0
        jc      .odd
.even:
        call    bi_shr_assign_256_1

        ret
.odd:
        call    bi_add_assign_256_256
;now it is even and we can safely shift it right
        jc      .carry 
        call    bi_shr_assign_256_1                  ;todo: bi_rcr_assign_256_1
        ret
.carry:
        call    bi_shr_assign_256_1
        bts     qword [rcx + 24], 63
        
        call    bi_cmp_256_256
        jae     .fix

        ret
.fix:
        call    bi_sub_assign_256_256
        ret
        ret

end if