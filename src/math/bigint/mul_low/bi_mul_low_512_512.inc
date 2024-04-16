if ~ definite bi_mul_low_512_512

include '../mul/bi_mul_256_256.inc'
include '../add/bi_add_assign_256_256.inc'
include 'bi_mul_low_256_256.inc'

;Multiplies two bi512 values
;input
; rcx - pointer to left bi512 value
; rdx - pointer to right bi512 value
; r8 - pointer to bi512 result value (low 512 bits)
bi_mul_low_512_512:
virtual at rsp
.locals_start:
  .temp rb __BIG_INTEGER_BYTES_256
  .left rq 1
  .right rq 1
  .result rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

        PrologCheckStackAligned 'bi_mul_low_512_512'
        CheckRegAligned rcx, 'bi_mul_low_512_512 rcx'
        CheckRegAligned rdx, 'bi_mul_low_512_512 rdx'
        CheckRegAligned r8, 'bi_mul_low_512_512 r8'

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

        add     rsp, .locals_end - .locals_start
        ret
end if