if ~ definite bi_shl_assign_256_128

; Shifts left bi256 by 128 bits
;input
; rcx - value
bi_shl_assign_256_128_basic:
    CheckRegBi256Alignment rcx, 'bi_shl_assign_256_128_basic rcx'

        mov     rax, [rcx + 8]
        mov     [rcx + 24], rax

        mov     rax, [rcx + 0]
        mov     [rcx + 16], rax

        mov     qword [rcx + 8], 0
        mov     qword [rcx + 0], 0

        ret

; Shifts left bi256 by 128 bits
;input
; rcx - value
bi_shl_assign_256_128_avx:
;todo: avx2 with shuffle
    CheckRegBi256Alignment rcx, 'bi_shl_assign_256_128_avx rcx'

        vmovdqu xmm1, [rcx]
        vmovdqu [rcx + 16], xmm1

        vpxor   ymm2, ymm2, ymm2
        vmovdqu [rcx], xmm2

        ret


if AVX_ENABLED = 1
  bi_shl_assign_256_128 = bi_shl_assign_256_128_avx
else
  bi_shl_assign_256_128 = bi_shl_assign_256_128_basic
end if

end if

