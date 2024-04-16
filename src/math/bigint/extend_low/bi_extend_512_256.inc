if ~ definite bi_extend_512_256

bi_extend_512_256_avx2:
        CheckRegAligned rcx, 'bi_extend_512_256_avx2 rcx'
        CheckRegAligned rdx, 'bi_extend_512_256_avx2 rdx'
;todo: require 32-bit alignment and use vmovdqa     
        vmovdqu ymm1, [rdx]
        vmovdqu [rcx], ymm1

        vpxor   ymm1, ymm1, ymm1
        vmovdqu [rcx + 32], ymm1
        ret

bi_extend_512_256_basic:
        CheckRegAligned rcx, 'bi_extend_512_256_basic rcx'
        CheckRegAligned rdx, 'bi_extend_512_256_basic rdx'

        mov     rax, [rdx + 0]
        mov     [rcx + 0], rax
        mov     rax, [rdx + 8]
        mov     [rcx + 8], rax
        mov     rax, [rdx + 16]
        mov     [rcx + 16], rax
        mov     rax, [rdx + 24]
        mov     [rcx + 24], rax
        mov     qword [rcx + 32], 0
        mov     qword [rcx + 40], 0
        mov     qword [rcx + 48], 0
        mov     qword [rcx + 56], 0

        ret


if AVX2_ENABLED = 1
  bi_extend_512_256 = bi_extend_512_256_avx2
else
  bi_extend_512_256 = bi_extend_512_256_basic
end if

end if