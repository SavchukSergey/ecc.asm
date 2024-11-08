__bi_mul_512_256_test_core:
BiMulTestCoreMacro 512, 256


__bi_mul_512_256_test:
        push    rbx
        lea     rbx, [__bi_mul_512_256_test_cases]

.loop:
        lea     rcx, [rbx]
        lea     rdx, [rbx + __BIG_INTEGER_HEX_DIGITS_512]
        lea     r8, [rbx + __BIG_INTEGER_HEX_DIGITS_512 + __BIG_INTEGER_HEX_DIGITS_256]
        call    __bi_mul_512_256_test_core

        add     rbx, __BIG_INTEGER_HEX_DIGITS_512 + __BIG_INTEGER_HEX_DIGITS_256 + __BIG_INTEGER_HEX_DIGITS_768
        cmp     rbx, __bi_mul_512_256_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_512_256_test_cases:
  db 'ba42240ffb037f1a4c64905998460012cdf5f2e685baf6578d8eb71c34f932f81874bb356c05027886d076a3b80bad4d8122481d2b79b2135f4381e8326893e8'
  db '0bfe17c68ef34e89e9650b0317d8c7b01949c45df01ad807af17a5bd72971bb8'
  db '08b9b678e00b3dc54918dff7b0901aadc24f52b90f136f1131c1001545f0f1acc76eb9dd142ae00f90051d17e45a05ba7a335dc36b80e8f17382fd4fe0a34c88e026ede67db201b686430abbd19e122562fa64a62034aa671e02e409d09bc6c0'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffeffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff0000000000000000000000000000000000000000000000000000000000000001'

.end:
