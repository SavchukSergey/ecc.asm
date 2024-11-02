include '../../../../src/math/bigint/div_rem/bi_div_rem_256_128.inc'

include 'bi_div_rem_test_macro.inc'

__bi_div_rem_256_128_test_core:
BiDivRemTestCoreMacro 256, 128

__bi_div_rem_256_128_test_measure_core:
virtual at rsp
.locals_start:
  .dividend BigInteger256
  .divisor BigInteger256
  .quotient BigInteger256
  .remainder BigInteger256
  .dividend_hex rq 1
  .divisor_hex rq 1
  .expected_quotient_hex rq 1
  .expected_remainder_hex rq 1
  .pointer rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__bi_div_rem_256_128_test_measure_core'
    CheckRegAligned rbx, '__bi_div_rem_256_128_test_measure_core rbx'

        mov     [.pointer], rbx
.loop:        
        mov     rbx, [.pointer]
        cmp     qword [rbx], 0
        je      .end

        lea     rcx, [rbx]
        lea     rdx, [rbx + __BIG_INTEGER_HEX_DIGITS_256]
        lea     r8, [rbx + __BIG_INTEGER_HEX_DIGITS_256 * 2]
        lea     r9, [rbx + __BIG_INTEGER_HEX_DIGITS_256 * 3]

        mov     [.dividend_hex], rcx
        mov     [.divisor_hex], rdx
        mov     [.expected_quotient_hex], r8
        mov     [.expected_remainder_hex], r9

        mov     rcx, [.dividend_hex]
        lea     rdx, [.dividend]
        call    bi_try_read_hex_256

        mov     rcx, [.divisor_hex]
        lea     rdx, [.divisor]
        call    bi_try_read_hex_256

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.dividend]
        lea     rdx, [.divisor]
        lea     r8, [.quotient]
        lea     r9, [.remainder]
        call    bi_div_rem_256_128
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_quotient_hex]
        lea     rdx, [.quotient]
        call    bi_assert_equal_hex_256

        mov     rcx, [.expected_remainder_hex]
        lea     rdx, [.remainder]
        call    bi_assert_equal_hex_256

        add     [.pointer], __BIG_INTEGER_HEX_DIGITS_256 * 4
        jmp     .loop
.end:

        add     rsp, .locals_end - .locals_start
        ret


__bi_div_rem_256_128_test:
        push    rbx

        mov     rbx, __bi_div_rem_256_64_test_cases
        call    __bi_div_rem_256_128_test_core

        mov     rbx, __bi_div_rem_256_128_test_cases
        call    __bi_div_rem_256_128_test_measure_core

        pop     rbx
        ret
