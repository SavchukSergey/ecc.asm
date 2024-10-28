include '../../../../src/math/bigint/sub/bi_sub_256_256.inc'
include '../../../assert.inc'

__bi_sub_256_256_test:
virtual at rsp
.locals_start:
  .left BigInteger256
  .right BigInteger256
  .result BigInteger256
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0

        mov     rbx,  __bi_sub_256_256_test_cases 
.loop:
        lea     rcx, [rbx + 0]
        lea     rdx, [.left]
        call    bi_try_read_hex_256

        lea     rcx, [rbx + 64]
        lea     rdx, [.right]
        call    bi_try_read_hex_256

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    bi_sub_256_256
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [rbx + 128]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_256

        add     rbx, 64 + 64 + 64
        cmp     rbx, __bi_sub_256_256_test_cases.end
        jb      .loop

        leave
        ret

__bi_sub_256_256_test_cases:
  db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d0'
  db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b48'
  db 'B3C9BFD4CF02D4E27409A6FDA61F12D69E310AD79498C7019A9E321C8477F688'

  db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b48'
  db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d0'
  db '4C36402B30FD2B1D8BF6590259E0ED2961CEF5286B6738FE6561CDE37B880978'

  db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b48'
  db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b48'
  db '0000000000000000000000000000000000000000000000000000000000000000'

.end: