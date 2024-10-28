include '../../../../src/math/bigint/sub/bi_sub_512_512.inc'
include '../../../assert.inc'

__bi_sub_512_512_test:
virtual at rsp
.locals_start:
  .left BigInteger512
  .right BigInteger512
  .result BigInteger512
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0

        mov     rbx,  __bi_sub_512_512_test_cases 
.loop:
        lea     rcx, [rbx + 0]
        lea     rdx, [.left]
        call    bi_try_read_hex_512

        lea     rcx, [rbx + 128]
        lea     rdx, [.right]
        call    bi_try_read_hex_512

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    bi_sub_512_512
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [rbx + 256]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_512

        add     rbx, 128 + 128 + 128
        cmp     rbx, __bi_sub_512_512_test_cases.end
        jb      .loop

        leave
        ret

__bi_sub_512_512_test_cases:
  db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c33'
  db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b4863400c3d833bdc3acb34eca9e788cf6d34474fe4e7de10de2a02d02c66609139'
  db 'B3C9BFD4CF02D4E27409A6FDA61F12D69E310AD79498C7019A9E321C8477F687FE7B4E113DD24B1C3857ACD96833320CFD56A5421403D0E75B5EA79E9813CAFA'

  db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b4863400c3d833bdc3acb34eca9e788cf6d34474fe4e7de10de2a02d02c66609139'
  db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c33'
  db '4C36402B30FD2B1D8BF6590259E0ED2961CEF5286B6738FE6561CDE37B8809780184B1EEC22DB4E3C7A8532697CCCDF302A95ABDEBFC2F18A4A1586167EC3506'

  db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b4863400c3d833bdc3acb34eca9e788cf6d34474fe4e7de10de2a02d02c66609139'
  db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b4863400c3d833bdc3acb34eca9e788cf6d34474fe4e7de10de2a02d02c66609139'
  db '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000'

.end: