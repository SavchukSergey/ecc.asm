include '../src/math/bigint/add/bi_add_256_256.inc'
include '../../../assert.inc'

__bi_add_256_256_test:
virtual at rsp
  .left rb __BIG_INTEGER_BYTES_256
  .right rb __BIG_INTEGER_BYTES_256
  .result rb __BIG_INTEGER_BYTES_256
end virtual
        sub     rsp, 3 * __BIG_INTEGER_BYTES_256

        lea     rcx, [.left_hex]
        lea     rdx, [.left]
        call    bi_try_read_hex_256

        lea     rcx, [.right_hex]
        lea     rdx, [.right]
        call    bi_try_read_hex_256

        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    test_context_start_measure
        call    bi_add_256_256
        call    test_context_end_measure

        lea     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_256

        jmp     .pass

.fail:
        add     rsp, 3 * __BIG_INTEGER_BYTES_256
        stc
        ret
.pass:
        add     rsp, 3 * __BIG_INTEGER_BYTES_256
        clc
        ret
.left_hex       db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d0'
.right_hex      db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b48'
.expected_hex   db '5DC187C01C2DD9F82CDFC36E39C3162883D47F8317CD5F168E094F01C6E28D18'