include '../../../../src/math/bigint/mul/bi_mul_320_64.inc'

include 'bi_mul_test_macro.inc'

__bi_mul_320_64_test_core:
BiMulTestCoreMacro 320, 64


__bi_mul_320_64_test:
        push    rbx
        lea     rbx, [__bi_mul_320_64_test_cases]

.loop:
        lea     rcx, [rbx]
        lea     rdx, [rbx + __BIG_INTEGER_HEX_DIGITS_320]
        lea     r8, [rbx + __BIG_INTEGER_HEX_DIGITS_320 + __BIG_INTEGER_HEX_DIGITS_64]
        call    __bi_mul_320_64_test_core

        add     rbx, __BIG_INTEGER_HEX_DIGITS_320 + __BIG_INTEGER_HEX_DIGITS_64 + __BIG_INTEGER_HEX_DIGITS_384
        cmp     rbx, __bi_mul_320_64_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_320_64_test_cases:
  db '8d8eb71c34f932f81874bb356c05027886d076a3b80bad4d8122481d2b79b2135f4381e8326893e8'
  db '42ee2737466d172a'
  db '25027b92d0617a976a9ed93e79e60f052883d91a68be2ed58c26a98ac1797b9260416b20926c15ec94155a70143a1c10'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffff'
  db 'fffffffffffffffeffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000000000000001'

.end:

