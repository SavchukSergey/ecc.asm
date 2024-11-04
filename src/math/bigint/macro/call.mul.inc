if ~ definite __bi_call_mul

__bi_call_mul equ 0

macro Call_Mul512X divisor_bits {
  if divisor_bits = 512
      call    bi_mul_512_512
  else if divisor_bits = 256
      call    bi_mul_512_256
  else if divisor_bits = 192
      call    bi_mul_512_192
  else if divisor_bits = 128
      call    bi_mul_512_128
  else if divisor_bits = 64
      call    bi_mul_512_64
  else
    display 'unknown Call_Mul512X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Call_Mul320X divisor_bits {
  if divisor_bits = 320
      call    bi_mul_320_320
  else if divisor_bits = 256
      call    bi_mul_320_256
  else if divisor_bits = 192
      call    bi_mul_320_192
  else if divisor_bits = 128
      call    bi_mul_320_128
  else if divisor_bits = 64
      call    bi_mul_320_64
  else
    display 'unknown Call_Mul320X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Call_Mul256X divisor_bits {
  if divisor_bits = 256
      call    bi_mul_256_256
  else if divisor_bits = 192
      call    bi_mul_256_192
  else if divisor_bits = 128
      call    bi_mul_256_128
  else if divisor_bits = 64
      call    bi_mul_256_64
  else
    display 'unknown Call_Mul256X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

macro Call_Mul192X divisor_bits {
  if  divisor_bits = 192
      call    bi_mul_192_192
  else if divisor_bits = 128
      call    bi_mul_192_128
  else if divisor_bits = 64
      call    bi_mul_192_64
  else
    display 'unknown Call_Mul192X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}


macro Call_Mul128X divisor_bits {
  if divisor_bits = 128
      call    bi_mul_128_128
  else if divisor_bits = 64
      call    bi_mul_128_64
  else
    display 'unknown Call_Mul128X '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}



macro Call_Mul dividend_bits, divisor_bits {
  if dividend_bits = 512
      Call_Mul512X divisor_bits
  else if dividend_bits = 320
      Call_Mul320X divisor_bits
  else if dividend_bits = 256
      Call_Mul256X divisor_bits
  else if dividend_bits = 192
      Call_Mul192X divisor_bits
  else if dividend_bits = 128
      Call_Mul128X divisor_bits
  else
    display 'unknown mul '
    DisplayDec dividend_bits
    display ', '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}

end if