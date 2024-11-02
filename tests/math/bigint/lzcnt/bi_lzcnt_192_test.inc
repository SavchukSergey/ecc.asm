include '../../../../src/math/bigint/lzcnt/bi_lzcnt_192.inc'
include '../../../assert.inc'

__bi_lzcnt_192_test_core:
virtual at rsp
.locals_start:
  .value BigInteger192
  .value_hex rq 1
  .expected rq 1
  .result rq 1
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.value_hex], rcx
        mov     [.expected], rdx

        mov     rcx, [.value_hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_192

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.value]
        call    bi_lzcnt_192
        mov     [.result], rax
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected]
        mov     rdx, [.result]
        call    bi_assert_equal_64

        jmp     .pass

.fail:
        leave
        stc
        ret
.pass:
        leave
        clc
        ret

__bi_lzcnt_192_test:
        lea     rcx, [.value_1]
        mov     rdx, [.result_1]
        call    __bi_lzcnt_192_test_core

        lea     rcx, [.value_2]
        mov     rdx, [.result_2]
        call    __bi_lzcnt_192_test_core

        lea     rcx, [.value_3]
        mov     rdx, [.result_3]
        call    __bi_lzcnt_192_test_core

        lea     rcx, [.value_4]
        mov     rdx, [.result_4]
        call    __bi_lzcnt_192_test_core

        ret

.value_1        db 'cd6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f59'
.result_1       dq 0

.value_2        db '0d6f06360fa5af8415f7a678ab45d8c1d435f8cf054b0f59'
.result_2       dq 4

.value_3        db '000000000000000008f7a678ab45d8c1d435f8cf054b0f59'
.result_3       dq 68

.value_4        db '000000000000000000000000000000000000000000000000'
.result_4       dq 192
