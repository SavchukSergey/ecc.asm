if ~ definite hex_parse_reverse_bytes

include 'hex_parse_byte.inc'

;input
;rsi - pointer to hex string
;rdi - destination for bytes
;rcx - bytes count
;output
;rsi advanced to the end of source
;rdi advanced to the end of destination
hex_parse_reverse_bytes:
        push    rax rbx rcx
.loop:
        call    hex_parse_byte
        jc      .error
        mov     [rdi + rcx - 1], al
        loop    .loop

        pop     rcx rbx rax
        add     rdi, rcx
        clc
        ret
.error:
        mov     byte [rdi], 0
        inc     rdi
        loop    .error
        pop     rcx rbx rax
        stc
        ret

end if