;Multiplies two bi256 values
;input:
; rcx - pointer to left bi256 value
; rdx - pointer to right bi256 value
; r8 - pointer to result bi512 value

bi_mul_256_256:
    PrologCheckStackAligned 'bi_mul_256_128'
    CheckRegBi256Alignment rcx, 'bi_mul_256_128 rcx'
    CheckRegBi256Alignment rdx, 'bi_mul_256_128 rdx'
    CheckRegBi512Alignment r8, 'bi_mul_256_128 r8'

        push    rbx r9

LEFT_PTR_REG equ rcx
RIGHT_PTR_REG equ r9
RESULT_PTR_REG equ r8
        mov     RIGHT_PTR_REG, rdx

; ld * rd
        mov     rdx, [RIGHT_PTR_REG + 0]
        mulx    rdx, rax, [LEFT_PTR_REG + 0]
        mov     [RESULT_PTR_REG + 0], rax
        mov     [RESULT_PTR_REG + 8], rdx

; lc * rc
        mov     rdx, [RIGHT_PTR_REG + 8]
        mulx    rdx, rax, [LEFT_PTR_REG + 8]
        mov     [RESULT_PTR_REG + 16], rax
        mov     [RESULT_PTR_REG + 24], rdx

; lb * rb
        mov     rdx, [RIGHT_PTR_REG + 16]
        mulx    rdx, rax, [LEFT_PTR_REG + 16]
        mov     [RESULT_PTR_REG + 32], rax
        mov     [RESULT_PTR_REG + 40], rdx

; la * ra
        mov     rdx, [RIGHT_PTR_REG + 24]
        mulx    rdx, rax, [LEFT_PTR_REG + 24]
        mov     [RESULT_PTR_REG + 48], rax
        mov     [RESULT_PTR_REG + 56], rdx

        mov     rbx, 2
.loop:
        xor     rax, rax               ;CF = 0, OF = 0
; lc * rd
        mov     rdx, [RIGHT_PTR_REG + 0]
        mulx    rdx, rax, [LEFT_PTR_REG + 8]
        adc     [RESULT_PTR_REG + 8], rax
        adc     [RESULT_PTR_REG + 16], rdx            ;CF = carry for [.result + 24]

; la * rd
        mov     rdx, [RIGHT_PTR_REG + 0]
        mulx    rdx, rax, [LEFT_PTR_REG + 24]
        adc     [RESULT_PTR_REG + 24], rax
        adc     [RESULT_PTR_REG + 32], rdx             ;CF = carry for [.result + 40]

; la * rb
        mov     rdx, [RIGHT_PTR_REG + 16]
        mulx    rdx, rax, [LEFT_PTR_REG + 24]
        adc     [RESULT_PTR_REG + 40], rax
        adc     [RESULT_PTR_REG + 48], rdx             ;CF = carry for [.result + 56]
        adc     qword [RESULT_PTR_REG + 56], 0

        ;OF, CF = 0, because result can never exceed 512 bits
        ;xor     rax, rax               ;CF = 0, OF = 0
; lb * rd
        mov     rdx, [RIGHT_PTR_REG + 0]
        mulx    rdx, rax, [LEFT_PTR_REG + 16]
        adc     [RESULT_PTR_REG + 16], rax
        adc     [RESULT_PTR_REG + 24], rdx             ;CF = carry for [.result + 32]

; la * rc
        mov     rdx, [RIGHT_PTR_REG + 8]
        mulx    rdx, rax, [LEFT_PTR_REG + 24]
        adc     [RESULT_PTR_REG + 32], rax             ;CF = carry for [.result + 48]
        adc     [RESULT_PTR_REG + 40], rdx
        adc     qword [RESULT_PTR_REG + 48], 0
        adc     qword [RESULT_PTR_REG + 56], 0

        ;OF, CF = 0, because result can never exceed 512 bits
        ;xor     rax, rax               ;CF = 0, OF = 0
; lb * rc
        mov     rdx, [RIGHT_PTR_REG + 8]
        mulx    rdx, rax, [LEFT_PTR_REG + 16]
        adc     [RESULT_PTR_REG + 24], rax
        adc     [RESULT_PTR_REG + 32], rdx             ;CF = carry for [.result + 40]
        adc     qword [RESULT_PTR_REG + 40], 0
        adc     qword [RESULT_PTR_REG + 48], 0
        adc     qword [RESULT_PTR_REG + 56], 0

        xchg    LEFT_PTR_REG, RIGHT_PTR_REG
        dec     rbx
        jnz     .loop
        pop     r9 rbx
        ret

