if ~ definite bi_mul_128_128

include '../zero/bi_zero_256.inc'
include '../add/bi_add_assign_192_128.inc'
include '../add/bi_add_assign_256_256.inc'
include '../add/bi_add_assign_448_256.inc'
include 'bi_mul_64_64.inc'

;Multiplies two bi128 values
;input
; rcx - pointer to left bi128 value
; rdx - pointer to right bi128 value
; r8 - pointer to result bi256 value
bi_mul_128_128____64_64:
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

    PrologCheckStackAligned 'bi_mul_128_128'
    CheckRegAligned rcx, 'bi_mul_128_128 rcx'
    CheckRegAligned rdx, 'bi_mul_128_128 rdx'
    CheckRegAligned r8, 'bi_mul_128_128 r8'
    
        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.result]
        call    bi_zero_256
; b * d (128 bit)
        mov     rcx, [.left]
        mov     rcx, [rcx]
        mov     rdx, [.right]
        mov     rdx, [rdx]
        mov     r8, [.result]
        call    bi_mul_64_64

; b * c (128 bit)
        mov     rcx, [.left]
        mov     rcx, [rcx]
        mov     rdx, [.right]
        mov     rdx, [rdx + __BIG_INTEGER_BYTES_128 / 2]
        lea     r8, [.temp]
        call    bi_mul_64_64

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_128 / 2
        lea     rdx, [.temp]
        call    bi_add_assign_192_128

; a * d (128 bit)
        mov     rcx, [.left]
        mov     rcx, [rcx + __BIG_INTEGER_BYTES_128 / 2]
        mov     rdx, [.right]
        mov     rdx, [rdx]
        lea     r8, [.temp]
        call    bi_mul_64_64

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_128 / 2
        lea     rdx, [.temp]
        call    bi_add_assign_192_128

; a * c (128 bit)
        mov     rcx, [.left]
        mov     rcx, [rcx + __BIG_INTEGER_BYTES_128 / 2]
        mov     rdx, [.right]
        mov     rdx, [rdx + __BIG_INTEGER_BYTES_128 / 2]
        lea     r8, [.temp]
        call    bi_mul_64_64

        mov     rcx, [.result]
        add     rcx, __BIG_INTEGER_BYTES_128
        lea     rdx, [.temp]
        call    bi_add_assign_128_128

        add     rsp, .locals_end - .locals_start
        ret

;Multiplies bi128 value by bi128 value
;input
;  rcx - left bi128 value
;  rdx - right bi128 value
;  r8 - result bi256 value
bi_mul_128_128:
        mov     r9, rdx

        mov     rax, [rcx + 0]
        mul     qword [r9 + 0]
        mov     [r8 + 0], rax
        mov     [r8 + 8], rdx

        mov     rax, [rcx + 0]
        mul     qword [r9 + 8]
        add     [r8 + 8], rax
        adc     rdx, 0
        mov     [r8 + 16], rdx
        setc    dl
        movzx   rdx, dl
        mov     qword [r8 + 24], rdx

        mov     rax, [rcx + 8]
        mul     qword [r9 + 0]
        add     [r8 + 8], rax
        adc     [r8 + 16], rdx
        adc     qword [r8 + 24], 0

        mov     rax, [rcx + 8]
        mul     qword [r9 + 8]
        add     [r8 + 16], rax
        adc     [r8 + 24], rdx

        ret

end if