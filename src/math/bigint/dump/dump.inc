macro BigIntegerDump bits {

if ~ definite __bi_dump_#bits

include '../src/console/write_line.inc'
include '../src/console/write_string.inc'
include '../src/math/bigint/write_hex.inc'

BigIntegerWriteHex bits

;Dumps bi to console
;input
; rax - pointer to biginteger
__bi_dump_#bits:
        push    rsi rdi
        sub     rsp, __BIG_INTEGER_HEX_DIGITS_#bits + 8
        lea     rdi, [rsp]
        call    __bi_write_hex_#bits
        mov     byte [rdi + __BIG_INTEGER_HEX_DIGITS_#bits], 0
        mov     rsi, rdi
        call    Console_WriteString
        call    Console_WriteLine
        add     rsp, __BIG_INTEGER_HEX_DIGITS_#bits + 8
        pop     rdi rsi
        ret

end if

}
