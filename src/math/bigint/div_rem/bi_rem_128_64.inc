if ~ definite bi_rem_128_64

;Divides bi128 by u64
;input:
;   rcx - pointer to bi128 dividend
;   rdx - u64 divisor
;   r8 - pointer to bi128 remainder (actual result will be u64)
bi_rem_128_64:
    CheckRegAligned rcx, 'bi_rem_128_64 rcx'

        push    rbx

        mov     rbx, rdx

        mov     rdx, [rcx + 8]
        mov     rax, [rcx + 0]
        div     rbx
        ;rdx - remainder, rax - quotient

        mov     qword [r8 + 0], rdx
        mov     qword [r8 + 8], 0

        pop     rbx
        ret
end if