if ~ definite bi_square_256

include '../zero/bi_zero_512.inc'
include '../add/bi_add_assign_256_256.inc'
include '../add/bi_add_assign_384_256.inc'
include 'bi_square_128.inc'

;Squares bi256 value
;input
; rcx - pointer to bi256 value
; rdx - pointer to bi512 result
bi_square_256__temp:
;todo: this can be optimized
        mov     r8, rdx
        mov     rdx, rcx
        call    bi_mul_256_256
        ret

;Squares bi256 value
;input
; rcx - pointer to bi256 value
; rdx - pointer to bi512 result
bi_square_256:
virtual at rsp
.locals_start:
  BigInteger256 .temp
  .value rq 1
  .result rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

        PrologCheckStackAligned 'bi_square_256'
        CheckRegAligned rcx, 'bi_square_256 rcx'
        CheckRegAligned rdx, 'bi_square_256 rdx'

        mov     [.value], rcx
        mov     [.result], rdx

        mov     rcx, [.result]
        call    bi_zero_512

; low * low (256 bit)
        mov     rcx, [.value]
        mov     rdx, [.result]
        call    bi_square_128

; low * high (256 bit)
        mov     rcx, [.value]
        lea     rdx, [rcx + __BIG_INTEGER_BYTES_256 / 2]
        lea     r8, [.temp]
        call    bi_mul_128_128

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_128
        lea     rdx, [.temp]
        call    bi_add_assign_384_256

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_128
        lea     rdx, [.temp]
        call    bi_add_assign_384_256

; high * high (256 bit)
        mov     rcx, [.value]
        add     rcx, __BIG_INTEGER_BYTES_256 / 2
        lea     rdx, [.temp]
        call    bi_square_128

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_256
        lea     rdx, [.temp]
        call    bi_add_assign_256_256

        add     rsp, .locals_end - .locals_start
        ret
end if