__bi_shr_assign_128_test_core:
virtual at rsp
.locals_start:
  .value BigInteger128
  .value_hex rq 1
  .expected_hex rq 1
  .count rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__bi_shr_assign_128_test_core'
    CheckRegAligned rcx, '__bi_shr_assign_128_test_core rcx'
    CheckRegAligned r8, '__bi_shr_assign_128_test_core r8'

        mov     [.value_hex], rcx
        mov     [.count], rdx
        mov     [.expected_hex], r8

        mov     rcx, [.value_hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_128

        lea     rcx, [.value]
        mov     rdx, [.count]
        call    bi_shr_assign_128

        mov     rcx, [.expected_hex]
        lea     rdx, [.value]
        call    bi_assert_equal_hex_128

        add     rsp, .locals_end - .locals_start
        ret

__bi_shr_assign_128_test_measure_core:
virtual at rsp
.locals_start:
  .value BigInteger128
  .value_hex rq 1
  .count rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__bi_shr_assign_128_test_measure_core'
    CheckRegAligned rcx, '__bi_shr_assign_128_test_measure_core rcx'
    CheckRegAligned r8, '__bi_shr_assign_128_test_measure_core r8'

        mov     [.value_hex], rcx
        mov     [.count], rdx

        mov     rcx, [.value_hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_128

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.value]
        mov     rdx, [.count]
        call    bi_shr_assign_128
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        add     rsp, .locals_end - .locals_start
        ret


__bi_shr_assign_128_test:
        sub     rsp, 8
        lea     rcx, [.value_hex]
        mov     rdx, 0
        lea     r8, [.expected_0_hex]
        call    __bi_shr_assign_128_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 4
        lea     r8, [.expected_4_hex]
        call    __bi_shr_assign_128_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 8
        lea     r8, [.expected_8_hex]
        call    __bi_shr_assign_128_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 32
        lea     r8, [.expected_32_hex]
        call    __bi_shr_assign_128_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 64
        lea     r8, [.expected_64_hex]
        call    __bi_shr_assign_128_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 127
        lea     r8, [.expected_127_hex]
        call    __bi_shr_assign_128_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 128
        lea     r8, [.expected_128_hex]
        call    __bi_shr_assign_128_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 65
        lea     r8, [.expected_128_hex]
        call    __bi_shr_assign_128_test_measure_core

        add     rsp, 8
        ret

align 16
.value_hex        db '88c5a3ca7598576d5074b535eff1147f'
.expected_0_hex   db '88c5a3ca7598576d5074b535eff1147f'
.expected_4_hex   db '088c5a3ca7598576d5074b535eff1147'
.expected_8_hex   db '0088c5a3ca7598576d5074b535eff114'
.expected_32_hex  db '0000000088c5a3ca7598576d5074b535'
.expected_64_hex  db '000000000000000088c5a3ca7598576d'
.expected_127_hex db '00000000000000000000000000000001'
.expected_128_hex db '00000000000000000000000000000000'