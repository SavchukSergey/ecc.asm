include '../../../../src/math/bigint/mul/bi_mul_192_64.inc'

include 'bi_mul_test_macro.inc'

__bi_mul_192_64_test_core:
BiMulTestCoreMacro 192, 64


__bi_mul_192_64_test:
        push    rbx
        lea     rbx, [__bi_mul_192_64_test_cases]

.loop:
        lea     rcx, [rbx]
        lea     rdx, [rbx + __BIG_INTEGER_HEX_DIGITS_192]
        lea     r8, [rbx + __BIG_INTEGER_HEX_DIGITS_192 + __BIG_INTEGER_HEX_DIGITS_64]
        call    __bi_mul_192_64_test_core

        add     rbx, __BIG_INTEGER_HEX_DIGITS_192 + __BIG_INTEGER_HEX_DIGITS_64 + __BIG_INTEGER_HEX_DIGITS_256
        cmp     rbx, __bi_mul_192_64_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_192_64_test_cases:
  db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621'
  db '42ee2737466d172a'
  db '1d12dbcfc432e8914d2899c63529058e5d54d3186cfb20cda9601841b79f786a'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffff'
  db 'fffffffffffffffeffffffffffffffffffffffffffffffff0000000000000001'

.end:
