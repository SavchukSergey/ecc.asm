include '../../text/hex_format_digit.inc'

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
        call    hex_format_digit
        mov     [rdi], al
        inc     rdi

        mov     al, [rbx + rcx - 1]
        and     al, 0x0f
        call    hex_format_digit
        mov     [rdi], al
        inc     rdi

        loop    .loop
        pop     rdi rcx rbx rax
        ret

}
