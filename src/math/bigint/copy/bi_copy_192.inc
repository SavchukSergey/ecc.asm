;Copies bi192 value
;input:
;  rcx - pointer to destination bi192
;  rdx - pointer to source bi192

bi_copy_192_basic:
        CheckRegBi192Alignment rcx, 'bi_copy_192_basic rcx'
        CheckRegBi192Alignment rdx, 'bi_copy_192_basic rdx'

        mov     rax, [rdx + 0]
        mov     [rcx + 0], rax
        mov     rax, [rdx + 8]
        mov     [rcx + 8], rax
        mov     rax, [rdx + 16]
        mov     [rcx + 16], rax
        ret

bi_copy_192_avx2:
        CheckRegBi192Alignment rcx, 'bi_copy_192_avx2 rcx'
        CheckRegBi192Alignment rdx, 'bi_copy_192_avx2 rdx'

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

