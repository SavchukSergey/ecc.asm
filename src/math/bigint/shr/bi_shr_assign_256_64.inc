if ~ definite bi_shr_assign_256_64

; Shifts left bi256 by 64 bits
;input
; rcx - value
bi_shr_assign_256_64:
;todo: AVX2
    CheckRegAligned rcx, 'bi_shr_assign_256_64 rcx'

        mov     rax, [rcx + 8]
        mov     [rcx + 0], rax

        mov     rax, [rcx + 16]
        mov     [rcx + 8], rax

        mov     rax, [rcx + 24]
        mov     [rcx + 16], rax

        mov     qword [rcx + 24], 0

        ret

end if