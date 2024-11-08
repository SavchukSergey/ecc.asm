if ~ definite Console_WriteUInt384Hex

;input
; rcx - pointer to bi384
Console_WriteUInt384Hex:
        push    rcx
        lea     rcx, [rcx + 16]
        call    Console_WriteUInt256Hex
        pop     rcx

        push    rcx
        call    Console_WriteUInt128Hex
        pop     rcx
        ret

end if
