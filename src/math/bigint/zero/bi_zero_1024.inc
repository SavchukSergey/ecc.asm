if ~ definite bi_zero_1024

;Zeroes bi1024 value
;input
; rcx - pointer to result
bi_zero_1024_basic:
    CheckRegBi1024Alignment rcx, 'bi_zero_1024_basic rcx'

        call    bi_zero_512
        add     rcx, 64
        call    bi_zero_512
        sub     rcx, 64
        ret

bi_zero_1024_avx2:
    CheckRegBi1024Alignment rcx, 'bi_zero_1024_avx2 rcx'

        vpxor   ymm1, ymm1, ymm1
        vmovdqu [rcx], ymm1
        vmovdqu [rcx + 32], ymm1
        vmovdqu [rcx + 64], ymm1
        vmovdqu [rcx + 96], ymm1
        ret

bi_zero_1024_avx512:
    CheckRegBi1024Alignment rcx, 'bi_zero_1024_avx512 rcx'

        vpxorq  zmm1, zmm1, zmm1
        vmovups [rcx], zmm1
        vmovups [rcx + 64], zmm1
        ret

if AVX512_ENABLED = 1
  bi_zero_1024 = bi_zero_1024_avx512
else
  if AVX2_ENABLED = 1
    bi_zero_1024 = bi_zero_1024_avx2
  else
    bi_zero_1024 = bi_zero_1024_basic
  end if
end if


end if