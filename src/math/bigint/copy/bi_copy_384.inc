if ~ definite bi_copy_384

include '../config.inc'

bi_copy_384_basic:
        CheckRegAligned rcx, 'bi_copy_384_basic rcx'
        CheckRegAligned rdx, 'bi_copy_384_basic rcx'

        mov     rax, [rdx + 0]
        mov     [rcx + 0], rax
        mov     rax, [rdx + 8]
        mov     [rcx + 8], rax
        mov     rax, [rdx + 16]
        mov     [rcx + 16], rax
        mov     rax, [rdx + 24]
        mov     [rcx + 24], rax
        mov     rax, [rdx + 32]
        mov     [rcx + 32], rax
        mov     rax, [rdx + 40]
        mov     [rcx + 40], rax
        ret

bi_copy_384_avx2:
        CheckRegAligned rcx, 'bi_copy_384_avx2 rcx'
        CheckRegAligned rdx, 'bi_copy_384_avx2 rcx'

        vmovdqu ymm1, [rdx]
        vmovdqu [rcx], ymm1

        vmovdqu xmm1, [rdx + 32]
        vmovdqu [rcx + 32], xmm1

        ret

if AVX2_ENABLED = 1
  bi_copy_384 = bi_copy_384_avx2
else
  bi_copy_384 = bi_copy_384_basic
end if

end if
