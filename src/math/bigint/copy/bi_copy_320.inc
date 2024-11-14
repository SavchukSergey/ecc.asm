;Copies bi320 value
;input:
;  rcx - pointer to destination bi320
;  rdx - pointer to source bi320

bi_copy_320_basic:
        CheckRegBi320Alignment rcx, 'bi_copy_320_basic rcx'
        CheckRegBi320Alignment rdx, 'bi_copy_320_basic rdx'

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
        ret

bi_copy_320_avx2:
        CheckRegBi320Alignment rcx, 'bi_copy_320_avx2 rcx'
        CheckRegBi320Alignment rdx, 'bi_copy_320_avx2 rdx'

        vmovdqu ymm1, [rdx]
        vmovdqu [rcx], ymm1

        mov     rax, [rdx + 32]
        mov     [rcx + 32], rax

        ret

if AVX2_ENABLED = 1
  bi_copy_320 = bi_copy_320_avx2
else
  bi_copy_320 = bi_copy_320_basic
end if

