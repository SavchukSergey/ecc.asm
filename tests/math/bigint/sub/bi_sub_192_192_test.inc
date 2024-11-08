__bi_sub_192_192_test:
virtual at rsp
.locals_start:
  .left BigInteger192
  .right BigInteger192
  .result BigInteger192
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0

        mov     rbx, __bi_sub_192_192_test_cases 
.loop:
        lea     rcx, [rbx + 0]
        lea     rdx, [.left]
        call    bi_try_read_hex_192

        lea     rcx, [rbx + __BIG_INTEGER_HEX_DIGITS_192]
        lea     rdx, [.right]
        call    bi_try_read_hex_192

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    bi_sub_192_192
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [rbx + __BIG_INTEGER_HEX_DIGITS_192 * 2]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_192

        add     rbx, __BIG_INTEGER_HEX_DIGITS_192 * 3
        cmp     rbx, __bi_sub_192_192_test_cases.end
        jb      .loop

        leave
        ret

__bi_sub_192_192_test_cases:
  db '5074b535eff1147f9102c52d5633130c1453c08f25ad41d0'
  db 'dc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b48'
  db '7409A6FDA61F12D69E310AD79498C7019A9E321C8477F688'

  db 'dc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b48'
  db '5074b535eff1147f9102c52d5633130c1453c08f25ad41d0'
  db '8BF6590259E0ED2961CEF5286B6738FE6561CDE37B880978'

  db 'dc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b48'
  db 'dc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b48'
  db '000000000000000000000000000000000000000000000000'

.end: