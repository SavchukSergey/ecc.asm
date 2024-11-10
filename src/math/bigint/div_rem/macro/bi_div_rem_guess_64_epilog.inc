macro DivRemGuess64_Epilog dividend_bits, divisor_bits {
if dividend_bits = divisor_bits
else
  mov      rcx, [.remainder]
  lea      rdx, [.remainder_temp]
  Fast_Copy divisor_bits
end if
  add      rsp, .locals_end - .locals_start
  ret
}