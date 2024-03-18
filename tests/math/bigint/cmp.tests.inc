include '../src/math/bigint/cmp/index.inc'
include '../src/math/bigint/read_hex.inc'

__bi_cmp_test_128:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 2 * __BIG_INTEGER_BYTES_128

        mov     rcx, rax
        lea     rdx, [rsp]
        push    rax rbx
        call    bi_try_read_hex_128
        pop     rbx rax

        mov     rcx, rbx
        lea     rdx, [rsp + __BIG_INTEGER_BYTES_128]
        call    bi_try_read_hex_128

        lea     rcx, [rsp + 0]
        lea     rdx, [rsp + __BIG_INTEGER_BYTES_128]
        call    test_context_start_measure
        call    bi_cmp_128_128
        call    test_context_end_measure
        mov     rsp, rbp
        pop     rbp
        ret
.small       db '08c5a3ca7598576d5074b535eff1147f'
.mid         db '54fbe3f5a695828adc6b0e3849d201a8'
.close_mid   db '54fbe3f5a695828adc6b0e3849d201a9'
.big         db 'a67d4db1549eef7091f9fb898ca5178a'

__bi_cmp_128_128_equal_test:
        mov     rax, __bi_cmp_test_128.mid
        mov     rbx, __bi_cmp_test_128.mid
        call    __bi_cmp_test_128
        test    rax, rax
        je      .passed
.failed:
        stc
        ret
.passed:
        clc
        ret

__bi_cmp_128_128_less_test:
        mov     rax, __bi_cmp_test_128.small
        mov     rbx, __bi_cmp_test_128.mid
        call    __bi_cmp_test_128
        cmp     rax, -1
        je      .passed
.failed:
        stc
        ret
.passed:
        clc
        ret

__bi_cmp_128_128_greater_test:
        mov     rax, __bi_cmp_test_128.big
        mov     rbx, __bi_cmp_test_128.mid
        call    __bi_cmp_test_128
        cmp     rax, 1
        je      .passed
.failed:
        stc
        ret
.passed:
        clc
        ret

__bi_cmp_128_128_close_test:
        mov     rax, __bi_cmp_test_128.close_mid
        mov     rbx, __bi_cmp_test_128.mid
        call    __bi_cmp_test_128
        cmp     rax, 1
        je      .passed
.failed:
        stc
        ret
.passed:
        clc
        ret






__bi_cmp_test_256:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 2 * __BIG_INTEGER_BYTES_256

        mov     rcx, rax
        lea     rdx, [rsp]
        push    rax rbx
        call    bi_try_read_hex_256
        pop     rbx rax

        mov     rcx, rbx
        lea     rdx, [rsp + __BIG_INTEGER_BYTES_256]
        call    bi_try_read_hex_256

        lea     rcx, [rsp + 0]
        lea     rdx, [rsp + __BIG_INTEGER_BYTES_256]
        call    test_context_start_measure
        call    bi_cmp_256_256
        call    test_context_end_measure
        mov     rsp, rbp
        pop     rbp
        ret
.small db     '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d0'
.mid db       '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b48'
.close_mid db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b49'
.big db       'a67d4db1549eef7091f9fb898ca5178a3ebf6e0df17b64eff331bea5eb416377'

__bi_cmp_256_256_equal_test:
        mov     rax, __bi_cmp_test_256.mid
        mov     rbx, __bi_cmp_test_256.mid
        call    __bi_cmp_test_256
        test    rax, rax
        je      .passed
.failed:
        stc
        ret
.passed:
        clc
        ret

__bi_cmp_256_256_less_test:
        mov     rax, __bi_cmp_test_256.small
        mov     rbx, __bi_cmp_test_256.mid
        call    __bi_cmp_test_256
        cmp     rax, -1
        je      .passed
.failed:
        stc
        ret
.passed:
        clc
        ret

__bi_cmp_256_256_greater_test:
        mov     rax, __bi_cmp_test_256.big
        mov     rbx, __bi_cmp_test_256.mid
        call    __bi_cmp_test_256
        cmp     rax, 1
        je      .passed
.failed:
        stc
        ret
.passed:
        clc
        ret

__bi_cmp_256_256_close_test:
        mov     rax, __bi_cmp_test_256.close_mid
        mov     rbx, __bi_cmp_test_256.mid
        call    __bi_cmp_test_256
        cmp     rax, 1
        je      .passed
.failed:
        stc
        ret
.passed:
        clc
        ret




__bi_cmp_test_512:
        push    rbp
        mov     rbp, rsp
        sub     rsp, 2 * __BIG_INTEGER_BYTES_512

        mov     rcx, rax
        lea     rdx, [rsp]
        push    rax rbx
        call    bi_try_read_hex_512
        pop     rbx rax

        mov     rcx, rbx
        lea     rdx, [rsp + __BIG_INTEGER_BYTES_512]
        call    bi_try_read_hex_512

        lea     rcx, [rsp + 0]
        lea     rdx, [rsp + __BIG_INTEGER_BYTES_512]
        call    test_context_start_measure
        call    bi_cmp_512_512
        call    test_context_end_measure
        mov     rsp, rbp
        pop     rbp
        ret
.small db     '08c5a3ca7598576d5074b535eff1147f9102c52d5633130c1453c08f25ad41d061bb5a4ec10e2757038c99834fbc017a319df526fbe1e1c5856177cafe745c33'
.mid db       '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b4863400c3d833bdc3acb34eca9e788cf6d34474fe4e7de10de2a02d02c66609139'
.close_mid db '54fbe3f5a695828adc6b0e3849d201a8f2d1ba55c19a4c0a79b58e72a1354b4863400c3d833bdc3acb34eca9e788cf6d34474fe4e7de10de2a02d02c6660913a'
.big db       'a67d4db1549eef7091f9fb898ca5178a3ebf6e0df17b64eff331bea5eb4163777434f5868ac786ef97750fe91a04eabe49905454ab8c643dc61924c4b485ef8f'

__bi_cmp_512_512_equal_test:
        mov     rax, __bi_cmp_test_512.mid
        mov     rbx, __bi_cmp_test_512.mid
        call    __bi_cmp_test_512
        test    rax, rax
        je      .passed
.failed:
        stc
        ret
.passed:
        clc
        ret

__bi_cmp_512_512_less_test:
        mov     rax, __bi_cmp_test_512.small
        mov     rbx, __bi_cmp_test_512.mid
        call    __bi_cmp_test_512
        cmp     rax, -1
        je      .passed
.failed:
        stc
        ret
.passed:
        clc
        ret

__bi_cmp_512_512_greater_test:
        mov     rax, __bi_cmp_test_512.big
        mov     rbx, __bi_cmp_test_512.mid
        call    __bi_cmp_test_512
        cmp     rax, 1
        je      .passed
.failed:
        stc
        ret
.passed:
        clc
        ret

__bi_cmp_512_512_close_test:
        mov     rax, __bi_cmp_test_512.close_mid
        mov     rbx, __bi_cmp_test_512.mid
        call    __bi_cmp_test_512
        cmp     rax, 1
        je      .passed
.failed:
        stc
        ret
.passed:
        clc
        ret