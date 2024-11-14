;Zeroes bi384 value
;input:
; rcx - pointer to bi384 result
bi_zero_384_basic:
    CheckRegBi384Alignment rcx, 'bi_zero_384 rcx'

        xor     rax, rax
        mov     [rcx], rax
        mov     [rcx + 8], rax
        mov     [rcx + 16], rax
        mov     [rcx + 24], rax
        mov     [rcx + 32], rax
        mov     [rcx + 40], rax
        ret

bi_zero_384_avx2:
        vpxor   ymm1, ymm1, ymm1
        vmovdqu [rcx], ymm1
        vmovdqu [rcx + 32], xmm1
        ret

if AVX2_ENABLED = 1
  bi_zero_384 = bi_zero_384_avx2
else
  bi_zero_384 = bi_zero_384_basic
end if
