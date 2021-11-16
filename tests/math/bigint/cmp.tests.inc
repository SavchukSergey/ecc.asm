macro BigIntegerCmpTests bits {

include '../src/math/bigint/cmp/cmp.inc'
include '../src/math/bigint/read_hex.inc'

BigIntegerCmp bits
BigIntegerReadHex bits

__bi_cmp_test_#bits:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 2 * __BIG_INTEGER_BYTES_#bits

        mov     rsi, rax
        lea     rdi, [rsp]
        call    __bi_read_hex_#bits

        mov     rsi, rbx
        lea     rdi, [rsp + __BIG_INTEGER_BYTES_#bits]
        call    __bi_read_hex_#bits

        lea     rax, [rsp + 0]
        lea     rbx, [rsp + __BIG_INTEGER_BYTES_#bits]
        call    test_context_start_measure
        call    __bi_cmp_#bits
        call    test_context_end_measure
        mov     rsp, rbp
        pop     rbp
        ret

__bi_cmp_equal_test_#bits:
        mov     rax, __bi_cmp_test.mid
        mov     rbx, __bi_cmp_test.mid
        call    __bi_cmp_test_#bits
        je      .passed
.failed:
        stc
        ret
.passed:
        clc
        ret

__bi_cmp_less_test_#bits:
        mov     rax, __bi_cmp_test.small
        mov     rbx, __bi_cmp_test.mid
        call    __bi_cmp_test_#bits
        jb      .passed
.failed:
        stc
        ret
.passed:
        clc
        ret

__bi_cmp_greater_test_#bits:
        mov     rax, __bi_cmp_test.big
        mov     rbx, __bi_cmp_test.mid
        call    __bi_cmp_test_#bits
        ja      .passed
.failed:
        stc
        ret
.passed:
        clc
        ret
}

__bi_cmp_test:
.small db '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c33'
.mid db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b4863400c3d833bdc3acb34eca9e788cf6d34474fe4e7de10de2a02d02c66609139'
.big db 'a67d4db1549eef7091f9fb898ca5178a3ebf6e0df17b64eff331bea5eb4163777434f5868ac786ef97750fe91a04eabe49905454ab8c643dc61924c4b485ef8f'
