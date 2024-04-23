if ~ definite bi_mul_low_512_64

include '../mul/bi_mul_256_64.inc'

;Multiplies bi512 by bi64 value and return low 512 bits
;input
;  rcx - pointer to bi512 left value
;  rdx - bi64 right value
;  r8 - result value (low 512 bits)
bi_mul_low_512_64:
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

    PrologCheckStackAligned 'bi_mul_low_512_64'
    CheckRegAligned rcx, 'bi_mul_low_512_64 rcx'
    CheckRegAligned r8, 'bi_mul_low_512_64 r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     r8, [.result]
        call    bi_mul_256_64

        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_256
        mov     rdx, [.right]
        lea     r8, [.temp]
        call    bi_mul_low_256_64

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_256
        lea     rdx, [.temp]
        call    bi_add_assign_256_256

        add     rsp, .locals_end - .locals_start
        ret
end if