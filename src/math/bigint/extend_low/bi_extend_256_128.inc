if ~ definite bi_extend_256_128

bi_extend_256_128_basic:
    CheckRegBi256Alignment rcx, 'bi_extend_256_128_basic rcx'
    CheckRegBi128Alignment rdx, 'bi_extend_256_128_basic rdx'

        mov     rax, [rdx + 0]
        mov     [rcx + 0], rax
        mov     rax, [rdx + 8]
        mov     [rcx + 8], rax
        mov     qword [rcx + 16], 0
        mov     qword [rcx + 24], 0
        ret

bi_extend_256_128_avx2:
    CheckRegBi256Alignment rcx, 'bi_extend_256_128_avx2 rcx'
    CheckRegBi128Alignment rdx, 'bi_extend_256_128_avx2 rdx'

        vmovdqu xmm1, [rdx]
        vmovdqu [rcx], ymm1
        ret

if AVX2_ENABLED = 1
  bi_extend_256_128 = bi_extend_256_128_avx2
else
  bi_extend_256_128 = bi_extend_256_128_basic
end if

end if