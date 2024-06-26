if ~ definite bi_rem_256_64

;Calculates remainder of bi256 divided by u64
;input:
;   rcx - pointer to bi256 divident
;   rdx - u64 divisor
;   r8 - pointer to bi256 remainder (actual result will be u64)
bi_rem_256_64:
    CheckRegAligned rcx, 'bi_rem_256_64 rcx'

        push    rbx

        mov     rbx, rdx

        xor     rdx, rdx

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
        mov     qword [r8 + 8], 0
        mov     qword [r8 + 16], 0
        mov     qword [r8 + 24], 0

        pop     rbx
        ret
end if