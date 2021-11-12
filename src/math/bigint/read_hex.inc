include '../../text/hex_parse_reverse_bytes.inc'

macro BigIntegerReadHex bits {

;Reads bi as hex string
;input
; rsi - pointer to __BIG_INTEGER_HEX_DIGITS_#bits string
; rdi - destination
__bi_read_hex_#bits:
        push    rcx
        mov     rcx, __BIG_INTEGER_BYTES_#bits
        call    hex_parse_reverse_bytes
        jc      .error

        pop     rcx
        clc
        ret
.error:
        pop     rcx
        stc
        ret


}

