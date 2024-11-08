__bi_zero_1024_test:
virtual at rsp
.locals_start:
  .source BigInteger1024
.locals_end:
end virtual
    enter   .locals_end - .locals_start, 0  
    lea     rcx, [.source_hex]
    lea     rdx, [.source]
    call    bi_try_read_hex_1024

    lea     rcx, [.source]
    call    bi_zero_1024

    lea     rcx, [.expected_hex]
    lea     rdx, [.source]
    call    bi_assert_equal_hex_1024

    call    test_context_start_measure
.chunk_loop:
    lea     rcx, [.source]
    call    bi_zero_1024
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
    call    test_context_end_measure

    leave
    ret

.source_hex db    '8989D0ECC425AFD9ECA5A905CBF83AB42912186013A1EBC8B8E578BD8AAADA86E3EFB62633564044539AF61685B4540DA8F8933BC698E864AE1065B8F7D78988F3100C37092F7EC6998EC8ECACF8D0419F64D7575E7562326087BD2DBCD917F3B4FED28F9AC2CD5B48D49A218FD3BC6015871892C8B6762169DBBDF973495D28'
.expected_hex  db '0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000'
