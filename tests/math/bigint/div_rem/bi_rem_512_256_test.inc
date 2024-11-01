include '../../../../src/math/bigint/div_rem/bi_rem_512_256.inc'

__bi_rem_512_256_test_core:
virtual at rsp
.locals_start:
  .dividend_hex rq 1
  .divisor_hex rq 1
  .expected_remainder_hex rq 1
  .pointer rq 1
  .dividend BigInteger512
  .divisor BigInteger512
  .remainder BigInteger512
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
        PrologCheckStackAligned '__bi_rem_512_256_test_core'
        CheckRegAligned rbx, '__bi_rem_512_256_test_core rbx'

        mov     [.pointer], rbx
.loop:        
        mov     rbx, [.pointer]
        cmp     qword [rbx], 0
        je      .end

        lea     rcx, [rbx]
        lea     rdx, [rbx + 128]
        lea     r8, [rbx + 384]

        mov     [.dividend_hex], rcx
        mov     [.divisor_hex], rdx
        mov     [.expected_remainder_hex], r8

        mov     rcx, [.dividend_hex]
        lea     rdx, [.dividend]
        call    bi_try_read_hex_512

        mov     rcx, [.divisor_hex]
        lea     rdx, [.divisor]
        call    bi_try_read_hex_512

        lea     rcx, [.dividend]
        lea     rdx, [.divisor + 0]
        lea     r8, [.remainder]
        call    bi_rem_512_256

        mov     rcx, [.expected_remainder_hex]
        lea     rdx, [.remainder]
        call    bi_assert_equal_hex_512

        add     [.pointer], 512
        jmp     .loop
.end:

        add     rsp, .locals_end - .locals_start
        ret

__bi_rem_512_256_test_measure_core:
virtual at rsp
.locals_start:
  .dividend_hex rq 1
  .divisor_hex rq 1
  .expected_remainder_hex rq 1
  .pointer rq 1
  .dividend BigInteger512
  .divisor BigInteger512
  .remainder BigInteger512
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

        PrologCheckStackAligned '__bi_rem_512_256_test_measure_core'
        CheckRegAligned rbx, '__bi_rem_512_256_test_measure_core rbx'

        mov     [.pointer], rbx
.loop:        
        mov     rbx, [.pointer]
        cmp     qword [rbx], 0
        je      .end

        lea     rcx, [rbx]
        lea     rdx, [rbx + 128]
        lea     r8, [rbx + 384]

        mov     [.dividend_hex], rcx
        mov     [.divisor_hex], rdx
        mov     [.expected_remainder_hex], r8

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
        lea     r8, [.remainder]
        call    bi_rem_512_256
        call    test_context_measure_dec_chunk
        jnz    .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_remainder_hex]
        lea     rdx, [.remainder]
        call    bi_assert_equal_hex_512

        add     [.pointer], 512
        jmp     .loop
.end:
        add     rsp, .locals_end - .locals_start
        ret

__bi_rem_512_256_test:
        sub     rsp, 8
        mov     rbx, __bi_div_rem_512_64_test_cases
        call    __bi_rem_512_256_test_core

        mov     rbx, __bi_div_rem_512_128_test_cases
        call    __bi_rem_512_256_test_core

        mov     rbx, __bi_div_rem_512_192_test_cases
        call    __bi_rem_512_256_test_measure_core

        mov     rbx, __bi_div_rem_512_256_test_cases
        call    __bi_rem_512_256_test_measure_core

        add     rsp, 8
        ret
