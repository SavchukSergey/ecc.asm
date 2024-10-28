if ~ definite bi_mul_512_64

include '../mul/bi_mul_64_64.inc'
include '../add/bi_add_assign_128_128.inc'

;Multiplies bi512 by u64
;input
; rcx - pointer to left bi512 value
; rdx - right u64 value
; r8 - pointer to result bi1024 value
bi_mul_512_64_basic:
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

    PrologCheckStackAligned 'bi_mul_512_64_basic'
    CheckRegAligned rcx, 'bi_mul_512_64_basic rcx'
    CheckRegAligned r8, 'bi_mul_512_64_basic r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.result]
        call    bi_zero_1024


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

        mov     rcx, [.result]
        add     rcx, 8
        lea     rdx, [.temp]
        call    bi_add_assign_128_128


        mov     rcx, [.left]
        mov     rcx, [rcx + 16]
        mov     rdx, [.right]
        lea     r8, [.temp]
        call    bi_mul_64_64

        mov     rcx, [.result]
        add     rcx, 16
        lea     rdx, [.temp]
        call    bi_add_assign_128_128


        mov     rcx, [.left]
        mov     rcx, [rcx + 24]
        mov     rdx, [.right]
        lea     r8, [.temp]
        call    bi_mul_64_64

        mov     rcx, [.result]
        add     rcx, 24
        lea     rdx, [.temp]
        call    bi_add_assign_128_128



        mov     rcx, [.left]
        mov     rcx, [rcx + 32]
        mov     rdx, [.right]
        lea     r8, [.temp]
        call    bi_mul_64_64

        mov     rcx, [.result]
        add     rcx, 32
        lea     rdx, [.temp]
        call    bi_add_assign_128_128



        mov     rcx, [.left]
        mov     rcx, [rcx + 40]
        mov     rdx, [.right]
        lea     r8, [.temp]
        call    bi_mul_64_64

        mov     rcx, [.result]
        add     rcx, 40
        lea     rdx, [.temp]
        call    bi_add_assign_128_128



        mov     rcx, [.left]
        mov     rcx, [rcx + 48]
        mov     rdx, [.right]
        lea     r8, [.temp]
        call    bi_mul_64_64

        mov     rcx, [.result]
        add     rcx, 48
        lea     rdx, [.temp]
        call    bi_add_assign_128_128



        mov     rcx, [.left]
        mov     rcx, [rcx + 56]
        mov     rdx, [.right]
        lea     r8, [.temp]
        call    bi_mul_64_64

        mov     rcx, [.result]
        add     rcx, 56
        lea     rdx, [.temp]
        call    bi_add_assign_128_128

        add     rsp, .locals_end - .locals_start
        ret





;Multiplies bi512 by u64
;input
; rcx - left bi512 value
; rdx - right u64 value
; r8 - result bi1024 value
bi_mul_512_64_bmi2:
    CheckRegAligned rcx, 'bi_mul_512_64_bmi2 rcx'
    CheckRegAligned r8, 'bi_mul_512_64_bmi2 r8'

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
        adcx    rax, [r8 + 24]       ; CF = carry for [result + 24]
        mov     [r8 + 24], rax
        mov     [r8 + 32], rdx

        mov     rdx, [r9 + 32]
        mulx    rdx, rax, rcx
        adcx    rax, [r8 + 32]       ; CF = carry for [result + 32]
        mov     [r8 + 32], rax
        mov     [r8 + 40], rdx

        mov     rdx, [r9 + 40]
        mulx    rdx, rax, rcx
        adcx    rax, [r8 + 40]       ; CF = carry for [result + 40]
        mov     [r8 + 40], rax
        mov     [r8 + 48], rdx

        mov     rdx, [r9 + 48]
        mulx    rdx, rax, rcx
        adcx    rax, [r8 + 48]       ; CF = carry for [result + 48]
        mov     [r8 + 48], rax
        mov     [r8 + 56], rdx

        mov     rdx, [r9 + 56]
        mulx    rdx, rax, rcx
        adcx    rax, [r8 + 56]       ; CF = carry for [result + 64]
        mov     [r8 + 56], rax
        adc     rdx, 0
        mov     [r8 + 64], rdx

        xor     rax, rax
        mov     [r8 + 72], rax
        mov     [r8 + 80], rax
        mov     [r8 + 88], rax
        mov     [r8 + 96], rax
        mov     [r8 + 104], rax
        mov     [r8 + 112], rax

        ret

if BMI2_ENABLED = 1
  bi_mul_512_64 = bi_mul_512_64_bmi2
else
  bi_mul_512_64 = bi_mul_512_64_basic
end if

end if
