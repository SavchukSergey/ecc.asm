if ~ definite bi_zero_128

;Zeroes bi128 value
;input
; rcx - pointer to result
bi_zero_128:
        xor     rax, rax
        mov     [rcx], rax
        mov     [rcx + 8], rax
        ret

end if