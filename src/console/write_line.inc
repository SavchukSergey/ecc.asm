if ~ definite Console_WriteLine

;include 'write_string.inc'

Console_WriteLine:
        push    rsi
        mov     rsi, Console_WriteLine_CRLF
        call    Console_WriteString
        pop     rsi
        ret


Console_WriteLine_CRLF db 13, 10, 0

end if