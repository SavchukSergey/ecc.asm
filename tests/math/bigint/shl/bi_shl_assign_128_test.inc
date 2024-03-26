
__bi_shl_assign_128_test_core:
virtual at rsp
.locals_start:
  .value_hex rq 1
  .expected_hex rq 1
  .count rq 1
  .value rb __BIG_INTEGER_BYTES_128
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.value_hex], rcx
        mov     [.count], rdx
        mov     [.expected_hex], r8

        mov     rcx, [.value_hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_128

        lea     rcx, [.value]
        mov     rdx, [.count]
        call    test_context_start_measure
        call    bi_shl_assign_128
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.value]
        call    bi_assert_equal_hex_128

        leave
        ret


__bi_shl_assign_128_test:
        lea     rcx, [.value_hex]
        mov     rdx, 0
        lea     r8, [.expected_0_hex]
        call    __bi_shl_assign_128_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 4
        lea     r8, [.expected_4_hex]
        call    __bi_shl_assign_128_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 8
        lea     r8, [.expected_8_hex]
        call    __bi_shl_assign_128_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 32
        lea     r8, [.expected_32_hex]
        call    __bi_shl_assign_128_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 64
        lea     r8, [.expected_64_hex]
        call    __bi_shl_assign_128_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 127
        lea     r8, [.expected_127_hex]
        call    __bi_shl_assign_128_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 128
        lea     r8, [.expected_128_hex]
        call    __bi_shl_assign_128_test_core

        ret

.value_hex        db '08c5a3ca7598576d5074b535eff1147f'
.expected_0_hex   db '08c5a3ca7598576d5074b535eff1147f'
.expected_4_hex   db '8c5a3ca7598576d5074b535eff1147f0'
.expected_8_hex   db 'c5a3ca7598576d5074b535eff1147f00'
.expected_32_hex  db '7598576d5074b535eff1147f00000000'
.expected_64_hex  db '5074b535eff1147f0000000000000000'
.expected_127_hex db '80000000000000000000000000000000'
.expected_128_hex db '00000000000000000000000000000000'