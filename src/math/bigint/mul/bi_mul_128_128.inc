if ~ definite bi_mul_128_128

include '../zero/bi_zero_256.inc'
include '../add/bi_add_assign_256_256.inc'
include 'bi_mul_64_64.inc'

;Multiplies two bi128 values
;input
; rcx - pointer to left bi128 value
; rdx - pointer to right bi128 value
; r8 - pointer to result bi256 value
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
        sub     rsp, .locals_end - .locals_start
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

        add     rsp, .locals_end - .locals_start
        ret
end if