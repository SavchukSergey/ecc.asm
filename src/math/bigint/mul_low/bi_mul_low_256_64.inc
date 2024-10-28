if ~ definite bi_mul_low_256_64

include '../mul/bi_mul_128_64.inc'
include '../mul_low/bi_mul_low_128_64.inc'

;Multiplies bi256 by bi64 value and return low 256 bits
;input
;  rcx - pointer to bi256 left value
;  rdx - bi64 right value
;  r8 - result value (low 256 bits)
bi_mul_low_256_64____64_64:
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

    PrologCheckStackAligned 'bi_mul_low_256_64'
    CheckRegAligned rcx, 'bi_mul_low_256_64 rcx'
    CheckRegAligned r8, 'bi_mul_low_256_64 r8'

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
        call    bi_mul_low_128_64

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_128
        lea     rdx, [.temp]
        call    bi_add_assign_128_128

        add     rsp, .locals_end - .locals_start
        ret



;Multiplies bi256 by bi64 value and return low 256 bits
;input
;  rcx - pointer to bi256 left value
;  rdx - bi64 right value
;  r8 - result value (low 256 bits)
bi_mul_low_256_64:
    CheckRegBi256Alignment rcx, 'bi_mul_low_256_64 rcx'
    CheckRegBi256Alignment r8, 'bi_mul_low_256_64 r8'

        mov     r9, rcx
        mov     rcx, rdx
        xor     rax, rax             ; CF = 0,

        mov     rdx, [r9 + 0]
        mulx    rdx, rax, rcx
        mov     [r8 + 0], rax
        mov     [r8 + 8], rdx

        mov     rdx, [r9 + 8]
        mulx    rdx, rax, rcx
        adcx    rax, [r8 + 8]        ; CF = carry for [result + 16]
        mov     [r8 + 8], rax
        mov     [r8 + 16], rdx

        mov     rdx, [r9 + 16]
        mulx    rdx, rax, rcx
        adcx    rax, [r8 + 16]       ; CF = carry for [result + 24]
        mov     [r8 + 16], rax
        mov     [r8 + 24], rdx

        mov     rdx, [r9 + 24]
        mulx    rdx, rax, rcx
        adc     [r8 + 24], rax

        ret

end if