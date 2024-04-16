if ~ definite bi_zero_128

;Zeroes bi128 value
;input
;  rcx - pointer to bi128 value
bi_zero_128:
    CheckRegAligned rcx, 'bi_zero_128 rcx'

        xor     rax, rax
        mov     [rcx], rax
        mov     [rcx + 8], rax
        ret

end if