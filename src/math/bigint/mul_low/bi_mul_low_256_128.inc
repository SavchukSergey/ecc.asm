if ~ definite bi_mul_low_256_128

include '../mul/bi_mul_128_128.inc'
include '../add/bi_add_assign_128_128.inc'
include 'bi_mul_low_128_128.inc'

;Multiplies bi256 by bi128 value and return low 256 bits
;input
;  rcx - pointer to bi256 left value
;  rdx - pointer to bi128 right value
;  r8 - result value (low 256 bits)
bi_mul_low_256_128:
virtual at rsp
.locals_start:
  BigInteger128 .temp
  .left rq 1
  .right rq 1
  .result rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'bi_mul_low_256_128'
    CheckRegAligned rcx, 'bi_mul_low_256_128 rcx'
    CheckRegAligned rdx, 'bi_mul_low_256_128 rdx'
    CheckRegAligned r8, 'bi_mul_low_256_128 r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     r8, [.result]
        call    bi_mul_128_128

        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_128
        mov     rdx, [.right]
        lea     r8, [.temp]
        call    bi_mul_low_128_128

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_128
        lea     rdx, [.temp]
        call    bi_add_assign_128_128

        add     rsp, .locals_end - .locals_start
        ret
end if