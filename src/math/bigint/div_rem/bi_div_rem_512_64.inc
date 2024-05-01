if ~ definite bi_div_rem_512_64

;Divides bi512 by u64
;input:
;   rcx - pointer to bi512 dividend
;   rdx - u64 divisor
;   r8 - pointer to bi512 quotient
;   r9 - pointer to bi512 remainder (actual result will be u64)
bi_div_rem_512_64:
        push    rbx

        mov     rbx, rdx

        xor     rdx, rdx

        mov     rax, [rcx + 56]
        div     rbx
        ;rdx - remainder, rax - quotient
        mov     [r8 + 56], rax

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

        vpxor   ymm1, ymm1, ymm1
        vmovdqu [r9], ymm1
        vmovdqu [r9 + 32], ymm1

        mov     qword [r9 + 0], rdx

        pop     rbx
        ret
end if