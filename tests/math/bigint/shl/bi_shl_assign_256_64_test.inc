include '../src/math/bigint/shl/bi_shl_assign_256_64.inc'

__bi_shl_assign_256_64_test:
virtual at rsp
.locals_start:
  BigInteger256 .value
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

        lea     rcx, [.value_hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_256

        lea     rcx, [.value]
        call    bi_shl_assign_256_64

        lea     rcx, [.expected_hex]
        lea     rdx, [.value]
        call    bi_assert_equal_hex_256

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.value]
        call    bi_shl_assign_256_64
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        add     rsp, .locals_end - .locals_start
        ret

align 16
.value_hex    db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d0'
.expected_hex db '5074b535eff1147f9102c52d5633130c1453c08f25ad41d00000000000000000'


