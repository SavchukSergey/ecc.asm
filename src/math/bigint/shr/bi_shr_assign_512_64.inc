if ~ definite bi_shr_assign_512_64

; Shifts right bi512 by 64 bits
;input
; rcx - value
bi_shr_assign_512_64:
    CheckRegBi512Alignment rcx, 'bi_shr_assign_512_64 rcx'

;todo: AVX2
        mov     rax, [rcx + 8]
        mov     [rcx + 0], rax

        mov     rax, [rcx + 16]
        mov     [rcx + 8], rax

        mov     rax, [rcx + 24]
        mov     [rcx + 16], rax

        mov     rax, [rcx + 32]
        mov     [rcx + 24], rax

        mov     rax, [rcx + 40]
        mov     [rcx + 32], rax

        mov     rax, [rcx + 48]
        mov     [rcx + 40], rax

        mov     rax, [rcx + 56]
        mov     [rcx + 48], rax

        mov     qword [rcx + 56], 0

        ret

end if