if ~ definite bi_zero_576

;Zeroes bi576 value
;input
; rcx - pointer to result
bi_zero_576_basic:
    CheckRegBi576Alignment rcx, 'bi_zero_576_basic rcx'

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
        ret


bi_zero_576_avx2:
    CheckRegBi576Alignment rcx, 'bi_zero_576_avx2 rcx'

        vpxor   ymm1, ymm1, ymm1
        vmovdqu [rcx], ymm1
        vmovdqu [rcx + 32], ymm1

        xor     rax, rax
        mov     [rcx + 64], rax

        ret

  if AVX2_ENABLED = 1
    bi_zero_576 = bi_zero_576_avx2
  else
    bi_zero_576 = bi_zero_576_basic
  end if

end if