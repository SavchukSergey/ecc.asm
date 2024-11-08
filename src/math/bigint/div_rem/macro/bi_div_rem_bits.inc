macro DivRemBits dividend_bits, divisor_bits {
  DIV_REM_BITS_DIVIDEND_SIZE = dividend_bits
  DIV_REM_BITS_DIVISOR_SIZE = divisor_bits
  DIV_REM_BITS_QUOTIENT_SIZE = dividend_bits
  DIV_REM_BITS_REMAINDER_SIZE = dividend_bits

virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1
  BigInteger .divisor_shifted, DIV_REM_BITS_REMAINDER_SIZE

  .divisor_lzcnt rq 1
  .remainder_lzcnt rq 1
  .bit rq 1
  .total_shift rq 1

  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        PrologCheckStackAligned 'DivRemBits'
        CheckRegAligned rcx, 'DivRemBits rcx'
        CheckRegAligned rdx, 'DivRemBits rdx'
        CheckRegAligned r8, 'DivRemBits r8'
        CheckRegAligned r9, 'DivRemBits r9'

        mov     [.dividend], rcx
        mov     [.divisor], rdx
        mov     [.quotient], r8
        mov     [.remainder], r9

        mov     rcx, [.divisor]
        Call_Lzcnt DIV_REM_BITS_DIVISOR_SIZE
if DIV_REM_BITS_DIVISOR_SIZE < DIV_REM_BITS_REMAINDER_SIZE
        add     rax, DIV_REM_BITS_REMAINDER_SIZE - DIV_REM_BITS_DIVISOR_SIZE
end if
        mov     [.divisor_lzcnt], rax

; .divisor_shifted must have DIV_REM_BITS_REMAINDER_SIZE width
if DIV_REM_BITS_DIVISOR_SIZE < DIV_REM_BITS_REMAINDER_SIZE
        lea     rcx, [.divisor_shifted]
        mov     rdx, [.divisor]
        Call_Extend DIV_REM_BITS_REMAINDER_SIZE, DIV_REM_BITS_DIVISOR_SIZE
else
        lea     rcx, [.divisor_shifted]
        mov     rdx, [.divisor]
        Call_Copy DIV_REM_BITS_REMAINDER_SIZE
end if

        lea     rcx, [.divisor_shifted]
        mov     rdx, [.divisor_lzcnt]
        Call_ShlAssign DIV_REM_BITS_REMAINDER_SIZE

        mov     rcx, [.quotient]
        Call_Zero DIV_REM_BITS_QUOTIENT_SIZE

        mov     rcx, [.remainder]
        mov     rdx, [.dividend]
        Call_Copy DIV_REM_BITS_REMAINDER_SIZE

        mov     rax, [.divisor_lzcnt]
        mov     [.bit], rax

        mov     [.total_shift], 0
.loop:
        mov     rcx, [.remainder]
        Call_Lzcnt DIV_REM_BITS_REMAINDER_SIZE
        mov     [.remainder_lzcnt], rax

        sub     [.bit], rax
        jc      .loop_end

        mov     rcx, [.remainder]
        mov     rdx, [.remainder_lzcnt]
        Call_ShlAssign DIV_REM_BITS_REMAINDER_SIZE

        mov     rax, [.remainder_lzcnt]
        add     [.total_shift], rax

        mov     rcx, [.remainder]
        lea     rdx, [.divisor_shifted]
        Call_Cmp DIV_REM_BITS_REMAINDER_SIZE, DIV_REM_BITS_REMAINDER_SIZE
        jb      .bit_zero
.bit_one:
        mov     rcx, [.remainder]
        lea     rdx, [.divisor_shifted]
        Call_SubAssign DIV_REM_BITS_REMAINDER_SIZE, DIV_REM_BITS_REMAINDER_SIZE

        mov     rcx, [.quotient]
        mov     rdx, [.bit]
        Call_BitSet DIV_REM_BITS_QUOTIENT_SIZE
        
        jmp     .loop
.bit_zero:
        sub     [.bit], 1
        jc      .loop_end

 ;next shift guaranteed to be successful
        mov     rcx, [.remainder]
        Call_ShlAssignX1 DIV_REM_BITS_REMAINDER_SIZE ; 1 bit overflow but it does not matter

        inc     [.total_shift]

        mov     rcx, [.remainder]
        lea     rdx, [.divisor_shifted]
        Call_SubAssign DIV_REM_BITS_REMAINDER_SIZE, DIV_REM_BITS_REMAINDER_SIZE

        mov     rcx, [.quotient]
        mov     rdx, [.bit]
        Call_BitSet DIV_REM_BITS_QUOTIENT_SIZE

        jmp     .loop
.loop_end:

        mov     rcx, [.remainder]
        mov     rdx, [.total_shift]
        Call_ShrAssign DIV_REM_BITS_REMAINDER_SIZE

        add     rsp, .locals_end - .locals_start
        ret

}