include '../src/math/bigint/cmp/bi_cmp_512_512.inc'

__bi_cmp_512_512_test:
virtual at rsp
.locals_start:
  .small rb __BIG_INTEGER_BYTES_512
  .mid rb __BIG_INTEGER_BYTES_512
  .close_mid rb __BIG_INTEGER_BYTES_512
  .big rb __BIG_INTEGER_BYTES_512
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0  

        mov     rcx, .small_hex
        lea     rdx, [.small]
        call    bi_try_read_hex_512

        mov     rcx, .mid_hex
        lea     rdx, [.mid]
        call    bi_try_read_hex_512

        mov     rcx, .close_mid_hex
        lea     rdx, [.close_mid]
        call    bi_try_read_hex_512

        mov     rcx, .big_hex
        lea     rdx, [.big]
        call    bi_try_read_hex_512

        lea     rcx, [.mid]
        lea     rdx, [.mid]
        call    bi_cmp_512_512
        mov     rcx, 0
        mov     rdx, rax
        call    bi_assert_equal_64

        lea     rcx, [.small]
        lea     rdx, [.mid]
        call    bi_cmp_512_512
        mov     rcx, -1
        mov     rdx, rax
        call    bi_assert_equal_64

        lea     rcx, [.big]
        lea     rdx, [.mid]
        call    bi_cmp_512_512
        mov     rcx, 1
        mov     rdx, rax
        call    bi_assert_equal_64

        lea     rcx, [.close_mid]
        lea     rdx, [.mid]
        call    bi_cmp_512_512
        mov     rcx, 1
        mov     rdx, rax
        call    bi_assert_equal_64

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.mid]
        lea     rdx, [.mid]
        call    bi_cmp_512_512
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        leave
        ret
.small_hex     db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c33'
.mid_hex       db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b4863400c3d833bdc3acb34eca9e788cf6d34474fe4e7de10de2a02d02c66609139'
.close_mid_hex db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b4863400c3d833bdc3acb34eca9e788cf6d34474fe4e7de10de2a02d02c6660913a'
.big_hex       db 'a67d4db1549eef7091f9fb898ca5178a3ebf6e0df17b64eff331bea5eb4163777434f5868ac786ef97750fe91a04eabe49905454ab8c643dc61924c4b485ef8f'


