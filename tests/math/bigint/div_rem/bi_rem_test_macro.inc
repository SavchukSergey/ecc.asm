if ~ definite __bi_rem_macro

__bi_rem_macro equ 0

include '../../../asserts/index.inc'
include '../../../../src/math/bigint/macro/call.try_read_hex.inc'
include '../../../../src/math/bigint/macro/call.inc'

macro BiRemTestCoreMacro dividend_bits, divisor_bits {
virtual at rsp
.locals_start:
  BigInteger .dividend, dividend_bits
  BigInteger .divisor, dividend_bits
  BigInteger .remainder, dividend_bits

  .pointer rq 1

  .dividend_hex rq 1
  .divisor_hex rq 1
  .expected_remainder_hex rq 1

  AlignLocalsStackFrame
.locals_end:
end virtual

    sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__bi_div_rem_test_core_macro'
    CheckRegAligned rbx, '__bi_div_rem_test_core_macro rbx'


        mov     [.pointer], rbx
.loop:        
        mov     rbx, [.pointer]
        cmp     qword [rbx], 0
        je      .end

        lea     rcx, [rbx]
        lea     rdx, [rbx + (dividend_bits / 4)]
        lea     r8, [rbx + (dividend_bits / 4) * 3]

        mov     [.dividend_hex], rcx
        mov     [.divisor_hex], rdx
        mov     [.expected_remainder_hex], r8

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
        lea     r8, [.remainder]
        Call_Rem dividend_bits, divisor_bits

        mov     rcx, [.expected_remainder_hex]
        lea     rdx, [.remainder]
        CallBiAssertEqualHex dividend_bits

        add     [.pointer], (dividend_bits / 4) * 4
        jmp     .loop
.end:

        add     rsp, .locals_end - .locals_start
        ret
}

end if

macro BiRemTestPerformanceCoreMacro dividend_bits, divisor_bits {
virtual at rsp
.locals_start:
  BigInteger .dividend, dividend_bits
  BigInteger .divisor, dividend_bits
  BigInteger .remainder, dividend_bits

  .dividend_hex rq 1
  .divisor_hex rq 1
  .expected_remainder_hex rq 1

  .pointer rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__bi_div_rem_test_performance_core_macro'
    CheckRegAligned rbx, '__bi_div_rem_test_performance_core_macro rbx'

        mov     [.pointer], rbx
.loop:        
        mov     rbx, [.pointer]
        cmp     qword [rbx], 0
        je      .end

        lea     rcx, [rbx]
        lea     rdx, [rbx + (dividend_bits / 4)]
        lea     r8, [rbx + (dividend_bits / 4) * 3]

        mov     [.dividend_hex], rcx
        mov     [.divisor_hex], rdx
        mov     [.expected_remainder_hex], r8

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
        lea     r8, [.remainder]
        Call_Rem dividend_bits, divisor_bits
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_remainder_hex]
        lea     rdx, [.remainder]
        CallBiAssertEqualHex dividend_bits

        add     [.pointer], (dividend_bits / 4) * 4
        jmp     .loop
.end:

        add     rsp, .locals_end - .locals_start
        ret
}