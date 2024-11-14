;Zeroes bi448 value
;input:
; rcx - pointer to bi448 result
bi_zero_448_basic:
    CheckRegBi448Alignment rcx, 'bi_zero_448 rcx'

        xor     rax, rax
        mov     [rcx], rax
        mov     [rcx + 8], rax
        mov     [rcx + 16], rax
        mov     [rcx + 24], rax
        mov     [rcx + 32], rax
        mov     [rcx + 40], rax
        mov     [rcx + 48], rax
        ret

bi_zero_448_avx2:
        vpxor   ymm1, ymm1, ymm1
        vmovdqu [rcx], ymm1
        vmovdqu [rcx + 32], xmm1
        mov     qword [rcx + 48], 0
        ret

if AVX2_ENABLED = 1
  bi_zero_448 = bi_zero_448_avx2
else
  bi_zero_448 = bi_zero_448_basic
end if