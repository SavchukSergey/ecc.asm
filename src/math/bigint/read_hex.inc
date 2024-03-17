;todo: swap params so first param is writeable using same approach everywhere

include '../../text/hex_parse_reverse_bytes.inc'

if ~ definite __bi_read_hex_128

;Reads bi as hex string
;input
; rcx - pointer to __BIG_INTEGER_HEX_DIGITS_128 string
; rdx - destination
;output
;  rax - 1 success
;  rax - 0 failure
bi_try_read_hex_128:
        push    rsi rdi rcx
        mov     rsi, rcx
        mov     rdi, rdx
        mov     rcx, __BIG_INTEGER_BYTES_128
        call    hex_parse_reverse_bytes
        setc    al
        xor     al, 0x01
        movzx   rax, al
        pop     rcx rdi rsi
        ret
end if

if ~ definite __bi_read_hex_256

;Reads bi as hex string
;input
; rcx - pointer to __BIG_INTEGER_HEX_DIGITS_128 string
; rdx - destination
;output
;  rax - 1 success
;  rax - 0 failure
bi_try_read_hex_256:
        push    rsi rdi rcx
        mov     rsi, rcx
        mov     rdi, rdx
        mov     rcx, __BIG_INTEGER_BYTES_256
        call    hex_parse_reverse_bytes
        setc    al
        xor     al, 0x01
        movzx   rax, al
        pop     rcx rdi rsi
        ret
end if

if ~ definite __bi_read_hex_512

;Reads bi as hex string
;input
; rcx - pointer to __BIG_INTEGER_HEX_DIGITS_128 string
; rdx - destination
;output
;  rax - 1 success
;  rax - 0 failure
bi_try_read_hex_512:
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

if ~ definite __bi_read_hex_1024
;Reads bi as hex string
;input
; rcx - pointer to __BIG_INTEGER_HEX_DIGITS_1024 string
; rdx - destination
;output
;  rax - 1 success
;  rax - 0 failure
bi_try_read_hex_1024:
        push    rsi rdi rcx
        mov     rsi, rcx
        mov     rdi, rdx
        mov     rcx, __BIG_INTEGER_BYTES_1024
        call    hex_parse_reverse_bytes
        setc    al
        xor     al, 0x01
        movzx   rax, al
        pop     rcx rdi rsi
        ret
end if
