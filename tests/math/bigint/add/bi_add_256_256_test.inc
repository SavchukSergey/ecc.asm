include '../../../../src/math/bigint/add/bi_add_256_256.inc'
include '../../../assert.inc'

__bi_add_256_256_test:
virtual at rsp
.locals_start:
  .left BigInteger256
  .right BigInteger256
  .result BigInteger256
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0

        mov     rbx, __bi_add_256_256_test_cases 
.loop:
        lea     rcx, [rbx + 0]
        lea     rdx, [.left]
        call    bi_try_read_hex_256

        lea     rcx, [rbx + __BIG_INTEGER_HEX_DIGITS_256]
        lea     rdx, [.right]
        call    bi_try_read_hex_256

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    bi_add_256_256
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [rbx + __BIG_INTEGER_HEX_DIGITS_256 * 2]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_256

        add     rbx, __BIG_INTEGER_HEX_DIGITS_256 * 3
        cmp     rbx, __bi_add_256_256_test_cases.end
        jb      .loop

        leave
        ret

__bi_add_256_256_test_cases:
  db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d0'
  db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b48'
  db '5DC187C01C2DD9F82CDFC36E39C3162883D47F8317CD5F168E094F01C6E28D18'

.end: