include '../src/math/bigint/shr/bi_shr_assign_512.inc'

__bi_shr_assign_512_test_core:
virtual at rsp
.locals_start:
  .value rb __BIG_INTEGER_BYTES_512
  .value_hex rq 1
  .expected_hex rq 1
  .count rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__bi_shr_assign_512_test_core'
    CheckRegAligned rcx, '__bi_shr_assign_512_test_core rcx'
    CheckRegAligned r8, '__bi_shr_assign_512_test_core r8'

        mov     [.value_hex], rcx
        mov     [.count], rdx
        mov     [.expected_hex], r8

        mov     rcx, [.value_hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_512

        lea     rcx, [.value]
        mov     rdx, [.count]
        call    bi_shr_assign_512

        mov     rcx, [.expected_hex]
        lea     rdx, [.value]
        call    bi_assert_equal_hex_512

        add     rsp, .locals_end - .locals_start
        ret

__bi_shr_assign_512_test_measure_core:
virtual at rsp
.locals_start:
  .value rb __BIG_INTEGER_BYTES_512
  .value_hex rq 1
  .count rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__bi_shr_assign_512_test_measure_core'
    CheckRegAligned rcx, '__bi_shr_assign_512_test_measure_core rcx'
    CheckRegAligned r8, '__bi_shr_assign_512_test_measure_core r8'

        mov     [.value_hex], rcx
        mov     [.count], rdx

        mov     rcx, [.value_hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_512

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.value]
        mov     rdx, [.count]
        call    bi_shr_assign_512
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        add     rsp, .locals_end - .locals_start
        ret


__bi_shr_assign_512_test:
        sub     rsp, 8
        lea     rcx, [.value_hex]
        mov     rdx, 0
        lea     r8, [.expected_0_hex]
        call    __bi_shr_assign_512_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 4
        lea     r8, [.expected_4_hex]
        call    __bi_shr_assign_512_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 8
        lea     r8, [.expected_8_hex]
        call    __bi_shr_assign_512_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 32
        lea     r8, [.expected_32_hex]
        call    __bi_shr_assign_512_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 64
        lea     r8, [.expected_64_hex]
        call    __bi_shr_assign_512_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 128
        lea     r8, [.expected_128_hex]
        call    __bi_shr_assign_512_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 256
        lea     r8, [.expected_256_hex]
        call    __bi_shr_assign_512_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 511
        lea     r8, [.expected_511_hex]
        call    __bi_shr_assign_512_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 512
        lea     r8, [.expected_512_hex]
        call    __bi_shr_assign_512_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 257
        call    __bi_shr_assign_512_test_measure_core
        
        add     rsp, 8

        ret

align 16
.value_hex        db '88c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c33'
.expected_0_hex   db '88c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c33'
.expected_4_hex   db '088c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c3'
.expected_8_hex   db '0088c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c'
.expected_32_hex  db '0000000088c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177ca'
.expected_64_hex  db '000000000000000088c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5'
.expected_128_hex db '0000000000000000000000000000000088c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a'
.expected_256_hex db '000000000000000000000000000000000000000000000000000000000000000088c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d0'
.expected_511_hex db '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001'
.expected_512_hex db '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000'
