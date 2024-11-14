;Zeroes bi192 value
;input:
; rcx - pointer to bi192 result
bi_zero_192_basic:
    CheckRegBi192Alignment rcx, 'bi_zero_192 rcx'

        xor     rax, rax
        mov     [rcx], rax
        mov     [rcx + 8], rax
        mov     [rcx + 16], rax
        ret

bi_zero_192_avx2:
        xor     rax, rax

        vpxor   xmm1, xmm1, xmm1
        vmovdqu [rcx], xmm1

        mov     [rcx + 16], rax
        ret

if AVX2_ENABLED = 1
  bi_zero_192 = bi_zero_192_avx2
else
  bi_zero_192 = bi_zero_192_basic
end if
