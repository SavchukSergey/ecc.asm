if ~ definite __bi_call

__bi_call equ 0

include 'call.add.inc'
include 'call.div_rem.inc'
include 'call.inc.inc'
include 'call.mul.inc'
include 'call.rem.inc'
include 'call.shl.inc'
include 'call.try_read_hex.inc'


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
  else if bits = 320
      call    bi_extend_320_128
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
  ;todo: inline
  if delta_bits = 384
    lea     rcx, [rcx + source_bits / 8]
    call    bi_zero_384
  else if delta_bits = 320
    lea     rcx, [rcx + source_bits / 8]
    call    bi_zero_320
  else if delta_bits = 256
    lea     rcx, [rcx + source_bits / 8]
    call    bi_zero_256
  else if delta_bits = 192
    lea     rcx, [rcx + source_bits / 8]
    call    bi_zero_192
  else if delta_bits = 128
    lea     rcx, [rcx + source_bits / 8]
    call    bi_zero_128
  else if delta_bits = 64
    mov     qword [rcx + source_bits / 8], 0
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

macro Call_Lzcnt bits {
  if bits = 128
      call    bi_lzcnt_128
  else if bits = 192
      call    bi_lzcnt_192
  else if bits = 256
      call    bi_lzcnt_256
  else if bits = 320
      call    bi_lzcnt_320
  else if bits = 384
      call    bi_lzcnt_384
  else if bits = 448
      call    bi_lzcnt_448
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
  if bits = 128
      call    bi_cmp_192_128
  else if bits = 192
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
  else if bits = 192
      call    bi_cmp_256_192
  else if bits = 256
      call    bi_cmp_256_256
  else
      display 'unknown Call_Cmp256X '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_Cmp320X bits {
  if bits = 128
      call    bi_cmp_320_128
  else if bits = 192
      call    bi_cmp_320_192
  else if bits = 256
      call    bi_cmp_320_256
  else if bits = 320
      call    bi_cmp_320_320
  else
      display 'unknown Call_Cmp320X '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_Cmp384X bits {
  if bits = 128
      call    bi_cmp_384_128
  else if bits = 192
      call    bi_cmp_384_192
  else if bits = 256
      call    bi_cmp_384_256
  else if bits = 320
      call    bi_cmp_384_320
  else if bits = 384
      call    bi_cmp_384_384
  else
      display 'unknown Call_Cmp384X '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_Cmp448X bits {
  if bits = 128
      call    bi_cmp_448_128
  else if bits = 192
      call    bi_cmp_448_192
  else if bits = 256
      call    bi_cmp_448_256
  else if bits = 320
      call    bi_cmp_448_320
  else if bits = 384
      call    bi_cmp_448_384
  else if bits = 448
      call    bi_cmp_448_448
  else
      display 'unknown Call_Cmp448X '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_Cmp512X bits {
  if bits = 128
      call    bi_cmp_512_128
  else if bits = 192
      call    bi_cmp_512_192
  else if bits = 256
      call    bi_cmp_512_256
  else if bits = 320
      call    bi_cmp_512_320
  else if bits = 384
      call    bi_cmp_512_384
  else if bits = 448
      call    bi_cmp_512_448
  else if bits = 512
      call    bi_cmp_512_512
  else
      display 'unknown Call_Cmp512X '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

macro Call_Cmp576X bits {
  if bits = 576
      call    bi_cmp_576_576
  else
      display 'unknown Call_Cmp576X '
      DisplayDec bits
      display 13, 10
      err 
  end if
}


macro Call_Cmp left_bits, right_bits {
  if left_bits = 128
      Call_Cmp128X right_bits
  else if left_bits = 192
      Call_Cmp192X right_bits
  else if left_bits = 256
      Call_Cmp256X right_bits
  else if left_bits = 320
      Call_Cmp320X right_bits
  else if left_bits = 384
      Call_Cmp384X right_bits
  else if left_bits = 448
      Call_Cmp448X right_bits
  else if left_bits = 512
      Call_Cmp512X right_bits
  else if left_bits = 576
      Call_Cmp576X right_bits
  else
      display 'unknown Call_Cmp '
      DisplayDec left_bits
      display ', '
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
  else if bits = 320
      call    bi_zero_320
  else if bits = 384
      call    bi_zero_384
  else if bits = 448
      call    bi_zero_448
  else if bits = 512
      call    bi_zero_512
  else if bits = 576
      call    bi_zero_576
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
  else if bits = 320
      call    bi_copy_320
  else if bits = 384
      call    bi_copy_384
  else if bits = 448
      call    bi_copy_448
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

macro Call_SubAssign_512_X right_bits {
  if (right_bits) = 128
      call    bi_sub_assign_512_128
  else if (right_bits) = 192
      call    bi_sub_assign_512_192
  else if (right_bits) = 256
      call    bi_sub_assign_512_256
  else if (right_bits) = 320
      call    bi_sub_assign_512_320
  else if (right_bits) = 384
      call    bi_sub_assign_512_384
  else if (right_bits) = 448
      call    bi_sub_assign_512_448
  else if (right_bits) = 512
      call    bi_sub_assign_512_512
  else
      display 'unknown Call_SubAssign_512_X '
      DisplayDec (right_bits)
      display 13, 10
      err 
  end if
}

macro Call_SubAssign_448_X right_bits {
  if (right_bits) = 128
      call    bi_sub_assign_448_128
  else if (right_bits) = 192
      call    bi_sub_assign_448_192
  else if (right_bits) = 256
      call    bi_sub_assign_448_256
  else if (right_bits) = 320
      call    bi_sub_assign_448_320
  else if (right_bits) = 384
      call    bi_sub_assign_448_384
  else if (right_bits) = 448
      call    bi_sub_assign_448_448
  else
      display 'unknown Call_SubAssign_448_X '
      DisplayDec (right_bits)
      display 13, 10
      err 
  end if
}

macro Call_SubAssign_384_X right_bits {
  if (right_bits) = 128
      call    bi_sub_assign_384_128
  else if (right_bits) = 192
      call    bi_sub_assign_384_192
  else if (right_bits) = 256
      call    bi_sub_assign_384_256
  else if (right_bits) = 320
      call    bi_sub_assign_384_320
  else if (right_bits) = 384
      call    bi_sub_assign_384_384
  else
      display 'unknown Call_SubAssign_384_X '
      DisplayDec (right_bits)
      display 13, 10
      err 
  end if
}

macro Call_SubAssign_320_X right_bits {
  if (right_bits) = 128
      call    bi_sub_assign_320_128
  else if (right_bits) = 192
      call    bi_sub_assign_320_192
  else if (right_bits) = 256
      call    bi_sub_assign_320_256
  else if (right_bits) = 320
      call    bi_sub_assign_320_320
  else
      display 'unknown Call_SubAssign_320_X '
      DisplayDec (right_bits)
      display 13, 10
      err 
  end if
}

macro Call_SubAssign_256_X right_bits {
  if (right_bits) = 128
      call    bi_sub_assign_256_128
  else if (right_bits) = 192
      call    bi_sub_assign_256_192
  else if (right_bits) = 256
      call    bi_sub_assign_256_256
  else
      display 'unknown Call_SubAssign_256_X '
      DisplayDec (right_bits)
      display 13, 10
      err 
  end if
}

macro Call_SubAssign_192_X right_bits {
  if (right_bits) = 128
      call    bi_sub_assign_192_128
  else if (right_bits) = 192
      call    bi_sub_assign_192_192
  else
      display 'unknown Call_SubAssign_192_X '
      DisplayDec (right_bits)
      display 13, 10
      err 
  end if
}

macro Call_SubAssign left_bits, right_bits {
  if left_bits = 128
      call    bi_sub_assign_128_128
  else if left_bits = 192
      Call_SubAssign_192_X right_bits
  else if left_bits = 256
      Call_SubAssign_256_X right_bits
  else if left_bits = 320
      Call_SubAssign_320_X right_bits
  else if left_bits = 384
      Call_SubAssign_384_X right_bits
  else if left_bits = 448
      Call_SubAssign_448_X right_bits
  else if left_bits = 512
      Call_SubAssign_512_X right_bits
  else
      display 'unknown Call_SubAssign '
      DisplayDec left_bits
      display ', '
      DisplayDec right_bits
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