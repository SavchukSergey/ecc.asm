include '../../../../src/math/bigint/add/bi_add_512_512.inc'
include '../../../assert.inc'

__bi_add_512_512_test:
virtual at rsp
  label .locals_start
  BigInteger512 .left
  BigInteger512 .right
  BigInteger512 .result
   AlignLocalsStackFrame
label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        lea     rcx, [.left_hex]
        lea     rdx, [.left]
        call    bi_try_read_hex_512

        lea     rcx, [.right_hex]
        lea     rdx, [.right]
        call    bi_try_read_hex_512

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    bi_add_512_512
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_512

        add     rsp, .locals_end - .locals_start
        ret

align 16
.left_hex       db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c33'
.right_hex      db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b4863400c3d833bdc3acb34eca9e788cf6d34474fe4e7de10de2a02d02c66609139'
.expected_hex   db '5DC187C01C2DD9F82CDFC36E39C3162883D47F8317CD5F168E094F01C6E28D18C4FB668C444A0391CEC1862D3744D0E765E5450BE3BFF2A3AF6447F764D4ED6C'
