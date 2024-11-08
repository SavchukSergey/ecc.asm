if ~ definite bi_shl_assign_512_256

; Shifts left bi512 by 256 bits
;input
; rcx - value
bi_shl_assign_512_256_basic:
    CheckRegAligned rcx, 'bi_shl_assign_512_256_basic rcx'

        mov     rax, [rcx + 24]
        mov     [rcx + 56], rax

        mov     rax, [rcx + 16]
        mov     [rcx + 48], rax

        mov     rax, [rcx + 8]
        mov     [rcx + 40], rax

        mov     rax, [rcx + 0]
        mov     [rcx + 32], rax

        mov     qword [rcx + 24], 0
        mov     qword [rcx + 16], 0
        mov     qword [rcx + 8], 0
        mov     qword [rcx + 0], 0

        ret

; Shifts left bi512 by 256 bits
;input
; rcx - value
bi_shl_assign_512_256_avx2:
    CheckRegAligned rcx, 'bi_shl_assign_512_256_avx2 rcx'

        vmovdqu ymm1, [rcx]
        vmovdqu [rcx + 32], ymm1

        vpxor   ymm1, ymm1, ymm1
        vmovdqu [rcx], ymm1
        ret

if AVX2_ENABLED = 1
  bi_shl_assign_512_256 = bi_shl_assign_512_256_avx2
else
  bi_shl_assign_512_256 = bi_shl_assign_512_256_basic
end if

end if
