macro DivRemGuess64_Divisor256 dividend_bits, divisor_bits {
  if divisor_bits >= 512
.divisor_256:
    mov     rcx, [.dividend]
    mov     rdx, [.divisor]
    mov     r8, [.quotient]
    mov     r9, [.remainder]
    Call_DivRem dividend_bits, 256
    jmp     .end
  end if
}

macro RemGuess64_Divisor256 dividend_bits, divisor_bits {
  if divisor_bits >= 512
.divisor_256:
    mov     rcx, [.dividend]
    mov     rdx, [.divisor]
    mov     r8, [.remainder]
    Call_Rem dividend_bits, 256
    jmp     .end
  end if
}

macro DivRemGuess64_Divisor128 dividend_bits, divisor_bits {
  if divisor_bits >= 256
.divisor_128:
    mov     rcx, [.dividend]
    mov     rdx, [.divisor]
    mov     r8, [.quotient]
    mov     r9, [.remainder]
    Call_DivRem dividend_bits, 128
    jmp     .end
  end if
}

macro RemGuess64_Divisor128 dividend_bits, divisor_bits {
  if divisor_bits >= 256
.divisor_128:
    mov     rcx, [.dividend]
    mov     rdx, [.divisor]
    mov     r8, [.remainder]
    Call_Rem dividend_bits, 128
    jmp     .end
  end if
}

macro DivRemGuess64_Divisor64 dividend_bits, divisor_bits {
  if divisor_bits >= 64
.divisor_64:
    mov     rcx, [.dividend]
    mov     rdx, [.divisor]
    mov     rdx, [rdx + 0]
    mov     r8, [.quotient]
    mov     r9, [.remainder]
    Call_DivRem dividend_bits, 64
    jmp     .end
  end if
}

macro RemGuess64_Divisor64 dividend_bits, divisor_bits {
  if divisor_bits >= 64
.divisor_64:
    mov     rcx, [.dividend]
    mov     rdx, [.divisor]
    mov     rdx, [rdx + 0]
    mov     r8, [.remainder]
    Call_Rem dividend_bits, 64
    jmp     .end
  end if
}



macro DivRemGuess64_DivisorSmallSwitch dividend_bits, divisor_bits {
.divisor_small:
    if divisor_bits >= 512
      cmp     rax, dividend_bits - 128
      jb      .divisor_256
    end if

    if divisor_bits >= 256
      cmp     rax, dividend_bits - 64
      jb      .divisor_128
    end if

    DivRemGuess64_Divisor64   dividend_bits, divisor_bits

    DivRemGuess64_Divisor128 dividend_bits, divisor_bits
    DivRemGuess64_Divisor256 dividend_bits, divisor_bits

}

macro RemGuess64_DivisorSmallSwitch dividend_bits, divisor_bits {
.divisor_small:
    if divisor_bits >= 512
      cmp     rax, dividend_bits - 128
      jb      .divisor_256
    end if

    if divisor_bits >= 256
      cmp     rax, dividend_bits - 64
      jb      .divisor_128
    end if

    RemGuess64_Divisor64 dividend_bits, divisor_bits

    RemGuess64_Divisor128 dividend_bits, divisor_bits
    RemGuess64_Divisor256 dividend_bits, divisor_bits

}
