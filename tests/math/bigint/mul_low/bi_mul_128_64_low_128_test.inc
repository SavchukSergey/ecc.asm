include '../../../../src/math/bigint/mul_low/bi_mul_128_64_low_128.inc'

__bi_mul_128_64_low_128_test_core:
virtual at rsp
.locals_start:
  .left BigInteger128
  .right BigInteger128
  .result BigInteger128
  .left_hex rq 1
  .right_hex rq 1
  .expected_hex rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__bi_mul_128_64_low_128_test_core'
    CheckRegAligned rcx, '__bi_mul_128_64_low_128_test_core rcx'
    CheckRegAligned rdx, '__bi_mul_128_64_low_128_test_core rdx'
    CheckRegAligned r8, '__bi_mul_128_64_low_128_test_core r8'

        mov     [.left_hex], rcx
        mov     [.right_hex], rdx
        mov     [.expected_hex], r8

        mov     rcx, [.left_hex]
        lea     rdx, [.left]
        call    bi_try_read_hex_128

        mov     rcx, [.right_hex]
        lea     rdx, [.right]
        call    bi_try_read_hex_128

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
        mov     rdx, qword [.right + 0]
        lea     r8, [.result]
        call    bi_mul_128_64_low_128
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_128

        add     rsp, .locals_end - .locals_start
        ret

__bi_mul_128_64_low_128_test:
        push    rbx
        mov     rbx, __bi_mul_128_64_low_128_test_cases
.loop:
        lea     rcx, [rbx + 0]
        lea     rdx, [rbx + 32]
        lea     r8, [rbx + 64]
        call    __bi_mul_128_64_low_128_test_core

        add     rbx, 32 + 32 + 32
        cmp     rbx, __bi_mul_128_64_low_128_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_128_64_low_128_test_cases:
  db '23e0715c2534cec45e6ac5894b97fccd'
  db '0000000000000000d874a75e73460deb'
  db '359D878C422525E23527CE445369792F'

  db 'ffffffffffffffffffffffffffffffff'
  db '0000000000000000ffffffffffffffff'
  db 'FFFFFFFFFFFFFFFF0000000000000001'
.end: