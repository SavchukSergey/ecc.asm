include '../src/math/bigint/shl/index.inc'
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

        leave
        ret
.value_hex       db '08c5a3ca7598576d5074b535eff1147f'
.expected_hex   db '118B4794EB30AEDAA0E96A6BDFE228FE'





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


