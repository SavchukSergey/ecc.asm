macro BigIntegerMulTests bits, dbits {

include '../src/math/bigint/mul/mul.inc'

BigIntegerMul bits, dbits

__bi_mul_test_#bits:
virtual at rsp
.locals_start:
  .left rb __BIG_INTEGER_BYTES_#bits
  .right rb __BIG_INTEGER_BYTES_#bits
  .actual_result rb __BIG_INTEGER_BYTES_#dbits
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0

        mov   rsi, __bi_mul_test.left_#bits
        lea   rdi, [.left]
        call  __bi_read_hex_#bits

        mov   rsi, __bi_mul_test.right_#bits
        lea   rdi, [.right]
        call  __bi_read_hex_#bits

        lea     rax, [.left]
        lea     rbx, [.right]
        lea     rdi, [.actual_result]
        call    test_context_start_measure
        call    __bi_mul_#bits
        call    test_context_end_measure

        lea     rax, [.actual_result]
        mov     rbx, __bi_mul_test.result_#bits
        call    expect_bi_equals_hex_#dbits
        jc     .failed

.passed:
        leave
        clc
        ret
.failed:
        leave
        stc
        ret
}


__bi_mul_test:
  .left_512    db 'ba42240ffb037f1a4c64905998460012cdf5f2e685baf6578d8eb71c34f932f81874bb356c05027886d076a3b80bad4d8122481d2b79b2135f4381e8326893e8'
  .right_512   db 'e43220d5e39ee79e8098c2cf65094404f6aad8d12f8bbff8b4ca17b77183acf90bfe17c68ef34e89e9650b0317d8c7b01949c45df01ad807af17a5bd72971bb8'
  .result_512  db 'A60760ED29D467DFF75670E661F7C75B9FA1E44A3663EC336A8D29971CB9A4413E79B5D4C44DCACA37C1783C66190709C929C3E9E99C102EEFDD96D808A36E5748FD7B8E374D65AE3D3C44300792DFE36742E721D6B31674B2A1E1AC43730930E026EDE67DB201B686430ABBD19E122562FA64A62034AA671E02E409D09BC6C0'
  
  .left_256    db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
  .right_256   db '42ee2737466d172a7dd3ec5c797b49a2f0db3a30fa26418148368b39b9b47053'
  .result_256  db '1D12DBCFC432E89183D10D1EAE34260870F397B818DF8118FC9B9A7A85E7322B04E694CB437F2D9CC15785B06F34EC8FD5A04C896866EB433352AFC9E5F4756A'
  
  .left_128    db '23e0715c2534cec45e6ac5894b97fccd'
  .right_128   db '6dce92970406d93ad874a75e73460deb'
  .result_128  db '0F63836A9E974E93A64D9962DE4654E2DC6ED62958AC31543527CE445369792F'

