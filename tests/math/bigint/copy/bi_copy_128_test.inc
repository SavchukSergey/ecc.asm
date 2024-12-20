__bi_copy_128_test:
virtual at rsp
.locals_start:
  .source BigInteger128
  .target BigInteger128
.locals_end:
end virtual
    enter   .locals_end - .locals_start, 0  
    lea     rcx, [.source_hex]
    lea     rdx, [.source]
    call    bi_try_read_hex_128

    call    test_context_start_measure
.chunk_loop:
    lea     rcx, [.target]
    lea     rdx, [.source]
    call    bi_copy_128
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
    call    test_context_end_measure

    lea     rcx, [.source_hex]
    lea     rdx, [.target]
    call    bi_assert_equal_hex_128

    leave
    ret

.source_hex db '079e1bb029e94621b5a1ebc753efcfae'
