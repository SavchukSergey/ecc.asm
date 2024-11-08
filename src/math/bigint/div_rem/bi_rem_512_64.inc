if ~ definite bi_rem_512_64

;Calculates remainder of bi512 divided by u64
;input:
;   rcx - pointer to bi512 divident
;   rdx - u64 divisor
;   r8 - pointer to bi512 remainder (actual result will be u64)
bi_rem_512_64:
    CheckRegAligned rcx, 'bi_rem_512_64 rcx'

        push    rbx

        mov     rbx, rdx

        xor     rdx, rdx

        mov     rax, [rcx + 56]
        div     rbx
        ;rdx - remainder, rax - quotient

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

        vpxor   ymm1, ymm1, ymm1
        vmovdqu [r8], ymm1
        vmovdqu [r8 + 32], ymm1

        mov     qword [r8 + 0], rdx

        pop     rbx
        ret
end if