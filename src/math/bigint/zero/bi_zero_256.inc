if ~ definite bi_zero_256

;Zeroes bi256 value
;input
; rcx - pointer to result
bi_zero_256_basic:
    CheckRegBi256Alignment rcx, 'bi_zero_256 rcx'

        xor     rax, rax
        mov     [rcx], rax
        mov     [rcx + 8], rax
        mov     [rcx + 16], rax
        mov     [rcx + 24], rax
        ret

bi_zero_256_avx2:
        vpxor   ymm1, ymm1, ymm1
        vmovdqu [rcx], ymm1
        ret

if AVX2_ENABLED = 1
  bi_zero_256 = bi_zero_256_avx2
else
  bi_zero_256 = bi_zero_256_basic
end if

end if