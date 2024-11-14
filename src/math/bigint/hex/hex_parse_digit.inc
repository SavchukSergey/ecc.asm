;@docs-ignore

if ~ definite hex_parse_digit

;input
;al - hex character
;output
;rax - byte
hex_parse_digit:
        movzx   rax, al
        cmp     al, '0'
        jb      .error
        cmp     al, '9'
        jbe     .digit
        cmp     al, 'A'
        jb      .error
        cmp     al, 'F'
        jbe     .upper
        cmp     al, 'a'
        jb      .error
        cmp     al, 'f'
        jbe     .lower
.error:
        xor     al, al
        stc
        ret
.digit:
        sub     al, '0'
        clc
        ret
.upper:
        sub     al, 'A' - 10
        clc
        ret
.lower:
        sub     al, 'a' - 10
        clc
        ret

end if