include '../../../../src/math/bigint/is_zero/bi_is_zero_256.inc'

__bi_is_zero_256_test_core:
virtual at rsp
.locals_start:
  .hex rq 1
  .expected rq 1
  .value rb __BIG_INTEGER_BYTES_256
  AlignLocalsStackFrame
.locals_end:
end virtual
    sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__bi_is_zero_256_test_core'
    CheckRegAligned rcx, '__bi_is_zero_256_test_core rcx'

    mov     [.hex], rcx
    mov     [.expected], rdx

    mov     rcx, [.hex]
    lea     rdx, [.value]
    call    bi_try_read_hex_256

    lea     rcx, [.value]
    call    bi_is_zero_256

    mov     rcx, [.expected]
    mov     rdx, rax
    call    bi_assert_equal_64

    call    test_context_start_measure
.chunk_loop:
    lea     rcx, [.value]
    call    bi_is_zero_256
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
    call    test_context_end_measure
    
    add     rsp, .locals_end - .locals_start
    ret

__bi_is_zero_256_test:
    sub     rsp, 8

    lea     rcx, [.non_zero_1_hex]
    xor     rdx, rdx
    call    __bi_is_zero_256_test_core

    lea     rcx, [.non_zero_2_hex]
    xor     rdx, rdx
    call    __bi_is_zero_256_test_core

    lea     rcx, [.non_zero_3_hex]
    xor     rdx, rdx
    call    __bi_is_zero_256_test_core

    lea     rcx, [.non_zero_4_hex]
    xor     rdx, rdx
    call    __bi_is_zero_256_test_core

    lea     rcx, [.non_zero_5_hex]
    xor     rdx, rdx
    call    __bi_is_zero_256_test_core

    lea     rcx, [.zero_hex]
    mov     rdx, 1
    call    __bi_is_zero_256_test_core

    add     rsp, 8

    ret

align 16
.non_zero_1_hex db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
.non_zero_2_hex db '00000000000000008990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
.non_zero_3_hex db '8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae0000000000000000'
.non_zero_4_hex db '8000000000000000000000000000000000000000000000000000000000000000'
.non_zero_5_hex db '8000000000000000000000000000000000000000000000000000000000000001'
.zero_hex       db '0000000000000000000000000000000000000000000000000000000000000000'
