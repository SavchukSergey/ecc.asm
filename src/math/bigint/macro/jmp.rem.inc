if ~ definite __bi_jmp_rem

__bi_jmp_rem equ 0

macro Jmp_Rem128X divisor_bits {
  if divisor_bits = 128
      jmp    bi_rem_128_128
  else if divisor_bits = 64
      jmp    bi_rem_128_64
  else
    display 'unknown Jmp_Rem128X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Jmp_Rem192X divisor_bits {
  if divisor_bits = 192
      jmp    bi_rem_192_192
  else if divisor_bits = 128
      jmp    bi_rem_192_128
  else if divisor_bits = 64
      jmp    bi_rem_192_64
  else
    display 'unknown Jmp_Rem192X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}


macro Jmp_Rem256X divisor_bits {
  if divisor_bits = 256
      jmp    bi_rem_256_256
  else if divisor_bits = 192
      jmp    bi_rem_256_192
  else if divisor_bits = 128
      jmp    bi_rem_256_128
  else if divisor_bits = 64
      jmp    bi_rem_256_64
  else
    display 'unknown Jmp_Rem256X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Jmp_Rem320X divisor_bits {
  if divisor_bits = 320
      jmp    bi_rem_320_320
  else if divisor_bits = 256
      jmp    bi_rem_320_256
  else if divisor_bits = 192
      jmp    bi_rem_320_192
  else if divisor_bits = 128
      jmp    bi_rem_320_128
  else if divisor_bits = 64
      jmp    bi_rem_320_64
  else
    display 'unknown Jmp_Rem320X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Jmp_Rem384X divisor_bits {
  if divisor_bits = 384
      jmp    bi_rem_384_384
  else if divisor_bits = 320
      jmp    bi_rem_384_320
  else if divisor_bits = 256
      jmp    bi_rem_384_256
  else if divisor_bits = 192
      jmp    bi_rem_384_192
  else if divisor_bits = 128
      jmp    bi_rem_384_128
  else if divisor_bits = 64
      jmp    bi_rem_384_64
  else
    display 'unknown Jmp_Rem384X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Jmp_Rem448X divisor_bits {
  if divisor_bits = 448
      jmp    bi_rem_448_448
  else if divisor_bits = 384
      jmp    bi_rem_448_384
  else if divisor_bits = 320
      jmp    bi_rem_448_320
  else if divisor_bits = 256
      jmp    bi_rem_448_256
  else if divisor_bits = 192
      jmp    bi_rem_448_192
  else if divisor_bits = 128
      jmp    bi_rem_448_128
  else if divisor_bits = 64
      jmp    bi_rem_448_64
  else
    display 'unknown Jmp_Rem448X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Jmp_Rem512X divisor_bits {
  if divisor_bits = 512
      jmp    bi_rem_512_512
  else if divisor_bits = 448
      jmp    bi_rem_512_448
  else if divisor_bits = 384
      jmp    bi_rem_512_384
  else if divisor_bits = 320
      jmp    bi_rem_512_320
  else if divisor_bits = 256
      jmp    bi_rem_512_256
  else if divisor_bits = 192
      jmp    bi_rem_512_192
  else if divisor_bits = 128
      jmp    bi_rem_512_128
  else if divisor_bits = 64
      jmp    bi_rem_512_64
  else
    display 'unknown Jmp_Rem512X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Jmp_Rem dividend_bits, divisor_bits {
  if dividend_bits = 512
      Jmp_Rem512X divisor_bits
  else if dividend_bits = 448
      Jmp_Rem448X divisor_bits
  else if dividend_bits = 384
      Jmp_Rem384X divisor_bits
  else if dividend_bits = 320
      Jmp_Rem320X divisor_bits
  else if dividend_bits = 256
      Jmp_Rem256X divisor_bits
  else if dividend_bits = 192
      Jmp_Rem192X divisor_bits
  else if dividend_bits = 128
      Jmp_Rem128X divisor_bits
  else
    display 'unknown Jmp_Rem '
    DisplayDec dividend_bits
    display ', '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}


end if