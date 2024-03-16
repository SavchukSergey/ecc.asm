include '../zero/zero.inc'
include '../add/add.inc'

;todo: Karatsuba. It requires careful overflow handling as z3 may exceed result

if ~ definite bi_mul_64_64

;Multiplies two bi128 values
;input
; rcx - left value
; rdx - right value
; r8 - pointer to result value
bi_mul_64_64:
        mov     rax, rcx
        mul     rdx
        mov     [r8], rax
        mov     [r8 + 8], rdx

        ret
end if

if ~ definite bi_mul_128_128

;Multiplies two bi128 values
;input
; rcx - left value
; rdx - right value
; r8 - result value
bi_mul_128_128:
virtual at rsp
.locals_start:
  ;Instead of .z0 .result is used to save one zero & copy operation ;.z0 rb __BIG_INTEGER_BYTES_256
  .z1 rb __BIG_INTEGER_BYTES_256
  .z2 rb __BIG_INTEGER_BYTES_256
  .z3 rb __BIG_INTEGER_BYTES_256
  .left rq 1
  .right rq 1
  .result rq 1
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.result]
        call    bi_zero_256
        lea     rcx, [.z1]
        call    bi_zero_256
        lea     rcx, [.z2]
        call    bi_zero_256
        lea     rcx, [.z3]
        call    bi_zero_256

        mov     rcx, [.left]
        mov     rcx, [rcx]
        mov     rdx, [.right]
        mov     rdx, [rdx]
        mov     r8, [.result]
        call    bi_mul_64_64

        mov     rcx, [.left]
        mov     rcx, [rcx]
        mov     rdx, [.right]
        mov     rdx, [rdx + __BIG_INTEGER_BYTES_128 / 2]
        lea     r8, [.z1 + __BIG_INTEGER_BYTES_128 / 2]
        call    bi_mul_64_64

        mov     rcx, [.left]
        mov     rcx, [rcx + __BIG_INTEGER_BYTES_128 / 2]
        mov     rdx, [.right]
        mov     rdx, [rdx]
        lea     r8, [.z2 + __BIG_INTEGER_BYTES_128 / 2]
        call    bi_mul_64_64

        mov     rcx, [.left]
        mov     rcx, [rcx + __BIG_INTEGER_BYTES_128 / 2]
        mov     rdx, [.right]
        mov     rdx, [rdx + __BIG_INTEGER_BYTES_128 / 2]
        lea     r8, [.z3 + __BIG_INTEGER_BYTES_128]
        call    bi_mul_64_64

        mov     rcx, [.result]
        lea     rdx, [.z1]
        call    bi_add_assign_256_256

        mov     rcx, [.result]
        lea     rdx, [.z2]
        call    bi_add_assign_256_256

        mov     rcx, [.result]
        lea     rdx, [.z3]
        call    bi_add_assign_256_256

        leave
        ret
end if

if ~ definite bi_mul_256_256

;Multiplies two bi256 values
;input
; rcx - left value
; rdx - right value
; r8 - result value
bi_mul_256_256:
virtual at rsp
.locals_start:
  ;Instead of .z0 .result is used to save one zero & copy operation ;.z0 rb __BIG_INTEGER_BYTES_512
  .z1 rb __BIG_INTEGER_BYTES_512
  .z2 rb __BIG_INTEGER_BYTES_512
  .z3 rb __BIG_INTEGER_BYTES_512
  .left rq 1
  .right rq 1
  .result rq 1
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.result]
        call    bi_zero_512
        lea     rcx, [.z1]
        call    bi_zero_512
        lea     rcx, [.z2]
        call    bi_zero_512
        lea     rcx, [.z3]
        call    bi_zero_512

        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     r8, [.result]
        call    bi_mul_128_128

        mov     rcx, [.left]
        mov     rdx, [.right]
        add     rdx, __BIG_INTEGER_BYTES_256 / 2
        lea     r8, [.z1]
        add     r8, __BIG_INTEGER_BYTES_256 / 2
        call    bi_mul_128_128

        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_256 / 2
        mov     rdx, [.right]
        lea     r8, [.z2]
        add     r8, __BIG_INTEGER_BYTES_256 / 2
        call    bi_mul_128_128

        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_256 / 2
        mov     rdx, [.right]
        add     rdx, __BIG_INTEGER_BYTES_256 / 2
        lea     r8, [.z3]
        add     r8, __BIG_INTEGER_BYTES_256
        call    bi_mul_128_128

        mov     rcx, [.result]
        lea     rdx, [.z1]
        call    bi_add_assign_512_512

        mov     rcx, [.result]
        lea     rdx, [.z2]
        call    bi_add_assign_512_512

        mov     rcx, [.result]
        lea     rdx, [.z3]
        call    bi_add_assign_512_512

        leave
        ret
end if


if ~ definite bi_mul_512_512

;Multiplies two bi512 values
;input
; rcx - left value
; rdx - right value
; r8 - result value
bi_mul_512_512:
virtual at rsp
.locals_start:
  ;Instead of .z0 .result is used to save one zero & copy operation ;.z0 rb __BIG_INTEGER_BYTES_1024
  .z1 rb __BIG_INTEGER_BYTES_1024
  .z2 rb __BIG_INTEGER_BYTES_1024
  .z3 rb __BIG_INTEGER_BYTES_1024
  .left rq 1
  .right rq 1
  .result rq 1
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.result]
        call    bi_zero_1024
        lea     rcx, [.z1]
        call    bi_zero_1024
        lea     rcx, [.z2]
        call    bi_zero_1024
        lea     rcx, [.z3]
        call    bi_zero_1024

        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     r8, [.result]
        call    bi_mul_256_256

        mov     rcx, [.left]
        mov     rdx, [.right]
        add     rdx, __BIG_INTEGER_BYTES_512 / 2
        lea     r8, [.z1]
        add     r8, __BIG_INTEGER_BYTES_512 / 2
        call    bi_mul_256_256

        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_512 / 2
        mov     rdx, [.right]
        lea     r8, [.z2]
        add     r8, __BIG_INTEGER_BYTES_512 / 2
        call    bi_mul_256_256

        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_512 / 2
        mov     rdx, [.right]
        add     rdx, __BIG_INTEGER_BYTES_512 / 2
        lea     r8, [.z3]
        add     r8, __BIG_INTEGER_BYTES_512
        call    bi_mul_256_256

        mov     rcx, [.result]
        lea     rdx, [.z1]
        call    bi_add_assign_1024_1024

        mov     rcx, [.result]
        lea     rdx, [.z2]
        call    bi_add_assign_1024_1024

        mov     rcx, [.result]
        lea     rdx, [.z3]
        call    bi_add_assign_1024_1024

        leave
        ret
end if
