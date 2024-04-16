if ~ definite bi_shl_assign_512_64

; Shifts left bi512 by 64 bits
;input
; rcx - value
bi_shl_assign_512_64:
;todo: AVX2
        mov     rax, [rcx + 48]
        mov     [rcx + 56], rax

        mov     rax, [rcx + 40]
        mov     [rcx + 48], rax

        mov     rax, [rcx + 32]
        mov     [rcx + 40], rax

        mov     rax, [rcx + 24]
        mov     [rcx + 32], rax

        mov     rax, [rcx + 16]
        mov     [rcx + 24], rax

        mov     rax, [rcx + 8]
        mov     [rcx + 16], rax

        mov     rax, [rcx + 0]
        mov     [rcx + 8], rax
        
        mov     qword [rcx + 0], 0

        ret

end if