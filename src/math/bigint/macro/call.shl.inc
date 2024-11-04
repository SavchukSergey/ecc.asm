if ~ definite __bi_call_shl

__bi_call_shl equ 0

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

macro Call_ShlAssign bits {
  if bits = 64
      shl     qword [rcx], bits
  else if bits = 128
      call    bi_shl_assign_128
  else if bits = 192
      call    bi_shl_assign_192
  else if bits = 256
      call    bi_shl_assign_256
  else if bits = 320
      call    bi_shl_assign_320
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

end if