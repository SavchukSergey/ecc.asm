;@docs-ignore

macro DivRemGuess64_Prepare dividend_bits, divisor_bits {
    DIV_REM_PARTIAL_DIVIDEND_SIZE = 128
    DIV_REM_PARTIAL_DIVISOR_SIZE = 64
    DIV_REM_MAX_REMAINDER_BOOST = (dividend_bits - DIV_REM_PARTIAL_DIVIDEND_SIZE)


    ; Because of preliminary checks at the begining
    DIV_REM_GUESS_MIN_DIVISOR_SIZE = (divisor_bits - 64)
    
    ; divisor_lzcnt contains value as if divisor had same width as dividend
    DIV_REM_GUESS_IMAGINARY_BITS = (dividend_bits - divisor_bits)
    
    DIV_REM_GUESS_QUOTIENT_SIZE = dividend_bits
    DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE = (dividend_bits - DIV_REM_GUESS_MIN_DIVISOR_SIZE)
    DIV_REM_GUESS_REMAINDER_SIZE = dividend_bits
    DIV_REM_GUESS_REMAINDER_ACTUAL_SIZE = divisor_bits

    if DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE > 128
      DIV_REM_GUESS_QUOTIENT_GUESS_SIZE = DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE
    else
      DIV_REM_GUESS_QUOTIENT_GUESS_SIZE = 128
    end if
}

macro RemGuess64_Prepare dividend_bits, divisor_bits {
    DIV_REM_PARTIAL_DIVIDEND_SIZE = 128
    DIV_REM_PARTIAL_DIVISOR_SIZE = 64
    DIV_REM_MAX_REMAINDER_BOOST = (dividend_bits - DIV_REM_PARTIAL_DIVIDEND_SIZE)


    ; Because of preliminary checks at the begining
    if ~ definite DIV_REM_GUESS_MIN_DIVISOR_SIZE
    ; divisor_bits/2 < divisor width <= divisor_bits
    DIV_REM_GUESS_MIN_DIVISOR_SIZE = (divisor_bits/2)
    end if
    
    ; divisor_lzcnt contains value as if divisor had same width as dividend
    DIV_REM_GUESS_IMAGINARY_BITS = dividend_bits - divisor_bits
    
    DIV_REM_GUESS_QUOTIENT_SIZE = dividend_bits
    DIV_REM_GUESS_QUOTIENT_ACTUAL_SIZE = (dividend_bits - DIV_REM_GUESS_MIN_DIVISOR_SIZE)
    DIV_REM_GUESS_REMAINDER_SIZE = dividend_bits
    DIV_REM_GUESS_REMAINDER_ACTUAL_SIZE = divisor_bits
}
