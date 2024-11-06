if ~ definite bi_mul_128_128_low_128_basic

include '../mul/bi_mul_64_64.inc'
include 'bi_mul_64_64_low_64.inc'

;Multiplies two bi128 values
;input
; rcx - pointer to left bi128 value
; rdx - pointer to right bi128 value
; r8 - pointer to result bi128 value (low 128 bits)
bi_mul_128_128_low_128_basic:
virtual at rsp
.locals_start:
  .left rq 1
  .right rq 1
  .result rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'bi_mul_128_128_low_128_basic'
    CheckRegAligned rcx, 'bi_mul_128_128_low_128_basic rcx'
    CheckRegAligned rdx, 'bi_mul_128_128_low_128_basic rdx'
    CheckRegAligned r8, 'bi_mul_128_128_low_128_basic r8'

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
        call    bi_mul_64_64_low_64
        mov     r8, [.result]
        add     [r8 + 8], rax

        mov     rcx, [.left]
        mov     rcx, [rcx + 8]
        mov     rdx, [.right]
        mov     rdx, [rdx + 0]
        call    bi_mul_64_64_low_64
        mov     r8, [.result]
        add     [r8 + 8], rax

        add     rsp, .locals_end - .locals_start
        ret

end if