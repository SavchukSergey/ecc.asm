if ~ definite Console_WriteUInt448Hex

include 'write_u256_hex.inc'
include 'write_u128_hex.inc'

;input
; rcx - pointer to bi448
Console_WriteUInt448Hex:
        push    rcx
        lea     rcx, [rcx + 24]
        call    Console_WriteUInt256Hex
        pop     rcx

        push    rcx
        lea     rcx, [rcx + 8]
        call    Console_WriteUInt128Hex
        pop     rcx

        push    rcx
        mov     rcx, [rcx + 0]
        call    Console_WriteUInt64Hex
        pop     rcx
        ret

end if
