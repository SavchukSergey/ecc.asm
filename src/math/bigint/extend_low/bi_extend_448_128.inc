if ~ definite bi_extend_448_128

bi_extend_448_128_basic:
        mov     rax, [rdx + 0]
        mov     [rcx + 0], rax
        mov     rax, [rdx + 8]
        mov     [rcx + 8], rax
        mov     qword [rcx + 16], 0
        mov     qword [rcx + 24], 0
        mov     qword [rcx + 32], 0
        mov     qword [rcx + 40], 0
        mov     qword [rcx + 48], 0
        ret

bi_extend_448_128_avx2:
        vmovdqu xmm1, [rdx]
        vmovdqu [rcx], xmm1

        vpxor   ymm2, ymm2, ymm2
        vmovdqu [rcx + 16], ymm2

        mov     qword [rcx + 48], 0

        ret

if AVX2_ENABLED = 1
  bi_extend_448_128 = bi_extend_448_128_avx2
else
  bi_extend_448_128 = bi_extend_448_128_basic
end if

end if
