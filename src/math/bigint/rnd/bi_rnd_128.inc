if ~ definite bi_rnd_128

include '../../rnd.inc'

;Randomize bi128 value
;input
;  rcx - value to be randomized
bi_rnd_128:
        push    rdi
        mov     rdi, rcx
        mov     rcx, __BIG_INTEGER_QWORDS_128
.loop:
        call    rnd_u64
        mov     [rdi + rcx * 8 - 8], rax
        loop    .loop
        pop     rdi
        ret

end if