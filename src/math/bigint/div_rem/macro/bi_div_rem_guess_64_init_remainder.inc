macro DivRemGuess64_InitRemainder dividend_bits, divisor_bits {
    mov     rcx, [.remainder]
    mov     rdx, [.dividend]
if dividend_bits = 512
  if AVX2_ENABLED = 1
    vmovdqu ymm1, [rdx]
    vmovdqu ymm2, [rdx + 32]
    vmovdqu [rcx], ymm1
    vmovdqu [rcx + 32], ymm2
  else
    Call_Copy dividend_bits
  end if
else if dividend_bits = 256
  if AVX2_ENABLED = 1
    vmovdqu ymm1, [rdx]
    vmovdqu [rcx], ymm1
  else
    Call_Copy dividend_bits
  end if
else
    Call_Copy dividend_bits
end if
}
