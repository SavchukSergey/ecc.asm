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
  else if left_bits = 320
      Call_Mul320X right_bits
  else if left_bits = 256
      Call_Mul256X right_bits
  else if left_bits = 192
      Call_Mul192X right_bits
  else if left_bits = 128
      Call_Mul128X right_bits
  else
    display 'unknown mul '
    DisplayDec left_bits
    display ', '
    DisplayDec right_bits
    display 13, 10
    err
  end if
}

macro Call_MulLow_192_64_X result_bits {
  if result_bits = 192
      call  bi_mul_low_192_64_192
  else
    display 'unknown Call_MulLow_192_64_X '
    DisplayDec result_bits
    display 13, 10
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
  end if
}

macro Call_MulLow_256_64_X result_bits {
  if result_bits = 256
      call  bi_mul_low_256_64_256
  else
    display 'unknown Call_MulLow_256_64_X '
    DisplayDec result_bits
    display 13, 10
  end if
}

macro Call_MulLow_256_X_X right_bits, result_bits {
  if right_bits = 64
      Call_MulLow_256_64_X result_bits
  else
    display 'unknown Call_MulLow_256_X_X '
    DisplayDec right_bits
    display ', '
    DisplayDec result_bits
    display 13, 10
  end if
}

macro Call_MulLow left_bits, right_bits, result_bits {
  if left_bits = 256
    Call_MulLow_256_X_X right_bits, result_bits
  else if left_bits = 192
    Call_MulLow_192_X_X right_bits, result_bits
  else
    display 'unknown Call_MulLow '
    DisplayDec left_bits
    display ', '
    DisplayDec right_bits
    display ', '
    DisplayDec result_bits
    display 13, 10
  end if
}

end if