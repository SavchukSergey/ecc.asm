include '../src/math/bigint/div_rem/bi_div_rem_128_128.inc'

__bi_div_rem_128_128_test_core:
virtual at rsp
.locals_start:
  BigInteger128 .dividend
  BigInteger128 .divisor
  BigInteger128 .quotient
  BigInteger128 .remainder
  .dividend_hex rq 1
  .divisor_hex rq 1
  .expected_quotient_hex rq 1
  .expected_remainder_hex rq 1
  .pointer rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__bi_div_rem_128_128_test_core'
    CheckRegAligned rbx, '__bi_div_rem_128_128_test_core rbx'

        mov     [.pointer], rbx
.loop:        
        mov     rbx, [.pointer]
        cmp     qword [rbx], 0
        je      .end

        lea     rcx, [rbx]
        lea     rdx, [rbx + 32]
        lea     r8, [rbx + 64]
        lea     r9, [rbx + 96]

        mov     [.dividend_hex], rcx
        mov     [.divisor_hex], rdx
        mov     [.expected_quotient_hex], r8
        mov     [.expected_remainder_hex], r9

        mov     rcx, [.dividend_hex]
        lea     rdx, [.dividend]
        call    bi_try_read_hex_128

        mov     rcx, [.divisor_hex]
        lea     rdx, [.divisor]
        call    bi_try_read_hex_128

        lea     rcx, [.dividend]
        lea     rdx, [.divisor]
        lea     r8, [.quotient]
        lea     r9, [.remainder]
        call    bi_div_rem_128_128

        mov     rcx, [.expected_quotient_hex]
        lea     rdx, [.quotient]
        call    bi_assert_equal_hex_128

        mov     rcx, [.expected_remainder_hex]
        lea     rdx, [.remainder]
        call    bi_assert_equal_hex_128

        add     [.pointer], 128
        jmp     .loop
.end:

        add     rsp, .locals_end - .locals_start
        ret

__bi_div_rem_128_128_test_measure_core:
virtual at rsp
.locals_start:
  BigInteger128 .dividend
  BigInteger128 .divisor
  BigInteger128 .quotient
  BigInteger128 .remainder
  .dividend_hex rq 1
  .divisor_hex rq 1
  .expected_quotient_hex rq 1
  .expected_remainder_hex rq 1
  .pointer rq 1
  AlignLocalsStackFrame

.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__bi_div_rem_128_128_test_measure_core'
    CheckRegAligned rbx, '__bi_div_rem_128_128_test_measure_core rbx'

        mov     [.pointer], rbx
.loop:        
        mov     rbx, [.pointer]
        cmp     qword [rbx], 0
        je      .end

        lea     rcx, [rbx]
        lea     rdx, [rbx + 32]
        lea     r8, [rbx + 64]
        lea     r9, [rbx + 96]

        mov     [.dividend_hex], rcx
        mov     [.divisor_hex], rdx
        mov     [.expected_quotient_hex], r8
        mov     [.expected_remainder_hex], r9

        mov     rcx, [.dividend_hex]
        lea     rdx, [.dividend]
        call    bi_try_read_hex_128

        mov     rcx, [.divisor_hex]
        lea     rdx, [.divisor]
        call    bi_try_read_hex_128

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.dividend]
        lea     rdx, [.divisor]
        lea     r8, [.quotient]
        lea     r9, [.remainder]
        call    bi_div_rem_128_128
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_quotient_hex]
        lea     rdx, [.quotient]
        call    bi_assert_equal_hex_128

        mov     rcx, [.expected_remainder_hex]
        lea     rdx, [.remainder]
        call    bi_assert_equal_hex_128

        add     [.pointer], 128
        jmp     .loop
.end:

        add     rsp, .locals_end - .locals_start
        ret


__bi_div_rem_128_128_test:
        push    rbx

        mov     rbx, __bi_div_rem_128_64_test_cases
        call    __bi_div_rem_128_128_test_core

        mov     rbx, __bi_div_rem_128_128_test_cases
        call    __bi_div_rem_128_128_test_measure_core

        pop     rbx
        ret
