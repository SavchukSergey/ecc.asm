__bi_cmp_192_192_test:
virtual at rsp
.locals_start:
  .small BigInteger192
  .mid BigInteger192
  .close_mid BigInteger192
  .big BigInteger192
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0  

        mov     rcx, .small_hex
        lea     rdx, [.small]
        call    bi_try_read_hex_192

        mov     rcx, .mid_hex
        lea     rdx, [.mid]
        call    bi_try_read_hex_192

        mov     rcx, .close_mid_hex
        lea     rdx, [.close_mid]
        call    bi_try_read_hex_192

        mov     rcx, .big_hex
        lea     rdx, [.big]
        call    bi_try_read_hex_192

        lea     rcx, [.mid]
        lea     rdx, [.mid]
        call    bi_cmp_192_192
        mov     rcx, 0
        mov     rdx, rax
        call    bi_assert_equal_64

        lea     rcx, [.small]
        lea     rdx, [.mid]
        call    bi_cmp_192_192
        mov     rcx, -1
        mov     rdx, rax
        call    bi_assert_equal_64

        lea     rcx, [.big]
        lea     rdx, [.mid]
        call    bi_cmp_192_192
        mov     rcx, 1
        mov     rdx, rax
        call    bi_assert_equal_64

        lea     rcx, [.close_mid]
        lea     rdx, [.mid]
        call    bi_cmp_192_192
        mov     rcx, 1
        mov     rdx, rax
        call    bi_assert_equal_64

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.mid]
        lea     rdx, [.mid]
        call    bi_cmp_192_192
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        leave
        ret

.small_hex     db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c'
.mid_hex       db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a'
.close_mid_hex db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0b'
.big_hex       db 'a67d4db1549eef7091f9fb898ca5178a3ebf6e0df17b64ef'


