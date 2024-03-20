if ~ definite bi_mul_low_128_128

include '../mul/bi_mul_64_64.inc'
include 'bi_mul_low_64_64.inc'

;Multiplies two bi128 values
;input
; rcx - left value
; rdx - right value
; r8 - result value (low 128 bits)
bi_mul_low_128_128:
virtual at rsp
.locals_start:
  .left rq 1
  .right rq 1
  .result rq 1
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.left]
        mov     rcx, [rcx + 0]
        mov     rdx, [.right]
        mov     rdx, [rdx + 0]
        mov     r8, [.result]
        call    bi_mul_64_64

        mov     rcx, [.left]
        mov     rcx, [rcx + 0]
        mov     rdx, [.right]
        mov     rdx, [rdx + 8]
        call    bi_mul_low_64_64
        mov     r8, [.result]
        add     [r8 + 8], rax

        mov     rcx, [.left]
        mov     rcx, [rcx + 8]
        mov     rdx, [.right]
        mov     rdx, [rdx + 0]
        call    bi_mul_low_64_64
        mov     r8, [.result]
        add     [r8 + 8], rax

        leave
        ret
end if