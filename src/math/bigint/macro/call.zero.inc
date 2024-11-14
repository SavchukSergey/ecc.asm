;@docs-ignore

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


macro Fast_Zero256 {
  if AVX2_ENABLED = 1
    vpxor   ymm1, ymm1, ymm1
    vmovdqu [rcx], ymm1
  else
    xor     rax, rax
    mov     [rcx], rax
    mov     [rcx + 8], rax
    mov     [rcx + 16], rax
    mov     [rcx + 24], rax
  end if
}

macro Fast_Zero512 {
  if AVX2_ENABLED = 1
    vpxor   ymm1, ymm1, ymm1
    vmovdqu [rcx], ymm1
    vmovdqu [rcx + 32], ymm1
  else
    xor     rax, rax
    mov     [rcx], rax
    mov     [rcx + 8], rax
    mov     [rcx + 16], rax
    mov     [rcx + 24], rax
    mov     [rcx + 32], rax
    mov     [rcx + 40], rax
    mov     [rcx + 48], rax
    mov     [rcx + 56], rax
  end if
}

macro Fast_Zero bits {
  if bits = 256
      Fast_Zero256
  else if bits = 512
      Fast_Zero512
  else
      Call_Zero bits
  end if
}