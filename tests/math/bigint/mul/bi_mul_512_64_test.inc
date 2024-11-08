__bi_mul_512_64_test_core:
BiMulTestCoreMacro 512, 64


__bi_mul_512_64_test:
        push    rbx
        lea     rbx, [__bi_mul_512_64_test_cases]

.loop:
        lea     rcx, [rbx]
        lea     rdx, [rbx + __BIG_INTEGER_HEX_DIGITS_512]
        lea     r8, [rbx + __BIG_INTEGER_HEX_DIGITS_512 + __BIG_INTEGER_HEX_DIGITS_64]
        call    __bi_mul_512_64_test_core

        add     rbx, __BIG_INTEGER_HEX_DIGITS_512 + __BIG_INTEGER_HEX_DIGITS_64 + __BIG_INTEGER_HEX_DIGITS_576
        cmp     rbx, __bi_mul_512_64_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_512_64_test_cases:
  db 'ba42240ffb037f1a4c64905998460012cdf5f2e685baf6578d8eb71c34f932f81874bb356c05027886d076a3b80bad4d8122481d2b79b2135f4381e8326893e8'
  db '42ee2737466d172a'
  db '30b25351f083e791a1ca7269d63a8402d2e279e66a737af4267b49103a3ab5dd6a9ed93e79e60f052883d91a68be2ed58c26a98ac1797b9260416b20926c15ec94155a70143a1c10'
  
  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffff'
  db 'fffffffffffffffeffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000000000000001'

.end:
