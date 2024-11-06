if ~ definite __bi_call_add

__bi_call_add equ 0

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
  else if right_bits = 128
      call    bi_add_assign_192_128
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

macro Call_AddAssign320X right_bits {
  if right_bits = 128
      call    bi_add_assign_320_128
  else if right_bits = 192
      call    bi_add_assign_320_192
  else if right_bits = 256
      call    bi_add_assign_320_256
  else if right_bits = 320
      call    bi_add_assign_320_320
  else
      display 'unknown Call_AddAssign320X '
      DisplayDec right_bits
      display 13, 10
      err 
  end if
}

macro Call_AddAssign384X right_bits {
  if right_bits = 128
      call    bi_add_assign_384_128
  else if right_bits = 192
      call    bi_add_assign_384_192
  else if right_bits = 256
      call    bi_add_assign_384_256
  else if right_bits = 320
      call    bi_add_assign_384_320
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
  if right_bits = 128
      call    bi_add_assign_448_128
  else if right_bits = 256
      call    bi_add_assign_448_256
  else if right_bits = 320
      call    bi_add_assign_448_320
  else if right_bits = 448
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
  else if left_bits = 320
    Call_AddAssign320X right_bits
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

end if