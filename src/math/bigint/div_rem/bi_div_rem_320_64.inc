if ~ definite bi_div_rem_320_64

;Divides bi320 by u64
;input:
;   rcx - pointer to bi320 divident
;   rdx - u64 divisor
;   r8 - pointer to bi320 quotient
;   r9 - pointer to bi320 remainder (actual result will be u64)
bi_div_rem_320_64:
        push    rbx

        mov     rbx, rdx

        xor     rdx, rdx

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
        ;todo: avx clear
        mov     qword [r9 + 8], 0
        mov     qword [r9 + 16], 0
        mov     qword [r9 + 24], 0
        mov     qword [r9 + 32], 0

        pop     rbx
        ret
end if