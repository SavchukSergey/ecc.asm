if ~ definite bi_rnd_128

;Randomize bi128 value
;input
;  rcx - value to be randomized
bi_rnd_128:
        push    rdi
        mov     rdi, rcx
        mov     rcx, __BIG_INTEGER_QWORDS_128
.loop:
        call    bi_rnd_64
        mov     [rdi + rcx * 8 - 8], rax
        loop    .loop
        pop     rdi
        ret

end if