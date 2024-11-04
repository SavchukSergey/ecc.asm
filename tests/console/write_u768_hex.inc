if ~ definite Console_WriteUInt768Hex

include 'write_u256_hex.inc'

;input
; rcx - pointer to bi256
Console_WriteUInt768Hex:
        push    rcx
        lea     rcx, [rcx + 64]
        call    Console_WriteUInt256Hex
        pop     rcx

        push    rcx
        lea     rcx, [rcx + 32]
        call    Console_WriteUInt256Hex
        pop     rcx

        push    rcx
        call    Console_WriteUInt256Hex
        pop     rcx
        ret

end if
