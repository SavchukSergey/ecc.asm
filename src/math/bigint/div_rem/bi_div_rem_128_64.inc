if ~ definite bi_div_rem_128_64

;Divides bi128 by u64
;input:
;   rcx - pointer to bi128 dividend
;   rdx - u64 divisor
;   r8 - pointer to bi128 quotient
;   r9 - pointer to bi128 remainder (actual result will be u64)
bi_div_rem_128_64:
        push    rbx

        mov     rbx, rdx

        xor     rdx, rdx

        mov     rax, [rcx + 8]
        div     rbx
        ;rdx - remainder, rax - quotient
        mov     [r8 + 8], rax

        mov     rax, [rcx + 0]
        div     rbx
        ;rdx - remainder, rax - quotient
        mov     [r8 + 0], rax

        mov     qword [r9 + 0], rdx
        mov     qword [r9 + 8], 0

        pop     rbx
        ret
end if