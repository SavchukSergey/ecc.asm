include '../../../../src/math/bigint/mul/bi_mul_256_128.inc'

include 'bi_mul_test_macro.inc'

__bi_mul_256_128_test_core:
BiMulTestCoreMacro 256, 128


__bi_mul_256_128_test:
        push    rbx
        lea     rbx, [__bi_mul_256_128_test_cases]

.loop:

        lea     rcx, [rbx]
        lea     rdx, [rbx + __BIG_INTEGER_HEX_DIGITS_256]
        lea     r8, [rbx + __BIG_INTEGER_HEX_DIGITS_256 +  + __BIG_INTEGER_HEX_DIGITS_128]
        call    __bi_mul_256_128_test_core

        add     rbx, __BIG_INTEGER_HEX_DIGITS_256 + __BIG_INTEGER_HEX_DIGITS_128 + __BIG_INTEGER_HEX_DIGITS_384
        cmp     rbx, __bi_mul_256_128_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_256_128_test_cases:
  db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db '42ee2737466d172a7dd3ec5c797b49a2'
  db '1d12dbcfc432e89183d10d1eae34260808539b663161e360464cfb5ff27c491397da3a52329343fcfc31c2fc86940a1c'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffff'
  db 'fffffffffffffffffffffffffffffffeffffffffffffffffffffffffffffffff00000000000000000000000000000001'

.end:
