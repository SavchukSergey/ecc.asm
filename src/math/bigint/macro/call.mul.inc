;@docs-ignore

if ~ definite __bi_call_mul

__bi_call_mul equ 0

macro Call_Mul512X right_bits {
  if right_bits = 512
      call    bi_mul_512_512
  else if right_bits = 256
      call    bi_mul_512_256
  else if right_bits = 192
      call    bi_mul_512_192
  else if right_bits = 128
      call    bi_mul_512_128
  else if right_bits = 64
      call    bi_mul_512_64
  else
    display 'unknown Call_Mul512X '
    DisplayDec right_bits
    display 13, 10
    err
  end if
}

macro Call_Mul448X right_bits {
  if right_bits = 448
      call    bi_mul_448_448
  else if right_bits = 384
      call    bi_mul_448_384
  else if right_bits = 320
      call    bi_mul_448_320
  else if right_bits = 256
      call    bi_mul_448_256
  else if right_bits = 192
      call    bi_mul_448_192
  else if right_bits = 128
      call    bi_mul_448_128
  else if right_bits = 64
      call    bi_mul_448_64
  else
    display 'unknown Call_Mul448X '
    DisplayDec right_bits
    display 13, 10
    err
  end if
}


macro Call_Mul384X right_bits {
  if right_bits = 384
      call    bi_mul_384_384
  else if right_bits = 320
      call    bi_mul_384_320
  else if right_bits = 256
      call    bi_mul_384_256
  else if right_bits = 192
      call    bi_mul_384_192
  else if right_bits = 128
      call    bi_mul_384_128
  else if right_bits = 64
      call    bi_mul_384_64
  else
    display 'unknown Call_Mul384X '
    DisplayDec right_bits
    display 13, 10
    err
  end if
}

macro Call_Mul320X right_bits {
  if right_bits = 320
      call    bi_mul_320_320
  else if right_bits = 256
      call    bi_mul_320_256
  else if right_bits = 192
      call    bi_mul_320_192
  else if right_bits = 128
      call    bi_mul_320_128
  else if right_bits = 64
      call    bi_mul_320_64
  else
    display 'unknown Call_Mul320X '
    DisplayDec right_bits
    display 13, 10
    err
  end if
}

macro Call_Mul256X right_bits {
  if right_bits = 256
      call    bi_mul_256_256
  else if right_bits = 192
      call    bi_mul_256_192
  else if right_bits = 128
      call    bi_mul_256_128
  else if right_bits = 64
      call    bi_mul_256_64
  else
    display 'unknown Call_Mul256X '
    DisplayDec right_bits
    display 13, 10
    err
  end if
}

macro Call_Mul192X right_bits {
  if  right_bits = 192
      call    bi_mul_192_192
  else if right_bits = 128
      call    bi_mul_192_128
  else if right_bits = 64
      call    bi_mul_192_64
  else
    display 'unknown Call_Mul192X '
    DisplayDec right_bits
    display 13, 10
    err
  end if
}


macro Call_Mul128X right_bits {
  if right_bits = 128
      call    bi_mul_128_128
  else if right_bits = 64
      call    bi_mul_128_64
  else
    display 'unknown Call_Mul128X '
    DisplayDec right_bits
    display 13, 10
    err
  end if
}



macro Call_Mul left_bits, right_bits {
  if left_bits = 512
      Call_Mul512X right_bits
  else if left_bits = 448
      Call_Mul448X right_bits
  else if left_bits = 384
      Call_Mul384X right_bits
  else if left_bits = 320
      Call_Mul320X right_bits
  else if left_bits = 256
      Call_Mul256X right_bits
  else if left_bits = 192
      Call_Mul192X right_bits
  else if left_bits = 128
      Call_Mul128X right_bits
  else
    display 'unknown Call_Mul '
    DisplayDec left_bits
    display ', '
    DisplayDec right_bits
    display 13, 10
    err
  end if
}



macro Call_MulLow_128_64_X result_bits {
  if result_bits = 128
      call  bi_mul_128_64_low_128
  else
    display 'unknown Call_MulLow_128_64_X '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}

macro Call_MulLow_128_128_X result_bits {
  if result_bits = 128
      call  bi_mul_128_128_low_128
  else
    display 'unknown Call_MulLow_128_128_X '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}

macro Call_MulLow_128_X_X right_bits, result_bits {
  if right_bits = 64
      Call_MulLow_128_64_X result_bits
  else if right_bits = 128
      Call_MulLow_128_128_X result_bits
  else
    display 'unknown Call_MulLow_128_X_X '
    DisplayDec right_bits
    display ', '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}



macro Call_MulLow_192_64_X result_bits {
  if result_bits = 192
      call  bi_mul_192_64_low_192
  else
    display 'unknown Call_MulLow_192_64_X '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}

macro Call_MulLow_192_X_X right_bits, result_bits {
  if right_bits = 64
      Call_MulLow_192_64_X result_bits
  else
    display 'unknown Call_MulLow_192_X_X '
    DisplayDec right_bits
    display ', '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}

macro Call_MulLow_256_64_X result_bits {
  if result_bits = 256
      call  bi_mul_256_64_low_256
  else
    display 'unknown Call_MulLow_256_64_X '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}

macro Call_MulLow_256_128_X result_bits {
  if result_bits = 256
      call  bi_mul_256_128_low_256
  else
    display 'unknown Call_MulLow_256_128_X '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}

macro Call_MulLow_256_256_X result_bits {
  if result_bits = 256
      call  bi_mul_256_256_low_256
  else
    display 'unknown Call_MulLow_256_256_X '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}

macro Call_MulLow_256_X_X right_bits, result_bits {
  if right_bits = 64
      Call_MulLow_256_64_X result_bits
  else if right_bits = 128
      Call_MulLow_256_128_X result_bits
  else if right_bits = 256
      Call_MulLow_256_256_X result_bits
  else
    display 'unknown Call_MulLow_256_X_X '
    DisplayDec right_bits
    display ', '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}




macro Call_MulLow_320_64_X result_bits {
  if result_bits = 320
      call  bi_mul_320_64_low_320
  else
    display 'unknown Call_MulLow_320_64_X '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}

macro Call_MulLow_320_320_X result_bits {
  if result_bits = 320
      call  bi_mul_320_320_low_320
  else
    display 'unknown Call_MulLow_320_320_X '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}

macro Call_MulLow_320_X_X right_bits, result_bits {
  if right_bits = 64
      Call_MulLow_320_64_X result_bits
  else if right_bits = 128
      Call_MulLow_320_128_X result_bits
  else if right_bits = 256
      Call_MulLow_320_256_X result_bits
  else if right_bits = 320
      Call_MulLow_320_320_X result_bits
  else
    display 'unknown Call_MulLow_320_X_X '
    DisplayDec right_bits
    display ', '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}




macro Call_MulLow_384_64_X result_bits {
  if result_bits = 384
      call  bi_mul_384_64_low_384
  else
    display 'unknown Call_MulLow_384_64_X '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}

macro Call_MulLow_384_384_X result_bits {
  if result_bits = 384
      call  bi_mul_384_384_low_384
  else
    display 'unknown Call_MulLow_384_384_X '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}

macro Call_MulLow_384_X_X right_bits, result_bits {
  if right_bits = 64
      Call_MulLow_384_64_X result_bits
  else if right_bits = 128
      Call_MulLow_384_128_X result_bits
  else if right_bits = 256
      Call_MulLow_384_256_X result_bits
  else if right_bits = 320
      Call_MulLow_384_320_X result_bits
  else if right_bits = 384
      Call_MulLow_384_384_X result_bits
  else
    display 'unknown Call_MulLow_384_X_X '
    DisplayDec right_bits
    display ', '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}




macro Call_MulLow_448_64_X result_bits {
  if result_bits = 448
      call  bi_mul_448_64_low_448
  else
    display 'unknown Call_MulLow_448_64_X '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}

macro Call_MulLow_448_X_X right_bits, result_bits {
  if right_bits = 64
      Call_MulLow_448_64_X result_bits
  else if right_bits = 128
      Call_MulLow_448_128_X result_bits
  else if right_bits = 256
      Call_MulLow_448_256_X result_bits
  else if right_bits = 320
      Call_MulLow_448_320_X result_bits
  else if right_bits = 384
      Call_MulLow_448_384_X result_bits
  else if right_bits = 448
      Call_MulLow_448_448_X result_bits
  else
    display 'unknown Call_MulLow_448_X_X '
    DisplayDec right_bits
    display ', '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}




macro Call_MulLow_512_64_X result_bits {
  if result_bits = 512
      call  bi_mul_512_64_low_512
  else
    display 'unknown Call_MulLow_512_64_X '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}

macro Call_MulLow_512_512_X result_bits {
  if result_bits = 512
      call  bi_mul_512_512_low_512
  else
    display 'unknown Call_MulLow_512_512_X '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}

macro Call_MulLow_512_X_X right_bits, result_bits {
  if right_bits = 64
      Call_MulLow_512_64_X result_bits
  else if right_bits = 512
      Call_MulLow_512_512_X result_bits
  else
    display 'unknown Call_MulLow_512_X_X '
    DisplayDec right_bits
    display ', '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}

macro Call_MulLow left_bits, right_bits, result_bits {
  if left_bits = 512
    Call_MulLow_512_X_X right_bits, result_bits
  else if left_bits = 448
    Call_MulLow_448_X_X right_bits, result_bits
  else if left_bits = 384
    Call_MulLow_384_X_X right_bits, result_bits
  else if left_bits = 320
    Call_MulLow_320_X_X right_bits, result_bits
  else if left_bits = 256
    Call_MulLow_256_X_X right_bits, result_bits
  else if left_bits = 192
    Call_MulLow_192_X_X right_bits, result_bits
  else if left_bits = 128
    Call_MulLow_128_X_X right_bits, result_bits
  else
    display 'unknown Call_MulLow '
    DisplayDec left_bits
    display ', '
    DisplayDec right_bits
    display ', '
    DisplayDec result_bits
    display 13, 10
    err
  end if
}

end if