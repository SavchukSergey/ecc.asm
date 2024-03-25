if ~ definite bi_mul_512_512

include '../zero/bi_zero_1024.inc'
include '../add/bi_add_assign_1024_1024.inc'
include 'bi_mul_256_256.inc'

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
        sub     rsp, .locals_end - .locals_start
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
        lea     r8, [.z1 + __BIG_INTEGER_BYTES_512 / 2]
        call    bi_mul_256_256

        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_512 / 2
        mov     rdx, [.right]
        lea     r8, [.z2 + __BIG_INTEGER_BYTES_512 / 2]
        call    bi_mul_256_256

        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_512 / 2
        mov     rdx, [.right]
        add     rdx, __BIG_INTEGER_BYTES_512 / 2
        lea     r8, [.z3 + __BIG_INTEGER_BYTES_512]
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

        add     rsp, .locals_end - .locals_start
        ret
end if
