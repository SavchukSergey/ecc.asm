;Zeroes bi128 value
;input:
;  rcx - pointer to bi128 value
bi_zero_128_basic:
    CheckRegBi128Alignment rcx, 'bi_zero_128 rcx'
        xor     rax, rax
        mov     [rcx], rax
        mov     [rcx + 8], rax
        ret

bi_zero_128_avx2:
    CheckRegBi128Alignment rcx, 'bi_zero_128 rcx'
        vpxor   xmm1, xmm1, xmm1
        vmovdqu [rcx], xmm1
        ret

bi_zero_128 = bi_zero_128_avx2