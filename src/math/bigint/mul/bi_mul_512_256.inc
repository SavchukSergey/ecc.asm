if ~ definite bi_mul_512_256

include '../add/bi_add_assign_768_512.inc'
include '../zero/bi_zero_1024.inc'
include 'bi_mul_256_256.inc'

;Multiplies bi512 by bi256 value
;input
; rcx - pointer to left bi512 value
; rdx - pointer to right bi256 value
; r8 - pointer to result bi1024 value
bi_mul_512_256:
virtual at rsp
.locals_start:
  BigInteger512 .temp
  .left rq 1
  .right rq 1
  .result rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

        PrologCheckStackAligned 'bi_mul_512_256'
        CheckRegAligned rcx, 'bi_mul_512_256 rcx'
        CheckRegAligned rdx, 'bi_mul_512_256 rdx'
        CheckRegAligned r8, 'bi_mul_512_256 r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.result]
        call    bi_zero_1024

; b * d (512 bit)
        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     r8, [.result]
        call    bi_mul_256_256

; a * d (512 bit)
        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_512 / 2
        mov     rdx, [.right]
        lea     r8, [.temp]
        call    bi_mul_256_256

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_256
        lea     rdx, [.temp]
        call    bi_add_assign_768_512

        add     rsp, .locals_end - .locals_start
        ret
end if
