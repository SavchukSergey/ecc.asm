if ~ definite __bi_call_rem

__bi_call_rem equ 0

macro Call_Rem128X divisor_bits {
  if divisor_bits = 128
      call    bi_rem_128_128
  else if divisor_bits = 64
      call    bi_rem_128_64
  else
    display 'unknown Call_Rem128X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Call_Rem192X divisor_bits {
  if divisor_bits = 192
      call    bi_rem_192_192
  else if divisor_bits = 128
      call    bi_rem_192_128
  else if divisor_bits = 64
      call    bi_rem_192_64
  else
    display 'unknown Call_Rem192X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}


macro Call_Rem256X divisor_bits {
  if divisor_bits = 256
      call    bi_rem_256_256
  else if divisor_bits = 192
      call    bi_rem_256_192
  else if divisor_bits = 128
      call    bi_rem_256_128
  else if divisor_bits = 64
      call    bi_rem_256_64
  else
    display 'unknown Call_Rem256X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Call_Rem320X divisor_bits {
  if divisor_bits = 320
      call    bi_rem_320_320
  else if divisor_bits = 256
      call    bi_rem_320_256
  else if divisor_bits = 192
      call    bi_rem_320_192
  else if divisor_bits = 128
      call    bi_rem_320_128
  else if divisor_bits = 64
      call    bi_rem_320_64
  else
    display 'unknown Call_Rem320X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Call_Rem512X divisor_bits {
  if divisor_bits = 512
      call    bi_rem_512_512
  else if divisor_bits = 256
      call    bi_rem_512_256
  else if divisor_bits = 128
      call    bi_rem_512_128
  else if divisor_bits = 64
      call    bi_rem_512_64
  else
    display 'unknown Call_Rem512X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Call_Rem dividend_bits, divisor_bits {
  if dividend_bits = 512
      Call_Rem512X divisor_bits
  else if dividend_bits = 320
      Call_Rem320X divisor_bits
  else if dividend_bits = 256
      Call_Rem256X divisor_bits
  else if dividend_bits = 192
      Call_Rem192X divisor_bits
  else if dividend_bits = 128
      Call_Rem128X divisor_bits
  else
    display 'unknown Call_Rem '
    DisplayDec dividend_bits
    display ', '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}


end if