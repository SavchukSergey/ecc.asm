;@docs-ignore

if ~ definite __bi_jmp_div_rem

__bi_jmp_div_rem equ 0

macro Jmp_DivRem512X divisor_bits {
  if divisor_bits = 512
      jmp    bi_div_rem_512_512
  else if divisor_bits = 448
      jmp    bi_div_rem_512_448
  else if divisor_bits = 384
      jmp    bi_div_rem_512_384
  else if divisor_bits = 320
      jmp    bi_div_rem_512_320
  else if divisor_bits = 256
      jmp    bi_div_rem_512_256
  else if divisor_bits = 192
      jmp    bi_div_rem_512_192
  else if divisor_bits = 128
      jmp    bi_div_rem_512_128
  else if divisor_bits = 64
      jmp    bi_div_rem_512_64
  else
    display 'unknown Jmp_DivRem512X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Jmp_DivRem448X divisor_bits {
  if divisor_bits = 448
      jmp    bi_div_rem_448_448
  else if divisor_bits = 384
      jmp    bi_div_rem_448_384
  else if divisor_bits = 320
      jmp    bi_div_rem_448_320
  else if divisor_bits = 256
      jmp    bi_div_rem_448_256
  else if divisor_bits = 192
      jmp    bi_div_rem_448_192
  else if divisor_bits = 128
      jmp    bi_div_rem_448_128
  else if divisor_bits = 64
      jmp    bi_div_rem_448_64
  else
    display 'unknown Jmp_DivRem448X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Jmp_DivRem384X divisor_bits {
  if divisor_bits = 384
      jmp    bi_div_rem_384_384
  else if divisor_bits = 320
      jmp    bi_div_rem_384_320
  else if divisor_bits = 256
      jmp    bi_div_rem_384_256
  else if divisor_bits = 192
      jmp    bi_div_rem_384_192
  else if divisor_bits = 128
      jmp    bi_div_rem_384_128
  else if divisor_bits = 64
      jmp    bi_div_rem_384_64
  else
    display 'unknown Jmp_DivRem384X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Jmp_DivRem320X divisor_bits {
  if divisor_bits = 320
      jmp    bi_div_rem_320_320
  else if divisor_bits = 256
      jmp    bi_div_rem_320_256
  else if divisor_bits = 192
      jmp    bi_div_rem_320_192
  else if divisor_bits = 128
      jmp    bi_div_rem_320_128
  else if divisor_bits = 64
      jmp    bi_div_rem_320_64
  else
    display 'unknown Jmp_DivRem320X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Jmp_DivRem256X divisor_bits {
  if divisor_bits = 256
      jmp    bi_div_rem_256_256
  else if divisor_bits = 192
      jmp    bi_div_rem_256_192
  else if divisor_bits = 128
      jmp    bi_div_rem_256_128
  else if divisor_bits = 64
      jmp    bi_div_rem_256_64
  else
    display 'unknown Jmp_DivRem256X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Jmp_DivRem192X divisor_bits {
  if  divisor_bits = 192
      jmp    bi_div_rem_192_192
  else if divisor_bits = 128
      jmp    bi_div_rem_192_128
  else if divisor_bits = 64
      jmp    bi_div_rem_192_64
  else
    display 'unknown Jmp_DivRem192X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}


macro Jmp_DivRem128X divisor_bits {
  if divisor_bits = 128
      jmp    bi_div_rem_128_128
  else if divisor_bits = 64
      jmp    bi_div_rem_128_64
  else
    display 'unknown Jmp_DivRem128X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}



macro Jmp_DivRem dividend_bits, divisor_bits {
  if dividend_bits = 512
      Jmp_DivRem512X divisor_bits
  else if dividend_bits = 448
      Jmp_DivRem448X divisor_bits
  else if dividend_bits = 320
      Jmp_DivRem320X divisor_bits
  else if dividend_bits = 384
      Jmp_DivRem384X divisor_bits
  else if dividend_bits = 256
      Jmp_DivRem256X divisor_bits
  else if dividend_bits = 192
      Jmp_DivRem192X divisor_bits
  else if dividend_bits = 128
      Jmp_DivRem128X divisor_bits
  else
    display 'unknown Jmp_DivRem '
    DisplayDec dividend_bits
    display ', '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

end if