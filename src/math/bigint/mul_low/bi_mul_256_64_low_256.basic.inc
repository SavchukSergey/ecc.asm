if ~ definite bi_mul_256_64_low_256_basic

;Multiplies bi256 by bi64 value and return low 256 bits
;input
;  rcx - pointer to bi256 left value
;  rdx - bi64 right value
;  r8 - result value (low 256 bits)
bi_mul_256_64_low_256_basic:
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

    PrologCheckStackAligned 'bi_mul_256_64_low_256_basic'
    CheckRegAligned rcx, 'bi_mul_256_64_low_256_basic rcx'
    CheckRegAligned r8, 'bi_mul_256_64_low_256_basic r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.left]
        mov     rdx, [.right]
        mov     r8, [.result]
        call    bi_mul_128_64

        mov     rcx, [.left]
        add     rcx, __BIG_INTEGER_BYTES_128
        mov     rdx, [.right]
        lea     r8, [.temp]
        call    bi_mul_128_64_low_128

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_128
        lea     rdx, [.temp]
        call    bi_add_assign_128_128

        add     rsp, .locals_end - .locals_start
        ret

end if