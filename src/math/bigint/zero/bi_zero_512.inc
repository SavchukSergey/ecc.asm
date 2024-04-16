if ~ definite bi_zero_512

include '../config.inc'

;Zeroes bi512 value
;input
; rcx - pointer to result
bi_zero_512_basic:
    CheckRegAligned rcx, 'bi_zero_512_basic rcx'

        xor     rax, rax
        mov     [rcx], rax
        mov     [rcx + 8], rax
        mov     [rcx + 16], rax
        mov     [rcx + 24], rax
        mov     [rcx + 32], rax
        mov     [rcx + 40], rax
        mov     [rcx + 48], rax
        mov     [rcx + 56], rax
        ret


bi_zero_512_avx2:
    CheckRegAligned rcx, 'bi_zero_512_avx2 rcx'

        vpxor   ymm1, ymm1, ymm1
        vmovdqu [rcx], ymm1
        vmovdqu [rcx + 32], ymm1
        ret

bi_zero_512_avx512:
        vpxorq  zmm1, zmm1, zmm1
        vmovups [rcx], zmm1
        ret

if AVX512_ENABLED = 1
  bi_zero_512 = bi_zero_512_avx512
else
  if AVX2_ENABLED = 1
    bi_zero_512 = bi_zero_512_avx2
  else
    bi_zero_512 = bi_zero_512_basic
  end if
end if

end if