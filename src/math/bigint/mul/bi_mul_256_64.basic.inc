;@docs-ignore

;Multiplies bi256 by bi64
;input:
; rcx - pointer to left bi256 value
; rdx - right bi64 value
; r8 - pointer to result bi320 value
bi_mul_256_64_basic:
virtual at rsp
.locals_start:
  .temp BigInteger128
  .left rq 1
  .right rq 1
  .result rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'bi_mul_256_64_basic'
    CheckRegAligned rcx, 'bi_mul_256_64_basic rcx'
    CheckRegAligned r8, 'bi_mul_256_64_basic r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.result]
        call    bi_zero_320

        mov     rcx, [.left]
        mov     rcx, [rcx + 0]
        mov     rdx, [.right]
        mov     r8, [.result]
        call    bi_mul_64_64


        mov     rcx, [.left]
        mov     rcx, [rcx + 8]
        mov     rdx, [.right]
        lea     r8, [.temp]
        call    bi_mul_64_64

;result will never exceed 320 so it is safe to use 256-bit addition here
        mov     rcx, [.result]
        add     rcx, 8
        lea     rdx, [.temp]
        call    bi_add_assign_256_128


        mov     rcx, [.left]
        mov     rcx, [rcx + 16]
        mov     rdx, [.right]
        lea     r8, [.temp]
        call    bi_mul_64_64

;result will never exceed 320 so it is safe to use 192-bit addition here
        mov     rcx, [.result]
        add     rcx, 16
        lea     rdx, [.temp]
        call    bi_add_assign_192_128


        mov     rcx, [.left]
        mov     rcx, [rcx + 24]
        mov     rdx, [.right]
        lea     r8, [.temp]
        call    bi_mul_64_64

;result will never exceed 320 so it is safe to use 128-bit addition here
        mov     rcx, [.result]
        add     rcx, 24
        lea     rdx, [.temp]
        call    bi_add_assign_128_128

        add     rsp, .locals_end - .locals_start
        ret
