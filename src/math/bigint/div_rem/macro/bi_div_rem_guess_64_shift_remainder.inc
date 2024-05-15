macro DivRemGuess64_ShiftRemainder dividend_bits, divisor_bits {
;shift remainder to the left, so the most meaningful bit is always the highest bit
      mov     rcx, [.remainder]
      Call_Lzcnt dividend_bits
      cmp     rax, [.divisor_lzcnt]
      jae     .recheck_once

      mov     rcx, rax
      mov     rdx, [.remainder]
;dividend is now wider than 128 bits, we can skip some checks here

; scale down guess to trim fractional part of division
      xor     r9, r9
      xor     r8, r8
      mov     rax, [.divisor_lzcnt]
      sub     rax, 64                    ;partial remainder was 128-bit wide, but partial divisor only 64 bit-wide
      sub     rax, rcx                   ;rax - downscale
      cmovns  r9, rax
      cmovs   r8, rax
      mov     [.correction], r9
      add     rcx, r8
      jns     .remainder_normal_boost
.remainder_overboost:
      neg     rcx
      mov     r8, [rdx + (dividend_bits shr 3) - 16]
      mov     r9, [rdx + (dividend_bits shr 3) - 8]
      shrd    r8, r9, cl
      shr     r9, cl
      mov     qword [.remainder_shifted], r8
      mov     qword [.remainder_shifted + 8], r9
      jmp     .correction_ready


.remainder_normal_boost:
      mov     rax, rcx
      and     rax, -64
      sar     rax, 3                              ; rax now is count of highest zero qwords multiplied by 8
      add     rdx, (dividend_bits shr 3) - 24     ; we need three qwords to build two
      sub     rdx, rax
; remainder has at least same bits as divisor, and divisor is at least 65-bit wide
; so at least two qwords are accessible
; but third one may be out of range
      mov     r9, [rdx]
      mov     r8, [rdx + 8]
      mov     rax, [rdx + 16]
      shld    rax, r8, cl
      shld    r8, r9, cl
      mov     qword [.remainder_shifted], r8
      mov     qword [.remainder_shifted + 8], rax
.correction_ready:



}