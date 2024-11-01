include '../../../../src/math/bigint/div_rem/bi_div_rem_512_256.inc'

__bi_div_rem_512_256_test_core:
virtual at rsp
.locals_start:
  .dividend_hex rq 1
  .divisor_hex rq 1
  .expected_quotient_hex rq 1
  .expected_remainder_hex rq 1
  .dividend BigInteger512
  .divisor BigInteger512
  .quotient BigInteger512
  .remainder BigInteger512
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
        lea     rdx, [rbx + 128]
        lea     r8, [rbx + 256]
        lea     r9, [rbx + 384]

        mov     [.dividend_hex], rcx
        mov     [.divisor_hex], rdx
        mov     [.expected_quotient_hex], r8
        mov     [.expected_remainder_hex], r9

        mov     rcx, [.dividend_hex]
        lea     rdx, [.dividend]
        call    bi_try_read_hex_512

        mov     rcx, [.divisor_hex]
        lea     rdx, [.divisor]
        call    bi_try_read_hex_512

        lea     rcx, [.dividend]
        lea     rdx, [.divisor + 0]
        lea     r8, [.quotient]
        lea     r9, [.remainder]
        call    bi_div_rem_512_256

        mov     rcx, [.expected_quotient_hex]
        lea     rdx, [.quotient]
        call    bi_assert_equal_hex_512

        mov     rcx, [.expected_remainder_hex]
        lea     rdx, [.remainder]
        call    bi_assert_equal_hex_512

        add     [.pointer], 512
        jmp     .loop
.end:

        leave
        ret

__bi_div_rem_512_256_test_measure_core:
virtual at rsp
.locals_start:
  .dividend_hex rq 1
  .divisor_hex rq 1
  .expected_quotient_hex rq 1
  .expected_remainder_hex rq 1
  .dividend BigInteger512
  .divisor BigInteger512
  .quotient BigInteger512
  .remainder BigInteger512
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
        lea     rdx, [rbx + 128]
        lea     r8, [rbx + 256]
        lea     r9, [rbx + 384]

        mov     [.dividend_hex], rcx
        mov     [.divisor_hex], rdx
        mov     [.expected_quotient_hex], r8
        mov     [.expected_remainder_hex], r9

        mov     rcx, [.dividend_hex]
        lea     rdx, [.dividend]
        call    bi_try_read_hex_512

        mov     rcx, [.divisor_hex]
        lea     rdx, [.divisor]
        call    bi_try_read_hex_512

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.dividend]
        lea     rdx, [.divisor + 0]
        lea     r8, [.quotient]
        lea     r9, [.remainder]
        call    bi_div_rem_512_256
        call    test_context_measure_dec_chunk
        jnz    .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_quotient_hex]
        lea     rdx, [.quotient]
        call    bi_assert_equal_hex_512

        mov     rcx, [.expected_remainder_hex]
        lea     rdx, [.remainder]
        call    bi_assert_equal_hex_512

        add     [.pointer], 512
        jmp     .loop
.end:

        leave
        ret

__bi_div_rem_512_256_test:
        mov     rbx, __bi_div_rem_512_64_test_cases
        call    __bi_div_rem_512_256_test_core

        mov     rbx, __bi_div_rem_512_128_test_cases
        call    __bi_div_rem_512_256_test_core

        mov     rbx, __bi_div_rem_512_192_test_cases
        call    __bi_div_rem_512_256_test_core

        mov     rbx, __bi_div_rem_512_256_test_cases
        call    __bi_div_rem_512_256_test_measure_core

        ret
