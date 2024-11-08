if ~ definite bi_rnd_384

;Randomize bi384 value
;input
;  rcx - value to be randomized
bi_rnd_384:
        push    rdi
        mov     rdi, rcx
        mov     rcx, __BIG_INTEGER_QWORDS_384
.loop:
        call    bi_rnd_64
        mov     [rdi + rcx * 8 - 8], rax
        loop    .loop
        pop     rdi
        ret

end if