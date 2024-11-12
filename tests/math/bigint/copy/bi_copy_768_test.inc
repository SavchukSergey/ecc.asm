__bi_copy_768_test:
virtual at rsp
.locals_start:
  .source BigInteger768
  .target BigInteger768
.locals_end:
end virtual
    enter   .locals_end - .locals_start, 0  
    lea     rcx, [.source_hex]
    lea     rdx, [.source]
    call    bi_try_read_hex_768

    call    test_context_start_measure
.chunk_loop:
    lea     rcx, [.target]
    lea     rdx, [.source]
    call    bi_copy_768
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
    call    test_context_end_measure

    lea     rcx, [.source_hex]
    lea     rdx, [.target]
    call    bi_assert_equal_hex_768

    leave
    ret

.source_hex db 'ba42240ffb037f1a4c64905998460012cdf5f2e685baf6578d8eb71c34f932f81874bb356c05027886d076a3b80bad4d8122481d2b79b2135f4381e8326893e86f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
