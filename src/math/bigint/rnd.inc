macro BigIntegerRnd bits {

;Randomize bi value
;input
; rax - value to be randomized
__bi_rnd_#bits:
        push    rax rbx
        mov     rbx, rax
        repeat  __BIG_INTEGER_QWORDS_#bits
        call    rnd_u64
        mov     [rbx + (% - 1) * 8], rax
        end repeat
        pop     rbx rax
        ret

}