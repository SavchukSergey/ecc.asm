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
