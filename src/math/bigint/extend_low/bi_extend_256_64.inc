if ~ definite bi_extend_256_64

bi_extend_256_64_basic:
    CheckRegAligned rcx, 'bi_extend_256_64_avx2 rcx'

        mov     [rcx + 0], rdx
        mov     qword [rcx + 8], 0
        mov     qword [rcx + 16], 0
        mov     qword [rcx + 24], 0

        ret

bi_extend_256_64_avx2:
    CheckRegAligned rcx, 'bi_extend_256_64_avx2 rcx'

        vmovq   xmm1, rdx
        vmovdqu [rcx], ymm1
        ret

if AVX2_ENABLED = 1
  bi_extend_256_64 = bi_extend_256_64_avx2
else
  bi_extend_256_64 = bi_extend_256_64_basic
end if


end if