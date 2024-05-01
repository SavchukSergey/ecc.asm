if ~ definite bi_mul_low_512_64

include '../mul/bi_mul_256_64.inc'

;Multiplies bi512 by bi64 value and return low 512 bits
;input
;  rcx - pointer to bi512 left value
;  rdx - bi64 right value
;  r8 - result value (low 512 bits)
bi_mul_low_512_64____64_64:
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


;Multiplies bi512 by bi64 value and return low 512 bits
;input
;  rcx - pointer to bi512 left value
;  rdx - bi64 right value
;  r8 - result value (low 512 bits)
bi_mul_low_512_64:
    CheckRegBi512Alignment rcx, 'bi_mul_low_512_64 rcx'
    CheckRegBi512Alignment r8, 'bi_mul_low_512_64 r8'

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
        adcx    rax, [r8 + 24]       ; CF = carry for [result + 32]
        mov     [r8 + 24], rax
        mov     [r8 + 32], rdx

        mov     rdx, [r9 + 32]
        mulx    rdx, rax, rcx
        adcx    rax, [r8 + 32]       ; CF = carry for [result + 40]
        mov     [r8 + 32], rax
        mov     [r8 + 40], rdx

        mov     rdx, [r9 + 40]
        mulx    rdx, rax, rcx
        adcx    rax, [r8 + 40]       ; CF = carry for [result + 48]
        mov     [r8 + 40], rax
        mov     [r8 + 48], rdx

        mov     rdx, [r9 + 48]
        mulx    rdx, rax, rcx
        adcx    rax, [r8 + 48]       ; CF = carry for [result + 56]
        mov     [r8 + 48], rax
        mov     [r8 + 56], rdx

        mov     rdx, [r9 + 56]
        mulx    rdx, rax, rcx
        adc     [r8 + 56], rax

        ret
end if