include '../src/math/bigint/add/bi_add_128_128.inc'
include '../../../assert.inc'

__bi_add_128_128_test:
virtual at rsp
  .left rb __BIG_INTEGER_BYTES_128
  .right rb __BIG_INTEGER_BYTES_128
  .result rb __BIG_INTEGER_BYTES_128
end virtual
        sub     rsp, 3 * __BIG_INTEGER_BYTES_128

        lea     rcx, [.left_hex]
        lea     rdx, [.left]
        call    bi_try_read_hex_128

        lea     rcx, [.right_hex]
        lea     rdx, [.right]
        call    bi_try_read_hex_128

        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    test_context_start_measure
        call    bi_add_128_128
        call    test_context_end_measure

        lea     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_128

        jmp     .pass

.fail:
        add     rsp, 3 * __BIG_INTEGER_BYTES_128
        stc
        ret
.pass:
        add     rsp, 3 * __BIG_INTEGER_BYTES_128
        clc
        ret
.left_hex       db '08c5a3ca7598576d5074b535eff1147f'
.right_hex      db '54fbe3f5a695828adc6b0e3849d201a8'
.expected_hex   db '5DC187C01C2DD9F82CDFC36E39C31627'
