if ~ definite bi_mod_tripple_assign_256

include '../shl/bi_shl_assign_256_1.inc'
include '../sub/bi_sub_assign_256_256.inc'
include '../cmp/bi_cmp_256_256.inc'

;Tripples bi256 value
;input:
;  rcx - pointer to left bi256 value. The modified value
;  rdx - pointer to bi256 modulus
bi_mod_tripple_assign_256:
        xor     rax, rax    ;OF = 0, CF = 0

        mov     r8, [rcx]
        mov     rax, r8
        adcx    rax, rax
        adox    rax, r8
        mov     [rcx], rax

        mov     r8, [rcx + 8]
        mov     rax, r8
        adcx    rax, rax
        adox    rax, r8
        mov     [rcx + 8], rax

        mov     r8, [rcx + 16]
        mov     rax, r8
        adcx    rax, rax
        adox    rax, r8
        mov     [rcx + 16], rax

        mov     r8, [rcx + 24]
        mov     rax, r8
        adcx    rax, rax
        adox    rax, r8
        mov     [rcx + 24], rax

        jc      .sub_c
        jo      .fix_once

        call    bi_cmp_256_256
        jae     .fix_once

        ret
.fix_once:
        call    bi_sub_assign_256_256
        ret

.sub_c:
        jno     .fix_once
.fix_twice:
        call    bi_sub_assign_256_256
        call    bi_sub_assign_256_256
        ret

end if