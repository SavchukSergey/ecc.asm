if ~ definite Console_WriteUInt256Hex

;input
; rcx - pointer to bi256
Console_WriteUInt256Hex:
        push    rcx
        lea     rcx, [rcx + 16]
        call    Console_WriteUInt128Hex
        pop     rcx

        push    rcx
        call    Console_WriteUInt128Hex
        pop     rcx
        ret

end if
