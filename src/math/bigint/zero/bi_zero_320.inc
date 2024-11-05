if ~ definite bi_zero_320

include '../config.inc'

;Zeroes bi320 value
;input
; rcx - pointer to result
bi_zero_320_basic:
    CheckRegAligned rcx, 'bi_zero_320 rcx'

        xor     rax, rax
        mov     [rcx], rax
        mov     [rcx + 8], rax
        mov     [rcx + 16], rax
        mov     [rcx + 24], rax
        mov     [rcx + 32], rax
        ret

bi_zero_320_avx2:
        vpxor   ymm1, ymm1, ymm1
        vmovdqu [rcx], ymm1
        mov     qword [rcx + 32], 0
        ret

if AVX2_ENABLED = 1
  bi_zero_320 = bi_zero_320_avx2
else
  bi_zero_320 = bi_zero_320_basic
end if

end if