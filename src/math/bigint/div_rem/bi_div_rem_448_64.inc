if ~ definite bi_div_rem_448_64

;Divides bi448 by bi64
;input:
;   rcx - pointer to bi448 dividend
;   rdx - u64 divisor
;   r8 - pointer to bi448 quotient
;   r9 - pointer to bi64 remainder
bi_div_rem_448_64:
        push    rbx

        mov     rbx, rdx

        xor     rdx, rdx

        mov     rax, [rcx + 48]
        div     rbx
        ;rdx - remainder, rax - quotient
        mov     [r8 + 48], rax

        mov     rax, [rcx + 40]
        div     rbx
        ;rdx - remainder, rax - quotient
        mov     [r8 + 40], rax

        mov     rax, [rcx + 32]
        div     rbx
        ;rdx - remainder, rax - quotient
        mov     [r8 + 32], rax

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