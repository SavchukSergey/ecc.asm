if ~ definite bi_zero_768

;Zeroes bi768 value
;input
; rcx - pointer to result
bi_zero_768_basic:
    CheckRegBi768Alignment rcx, 'bi_zero_768_basic rcx'

        xor     rax, rax
        mov     [rcx], rax
        mov     [rcx + 8], rax
        mov     [rcx + 16], rax
        mov     [rcx + 24], rax
        mov     [rcx + 32], rax
        mov     [rcx + 40], rax
        mov     [rcx + 48], rax
        mov     [rcx + 56], rax

        mov     [rcx + 64], rax
        mov     [rcx + 72], rax
        mov     [rcx + 80], rax
        mov     [rcx + 88], rax
        ret


bi_zero_768_avx2:
    CheckRegBi768Alignment rcx, 'bi_zero_768_avx2 rcx'

        vpxor   ymm1, ymm1, ymm1
        vmovdqu [rcx], ymm1
        vmovdqu [rcx + 32], ymm1
        vmovdqu [rcx + 64], xmm1
        ret

if AVX2_ENABLED = 1
  bi_zero_768 = bi_zero_768_avx2
else
  bi_zero_768 = bi_zero_768_basic
end if

end if