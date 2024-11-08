if ~ definite __bi_div_rem_macro

__bi_div_rem_macro equ 0

macro BiDivRemTestCoreMacro dividend_bits, divisor_bits {
virtual at rsp
.locals_start:
  BigInteger .dividend, dividend_bits
  BigInteger .divisor, dividend_bits
  GuardPreField
  BigInteger .quotient, dividend_bits
  BigInteger .remainder, dividend_bits
  GuardPostField
  .pointer rq 1

  .dividend_hex rq 1
  .divisor_hex rq 1
  .expected_quotient_hex rq 1
  .expected_remainder_hex rq 1

  AlignLocalsStackFrame
.locals_end:
end virtual

    sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__bi_div_rem_test_core_macro'
    CheckRegAligned rbx, '__bi_div_rem_test_core_macro rbx'

        GuardInit

        mov     [.pointer], rbx
.loop:        
        mov     rbx, [.pointer]
        cmp     qword [rbx], 0
        je      .end

        lea     rcx, [rbx]
        lea     rdx, [rbx + (dividend_bits / 4)]
        lea     r8, [rbx + (dividend_bits / 4) * 2]
        lea     r9, [rbx + (dividend_bits / 4) * 3]

        mov     [.dividend_hex], rcx
        mov     [.divisor_hex], rdx
        mov     [.expected_quotient_hex], r8
        mov     [.expected_remainder_hex], r9

        mov     rcx, [.dividend_hex]
        lea     rdx, [.dividend]
        CallBiTryReadHex dividend_bits

        mov     rcx, [.divisor_hex]
        lea     rdx, [.divisor]
        CallBiTryReadHex dividend_bits

        lea     rcx, [.dividend]
  if divisor_bits > 64
        lea     rdx, [.divisor]
  else
        mov     rdx, [.divisor]
  end if
        lea     r8, [.quotient]
        lea     r9, [.remainder]
        Call_DivRem dividend_bits, divisor_bits

        mov     rcx, [.expected_quotient_hex]
        lea     rdx, [.quotient]
        CallBiAssertEqualHex dividend_bits

        mov     rcx, [.expected_remainder_hex]
        add     rcx, (dividend_bits - divisor_bits) / 4
if divisor_bits > 64
        lea     rdx, [.remainder]
else
        mov     rdx, [.remainder]
end if
        CallBiAssertEqualHex divisor_bits

        add     [.pointer], (dividend_bits / 4) * 4
        jmp     .loop
.end:

        GuardCheck

        add     rsp, .locals_end - .locals_start
        ret
}

end if

macro BiDivRemTestPerformanceCoreMacro dividend_bits, divisor_bits {
virtual at rsp
.locals_start:
  BigInteger .dividend, dividend_bits
  BigInteger .divisor, dividend_bits
  GuardPreField
  BigInteger .quotient, dividend_bits
  BigInteger .remainder, dividend_bits
  GuardPostField

  .dividend_hex rq 1
  .divisor_hex rq 1
  .expected_quotient_hex rq 1
  .expected_remainder_hex rq 1

  .pointer rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__bi_div_rem_test_performance_core_macro'
    CheckRegAligned rbx, '__bi_div_rem_test_performance_core_macro rbx'

        GuardInit

        mov     [.pointer], rbx
.loop:        
        mov     rbx, [.pointer]
        cmp     qword [rbx], 0
        je      .end

        lea     rcx, [rbx]
        lea     rdx, [rbx + (dividend_bits / 4)]
        lea     r8, [rbx + (dividend_bits / 4) * 2]
        lea     r9, [rbx + (dividend_bits / 4) * 3]

        mov     [.dividend_hex], rcx
        mov     [.divisor_hex], rdx
        mov     [.expected_quotient_hex], r8
        mov     [.expected_remainder_hex], r9

        mov     rcx, [.dividend_hex]
        lea     rdx, [.dividend]
        CallBiTryReadHex dividend_bits

        mov     rcx, [.divisor_hex]
        lea     rdx, [.divisor]
        CallBiTryReadHex dividend_bits

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.dividend]
  if divisor_bits > 64
        lea     rdx, [.divisor]
  else
        mov     rdx, [.divisor]
  end if
        lea     r8, [.quotient]
        lea     r9, [.remainder]
        Call_DivRem dividend_bits, divisor_bits
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_quotient_hex]
        lea     rdx, [.quotient]
        CallBiAssertEqualHex dividend_bits

        mov     rcx, [.expected_remainder_hex]
        add     rcx, (dividend_bits - divisor_bits) / 4
if divisor_bits > 64
        lea     rdx, [.remainder]
else
        mov     rdx, [.remainder]
end if
        CallBiAssertEqualHex divisor_bits

        add     [.pointer], (dividend_bits / 4) * 4
        jmp     .loop
.end:

        GuardCheck

        add     rsp, .locals_end - .locals_start
        ret
}