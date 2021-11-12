macro BigIntegerWriteHex bits {

;Formats bi as hex string
;input
; rax - bi value
; rdi - destination (rb __BIG_INTEGER_BYTES_#bits)
__bi_write_hex_#bits:
        push    rax rbx rcx rdi
        mov     rbx, rax
        mov     rcx, __BIG_INTEGER_BYTES_#bits
.loop:
        mov     al, [rbx + rcx - 1]
        shr     al, 4
        call    __bi_get_hex_digit
        mov     [rdi], al
        inc     rdi

        mov     al, [rbx + rcx - 1]
        and     al, 0x0f
        call    __bi_get_hex_digit
        mov     [rdi], al
        inc     rdi

        loop    .loop
        pop     rdi rcx rbx rax
        ret

}

;input
;al - byte
;output
;al - hex character
__bi_get_hex_digit:
        cmp     al, 10
        jae     .letter
        add     al, '0'
        ret
.letter:
        add     al, 'A' - 10
        ret
