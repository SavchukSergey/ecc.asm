__bi_mul_512_512_low_512_test_core:
BiMulLowTestCoreMacro 512, 512, 512

__bi_mul_512_512_low_512_test:
        push    rbx
        lea     rbx, [__bi_mul_512_512_low_512_test_cases]

.loop:
        lea     rcx, [rbx]
        lea     rdx, [rbx + __BIG_INTEGER_HEX_DIGITS_512]
        lea     r8, [rbx + __BIG_INTEGER_HEX_DIGITS_512 + __BIG_INTEGER_HEX_DIGITS_512]
        call    __bi_mul_512_512_low_512_test_core

        add     rbx, __BIG_INTEGER_HEX_DIGITS_512 + __BIG_INTEGER_HEX_DIGITS_512 + __BIG_INTEGER_HEX_DIGITS_512
        cmp     rbx, __bi_mul_512_512_low_512_test_cases.end
        jb      .loop

        pop     rbx
        ret


align 16
__bi_mul_512_512_low_512_test_cases:
  db 'ba42240ffb037f1a4c64905998460012cdf5f2e685baf6578d8eb71c34f932f81874bb356c05027886d076a3b80bad4d8122481d2b79b2135f4381e8326893e8'
  db 'e43220d5e39ee79e8098c2cf65094404f6aad8d12f8bbff8b4ca17b77183acf90bfe17c68ef34e89e9650b0317d8c7b01949c45df01ad807af17a5bd72971bb8'
  db '48FD7B8E374D65AE3D3C44300792DFE36742E721D6B31674B2A1E1AC43730930E026EDE67DB201B686430ABBD19E122562FA64A62034AA671E02E409D09BC6C0'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db '00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001'

.end:
