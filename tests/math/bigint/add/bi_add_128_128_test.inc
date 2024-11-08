__bi_add_128_128_test:
virtual at rsp
  label .locals_start
  .left BigInteger128
  .right BigInteger128
  .result BigInteger128
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        lea     rcx, [.left_hex]
        lea     rdx, [.left]
        call    bi_try_read_hex_128

        lea     rcx, [.right_hex]
        lea     rdx, [.right]
        call    bi_try_read_hex_128

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    bi_add_128_128
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_128

        add     rsp, .locals_end - .locals_start
        ret

.left_hex       db '08c5a3ca7598576d5074b535eff1147f'
.right_hex      db '54fbe3f5a695828adc6b0e3849d201a8'
.expected_hex   db '5DC187C01C2DD9F82CDFC36E39C31627'
