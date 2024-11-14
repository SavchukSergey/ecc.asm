;@docs-ignore

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
  else if bits = 768
      call    bi_copy_768
  else if bits = 1024
      call    bi_copy_1024
  else
      display 'unknown copy '
      DisplayDec bits
      display 13, 10
      err 
  end if
}


macro Fast_Copy256 {
  if AVX2_ENABLED = 1
    vmovdqu ymm1, [rdx]
    vmovdqu [rcx], ymm1
  else
    Call_Copy 256
  end if
}

macro Fast_Copy512 {
  if AVX2_ENABLED = 1
    vmovdqu ymm1, [rdx]
    vmovdqu ymm2, [rdx + 32]
    vmovdqu [rcx], ymm1
    vmovdqu [rcx + 32], ymm2
  else
    Call_Copy 512
  end if
}

macro Fast_Copy bits {
  if bits = 256
      Fast_Copy256
  else if bits = 512
      Fast_Copy512
  else
      Call_Copy bits
  end if
}