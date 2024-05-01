if ~ definite bi_shr_assign_256_128

; Shifts left bi256 by 128 bits
;input
; rcx - value
bi_shr_assign_256_128_basic:
    CheckRegBi256Alignment rcx, 'bi_shr_assign_256_128_basic rcx'

        mov     rax, [rcx + 16]
        mov     [rcx + 0], rax

        mov     rax, [rcx + 24]
        mov     [rcx + 8], rax

        mov     qword [rcx + 16], 0
        mov     qword [rcx + 24], 0


        ret

; Shifts left bi256 by 128 bits
;input
; rcx - value
bi_shr_assign_256_128_avx:
;todo: avx2 with shuffle
    CheckRegBi256Alignment rcx, 'bi_shr_assign_256_128_avx rcx'

        vmovdqu xmm1, [rcx + 16]
        vmovdqu [rcx + 0], xmm1

        vpxor   ymm1, ymm1, ymm1
        vmovdqu [rcx + 16], xmm1

        ret


;vzeroupper 
if AVX_ENABLED = 1
  bi_shr_assign_256_128 = bi_shr_assign_256_128_avx
else
  bi_shr_assign_256_128 = bi_shr_assign_256_128_basic
end if

end if

