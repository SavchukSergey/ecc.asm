include '../src/math/bigint/is_zero/bi_is_zero_256.inc'

__bi_is_zero_256_test:
virtual at rsp
.locals_start:
  .non_zero rb __BIG_INTEGER_BYTES_256
  .zero rb __BIG_INTEGER_BYTES_256
.locals_end:
end virtual
    enter   .locals_end - .locals_start, 0  

    lea     rcx, [.non_zero_hex]
    lea     rdx, [.non_zero]
    call    bi_try_read_hex_256

    call    test_context_start_measure
    lea     rcx, [.non_zero]
    call    bi_is_zero_256
    call    test_context_end_measure

    mov     rcx, 0
    mov     rdx, rax
    call    bi_assert_equal_64
    jc      .fail

    lea     rcx, [.zero_hex]
    lea     rdx, [.zero]
    call    bi_try_read_hex_256

    call    test_context_start_measure
    lea     rcx, [.zero]
    call    bi_is_zero_256
    call    test_context_end_measure

    mov     rcx, 1
    mov     rdx, rax
    call    bi_assert_equal_64
    jc      .fail

.pass:
    leave
    clc
    ret
.fail:
    leave
    stc
    ret

.non_zero_hex db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
.zero_hex  db '0000000000000000000000000000000000000000000000000000000000000000'
