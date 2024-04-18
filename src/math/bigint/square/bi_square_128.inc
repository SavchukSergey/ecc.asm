if ~ definite bi_square_128

include '../zero/bi_zero_256.inc'
include '../add/bi_add_assign_128_128.inc'
include '../add/bi_add_assign_192_128.inc'
include 'bi_square_64.inc'

;Squares bi128 value
;input
; rcx - pointer to bi128 value
; rdx - pointer to bi256 result
bi_square_128:
virtual at rsp
.locals_start:
  BigInteger128 .temp
  .value rq 1
  .result rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

        PrologCheckStackAligned 'bi_square_128'
        CheckRegAligned rcx, 'bi_square_128 rcx'
        CheckRegAligned rdx, 'bi_square_128 rdx'

        mov     [.value], rcx
        mov     [.result], rdx

        mov     rcx, [.result]
        call    bi_zero_256

; low * low (128 bit)
        mov     rcx, [.value]
        mov     rcx, [rcx]
        mov     rdx, [.result]
        call    bi_square_64

; low * high (128 bit)
        mov     rax, [.value]
        mov     rcx, [rax]
        mov     rdx, [rax + __BIG_INTEGER_BYTES_128 / 2]
        lea     r8, [.temp]
        call    bi_mul_64_64

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_128 / 2
        lea     rdx, [.temp]
        call    bi_add_assign_192_128

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_128 / 2
        lea     rdx, [.temp]
        call    bi_add_assign_192_128

; high * high (128 bit)
        mov     rcx, [.value]
        mov     rcx, [rcx + 8]
        lea     rdx, [.temp]
        call    bi_square_64

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_128
        lea     rdx, [.temp]
        call    bi_add_assign_128_128

        add     rsp, .locals_end - .locals_start
        ret
end if