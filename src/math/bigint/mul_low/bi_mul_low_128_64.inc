if ~ definite bi_mul_low_128_64

include '../mul/bi_mul_64_64.inc'
include 'bi_mul_low_64_64.inc'

;Multiplies bi128 by bi64 values
;input
; rcx - pointer to left bi128 value
; rdx - right bi64 value
; r8 - result value (low 128 bits)
bi_mul_low_128_64:
virtual at rsp
.locals_start:
  .left rq 1
  .right rq 1
  .result rq 1
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.left]
        mov     rcx, [rcx + 0]
        mov     rdx, [.right]
        mov     r8, [.result]
        call    bi_mul_64_64

        mov     rcx, [.left]
        mov     rcx, [rcx + 8]
        mov     rdx, [.right]
        call    bi_mul_low_64_64
        mov     r8, [.result]
        add     [r8 + 8], rax

        add     rsp, .locals_end - .locals_start
        ret
end if