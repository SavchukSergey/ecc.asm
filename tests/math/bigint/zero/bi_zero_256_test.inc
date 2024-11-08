__bi_zero_256_test:
virtual at rsp
.locals_start:
  .source BigInteger256
.locals_end:
end virtual
    enter   .locals_end - .locals_start, 0  
    lea     rcx, [.source_hex]
    lea     rdx, [.source]
    call    bi_try_read_hex_256

    lea     rcx, [.source]
    call    bi_zero_256

    lea     rcx, [.expected_hex]
    lea     rdx, [.source]
    call    bi_assert_equal_hex_256

    call    test_context_start_measure
.chunk_loop:
    lea     rcx, [.source]
    call    bi_zero_256
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
    call    test_context_end_measure

    leave
    ret

.source_hex db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
.expected_hex  db '0000000000000000000000000000000000000000000000000000000000000000'
