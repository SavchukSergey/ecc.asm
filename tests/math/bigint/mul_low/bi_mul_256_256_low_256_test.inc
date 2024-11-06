include '../../../../src/math/bigint/mul_low/bi_mul_256_256_low_256.inc'

include 'bi_mul_low_test_macro.inc'

__bi_mul_256_256_low_256_test_core:
BiMulLowTestCoreMacro 256, 256, 256

__bi_mul_256_256_low_256_test:
        push    rbx

        mov     rbx, __bi_mul_256_256_low_256_test_cases
.loop:
        lea     rcx, [rbx + 0]
        lea     rdx, [rbx + __BIG_INTEGER_HEX_DIGITS_256]
        lea     r8, [rbx + __BIG_INTEGER_HEX_DIGITS_256 + __BIG_INTEGER_HEX_DIGITS_256]
        call    __bi_mul_256_256_low_256_test_core

        add     rbx, __BIG_INTEGER_HEX_DIGITS_256 + __BIG_INTEGER_HEX_DIGITS_256 + __BIG_INTEGER_HEX_DIGITS_256
        cmp     rbx, __bi_mul_256_256_low_256_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_256_256_low_256_test_cases:
  db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db '42ee2737466d172a7dd3ec5c797b49a2f0db3a30fa26418148368b39b9b47053'
  db '04E694CB437F2D9CC15785B06F34EC8FD5A04C896866EB433352AFC9E5F4756A'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db '0000000000000000000000000000000000000000000000000000000000000001'
.end: