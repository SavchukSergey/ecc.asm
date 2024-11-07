if ~ definite bi_div_rem_256_64

;Divides bi256 by bi64
;input:
;   rcx - pointer to bi256 divident
;   rdx - bi64 divisor
;   r8 - pointer to bi256 quotient
;   r9 - pointer to bi64 remainder
bi_div_rem_256_64:
        push    rbx

        mov     rbx, rdx

        xor     rdx, rdx

        mov     rax, [rcx + 24]
        div     rbx
        ;rdx - remainder, rax - quotient
        mov     [r8 + 24], rax

        mov     rax, [rcx + 16]
        div     rbx
        ;rdx - remainder, rax - quotient
        mov     [r8 + 16], rax

        mov     rax, [rcx + 8]
        div     rbx
        ;rdx - remainder, rax - quotient
        mov     [r8 + 8], rax

        mov     rax, [rcx + 0]
        div     rbx
        ;rdx - remainder, rax - quotient
        mov     [r8 + 0], rax

        mov     qword [r9 + 0], rdx

        pop     rbx
        ret
end if