if ~ definite bi_copy_128

include '../config.inc'

bi_copy_128_basic:
        mov     rax, [rdx + 0]
        mov     [rcx + 0], rax
        mov     rax, [rdx + 8]
        mov     [rcx + 8], rax
        ret

bi_copy_128_avx2:
        CheckRegAligned rcx, 'bi_copy_128_avx2 rcx'
        CheckRegAligned rdx, 'bi_copy_128_avx2 rcx'

        vmovdqu xmm1, [rdx]
        vmovdqu [rcx], xmm1
        ret

if AVX2_ENABLED = 1
  bi_copy_128 = bi_copy_128_avx2
else
  bi_copy_128 = bi_copy_128_basic
end if


end if
