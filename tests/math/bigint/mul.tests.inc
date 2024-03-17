include '../src/math/bigint/mul/index.inc'
include '../../assert.inc'

__bi_mul_128_128_test_core:
virtual at rsp
.locals_start:
  .left_hex rq 1
  .right_hex rq 1
  .expected_hex rq 1
  .left rb __BIG_INTEGER_BYTES_128
  .right rb __BIG_INTEGER_BYTES_128
  .result rb __BIG_INTEGER_BYTES_256
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.left_hex], rcx
        mov     [.right_hex], rdx
        mov     [.expected_hex], r8

        mov     rcx, [.left_hex]
        lea     rdx, [.left]
        call    bi_try_read_hex_128

        mov     rcx, [.right_hex]
        lea     rdx, [.right]
        call    bi_try_read_hex_128

        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    test_context_start_measure
        call    bi_mul_128_128
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_256

        jmp     .pass

.fail:
        leave
        stc
        ret
.pass:
        leave
        clc
        ret

__bi_mul_128_128_test:
        lea     rcx, [.left_hex]
        lea     rdx, [.right_hex]
        lea     r8, [.expected_hex]
        call    __bi_mul_128_128_test_core
        ret
.left_hex       db '23e0715c2534cec45e6ac5894b97fccd'
.right_hex      db '6dce92970406d93ad874a75e73460deb'
.expected_hex   db '0F63836A9E974E93A64D9962DE4654E2DC6ED62958AC31543527CE445369792F'


__bi_mul_128_128_max_test:
        lea     rcx, [.left_hex]
        lea     rdx, [.right_hex]
        lea     r8, [.expected_hex]
        call    __bi_mul_128_128_test_core
        ret
.left_hex       db 'ffffffffffffffffffffffffffffffff'
.right_hex      db 'ffffffffffffffffffffffffffffffff'
.expected_hex   db 'FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE00000000000000000000000000000001'

__bi_mul_256_256_test_core:
virtual at rsp
.locals_start:
  .left_hex rq 1
  .right_hex rq 1
  .expected_hex rq 1
  .left rb __BIG_INTEGER_BYTES_256
  .right rb __BIG_INTEGER_BYTES_256
  .result rb __BIG_INTEGER_BYTES_512
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.left_hex], rcx
        mov     [.right_hex], rdx
        mov     [.expected_hex], r8

        mov     rcx, [.left_hex]
        lea     rdx, [.left]
        call    bi_try_read_hex_256

        mov     rcx, [.right_hex]
        lea     rdx, [.right]
        call    bi_try_read_hex_256

        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    test_context_start_measure
        call    bi_mul_256_256
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_512

        jmp     .pass

.fail:
        leave
        stc
        ret
.pass:
        leave
        clc
        ret

__bi_mul_256_256_test:
        lea     rcx, [.left_hex]
        lea     rdx, [.right_hex]
        lea     r8, [.expected_hex]
        call    __bi_mul_256_256_test_core
        ret
.left_hex       db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
.right_hex      db '42ee2737466d172a7dd3ec5c797b49a2f0db3a30fa26418148368b39b9b47053'
.expected_hex   db '1D12DBCFC432E89183D10D1EAE34260870F397B818DF8118FC9B9A7A85E7322B04E694CB437F2D9CC15785B06F34EC8FD5A04C896866EB433352AFC9E5F4756A'

__bi_mul_256_256_max_test:
        lea     rcx, [.left_hex]
        lea     rdx, [.right_hex]
        lea     r8, [.expected_hex]
        call    __bi_mul_256_256_test_core
        ret
.left_hex       db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
.right_hex      db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
.expected_hex   db 'FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE0000000000000000000000000000000000000000000000000000000000000001'

__bi_mul_512_512_test_core:
virtual at rsp
.locals_start:
  .left_hex rq 1
  .right_hex rq 1
  .expected_hex rq 1
  .left rb __BIG_INTEGER_BYTES_512
  .right rb __BIG_INTEGER_BYTES_512
  .result rb __BIG_INTEGER_BYTES_1024
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.left_hex], rcx
        mov     [.right_hex], rdx
        mov     [.expected_hex], r8

        mov     rcx, [.left_hex]
        lea     rdx, [.left]
        call    bi_try_read_hex_512

        mov     rcx, [.right_hex]
        lea     rdx, [.right]
        call    bi_try_read_hex_512

        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    test_context_start_measure
        call    bi_mul_512_512
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        call    bi_assert_equal_hex_1024

        jmp     .pass

.fail:
        leave
        stc
        ret
.pass:
        leave
        clc
        ret


__bi_mul_512_512_test:
        lea     rcx, [.left_hex]
        lea     rdx, [.right_hex]
        lea     r8, [.expected_hex]
        call    __bi_mul_512_512_test_core
        ret
.left_hex       db 'ba42240ffb037f1a4c64905998460012cdf5f2e685baf6578d8eb71c34f932f81874bb356c05027886d076a3b80bad4d8122481d2b79b2135f4381e8326893e8'
.right_hex      db 'e43220d5e39ee79e8098c2cf65094404f6aad8d12f8bbff8b4ca17b77183acf90bfe17c68ef34e89e9650b0317d8c7b01949c45df01ad807af17a5bd72971bb8'
.expected_hex   db 'A60760ED29D467DFF75670E661F7C75B9FA1E44A3663EC336A8D29971CB9A4413E79B5D4C44DCACA37C1783C66190709C929C3E9E99C102EEFDD96D808A36E5748FD7B8E374D65AE3D3C44300792DFE36742E721D6B31674B2A1E1AC43730930E026EDE67DB201B686430ABBD19E122562FA64A62034AA671E02E409D09BC6C0'

__bi_mul_512_512_max_test:
        lea     rcx, [.left_hex]
        lea     rdx, [.right_hex]
        lea     r8, [.expected_hex]
        call    __bi_mul_512_512_test_core
        ret
.left_hex       db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
.right_hex      db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffff'
.expected_hex   db 'ffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffffFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001'