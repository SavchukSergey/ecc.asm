include '../../../../src/math/bigint/mul_low/bi_mul_128_64_low_128.inc'

include 'bi_mul_low_test_macro.inc'

__bi_mul_128_64_low_128_test_core:
BiMulLowTestCoreMacro 128, 64, 128

__bi_mul_128_64_low_128_test:
        push    rbx
        mov     rbx, __bi_mul_128_64_low_128_test_cases
.loop:
        lea     rcx, [rbx + 0]
        lea     rdx, [rbx + __BIG_INTEGER_HEX_DIGITS_128]
        lea     r8, [rbx + __BIG_INTEGER_HEX_DIGITS_128 + __BIG_INTEGER_HEX_DIGITS_64]
        call    __bi_mul_128_64_low_128_test_core

        add     rbx, __BIG_INTEGER_HEX_DIGITS_128 + __BIG_INTEGER_HEX_DIGITS_64 + __BIG_INTEGER_HEX_DIGITS_128
        cmp     rbx, __bi_mul_128_64_low_128_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_128_64_low_128_test_cases:
  db '23e0715c2534cec45e6ac5894b97fccd'
  db 'd874a75e73460deb'
  db '359D878C422525E23527CE445369792F'

  db 'ffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffff'
  db 'FFFFFFFFFFFFFFFF0000000000000001'
.end: