if ~ definite bi_div_rem_debug

bi_div_rem_debug:


bi_div_rem_dump_guess_corrected_128:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_guess_corrected_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt128Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret


bi_div_rem_dump_guess_corrected_msg:   db 'guess (corrected): ', 0

end if