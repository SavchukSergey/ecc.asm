include '../src/math/bigint/is_zero/bi_is_zero_512.inc'

__bi_is_zero_512_test:
virtual at rsp
.locals_start:
  .non_zero rb __BIG_INTEGER_BYTES_512
  .zero rb __BIG_INTEGER_BYTES_512
.locals_end:
end virtual
    enter   .locals_end - .locals_start, 0  

    lea     rcx, [.non_zero_hex]
    lea     rdx, [.non_zero]
    call    bi_try_read_hex_512

    lea     rcx, [.non_zero]
    call    bi_is_zero_512

    mov     rcx, 0
    mov     rdx, rax
    call    bi_assert_equal_64

    lea     rcx, [.zero_hex]
    lea     rdx, [.zero]
    call    bi_try_read_hex_512

    lea     rcx, [.zero]
    call    bi_is_zero_512

    mov     rcx, 1
    mov     rdx, rax
    call    bi_assert_equal_64

    call    test_context_start_measure
.chunk_loop:
    lea     rcx, [.zero]
    call    bi_is_zero_512
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
    call    test_context_end_measure
    
    leave
    ret

.non_zero_hex db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfaec78b801f7b54ffcffae2f24530dbd0be9c3502a33e6b7db03dfd53b6a8a36766'
.zero_hex     db '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000'
