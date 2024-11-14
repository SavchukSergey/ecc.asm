;Calculates remainder of bi128 dividend by bi64
;input:
;   rcx - pointer to bi128 dividend
;   rdx - bi64 divisor
;   r8 - pointer to bi64 remainder
bi_rem_128_64:
        push    rbx

        mov     rbx, rdx

        xor     rdx, rdx

        mov     rax, [rcx + 8]
        div     rbx
        ;rdx - remainder, rax - quotient

        mov     rax, [rcx + 0]
        div     rbx
        ;rdx - remainder, rax - quotient

        mov     qword [r8 + 0], rdx

        pop     rbx
        ret