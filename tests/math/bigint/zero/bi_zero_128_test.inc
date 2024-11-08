__bi_zero_128_test:
virtual at rsp
.locals_start:
  .source BigInteger128
.locals_end:
end virtual
    enter   .locals_end - .locals_start, 0  
    lea     rcx, [.source_hex]
    lea     rdx, [.source]
    call    bi_try_read_hex_128

    lea     rcx, [.source]
    call    bi_zero_128

    lea     rcx, [.expected_hex]
    lea     rdx, [.source]
    call    bi_assert_equal_hex_128

    call    test_context_start_measure
.chunk_loop:
    lea     rcx, [.source]
    call    bi_zero_128
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
    call    test_context_end_measure

    leave
    ret

.source_hex db '23e0715c2534cec45e6ac5894b97fccd'
.expected_hex  db '00000000000000000000000000000000'
