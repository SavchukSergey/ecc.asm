include '../../../../src/math/bigint/mul/bi_mul_256_256.inc'

include 'bi_mul_test_macro.inc'

__bi_mul_256_256_test_core:
BiMulTestCoreMacro 256, 256

__bi_mul_256_256_test:
        sub     rsp, 8
        lea     rbx, [__bi_mul_256_256_test_cases]
.loop:
        lea     rcx, [rbx]
        lea     rdx, [rbx + 64]
        lea     r8, [rbx + 128]
        call    __bi_mul_256_256_test_core

        add     rbx, 64 + 64 + 128
        cmp     rbx, __bi_mul_256_256_test_cases.end
        jb      .loop

        add     rsp, 8
        ret

align 16
__bi_mul_256_256_test_cases:
  db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  db '42ee2737466d172a7dd3ec5c797b49a2f0db3a30fa26418148368b39b9b47053'
  db '1D12DBCFC432E89183D10D1EAE34260870F397B818DF8118FC9B9A7A85E7322B04E694CB437F2D9CC15785B06F34EC8FD5A04C896866EB433352AFC9E5F4756A'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0000000000000000000000000000000000000000000000000000000000000001'

.end:
