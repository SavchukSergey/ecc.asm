if ~ definite bi_rem_448_64

;Calculates remainder of bi448 divided by u64
;input:
;   rcx - pointer to bi448 divident
;   rdx - u64 divisor
;   r8 - pointer to bi64 remainder
bi_rem_448_64:
    CheckRegBi448Alignment rcx, 'bi_rem_448_64 rcx'

        push    rbx

        mov     rbx, rdx

        xor     rdx, rdx

        mov     rax, [rcx + 48]
        div     rbx
        ;rdx - remainder, rax - quotient

        mov     rax, [rcx + 40]
        div     rbx
        ;rdx - remainder, rax - quotient

        mov     rax, [rcx + 32]
        div     rbx
        ;rdx - remainder, rax - quotient

        mov     rax, [rcx + 24]
        div     rbx
        ;rdx - remainder, rax - quotient

        mov     rax, [rcx + 16]
        div     rbx
        ;rdx - remainder, rax - quotient

        mov     rax, [rcx + 8]
        div     rbx
        ;rdx - remainder, rax - quotient

        mov     rax, [rcx + 0]
        div     rbx
        ;rdx - remainder, rax - quotient

        mov     qword [r8 + 0], rdx

        pop     rbx
        ret
end if