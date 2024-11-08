if ~ definite Console_WriteUInt192Hex

;input
; rcx - pointer to bi192
Console_WriteUInt192Hex:
        push    rcx
        mov     rcx, [rcx + 16]
        call    Console_WriteUInt64Hex
        pop     rcx

        push    rcx
        mov     rcx, [rcx + 8]
        call    Console_WriteUInt64Hex
        pop     rcx

        push    rcx
        mov     rcx, [rcx + 0]
        call    Console_WriteUInt64Hex
        pop     rcx
        ret

end if
