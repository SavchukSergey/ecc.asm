include '../../../../src/math/bigint/mul/bi_mul_256_256.inc'

include 'bi_mul_test_macro.inc'

__bi_mul_256_256_test_core:
BiMulTestCoreMacro 256, 256


__bi_mul_256_256_test:
        sub     rsp, 8
        lea     rbx, [__bi_mul_256_256_test_cases]

.loop:
        lea     rcx, [rbx]
        lea     rdx, [rbx + __BIG_INTEGER_HEX_DIGITS_256]
        lea     r8, [rbx + __BIG_INTEGER_HEX_DIGITS_256 + __BIG_INTEGER_HEX_DIGITS_256]
        call    __bi_mul_256_256_test_core

        add     rbx, __BIG_INTEGER_HEX_DIGITS_256 + __BIG_INTEGER_HEX_DIGITS_256 + __BIG_INTEGER_HEX_DIGITS_512
        cmp     rbx, __bi_mul_256_256_test_cases.end
        jb      .loop

        add     rsp, 8
        ret

align 16
__bi_mul_256_256_test_cases:
  db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db '42ee2737466d172a7dd3ec5c797b49a2f0db3a30fa26418148368b39b9b47053'
  db '1d12dbcfc432e89183d10d1eae34260870f397b818df8118fc9b9a7a85e7322b04e694cb437f2d9cc15785b06f34ec8fd5a04c896866eb433352afc9e5f4756a'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0000000000000000000000000000000000000000000000000000000000000001'

.end:
