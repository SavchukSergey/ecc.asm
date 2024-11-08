if ~ definite Console_WriteUInt320Hex

;input
; rcx - pointer to bi320
Console_WriteUInt320Hex:
        push    rcx
        lea     rcx, [rcx + 8]
        call    Console_WriteUInt256Hex
        pop     rcx

        push    rcx
        mov     rcx, [rcx + 0]
        call    Console_WriteUInt64Hex
        pop     rcx
        ret

end if
