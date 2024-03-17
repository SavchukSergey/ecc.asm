if ~ definite bi_zero_512

;Zeroes bi512 value
;input
; rcx - pointer to result
bi_zero_512:
        xor     rax, rax
        mov     [rcx], rax
        mov     [rcx + 8], rax
        mov     [rcx + 16], rax
        mov     [rcx + 24], rax
        mov     [rcx + 32], rax
        mov     [rcx + 40], rax
        mov     [rcx + 48], rax
        mov     [rcx + 56], rax
        ret

end if