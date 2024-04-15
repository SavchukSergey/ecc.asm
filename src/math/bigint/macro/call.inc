macro Call_Shl bits {
  if bits = 128
      call    bi_shl_128
  else if bits = 256
      call    bi_shl_256
  else if bits = 512
      call    bi_shl_512
  else
      display 'unknown shl '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_ShlAssign bits {
  if bits = 64
      shl     qword [rcx], bits
  else if bits = 128
      call    bi_shl_assign_128
  else if bits = 192
      call    bi_shl_assign_192
  else if bits = 256
      call    bi_shl_assign_256
  else if bits = 384
      call    bi_shl_assign_384
  else if bits = 448
      call    bi_shl_assign_448
  else if bits = 512
      call    bi_shl_assign_512
  else
      display 'unknown shl assign '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_ExtendX128 bits {
  if bits = 192
      call    bi_extend_192_128
  else if bits = 256
      call    bi_extend_256_128
  else if bits = 384
      call    bi_extend_384_128
  else if bits = 448
      call    bi_extend_448_128
  else if bits = 512
      call    bi_extend_512_128
  else
      display 'unknown extendx128 '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_ExtendAssign target_bits, source_bits {
  delta_bits = target_bits - source_bits
  if delta_bits = 256
    lea     rcx, [rcx + source_bits / 8]
    call    bi_zero_256
  else
      display 'unknown extend_assign '
      DisplayDec target_bits
      display ', '
      DisplayDec source_bits
      display 13, 10
      err 
  end if
}

macro Call_IncAssign bits {
  if bits = 64
      inc qword [rcx]
  else if bits = 128
      call    bi_inc_assign_128
  else if bits = 192
      call    bi_inc_assign_192
  else if bits = 256
      call    bi_inc_assign_256
  else if bits = 384
      call    bi_inc_assign_384
  else if bits = 448
      call    bi_inc_assign_448
  else if bits = 512
      call    bi_inc_assign_512
  else
      display 'unknown inc assign '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_Lzcnt bits {
  if bits = 128
      call    bi_lzcnt_128
  else if bits = 256
      call    bi_lzcnt_256
  else if bits = 512
      call    bi_lzcnt_512
  else
      display 'unknown lzcnt '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_Cmp bits {
  if bits = 128
      call    bi_cmp_128_128
  else if bits = 256
      call    bi_cmp_256_256
  else if bits = 512
      call    bi_cmp_512_512
  else
      display 'unknown cmp '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_Zero bits {
  if bits = 128
      call    bi_zero_128
  else if bits = 256
      call    bi_zero_256
  else if bits = 512
      call    bi_zero_512
  else if bits = 1024
      call    bi_zero_1024
  else
      display 'unknown zero '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_Copy bits {
  if bits = 128
      call    bi_copy_128
  else if bits = 256
      call    bi_copy_256
  else if bits = 512
      call    bi_copy_512
  else if bits = 1024
      call    bi_copy_1024
  else
      display 'unknown copy '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_SubAssign512X right_bits {
  if (right_bits) = 128
      call    bi_sub_assign_512_128
  else if (right_bits) = 256
      call    bi_sub_assign_512_256
  else if (right_bits) = 384
      call    bi_sub_assign_512_384
  else if (right_bits) = 448
      call    bi_sub_assign_512_512
  else if (right_bits) = 512
      call    bi_sub_assign_512_512
  else
      display 'unknown Call_SubAssign512X '
      DisplayDec (right_bits)
      display 13, 10
      err 
  end if
}

macro Call_SubAssign left_bits, right_bits {
;todo: implement asymmetric sub
  if left_bits = 128
      call    bi_sub_assign_128_128
  else if left_bits = 256
      call    bi_sub_assign_256_256
  else if left_bits = 384
      call    bi_sub_assign_384_384
  else if left_bits = 448
      call    bi_sub_assign_448_448
  else if left_bits = 512
;      call    bi_sub_assign_512_512
      Call_SubAssign512X right_bits
  else
      display 'unknown sub_assign '
      DisplayDec left_bits
      display 13, 10
      err 
  end if
}

macro Call_AddAssign bits {
  if bits = 64
      add     [rcx], rdx
  else if bits = 128
      call    bi_add_assign_128_128
  else if bits = 192
      call    bi_add_assign_192_192 
  else if bits = 256
      call    bi_add_assign_256_256
  else if bits = 384
      call    bi_add_assign_384_384
  else if bits = 448
      call    bi_add_assign_512_512
  else if bits = 512
      call    bi_add_assign_512_512
  else
      display 'unknown add assign '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_MulX128 bits {
  if bits = 128
      call    bi_mul_128_128
  else if bits = 256
      call    bi_mul_256_128
  else if bits = 512
      call    bi_mul_512_128
  else
      display 'unknown mul '
      DisplayDec bits
      display 13, 10
      err
  end if
}

macro Call_MulLowX128 bits {
  if bits = 128
      call    bi_mul_low_128_128
  else if bits = 256
      call    bi_mul_low_256_128
  else if bits = 512
      call    bi_mul_low_512_128
  else
      display 'unknown mul_low '
      DisplayDec bits
      display 13, 10
      err
  end if
}

macro Call_DivRem512X divisor_bits {
  if divisor_bits = 512
      call    bi_div_rem_512_512
  else if divisor_bits = 256
      call    bi_div_rem_512_256
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

macro Call_DivRem256X divisor_bits {
  if divisor_bits = 256
      call    bi_div_rem_256_256
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
  else if dividend_bits = 256
      Call_DivRem256X divisor_bits
  else if dividend_bits = 128
      Call_DivRem128X divisor_bits
  else
    display 'unknown div_rem '
    DisplayDec dividend_bits
    display ', '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}


