if ~ definite Console_WriteUInt576Hex

;input
; rcx - pointer to bi256
Console_WriteUInt576Hex:
        push    rcx
        mov     rcx, [rcx + 64]
        call    Console_WriteUInt64Hex
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
