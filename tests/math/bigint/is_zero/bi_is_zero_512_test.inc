include '../../../../src/math/bigint/is_zero/bi_is_zero_512.inc'

__bi_is_zero_512_test_core:
virtual at rsp
.locals_start:
  .hex rq 1
  .expected rq 1
  .value BigInteger512
.locals_end:
end virtual
    enter   .locals_end - .locals_start, 0  
    mov     [.hex], rcx
    mov     [.expected], rdx

    mov     rcx, [.hex]
    lea     rdx, [.value]
    call    bi_try_read_hex_512

    lea     rcx, [.value]
    call    bi_is_zero_512

    mov     rcx, [.expected]
    mov     rdx, rax
    call    bi_assert_equal_64

    call    test_context_start_measure
.chunk_loop:
    lea     rcx, [.value]
    call    bi_is_zero_512
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
    call    test_context_end_measure
    
    leave
    ret

__bi_is_zero_512_test:
    lea     rcx, [.non_zero_1_hex]
    xor     rdx, rdx
    call    __bi_is_zero_512_test_core

    lea     rcx, [.non_zero_2_hex]
    xor     rdx, rdx
    call    __bi_is_zero_512_test_core

    lea     rcx, [.non_zero_3_hex]
    xor     rdx, rdx
    call    __bi_is_zero_512_test_core

    lea     rcx, [.non_zero_4_hex]
    xor     rdx, rdx
    call    __bi_is_zero_512_test_core

    lea     rcx, [.non_zero_5_hex]
    xor     rdx, rdx
    call    __bi_is_zero_512_test_core

    lea     rcx, [.zero_hex]
    mov     rdx, 1
    call    __bi_is_zero_512_test_core

    ret

.non_zero_1_hex db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfaec78b801f7b54ffcffae2f24530dbd0be9c3502a33e6b7db03dfd53b6a8a36766'
.non_zero_2_hex db '00000000000000006f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfaec78b801f7b54ffcffae2f24530dbd0be9c3502a33e6b7db0'
.non_zero_3_hex db '8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfaec78b801f7b54ffcffae2f24530dbd0be9c3502a33e6b7db03dfd53b6a8a367660000000000000000'
.non_zero_4_hex db '80000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000'
.non_zero_5_hex db '80000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001'
.zero_hex       db '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000'
