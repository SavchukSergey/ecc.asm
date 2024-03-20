if ~ definite bi_mul_low_512_512

include '../mul/bi_mul_256_256.inc'
include '../add/bi_add_assign_256_256.inc'
include 'bi_mul_low_256_256.inc'

;Multiplies two bi512 values
;input
; rcx - left value
; rdx - right value
; r8 - result value (low 512 bits)
bi_mul_low_512_512:
virtual at rsp
.locals_start:
  .left rq 1
  .right rq 1
  .result rq 1
  .temp rb __BIG_INTEGER_BYTES_256

.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     r8, [.result]
        call    bi_mul_256_256

        mov     rcx, [.left]
        mov     rdx, [.right]
        add     rdx, __BIG_INTEGER_BYTES_256
        lea     r8, [.temp]
        call    bi_mul_low_256_256

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_256
        lea     rdx, [.temp]
        call    bi_add_assign_256_256

        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_256
        mov     rdx, [.right]
        lea     r8, [.temp]
        call    bi_mul_low_256_256

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_256
        lea     rdx, [.temp]
        call    bi_add_assign_256_256

        leave
        ret
end if