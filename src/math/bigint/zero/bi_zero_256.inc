if ~ definite bi_zero_256

;Zeroes bi256 value
;input
; rcx - pointer to result
bi_zero_256:
        xor     rax, rax
        mov     [rcx], rax
        mov     [rcx + 8], rax
        mov     [rcx + 16], rax
        mov     [rcx + 24], rax
        ret

end if