if ~ definite Console_WriteUInt512Hex

;input
; rcx - pointer to bi256
Console_WriteUInt512Hex:
        push    rcx
        lea     rcx, [rcx + 32]
        call    Console_WriteUInt256Hex
        pop     rcx

        push    rcx
        call    Console_WriteUInt256Hex
        pop     rcx
        ret

end if
