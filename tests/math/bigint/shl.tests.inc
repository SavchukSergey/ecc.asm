include '../src/math/bigint/shl/shl.inc'
include '../../assert.inc'

__bi_shl_assign_128_1_test:
virtual at rsp
.locals_start:
  .value rb __BIG_INTEGER_BYTES_128
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0

        lea     rcx, [.value_hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_128

        lea     rcx, [.value]
        call    test_context_start_measure
        call    bi_shl_assign_128_1
        call    test_context_end_measure

        lea     rcx, [.expected_hex]
        lea     rdx, [.value]
        call    bi_assert_equal_hex_128

        jmp     .pass

.fail:
        leave
        stc
        ret
.pass:
        leave
        clc
        ret
.value_hex       db '08c5a3ca7598576d5074b535eff1147f'
.expected_hex   db '118B4794EB30AEDAA0E96A6BDFE228FE'


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

        jmp     .pass

.fail:
        leave
        stc
        ret
.pass:
        leave
        clc
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



__bi_shl_assign_256_1_test:
virtual at rsp
.locals_start:
  .value rb __BIG_INTEGER_BYTES_256
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0

        lea     rcx, [.value_hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_256

        lea     rcx, [.value]
        call    test_context_start_measure
        call    bi_shl_assign_256_1
        call    test_context_end_measure

        lea     rcx, [.expected_hex]
        lea     rdx, [.value]
        call    bi_assert_equal_hex_256

        jmp     .pass

.fail:
        leave
        stc
        ret
.pass:
        leave
        clc
        ret
.value_hex       db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d0'
.expected_hex   db '118B4794EB30AEDAA0E96A6BDFE228FF22058A5AAC66261828A7811E4B5A83A0'


__bi_shl_assign_256_test_core:
virtual at rsp
.locals_start:
  .value_hex rq 1
  .expected_hex rq 1
  .count rq 1
  .value rb __BIG_INTEGER_BYTES_256
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.value_hex], rcx
        mov     [.count], rdx
        mov     [.expected_hex], r8

        mov     rcx, [.value_hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_256

        lea     rcx, [.value]
        mov     rdx, [.count]
        call    test_context_start_measure
        call    bi_shl_assign_256
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.value]
        call    bi_assert_equal_hex_256

        jmp     .pass

.fail:
        leave
        stc
        ret
.pass:
        leave
        clc
        ret


__bi_shl_assign_256_test:
        lea     rcx, [.value_hex]
        mov     rdx, 0
        lea     r8, [.expected_0_hex]
        call    __bi_shl_assign_256_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 4
        lea     r8, [.expected_4_hex]
        call    __bi_shl_assign_256_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 8
        lea     r8, [.expected_8_hex]
        call    __bi_shl_assign_256_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 32
        lea     r8, [.expected_32_hex]
        call    __bi_shl_assign_256_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 64
        lea     r8, [.expected_64_hex]
        call    __bi_shl_assign_256_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 128
        lea     r8, [.expected_128_hex]
        call    __bi_shl_assign_256_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 255
        lea     r8, [.expected_255_hex]
        call    __bi_shl_assign_256_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 256
        lea     r8, [.expected_256_hex]
        call    __bi_shl_assign_256_test_core

        ret

.value_hex        db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d1'
.expected_0_hex   db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d1'
.expected_4_hex   db '8c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d10'
.expected_8_hex   db 'c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d100'
.expected_32_hex  db '7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d100000000'
.expected_64_hex  db '5074b535eff1147f9102c52d5633130c1453c08f25ad41d10000000000000000'
.expected_128_hex db '9102c52d5633130c1453c08f25ad41d100000000000000000000000000000000'
.expected_255_hex db '8000000000000000000000000000000000000000000000000000000000000000'
.expected_256_hex db '0000000000000000000000000000000000000000000000000000000000000000'




__bi_shl_assign_512_1_test:
virtual at rsp
.locals_start:
  .value rb __BIG_INTEGER_BYTES_512
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0

        lea     rcx, [.value_hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_512

        lea     rcx, [.value]
        call    test_context_start_measure
        call    bi_shl_assign_512_1
        call    test_context_end_measure

        lea     rcx, [.expected_hex]
        lea     rdx, [.value]
        call    bi_assert_equal_hex_512

        jmp     .pass

.fail:
        leave
        stc
        ret
.pass:
        leave
        clc
        ret
.value_hex       db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c33'
.expected_hex   db '118B4794EB30AEDAA0E96A6BDFE228FF22058A5AAC66261828A7811E4B5A83A0C376B49D821C4EAE071933069F7802F4633BEA4DF7C3C38B0AC2EF95FCE8B866'


__bi_shl_assign_512_test_core:
virtual at rsp
.locals_start:
  .value_hex rq 1
  .expected_hex rq 1
  .count rq 1
  .value rb __BIG_INTEGER_BYTES_512
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.value_hex], rcx
        mov     [.count], rdx
        mov     [.expected_hex], r8

        mov     rcx, [.value_hex]
        lea     rdx, [.value]
        call    bi_try_read_hex_512

        lea     rcx, [.value]
        mov     rdx, [.count]
        call    test_context_start_measure
        call    bi_shl_assign_512
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.value]
        call    bi_assert_equal_hex_512

        jmp     .pass

.fail:
        leave
        stc
        ret
.pass:
        leave
        clc
        ret


__bi_shl_assign_512_test:
        lea     rcx, [.value_hex]
        mov     rdx, 0
        lea     r8, [.expected_0_hex]
        call    __bi_shl_assign_512_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 4
        lea     r8, [.expected_4_hex]
        call    __bi_shl_assign_512_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 8
        lea     r8, [.expected_8_hex]
        call    __bi_shl_assign_512_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 32
        lea     r8, [.expected_32_hex]
        call    __bi_shl_assign_512_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 64
        lea     r8, [.expected_64_hex]
        call    __bi_shl_assign_512_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 256
        lea     r8, [.expected_256_hex]
        call    __bi_shl_assign_512_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 511
        lea     r8, [.expected_511_hex]
        call    __bi_shl_assign_512_test_core

        lea     rcx, [.value_hex]
        mov     rdx, 512
        lea     r8, [.expected_512_hex]
        call    __bi_shl_assign_512_test_core

        ret

.value_hex        db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c33'
.expected_0_hex   db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c33'
.expected_4_hex   db '8c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c330'
.expected_8_hex   db 'c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c3300'
.expected_32_hex  db '7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c3300000000'
.expected_64_hex  db '5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c330000000000000000'
.expected_256_hex db '61bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c330000000000000000000000000000000000000000000000000000000000000000'
.expected_511_hex db '80000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000'
.expected_512_hex db '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000'
