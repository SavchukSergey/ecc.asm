;@docs-ignore

if ~ definite __bi_call_div_rem

__bi_call_div_rem equ 0

macro Call_DivRem512X divisor_bits {
  if divisor_bits = 512
      call    bi_div_rem_512_512
  else if divisor_bits = 448
      call    bi_div_rem_512_448
  else if divisor_bits = 384
      call    bi_div_rem_512_384
  else if divisor_bits = 320
      call    bi_div_rem_512_320
  else if divisor_bits = 256
      call    bi_div_rem_512_256
  else if divisor_bits = 192
      call    bi_div_rem_512_192
  else if divisor_bits = 128
      call    bi_div_rem_512_128
  else if divisor_bits = 64
      call    bi_div_rem_512_64
  else
    display 'unknown Call_DivRem512X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Call_DivRem448X divisor_bits {
  if divisor_bits = 448
      call    bi_div_rem_448_448
  else if divisor_bits = 384
      call    bi_div_rem_448_384
  else if divisor_bits = 320
      call    bi_div_rem_448_320
  else if divisor_bits = 256
      call    bi_div_rem_448_256
  else if divisor_bits = 192
      call    bi_div_rem_448_192
  else if divisor_bits = 128
      call    bi_div_rem_448_128
  else if divisor_bits = 64
      call    bi_div_rem_448_64
  else
    display 'unknown Call_DivRem448X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Call_DivRem384X divisor_bits {
  if divisor_bits = 384
      call    bi_div_rem_384_384
  else if divisor_bits = 320
      call    bi_div_rem_384_320
  else if divisor_bits = 256
      call    bi_div_rem_384_256
  else if divisor_bits = 192
      call    bi_div_rem_384_192
  else if divisor_bits = 128
      call    bi_div_rem_384_128
  else if divisor_bits = 64
      call    bi_div_rem_384_64
  else
    display 'unknown Call_DivRem384X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Call_DivRem320X divisor_bits {
  if divisor_bits = 320
      call    bi_div_rem_320_320
  else if divisor_bits = 256
      call    bi_div_rem_320_256
  else if divisor_bits = 192
      call    bi_div_rem_320_192
  else if divisor_bits = 128
      call    bi_div_rem_320_128
  else if divisor_bits = 64
      call    bi_div_rem_320_64
  else
    display 'unknown Call_DivRem320X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Call_DivRem256X divisor_bits {
  if divisor_bits = 256
      call    bi_div_rem_256_256
  else if divisor_bits = 192
      call    bi_div_rem_256_192
  else if divisor_bits = 128
      call    bi_div_rem_256_128
  else if divisor_bits = 64
      call    bi_div_rem_256_64
  else
    display 'unknown Call_DivRem256X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Call_DivRem192X divisor_bits {
  if  divisor_bits = 192
      call    bi_div_rem_192_192
  else if divisor_bits = 128
      call    bi_div_rem_192_128
  else if divisor_bits = 64
      call    bi_div_rem_192_64
  else
    display 'unknown Call_DivRem192X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}


macro Call_DivRem128X divisor_bits {
  if divisor_bits = 128
      call    bi_div_rem_128_128
  else if divisor_bits = 64
      call    bi_div_rem_128_64
  else
    display 'unknown Call_DivRem128X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}



macro Call_DivRem dividend_bits, divisor_bits {
  if dividend_bits = 512
      Call_DivRem512X divisor_bits
  else if dividend_bits = 448
      Call_DivRem448X divisor_bits
  else if dividend_bits = 320
      Call_DivRem320X divisor_bits
  else if dividend_bits = 384
      Call_DivRem384X divisor_bits
  else if dividend_bits = 256
      Call_DivRem256X divisor_bits
  else if dividend_bits = 192
      Call_DivRem192X divisor_bits
  else if dividend_bits = 128
      Call_DivRem128X divisor_bits
  else
    display 'unknown Call_DivRem '
    DisplayDec dividend_bits
    display ', '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

end if