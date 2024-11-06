include '../../../../src/math/bigint/mul_low/bi_mul_192_64_low_192.inc'

include 'bi_mul_low_test_macro.inc'

__bi_mul_192_64_low_192_test_core:
BiMulLowTestCoreMacro 192, 64, 192


__bi_mul_192_64_low_192_test:
        push    rbx
        lea     rbx, [__bi_mul_192_64_low_192_test_cases]
.loop:

        lea     rcx, [rbx]
        lea     rdx, [rbx + __BIG_INTEGER_HEX_DIGITS_192]
        lea     r8, [rbx + __BIG_INTEGER_HEX_DIGITS_192 + __BIG_INTEGER_HEX_DIGITS_64]
        call    __bi_mul_192_64_low_192_test_core

        add     rbx, __BIG_INTEGER_HEX_DIGITS_192 + __BIG_INTEGER_HEX_DIGITS_64 + __BIG_INTEGER_HEX_DIGITS_192
        cmp     rbx, __bi_mul_192_64_low_192_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_192_64_low_192_test_cases:
  db '8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db '42ee2737466d172a'
  db '5d54d3186cfb20cdd8dccf673140075dbe7f07855216b48c'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffff0000000000000001'

.end:
