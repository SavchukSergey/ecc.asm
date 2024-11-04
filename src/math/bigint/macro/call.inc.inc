if ~ definite __bi_call_inc

__bi_call_inc equ 0

macro Call_IncAssign bits {
  if bits = 64
      inc     qword [rcx]
  else if bits = 128
      call    bi_inc_assign_128
  else if bits = 192
      call    bi_inc_assign_192
  else if bits = 256
      call    bi_inc_assign_256
  else if bits = 320
      call    bi_inc_assign_320
  else if bits = 384
      call    bi_inc_assign_384
  else if bits = 448
      call    bi_inc_assign_448
  else if bits = 512
      call    bi_inc_assign_512
  else
      display 'unknown Call_IncAssign '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

end if