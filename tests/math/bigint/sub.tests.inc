include '../src/math/bigint/sub/sub.inc'
include '../../assert.inc'

__bi_sub_128_128_test:
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
        call    bi_sub_128_128
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
.expected_hex   db 'B3C9BFD4CF02D4E27409A6FDA61F12D7'




__bi_sub_256_256_test:
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
        call    bi_sub_256_256
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
.expected_hex   db 'B3C9BFD4CF02D4E27409A6FDA61F12D69E310AD79498C7019A9E321C8477F688'




__bi_sub_512_512_test:
virtual at rsp
  .left rb __BIG_INTEGER_BYTES_512
  .right rb __BIG_INTEGER_BYTES_512
  .result rb __BIG_INTEGER_BYTES_512
end virtual
        sub     rsp, 3 * __BIG_INTEGER_BYTES_512

        lea     rcx, [.left_hex]
        lea     rdx, [.left]
        call    bi_try_read_hex_512

        lea     rcx, [.right_hex]
        lea     rdx, [.right]
        call    bi_try_read_hex_512

        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    test_context_start_measure
        call    bi_sub_512_512
        call    test_context_end_measure

        lea     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_512

        jmp     .pass

.fail:
        add     rsp, 3 * __BIG_INTEGER_BYTES_512
        stc
        ret
.pass:
        add     rsp, 3 * __BIG_INTEGER_BYTES_512
        clc
        ret
.left_hex       db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c33'
.right_hex      db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b4863400c3d833bdc3acb34eca9e788cf6d34474fe4e7de10de2a02d02c66609139'
.expected_hex   db 'B3C9BFD4CF02D4E27409A6FDA61F12D69E310AD79498C7019A9E321C8477F687FE7B4E113DD24B1C3857ACD96833320CFD56A5421403D0E75B5EA79E9813CAFA'
