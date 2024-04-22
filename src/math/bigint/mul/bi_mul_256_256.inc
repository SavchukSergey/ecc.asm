if ~ definite bi_mul_256_256

include '../zero/bi_zero_512.inc'
include '../add/bi_add_assign_256_256.inc'
include '../add/bi_add_assign_384_256.inc'
include 'bi_mul_128_128.inc'

;Multiplies two bi256 values
;input
; rcx - left value
; rdx - right value
; r8 - result value
bi_mul_256_256____128_128:
virtual at rsp
.locals_start:
  BigInteger256 .temp
  .left rq 1
  .right rq 1
  .result rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

        PrologCheckStackAligned 'bi_mul_256_256'
        CheckRegAligned rcx, 'bi_mul_256_256 rcx'
        CheckRegAligned rdx, 'bi_mul_256_256 rdx'
        CheckRegAligned r8, 'bi_mul_256_256 r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.result]
        call    bi_zero_512

; b * d (256 bit)
        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     r8, [.result]
        call    bi_mul_128_128

; b * c (256 bit)
        mov     rcx, [.left]
        mov     rdx, [.right]
        add     rdx, __BIG_INTEGER_BYTES_256 / 2
        lea     r8, [.temp]
        call    bi_mul_128_128

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_128
        lea     rdx, [.temp]
        call    bi_add_assign_384_256

; a * d (256 bit)
        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_256 / 2
        mov     rdx, [.right]
        lea     r8, [.temp]
        call    bi_mul_128_128

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_128
        lea     rdx, [.temp]
        call    bi_add_assign_384_256

; a * c (256 bit)
        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_256 / 2
        mov     rdx, [.right]
        add     rdx, __BIG_INTEGER_BYTES_256 / 2
        lea     r8, [.temp]
        call    bi_mul_128_128

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_256
        lea     rdx, [.temp]
        call    bi_add_assign_256_256

        add     rsp, .locals_end - .locals_start
        ret


;Multiplies bi256 value by bi256 value
;input
;  rcx - left bi256 value
;  rdx - right bi256 value
;  r8 - result bi512 value
bi_mul_256_256____256_64:
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

    PrologCheckStackAligned 'bi_mul_256_128'
    CheckRegAligned rcx, 'bi_mul_256_128 rcx'
    CheckRegAligned rdx, 'bi_mul_256_128 rdx'
    CheckRegAligned r8, 'bi_mul_256_128 r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     rdx, [rdx]
        mov     r8, [.result]
        call    bi_mul_256_64



        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     rdx, [rdx + 8]
        lea     r8, [.temp]
        call    bi_mul_256_64

        mov     rcx, [.result]
        add     rcx, 8
        lea     rdx, [.temp]
        call    bi_add_assign_320_256


        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     rdx, [rdx + 16]
        lea     r8, [.temp]
        call    bi_mul_256_64

        mov     rcx, [.result]
        add     rcx, 16
        lea     rdx, [.temp]
        call    bi_add_assign_320_256



        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     rdx, [rdx + 24]
        lea     r8, [.temp]
        call    bi_mul_256_64

        mov     rcx, [.result]
        add     rcx, 24
        lea     rdx, [.temp]
        call    bi_add_assign_320_256

        add     rsp, .locals_end - .locals_start
        ret

bi_mul_256_256 = bi_mul_256_256____256_64

end if