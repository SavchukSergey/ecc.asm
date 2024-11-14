;Checks if bi256 value is zero
;input:
;  rcx - pointer to bi256 value
;output:
;  rax - 1 if value is zero, 0 otherwise
;  ZF = 1 if value is zero, 0 otherwise
bi_is_zero_256_basic:
    CheckRegBi256Alignment rcx, 'bi_is_zero_256_basic rcx'

        xor     rax, rax
        or      rax, [rcx]
        or      rax, [rcx + 8]
        or      rax, [rcx + 16]
        or      rax, [rcx + 24]
        setz    al
        movzx   rax, al
        ret

;Checks if bi256 value is zero
;input
;  rcx - pointer to result
;output
;  rax - 1 if value is zero, 0 otherwise
;  ZF = 1 if value is zero, 0 otherwise
bi_is_zero_256_avx2:
    CheckRegBi256Alignment rcx, 'bi_is_zero_256_avx2 rcx'

        vmovdqu ymm1, [rcx]
        vptest  ymm1, ymm1
        setz    al
        movzx   rax, al
        ret

if AVX2_ENABLED = 1
  bi_is_zero_256 = bi_is_zero_256_avx2
else
  bi_is_zero_256 = bi_is_zero_256_basic
end if