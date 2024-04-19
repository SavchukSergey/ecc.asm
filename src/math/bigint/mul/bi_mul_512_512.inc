if ~ definite bi_mul_512_512

include '../zero/bi_zero_1024.inc'
include '../add/bi_add_assign_512_512.inc'
include '../add/bi_add_assign_768_512.inc'
include '../add/bi_add_assign_1024_512.inc'
include 'bi_mul_256_256.inc'

;Multiplies two bi512 values
;input
; rcx - pointer to left bi512 value
; rdx - pointer to right bi512 value
; r8 - pointer to result bi1024 value
bi_mul_512_512:
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

        PrologCheckStackAligned 'bi_mul_512_512'
        CheckRegAligned rcx, 'bi_mul_512_512 rcx'
        CheckRegAligned rdx, 'bi_mul_512_512 rdx'
        CheckRegAligned r8, 'bi_mul_512_512 r8'

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

; b * c (512 bit)
        mov     rcx, [.left]
        mov     rdx, [.right]
        add     rdx, __BIG_INTEGER_BYTES_512 / 2
        lea     r8, [.temp]
        call    bi_mul_256_256

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_256
        lea     rdx, [.temp]
        call    bi_add_assign_768_512

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

; a * c (512 bit)
        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_512 / 2
        mov     rdx, [.right]
        add     rdx, __BIG_INTEGER_BYTES_512 / 2
        lea     r8, [.temp]
        call    bi_mul_256_256

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_512
        lea     rdx, [.temp]
        call    bi_add_assign_512_512

        add     rsp, .locals_end - .locals_start
        ret
end if
