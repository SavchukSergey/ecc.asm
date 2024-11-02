include '../../../../src/math/bigint/div_rem/bi_div_rem_192_64.inc'

__bi_div_rem_192_64_test_core:
virtual at rsp
.locals_start:
  .dividend_hex rq 1
  .divisor_hex rq 1
  .expected_quotient_hex rq 1
  .expected_remainder_hex rq 1
  .dividend BigInteger192
  .divisor BigInteger192
  .quotient BigInteger192
  .remainder BigInteger192
  .pointer rq 1
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0

        mov     [.pointer], rbx
.loop:        
        mov     rbx, [.pointer]
        cmp     qword [rbx], 0
        je      .end

        lea     rcx, [rbx]
        lea     rdx, [rbx + __BIG_INTEGER_HEX_DIGITS_192 * 1]
        lea     r8, [rbx + __BIG_INTEGER_HEX_DIGITS_192 * 2]
        lea     r9, [rbx + __BIG_INTEGER_HEX_DIGITS_192 * 3]

        mov     [.dividend_hex], rcx
        mov     [.divisor_hex], rdx
        mov     [.expected_quotient_hex], r8
        mov     [.expected_remainder_hex], r9

        mov     rcx, [.dividend_hex]
        lea     rdx, [.dividend]
        call    bi_try_read_hex_192

        mov     rcx, [.divisor_hex]
        lea     rdx, [.divisor]
        call    bi_try_read_hex_192

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.dividend]
        mov     rdx, qword [.divisor + 0]
        lea     r8, [.quotient]
        lea     r9, [.remainder]
        call    bi_div_rem_192_64
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_quotient_hex]
        lea     rdx, [.quotient]
        call    bi_assert_equal_hex_192

        mov     rcx, [.expected_remainder_hex]
        lea     rdx, [.remainder]
        call    bi_assert_equal_hex_192

        add     [.pointer], __BIG_INTEGER_HEX_DIGITS_192 * 4
        jmp     .loop
.end:

        leave
        ret


__bi_div_rem_192_64_test:
        mov     rbx, __bi_div_rem_192_64_test_cases
        call    __bi_div_rem_192_64_test_core

        ret
