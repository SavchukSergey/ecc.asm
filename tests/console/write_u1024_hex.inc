if ~ definite Console_WriteUInt1024Hex

include 'write_u512_hex.inc'

;input
; rcx - pointer to bi1024
Console_WriteUInt1024Hex:
        push    rcx
        lea     rcx, [rcx + 64]
        call    Console_WriteUInt512Hex
        pop     rcx

        push    rcx
        call    Console_WriteUInt512Hex
        pop     rcx
        ret

end if
