if ~ definite bi_rem_128_64

;Divides bi128 by u64
;input:
;   rcx - pointer to bi128 dividend
;   rdx - u64 divisor
;   r8 - pointer to bi128 remainder (actual result will be u64)
bi_rem_128_64:
    CheckRegAligned rcx, 'bi_rem_128_64 rcx'
        mov     r9, rdx

        mov     rdx, [rcx + 8]
        mov     rax, [rcx + 0]
        div     r9
        ;rdx - remainder, rax - quotient

        mov     qword [r8 + 0], rdx
        mov     qword [r8 + 8], 0

        ret
end if