if ~ definite bi_div_rem_debug

bi_div_rem_debug:



bi_div_rem_dump_divisor_128:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_divisor_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt128Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret

bi_div_rem_dump_divisor_256:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_divisor_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt256Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret

bi_div_rem_dump_divisor_shifted_128:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_divisor_shifted_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt128Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret

bi_div_rem_dump_divisor_shifted_256:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_divisor_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt256Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret

bi_div_rem_dump_dividend_128:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_dividend_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt128Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret

bi_div_rem_dump_dividend_256:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_dividend_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt256Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret

bi_div_rem_dump_dividend_512:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_dividend_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt512Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret



bi_div_rem_dump_remainder_128:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_remainder_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt128Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret

bi_div_rem_dump_remainder_256:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_remainder_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt256Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret

bi_div_rem_dump_remainder_512:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_remainder_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt512Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret



bi_div_rem_dump_remainder_shifted_128:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_remainder_shifted_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt128Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret

bi_div_rem_dump_remainder_shifted_256:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_remainder_shifted_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt256Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret

bi_div_rem_dump_remainder_shifted_512:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_remainder_shifted_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt512Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret




bi_div_rem_dump_guess_128:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_guess_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt128Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret


bi_div_rem_dump_delta_128:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_delta_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt128Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret

bi_div_rem_dump_delta_256:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_delta_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt256Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret

bi_div_rem_dump_delta_512:
    push    rcx rsi

    push    rcx
    lea     rsi, [bi_div_rem_dump_delta_msg]
    call    Console_WriteString
    pop     rcx

    call    Console_WriteUInt512Hex
    call    Console_WriteLine

    pop     rsi rcx
    ret

bi_div_rem_dump_divisor_msg:           db 'divisor:           ', 0
bi_div_rem_dump_dividend_msg:          db 'dividend:          ', 0
bi_div_rem_dump_divisor_shifted_msg:   db 'divisor shifted:   ', 0
bi_div_rem_dump_remainder_msg:         db 'remainder:         ', 0
bi_div_rem_dump_remainder_shifted_msg: db 'remainder shifted: ', 0
bi_div_rem_dump_guess_msg:             db 'guess:             ', 0
bi_div_rem_dump_delta_msg:             db 'delta:             ', 0

end if