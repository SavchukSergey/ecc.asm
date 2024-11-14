;@docs-ignore

if ~ definite __bi_call_rnd

__bi_call_rnd equ 0

macro Call_Rnd bits {
  if bits = 64
      call    bi_rnd_64
  else if bits = 128
      call    bi_rnd_128
  else if bits = 192
      call    bi_rnd_192
  else if bits = 256
      call    bi_rnd_256
  else if bits = 320
      call    bi_rnd_320
  else if bits = 384
      call    bi_rnd_384
  else if bits = 448
      call    bi_rnd_448
  else if bits = 512
      call    bi_rnd_512
  else if bits = 1024
      call    bi_rnd_1024
  else
      display 'unknown Call_Rnd '
      DisplayDec bits
      display 13, 10
      err 
  end if
}

end if