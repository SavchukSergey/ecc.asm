include '../src/math/bigint/sub/bi_sub_128_128.inc'
include '../../../assert.inc'

__bi_sub_128_128_test:
virtual at rsp
.locals_start:
  .left rb __BIG_INTEGER_BYTES_128
  .right rb __BIG_INTEGER_BYTES_128
  .result rb __BIG_INTEGER_BYTES_128
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0

        mov     rbx,  __bi_sub_128_128_test_cases 
.loop:
        lea     rcx, [rbx + 0]
        lea     rdx, [.left]
        call    bi_try_read_hex_128

        lea     rcx, [rbx + 32]
        lea     rdx, [.right]
        call    bi_try_read_hex_128

        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    test_context_start_measure
        call    bi_sub_128_128
        call    test_context_end_measure

        lea     rcx, [rbx + 64]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_128

        add     rbx, 32 + 32 + 32
        cmp     rbx, __bi_sub_128_128_test_cases.end
        jb      .loop

        leave
        ret

__bi_sub_128_128_test_cases:
  db '08c5a3ca7598576d5074b535eff1147f'
  db '54fbe3f5a695828adc6b0e3849d201a8'
  db 'B3C9BFD4CF02D4E27409A6FDA61F12D7'

  db '54fbe3f5a695828adc6b0e3849d201a8'
  db '08c5a3ca7598576d5074b535eff1147f'
  db '4C36402B30FD2B1D8BF6590259E0ED29'

  db '54fbe3f5a695828adc6b0e3849d201a8'
  db '54fbe3f5a695828adc6b0e3849d201a8'
  db '00000000000000000000000000000000'

.end: