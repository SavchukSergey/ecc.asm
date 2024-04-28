if ~ definite bi_try_read_hex_64

;todo: swap params so first param is writeable using same approach everywhere

include '../../../text/hex_parse_reverse_bytes.inc'

;Reads bi as hex string
;input
; rcx - pointer to __BIG_INTEGER_HEX_DIGITS_64 string
; rdx - destination
;output
;  rax - 1 success
;  rax - 0 failure
bi_try_read_hex_64:
        push    rsi rdi rcx
        mov     rsi, rcx
        mov     rdi, rdx
        mov     rcx, __BIG_INTEGER_BYTES_64
        call    hex_parse_reverse_bytes
        setc    al
        xor     al, 0x01
        movzx   rax, al
        pop     rcx rdi rsi
        ret
end if
