if ~ definite hex_format_digit

;input
;al - byte
;output
;al - hex character
hex_format_digit:
        and     al, 0x0f
        cmp     al, 10
        jae     .letter
        add     al, '0'
        ret
.letter:
        add     al, 'A' - 10
        ret

end if