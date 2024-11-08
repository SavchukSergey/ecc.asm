if ~ definite bi_shr_assign_512_256

; Shifts right bi512 by 256 bits
;input
; rcx - value
bi_shr_assign_512_256_basic:
    CheckRegAligned rcx, 'bi_shr_assign_512_256_basic rcx'

        mov     rax, [rcx + 32]
        mov     [rcx + 0], rax

        mov     rax, [rcx + 40]
        mov     [rcx + 8], rax

        mov     rax, [rcx + 48]
        mov     [rcx + 16], rax

        mov     rax, [rcx + 56]
        mov     [rcx + 24], rax

        mov     qword [rcx + 32], 0
        mov     qword [rcx + 40], 0
        mov     qword [rcx + 48], 0
        mov     qword [rcx + 56], 0


        ret

; Shifts right bi512 by 256 bits
;input
; rcx - value
bi_shr_assign_512_256_avx2:
    CheckRegAligned rcx, 'bi_shr_assign_512_256_avx2 rcx'

        vmovdqu ymm1, [rcx + 32]
        vmovdqu [rcx + 0], ymm1

        vpxor   ymm1, ymm1, ymm1
        vmovdqu [rcx + 32], ymm1
        ret

if AVX2_ENABLED = 1
  bi_shr_assign_512_256 = bi_shr_assign_512_256_avx2
else
  bi_shr_assign_512_256 = bi_shr_assign_512_256_basic
end if

end if
