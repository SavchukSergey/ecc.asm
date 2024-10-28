include '../../../../src/math/bigint/square/bi_square_128.inc'

__bi_square_128_test_core:
virtual at rsp
.locals_start:
  .value BigInteger128
  .result BigInteger256
  .value_hex rq 1
  .expected_hex rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__bi_square_128_test_core'
    CheckRegAligned rcx, '__bi_square_128_test_core rcx'
    CheckRegAligned rdx, '__bi_square_128_test_core rdx'

        mov     [.value_hex], rcx
        mov     [.expected_hex], rdx

        mov     rcx, [.value_hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_128

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.value]
        lea     rdx, [.result]
        call    bi_square_128
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_256

        add     rsp, .locals_end - .locals_start
        ret

__bi_square_128_test:
        push    rbx

        lea     rbx, [__bi_square_128_test_cases]
.loop:

        lea     rcx, [rbx]
        lea     rdx, [rbx + 32]
        call    __bi_square_128_test_core

        add     rbx, 32 + 64
        cmp     rbx, __bi_square_128_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_square_128_test_cases:
  db '23e0715c2534cec45e6ac5894b97fccd'
  db '050723c5c5a006f6eb5cb404c422df93730557a7527fd565cfd67dc6517a3c29'

  db 'ffffffffffffffffffffffffffffffff'
  db 'FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE00000000000000000000000000000001'

.end:
