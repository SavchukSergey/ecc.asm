if ~ definite bi_shl_assign_256_64

; Shifts left bi256 by 64 bits
;input
; rcx - value
bi_shl_assign_256_64_basic:
    CheckRegAligned rcx, 'bi_shl_assign_256_64 rcx'

        mov     rax, [rcx + 16]
        mov     [rcx + 24], rax

        mov     rax, [rcx + 8]
        mov     [rcx + 16], rax

        mov     rax, [rcx + 0]
        mov     [rcx + 8], rax
        
        mov     qword [rcx + 0], 0

        ret

; Shifts left bi256 by 64 bits
;input
; rcx - value
bi_shl_assign_256_64_avx2:
    CheckRegAligned rcx, 'bi_shl_assign_256_64_avx2 rcx'

        vpermq    ymm1, [rcx], 10010000b
        vmovdqu   [rcx], ymm1

        mov     qword [rcx + 0], 0

        ret

;avx2 is slower here
; if AVX2_ENABLED = 1
;   bi_shl_assign_256_64 = bi_shl_assign_256_64_avx2
; else
;   bi_shl_assign_256_64 = bi_shl_assign_256_64_basic
; end if

  bi_shl_assign_256_64 = bi_shl_assign_256_64_basic

end if