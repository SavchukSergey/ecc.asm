if ~ definite bi_copy_768

bi_copy_768_basic:
        CheckRegBi768Alignment rcx, 'bi_copy_768_basic rcx'
        CheckRegBi768Alignment rdx, 'bi_copy_768_basic rcx'

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
        mov     rax, [rdx + 48]
        mov     [rcx + 48], rax
        mov     rax, [rdx + 56]
        mov     [rcx + 56], rax

        mov     rax, [rdx + 64]
        mov     [rcx + 64], rax
        mov     rax, [rdx + 72]
        mov     [rcx + 72], rax
        mov     rax, [rdx + 80]
        mov     [rcx + 80], rax
        mov     rax, [rdx + 88]
        mov     [rcx + 88], rax

        ret

bi_copy_768_avx2:
        CheckRegBi768Alignment rcx, 'bi_copy_768_avx2 rcx'
        CheckRegBi768Alignment rdx, 'bi_copy_768_avx2 rdx'

;todo: use aligned vmovdqa
        vmovdqu ymm1, [rdx]
        vmovdqu [rcx], ymm1
        vmovdqu ymm1, [rdx + 32]
        vmovdqu [rcx + 32], ymm1
        vmovdqu ymm1, [rdx + 64]
        vmovdqu [rcx + 64], ymm1
        ret

if AVX2_ENABLED = 1
  bi_copy_768 = bi_copy_768_avx2
else
  bi_copy_768 = bi_copy_768_basic
end if

end if
