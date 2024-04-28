if ~ definite bi_try_read_hex_512

include '../../../text/hex_parse_reverse_bytes.inc'

;Reads bi as hex string
;input
; rcx - pointer to __BIG_INTEGER_HEX_DIGITS_512 string
; rdx - destination
;output
;  rax - 1 success
;  rax - 0 failure
bi_try_read_hex_512:
;todo: set CF if error
        push    rsi rdi rcx
        mov     rsi, rcx
        mov     rdi, rdx
        mov     rcx, __BIG_INTEGER_BYTES_512
        call    hex_parse_reverse_bytes
        setc    al
        xor     al, 0x01
        movzx   rax, al
        pop     rcx rdi rsi
        ret
end if