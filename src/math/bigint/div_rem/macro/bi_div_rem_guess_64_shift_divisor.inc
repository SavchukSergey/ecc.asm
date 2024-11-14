;@docs-ignore

macro DivRemGuess64_ShiftDivisor dividend_bits, divisor_bits {
;shift divisor to the left, so the most meaningful bit is always the highest bit
if divisor_bits = 128
      mov     r8, [.divisor]
      mov     rdx, [r8 + 8]
      mov     rax, [r8 + 0]
      lzcnt   rcx, rdx
      shld    rdx, rax, cl
      mov     qword [.divisor_shifted], rdx
else
    mov     rax, [.divisor_lzcnt]
  if DIV_REM_GUESS_IMAGINARY_BITS > 0
    sub     rax, DIV_REM_GUESS_IMAGINARY_BITS    ;todo: remove
  end if
  ;todo: if divisor is 128 bit can be simplified
; divisor_bits is at least 128-bit wide
      mov     rcx, rax
      and     rax, -64
      shr     rax, 3                              ; rax now is count of highest zero qwords multiplied by 8
      mov     rdx, (divisor_bits shr 3) - 16      ; we need two qwords to build one
      sub     rdx, rax

      mov     rax, [.divisor]
      mov     r8, [rax + rdx]
      mov     r9, [rax + rdx + 8]
      shld    r9, r8, cl
      mov     qword [.divisor_shifted], r9

end if
}