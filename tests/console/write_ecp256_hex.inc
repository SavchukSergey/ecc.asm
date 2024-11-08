if ~ definite Console_WriteECP256Hex

;input
; rcx - pointer to ecp256
Console_WriteECP256Hex:
        push    rsi

        mov     rsi, .prefix
        call    Console_WriteString

        call    Console_WriteUInt256Hex

        mov     rsi, .mid
        call    Console_WriteString

        add     rcx, ECPoint256.y
        call    Console_WriteUInt256Hex

        mov     rsi, .suffix
        call    Console_WriteString

        pop     rsi

        ret
.prefix db '(X: ', 0
.mid db ', Y: ', 0
.suffix db ')', 0

end if
