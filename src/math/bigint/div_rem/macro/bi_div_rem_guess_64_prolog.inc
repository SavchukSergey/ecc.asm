macro DivRemGuess64_Prolog dividend_bits, divisor_bits {
    sub     rsp, .locals_end - .locals_start
    mov     [.dividend], rcx
    mov     [.divisor], rdx
    mov     [.quotient], r8
    mov     [.remainder], r9

    PrologCheckStackAligned 'DivRemGuess64_Prolog'
    CheckRegAligned rcx, 'DivRemGuess64_Prolog rcx'
    CheckRegAligned rdx, 'DivRemGuess64_Prolog rdx'
    CheckRegAligned r8, 'DivRemGuess64_Prolog r8'
    CheckRegAligned r9, 'DivRemGuess64_Prolog r9'


    DivRemGuess64_DumpArgs dividend_bits, divisor_bits
}

macro RemGuess64_Prolog dividend_bits, divisor_bits {
    sub     rsp, .locals_end - .locals_start
    mov     [.dividend], rcx
    mov     [.divisor], rdx
    mov     [.remainder], r8

    PrologCheckStackAligned 'RemGuess64_Prolog'
    CheckRegAligned rcx, 'RemGuess64_Prolog rcx'
    CheckRegAligned rdx, 'RemGuess64_Prolog rdx'
    CheckRegAligned r8, 'RemGuess64_Prolog r8'

    DivRemGuess64_DumpArgs dividend_bits, divisor_bits
}
