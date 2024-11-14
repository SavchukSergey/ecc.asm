;Copies bi256 value
;input:
;  rcx - pointer to destination bi256
;  rdx - pointer to source bi256

bi_copy_256_basic:
        CheckRegBi256Alignment rcx, 'bi_copy_256_basic rcx'
        CheckRegBi256Alignment rdx, 'bi_copy_256_basic rdx'

        mov     rax, [rdx + 0]
        mov     [rcx + 0], rax
        mov     rax, [rdx + 8]
        mov     [rcx + 8], rax
        mov     rax, [rdx + 16]
        mov     [rcx + 16], rax
        mov     rax, [rdx + 24]
        mov     [rcx + 24], rax
        ret

bi_copy_256_avx2:
        CheckRegBi256Alignment rcx, 'bi_copy_256_avx2 rcx'
        CheckRegBi256Alignment rdx, 'bi_copy_256_avx2 rdx'

        vmovdqu ymm1, [rdx]
        vmovdqu [rcx], ymm1
        ret

if AVX2_ENABLED = 1
  bi_copy_256 = bi_copy_256_avx2
else
  bi_copy_256 = bi_copy_256_basic
end if
