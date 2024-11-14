;@docs-ignore

if ~ definite hex_parse_byte

;input
;rsi - pointer to hex string
;output
;rax - byte
;rsi advanced by 2
hex_parse_byte:
        push    rbx
        mov     al, [rsi]
        call    hex_parse_digit
        jc      .error
        inc     rsi
        mov     bl, al
        mov     al, [rsi]
        call    hex_parse_digit
        jc      .error
        inc     rsi
        shl     bl, 4
        or      al, bl
        clc
        pop     rbx
        ret
.error:
        xor     rax, rax
        stc
        ret

end if