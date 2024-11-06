include '../../../../src/math/bigint/mul_low/bi_mul_128_128_low_128.inc'

include 'bi_mul_low_test_macro.inc'

__bi_mul_128_128_low_128_test_core:
BiMulLowTestCoreMacro 128, 128, 128

__bi_mul_128_128_low_128_test:
        push    rbx
        mov     rbx, __bi_mul_128_128_low_128_test_cases
.loop:
        lea     rcx, [rbx + 0]
        lea     rdx, [rbx + __BIG_INTEGER_HEX_DIGITS_128]
        lea     r8, [rbx + __BIG_INTEGER_HEX_DIGITS_128 + __BIG_INTEGER_HEX_DIGITS_128]
        call    __bi_mul_128_128_low_128_test_core

        add     rbx, __BIG_INTEGER_HEX_DIGITS_128 + __BIG_INTEGER_HEX_DIGITS_128 + __BIG_INTEGER_HEX_DIGITS_128
        cmp     rbx, __bi_mul_128_128_low_128_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_128_128_low_128_test_cases:
  db '23e0715c2534cec45e6ac5894b97fccd'
  db '6dce92970406d93ad874a75e73460deb'
  db 'DC6ED62958AC31543527CE445369792F'

  db 'ffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffff'
  db '00000000000000000000000000000001'
.end: