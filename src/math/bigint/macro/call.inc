if ~ definite __bi_call

__bi_call equ 0

macro Call_Shl bits {
  if bits = 128
      call    bi_shl_128
  else if bits = 256
      call    bi_shl_256
  else if bits = 512
      call    bi_shl_512
  else
      display 'unknown Call_Shl '
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
      display 'unknown Call_ShlAssign '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_ShlAssignX1 bits {
  if bits = 128
      call    bi_shl_assign_128_1
  else if bits = 256
      call    bi_shl_assign_256_1
  else if bits = 512
      call    bi_shl_assign_512_1
  else
      display 'unknown Call_ShlAssignX1 '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_Shr bits {
  if bits = 128
      call    bi_shr_128
  else if bits = 256
      call    bi_shr_256
  else if bits = 512
      call    bi_shr_512
  else
      display 'unknown Call_Shr '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_ShrAssign bits {
  if bits = 64
      shr     qword [rcx], bits
  else if bits = 128
      call    bi_shr_assign_128
  else if bits = 192
      call    bi_shr_assign_192
  else if bits = 256
      call    bi_shr_assign_256
  else if bits = 384
      call    bi_shr_assign_384
  else if bits = 448
      call    bi_shr_assign_448
  else if bits = 512
      call    bi_shr_assign_512
  else
      display 'unknown Call_ShrAssign '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_ExtendAssignX64 bits {
  if bits = 128
      mov     qword [rcx + 8], 0
;      call    bi_extend_assign_128_64
  else if bits = 192
      mov     qword [rcx + 8], 0
      mov     qword [rcx + 16], 0
;      call    bi_extend_assign_192_64
  else if bits = 256
      mov     qword [rcx + 8], 0
      mov     qword [rcx + 16], 0
      mov     qword [rcx + 24], 0
;      call    bi_extend_assign_256_64
  else if bits = 384
      call    bi_extend_assign_384_64
  else if bits = 448
      call    bi_extend_assign_448_64
  else if bits = 512
      call    bi_extend_assign_512_64
  else
      display 'unknown Call_ExtendAssignX64 '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_ExtendX64 bits {
  if bits = 192
      call    bi_extend_192_64
  else if bits = 256
      call    bi_extend_256_64
  else if bits = 384
      call    bi_extend_384_64
  else if bits = 448
      call    bi_extend_448_64
  else if bits = 512
      call    bi_extend_512_64
  else
      display 'unknown Call_ExtendX64 '
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
      display 'unknown Call_ExtendX128 '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_ExtendX256 bits {
  if bits = 512
      call    bi_extend_512_256
  else
      display 'unknown Call_ExtendX256 '
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
      display 'unknown Call_ExtendAssign '
      DisplayDec target_bits
      display ', '
      DisplayDec source_bits
      display 13, 10
      err 
  end if
}

macro Call_Extend target_bits, source_bits {
  delta_bits = target_bits - source_bits
  if source_bits = 128
    Call_ExtendX128 target_bits
  else if source_bits = 256
    Call_ExtendX256 target_bits
  else
      display 'unknown Call_Assign '
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
  else if bits = 192
      call    bi_lzcnt_192
  else if bits = 256
      call    bi_lzcnt_256
  else if bits = 512
      call    bi_lzcnt_512
  else
      display 'unknown Call_Lzcnt '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_Cmp128X bits {
  if bits = 128
      call    bi_cmp_128_128
  else
      display 'unknown Call_Cmp128X '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_Cmp192X bits {
  if bits = 192
      call    bi_cmp_192_192
  else
      display 'unknown Call_Cmp192X '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_Cmp256X bits {
  if bits = 128
      call    bi_cmp_256_128
  else if bits = 256
      call    bi_cmp_256_256
  else
      display 'unknown Call_Cmp256X '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_Cmp512X bits {
  if bits = 128
      call    bi_cmp_512_128
  else if bits = 256
      call    bi_cmp_512_256
  else if bits = 512
      call    bi_cmp_512_512
  else
      display 'unknown Call_Cmp512X '
      DisplayDec bits
      display 13, 10
      err 
  end if
}


macro Call_Cmp left_bits, right_bits {
  if left_bits = 128
      Call_Cmp128X right_bits
  else if left_bits = 256
      Call_Cmp256X right_bits
  else if left_bits = 512
      Call_Cmp512X right_bits
  else
      display 'unknown Call_Cmp '
      DisplayDec left_bits
      DisplayDec ', '
      DisplayDec right_bits
      display 13, 10
      err 
  end if
}


macro Call_Zero bits {
  if bits = 128
      call    bi_zero_128
  else if bits = 192
      call    bi_zero_192
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
  else if bits = 192
      call    bi_copy_192
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
      display 'unknown Call_SubAssign '
      DisplayDec left_bits
      display ', '
      DisplayDec right_bits
      display 13, 10
      err 
  end if
}

macro Call_AddAssign64X right_bits {
  if right_bits = 64
      add     [rcx], rdx
  else
      display 'unknown Call_AddAssign64X '
      DisplayDec right_bits
      display 13, 10
      err 
  end if
}

macro Call_AddAssign128X right_bits {
  if right_bits = 128
      call    bi_add_assign_128_128
  else
      display 'unknown Call_AddAssign128X '
      DisplayDec right_bits
      display 13, 10
      err 
  end if
}

macro Call_AddAssign192X right_bits {
  if right_bits = 192
      call    bi_add_assign_192_192
  else
      display 'unknown Call_AddAssign192X '
      DisplayDec right_bits
      display 13, 10
      err 
  end if
}

macro Call_AddAssign256X right_bits {
  if right_bits = 128
      call    bi_add_assign_256_128
  else if right_bits = 256
      call    bi_add_assign_256_256
  else
      display 'unknown Call_AddAssign256X '
      DisplayDec right_bits
      display 13, 10
      err 
  end if
}

macro Call_AddAssign384X right_bits {
  if right_bits = 128
      call    bi_add_assign_384_128
  else if right_bits = 256
      call    bi_add_assign_384_256
  else if right_bits = 384
      call    bi_add_assign_384_384
  else
      display 'unknown Call_AddAssign384X '
      DisplayDec right_bits
      display 13, 10
      err 
  end if
}

macro Call_AddAssign448X right_bits {
  if right_bits = 448
      call    bi_add_assign_448_448
  else
      display 'unknown Call_AddAssign448X '
      DisplayDec right_bits
      display 13, 10
      err 
  end if
}

macro Call_AddAssign512X right_bits {
  if right_bits = 256
      call    bi_add_assign_512_256
  else if right_bits = 512
      call    bi_add_assign_512_512
  else
      display 'unknown Call_AddAssign512X '
      DisplayDec right_bits
      display 13, 10
      err 
  end if
}

macro Call_AddAssignX128 bits {
  if bits = 128
      call    bi_add_assign_128_128
  else if bits = 192
      call    bi_add_assign_192_128
  else if bits = 256
      call    bi_add_assign_256_128
  else if bits = 384
      call    bi_add_assign_384_128
  else if bits = 448
      call    bi_add_assign_512_128
  else if bits = 512
      call    bi_add_assign_512_128
  else
      display 'unknown Call_AddAssignX128 '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_AddAssign left_bits, right_bits {
  if left_bits = 64
    Call_AddAssign64X right_bits
  else if left_bits = 128
    Call_AddAssign128X right_bits
  else if left_bits = 192
    Call_AddAssign192X right_bits
  else if left_bits = 256
    Call_AddAssign256X right_bits
  else if left_bits = 384
    Call_AddAssign384X right_bits
  else if left_bits = 448
    Call_AddAssign448X right_bits
  else if left_bits = 512
    Call_AddAssign512X right_bits
  else
      display 'unknown Call_AddAssign '
      DisplayDec left_bits
      display ', '
      DisplayDec right_bits
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
      display 'unknown Call_MulX128 '
      DisplayDec bits
      display 13, 10
      err
  end if
}

macro Call_MulX64 bits {
  if bits = 128
      call    bi_mul_128_64
  else if bits = 192
      call    bi_mul_192_64
  else if bits = 256
      call    bi_mul_256_64
  else if bits = 512
      call    bi_mul_512_64
  else
      display 'unknown Call_MulX64 '
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
      display 'unknown Call_MulLowX128 '
      DisplayDec bits
      display 13, 10
      err
  end if
}

macro Call_MulLowX64 bits {
  if bits = 128
      call    bi_mul_low_128_64
  else if bits = 256
      call    bi_mul_low_256_64
  else if bits = 512
      call    bi_mul_low_512_64
  else
      display 'unknown Call_MulLowX64 '
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

macro Call_Rem256X divisor_bits {
  if divisor_bits = 256
      call    bi_rem_256_256
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

macro Call_Rem dividend_bits, divisor_bits {
  if dividend_bits = 512
      Call_Rem512X divisor_bits
  else if dividend_bits = 256
      Call_Rem256X divisor_bits
  else if dividend_bits = 128
      Call_Rem128X divisor_bits
  else
    display 'unknown rem '
    DisplayDec dividend_bits
    display ', '
    DisplayDec divisor_bits
    display 13, 10
    err
  end if
}


macro Call_BitSet bits {
  if bits = 256
        call    bi_bit_set_256
  else if bits = 512
        call    bi_bit_set_512
  else
    display 'unknown Call_BitSet '
    DisplayDec bits
    display 13, 10
    err
  end if
}

end if