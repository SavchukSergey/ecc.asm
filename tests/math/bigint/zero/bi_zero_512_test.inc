include '../src/math/bigint/zero/bi_zero_512.inc'

__bi_zero_512_test:
virtual at rsp
.locals_start:
  .source rb __BIG_INTEGER_BYTES_512
.locals_end:
end virtual
    enter   .locals_end - .locals_start, 0  
    lea     rcx, [.source_hex]
    lea     rdx, [.source]
    call    bi_try_read_hex_512

    lea     rcx, [.source]
    call    bi_zero_512

    lea     rcx, [.expected_hex]
    lea     rdx, [.source]
    call    bi_assert_equal_hex_512

    call    test_context_start_measure
.chunk_loop:
    lea     rcx, [.source]
    call    bi_zero_512
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
    call    test_context_end_measure
    
    leave
    ret

.source_hex db 'ba42240ffb037f1a4c64905998460012cdf5f2e685baf6578d8eb71c34f932f81874bb356c05027886d076a3b80bad4d8122481d2b79b2135f4381e8326893e8'
.expected_hex  db '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000'
