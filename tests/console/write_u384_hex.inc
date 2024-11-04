if ~ definite Console_WriteUInt384Hex

include 'write_u256_hex.inc'
include 'write_u128_hex.inc'

;input
; rcx - pointer to bi384
Console_WriteUInt384Hex:
        push    rcx
        lea     rcx, [rcx + 16]
        call    Console_WriteUInt256Hex
        pop     rcx

        push    rcx
        mov     rcx, [rcx + 0]
        call    Console_WriteUInt128Hex
        pop     rcx
        ret

end if
