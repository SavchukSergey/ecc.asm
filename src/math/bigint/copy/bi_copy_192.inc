if ~ definite bi_copy_192

include '../config.inc'

bi_copy_192_basic:
        CheckRegAligned rcx, 'bi_copy_192_basic rcx'
        CheckRegAligned rdx, 'bi_copy_192_basic rcx'

        mov     rax, [rdx + 0]
        mov     [rcx + 0], rax
        mov     rax, [rdx + 8]
        mov     [rcx + 8], rax
        mov     rax, [rdx + 16]
        mov     [rcx + 16], rax
        ret

bi_copy_192_avx2:
        CheckRegAligned rcx, 'bi_copy_192_avx2 rcx'
        CheckRegAligned rdx, 'bi_copy_192_avx2 rcx'

        vmovdqu xmm1, [rdx]
        vmovdqu [rcx], xmm1

        mov     rax, [rdx + 16]
        mov     [rcx + 16], rax
        ret

if AVX2_ENABLED = 1
  bi_copy_192 = bi_copy_192_avx2
else
  bi_copy_192 = bi_copy_192_basic
end if

end if
