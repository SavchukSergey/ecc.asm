__bi_shl_assign_128_1_test:
virtual at rsp
.locals_start:
  .value BigInteger128
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0

        lea     rcx, [.value_hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_128

        lea     rcx, [.value]
        call    bi_shl_assign_128_1

        lea     rcx, [.expected_hex]
        lea     rdx, [.value]
        call    bi_assert_equal_hex_128

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.value]
        call    bi_shl_assign_128_1
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        leave
        ret
.value_hex       db '08c5a3ca7598576d5074b535eff1147f'
.expected_hex   db '118B4794EB30AEDAA0E96A6BDFE228FE'
