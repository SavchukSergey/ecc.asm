include '../src/math/bigint/cmp/bi_cmp_128_128.inc'

__bi_cmp_128_128_test:
virtual at rsp
.locals_start:
  .small rb __BIG_INTEGER_BYTES_128
  .mid rb __BIG_INTEGER_BYTES_128
  .close_mid rb __BIG_INTEGER_BYTES_128
  .big rb __BIG_INTEGER_BYTES_128
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0  

        mov     rcx, .small_hex
        lea     rdx, [.small]
        call    bi_try_read_hex_128

        mov     rcx, .mid_hex
        lea     rdx, [.mid]
        call    bi_try_read_hex_128

        mov     rcx, .close_mid_hex
        lea     rdx, [.close_mid]
        call    bi_try_read_hex_128

        mov     rcx, .big_hex
        lea     rdx, [.big]
        call    bi_try_read_hex_128

        lea     rcx, [.mid]
        lea     rdx, [.mid]
        call    bi_cmp_128_128
        mov     rcx, 0
        mov     rdx, rax
        call    bi_assert_equal_64

        lea     rcx, [.small]
        lea     rdx, [.mid]
        call    bi_cmp_128_128
        mov     rcx, -1
        mov     rdx, rax
        call    bi_assert_equal_64

        lea     rcx, [.big]
        lea     rdx, [.mid]
        call    bi_cmp_128_128
        mov     rcx, 1
        mov     rdx, rax
        call    bi_assert_equal_64

        lea     rcx, [.close_mid]
        lea     rdx, [.mid]
        call    bi_cmp_128_128
        mov     rcx, 1
        mov     rdx, rax
        call    bi_assert_equal_64

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.mid]
        lea     rdx, [.mid]
        call    bi_cmp_128_128
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        leave
        ret

.small_hex     db '08c5a3ca7598576d5074b535eff1147f'
.mid_hex       db '54fbe3f5a695828adc6b0e3849d201a8'
.close_mid_hex db '54fbe3f5a695828adc6b0e3849d201a9'
.big_hex       db 'a67d4db1549eef7091f9fb898ca5178a'
