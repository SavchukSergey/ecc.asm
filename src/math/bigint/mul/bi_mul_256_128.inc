if ~ definite bi_mul_256_128

include '../zero/bi_zero_512.inc'
include '../add/bi_add_assign_512_512.inc'
include 'bi_mul_128_128.inc'

;Multiplies bi256 value by bi128 value
;input
; rcx - left bi256 value
; rdx - right bi128 value
; r8 - result bi512 value
bi_mul_256_128:
virtual at rsp
.locals_start:
  .z0 rb __BIG_INTEGER_BYTES_256
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
        add     rcx, __BIG_INTEGER_BYTES_256
        call    bi_zero_256

        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     r8, [.result]
        call    bi_mul_128_128

        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_256 / 2
        mov     rdx, [.right]
        lea     r8, [.z0]
        call    bi_mul_128_128

;result will never exceed 384 so it is safe to use 256-bit addition here
;todo: Check everywhere
        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_256 / 2
        lea     rdx, [.z0]
        call    bi_add_assign_256_256

        add     rsp, .locals_end - .locals_start
        ret
end if