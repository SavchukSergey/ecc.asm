include '../src/math/bigint/shl/bi_shl_assign_512_64.inc'

__bi_shl_assign_512_64_test:
virtual at rsp
.locals_start:
  .value rb __BIG_INTEGER_BYTES_512
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0

        lea     rcx, [.value_hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_512

        lea     rcx, [.value]
        call    bi_shl_assign_512_64

        lea     rcx, [.expected_hex]
        lea     rdx, [.value]
        call    bi_assert_equal_hex_512

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.value]
        call    bi_shl_assign_512_64
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        leave
        ret

.value_hex      db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c33'
.expected_hex   db '5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c330000000000000000'


