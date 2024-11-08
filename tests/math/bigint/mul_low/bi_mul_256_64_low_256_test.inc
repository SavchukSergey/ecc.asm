__bi_mul_256_64_low_256_test_core:
BiMulLowTestCoreMacro 256, 64, 256


__bi_mul_256_64_low_256_test:
        push    rbx
        lea     rbx, [__bi_mul_256_64_low_256_test_cases]
.loop:

        lea     rcx, [rbx]
        lea     rdx, [rbx + __BIG_INTEGER_HEX_DIGITS_256]
        lea     r8, [rbx + __BIG_INTEGER_HEX_DIGITS_256 + __BIG_INTEGER_HEX_DIGITS_64]
        call    __bi_mul_256_64_low_256_test_core

        add     rbx, __BIG_INTEGER_HEX_DIGITS_256 + __BIG_INTEGER_HEX_DIGITS_64 + __BIG_INTEGER_HEX_DIGITS_256
        cmp     rbx, __bi_mul_256_64_low_256_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_256_64_low_256_test_cases:
  db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db '42ee2737466d172a'
  db '4d2899c63529058e5d54d3186cfb20cdd8dccf673140075dbe7f07855216b48c'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffffffffffffffffffff0000000000000001'

.end:
