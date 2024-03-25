if ~ definite Console_WriteUInt128Hex


include 'write_u64_hex.inc'

;input
; rcx - pointer to bi128
Console_WriteUInt128Hex:
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