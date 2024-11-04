if ~ definite bi_mul_low_256_256

include '../mul/bi_mul_128_128.inc'
include '../add/bi_add_assign_128_128.inc'
include 'bi_mul_128_128_low_128.inc'

;Multiplies two bi256 values
;input
; rcx - pointer to left bi256 value
; rdx - pointer to right bi256 value
; r8 - pointer to result bi256 value (low 256 bits)
bi_mul_low_256_256:
    PrologCheckStackAligned 'bi_mul_low_256_256'
    CheckRegBi256Alignment rcx, 'bi_mul_low_256_256 rcx'
    CheckRegBi256Alignment rdx, 'bi_mul_low_256_256 rdx'
    CheckRegBi256Alignment r8, 'bi_mul_low_256_256 r8'

        push    r10 r11 r12 r13 r14
        mov     r10, rdx

ResultReg0 equ r11
ResultReg1 equ r12
ResultReg2 equ r13
ResultReg3 equ r14

        mov     r9, [r10 + 0]
        xor     rax, rax

        mov     rdx, [rcx + 0]
        mulx    rdx, rax, r9
        mov     ResultReg0, rax
        mov     ResultReg1, rdx

        mov     rdx, [rcx + 8]
        mulx    rdx, rax, r9
        adcx    ResultReg1, rax        ; CF = carry for ResultReg2
        mov     ResultReg2, rdx

        mov     rdx, [rcx + 16]
        mulx    rdx, rax, r9
        adcx    ResultReg2, rax         ; CF = carry for ResultReg3
        mov     ResultReg3, rdx

        mov     rdx, [rcx + 24]
        mulx    rdx, rax, r9
        adcx    ResultReg3, rax




        mov     r9, [r10 + 8]
        xor     rax, rax

        mov     rdx, [rcx + 0]
        mulx    rdx, rax, r9
        adcx    ResultReg1, rax        ; CF = carry for ResultReg2
        adox    ResultReg2, rdx        ; OF = carry for ResultReg3

        mov     rdx, [rcx + 8]
        mulx    rdx, rax, r9
        adcx    ResultReg2, rax        ; CF = carry for ResultReg3
        adox    ResultReg3, rdx

        mov     rdx, [rcx + 16]
        mulx    rdx, rax, r9
        adcx    ResultReg3, rax 




        mov     r9, [r10 + 16]
        xor     rax, rax

        mov     rdx, [rcx + 0]
        mulx    rdx, rax, r9
        adcx    ResultReg2, rax         ; CF = carry for ResultReg3
        adox    ResultReg3, rdx

        mov     rdx, [rcx + 8]
        mulx    rdx, rax, r9
        adcx    ResultReg3, rax 



        mov     r9, [r10 + 24]
        xor     rax, rax

        mov     rdx, [rcx + 0]
        mulx    rdx, rax, r9
        adcx    ResultReg3, rax

        mov     [r8 + 0], ResultReg0
        mov     [r8 + 8], ResultReg1
        mov     [r8 + 16], ResultReg2
        mov     [r8 + 24], ResultReg3

        pop     r14 r13 r12 r11 r10
        ret
end if