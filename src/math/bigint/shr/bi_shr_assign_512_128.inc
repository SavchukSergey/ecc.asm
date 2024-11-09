if ~ definite bi_shr_assign_512_128

; Shifts right bi512 by 128 bits
;input
; rcx - value
bi_shr_assign_512_128_basic:
    CheckRegBi512Alignment rcx, 'bi_shr_assign_512_128_basic rcx'

        mov     rax, [rcx + 16]
        mov     [rcx + 0], rax

        mov     rax, [rcx + 24]
        mov     [rcx + 8], rax

        mov     rax, [rcx + 32]
        mov     [rcx + 16], rax

        mov     rax, [rcx + 40]
        mov     [rcx + 24], rax

        mov     rax, [rcx + 48]
        mov     [rcx + 32], rax

        mov     rax, [rcx + 56]
        mov     [rcx + 40], rax

        mov     qword [rcx + 48], 0
        mov     qword [rcx + 56], 0

        ret

; Shifts right bi512 by 128 bits
;input
; rcx - value
bi_shr_assign_512_128_avx:
    CheckRegAligned rcx, 'bi_shr_assign_512_128_avx rcx'

        vmovdqu xmm1, [rcx + 16]
        vmovdqu [rcx + 0], xmm1

        vmovdqu xmm1, [rcx + 32]
        vmovdqu [rcx + 16], xmm1

        vmovdqu xmm1, [rcx + 48]
        vmovdqu [rcx + 32], xmm1

        vpxor   ymm1, ymm1, ymm1
        vmovdqu [rcx + 48], xmm1

        ret


if AVX_ENABLED = 1
  bi_shr_assign_512_128 = bi_shr_assign_512_128_avx
else
  bi_shr_assign_512_128 = bi_shr_assign_512_128_basic
end if

end if

