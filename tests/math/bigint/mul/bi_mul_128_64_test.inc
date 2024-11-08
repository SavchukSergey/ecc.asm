__bi_mul_128_64_test_core:
BiMulTestCoreMacro 128, 64


__bi_mul_128_64_test:
        push    rbx
        lea     rbx, [__bi_mul_128_64_test_cases]

.loop:
        lea     rcx, [rbx]
        lea     rdx, [rbx + __BIG_INTEGER_HEX_DIGITS_128]
        lea     r8, [rbx + __BIG_INTEGER_HEX_DIGITS_128 + __BIG_INTEGER_HEX_DIGITS_64]
        call    __bi_mul_128_64_test_core

        add     rbx, __BIG_INTEGER_HEX_DIGITS_128 + __BIG_INTEGER_HEX_DIGITS_64 + __BIG_INTEGER_HEX_DIGITS_192
        cmp     rbx, __bi_mul_128_64_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_128_64_test_cases:
  db '23e0715c2534cec45e6ac5894b97fccd'
  db 'd874a75e73460deb'
  db '1E55B8CDC3A9CABD359D878C422525E23527CE445369792F'

  db 'ffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffff'
  db 'FFFFFFFFFFFFFFFEFFFFFFFFFFFFFFFF0000000000000001'

.end:
