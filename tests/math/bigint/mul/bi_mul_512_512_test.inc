include '../../../../src/math/bigint/mul/bi_mul_512_512.inc'

include 'bi_mul_test_macro.inc'

__bi_mul_512_512_test_core:
BiMulTestCoreMacro 512, 512


__bi_mul_512_512_test:
        push    rbx
        lea     rbx, [__bi_mul_512_512_test_cases]

.loop:
        lea     rcx, [rbx]
        lea     rdx, [rbx + 128]
        lea     r8, [rbx + 256]
        call    __bi_mul_512_512_test_core

        add     rbx, 128 + 128 + 256
        cmp     rbx, __bi_mul_512_512_test_cases.end
        jb      .loop

        pop     rbx
        ret

align 16
__bi_mul_512_512_test_cases:
  db 'ba42240ffb037f1a4c64905998460012cdf5f2e685baf6578d8eb71c34f932f81874bb356c05027886d076a3b80bad4d8122481d2b79b2135f4381e8326893e8'
  db 'e43220d5e39ee79e8098c2cf65094404f6aad8d12f8bbff8b4ca17b77183acf90bfe17c68ef34e89e9650b0317d8c7b01949c45df01ad807af17a5bd72971bb8'
  db 'a60760ed29d467dff75670e661f7c75b9fa1e44a3663ec336a8d29971cb9a4413e79b5d4c44dcaca37c1783c66190709c929c3e9e99c102eefdd96d808a36e5748fd7b8e374d65ae3d3c44300792dfe36742e721d6b31674b2a1e1ac43730930e026ede67db201b686430abbd19e122562fa64a62034aa671e02e409d09bc6c0'

  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
  db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffe00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001'

.end:
