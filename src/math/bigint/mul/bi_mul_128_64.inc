if ~ definite bi_mul_128_64

;Multiplies bi128 by u64
;input
;  rcx - pointer to left bi128 value
;  rdx - right u64 value
;  r8 - pointer result bi256 value
bi_mul_128_64_basic:
    CheckRegAligned rcx, 'bi_mul_128_64 rcx'
    CheckRegAligned r8, 'bi_mul_128_64 r8'
        mov     r9, rdx

        mov     rax, [rcx + 0]
        mul     r9
        mov     [r8 + 0], rax
        mov     [r8 + 8], rdx

        mov     rax, [rcx + 8]
        mul     r9
        add     [r8 + 8], rax
        mov     [r8 + 16], rdx

        adc     qword [r8 + 16], 0
        mov     qword [r8 + 24], 0

        ret


bi_mul_128_64_bmi2:
    CheckRegAligned rcx, 'bi_mul_128_64 rcx'
    CheckRegAligned r8, 'bi_mul_128_64 r8'
        mov     rax, [rcx + 0]
        mulx    r9, rax, rax
        mov     [r8 + 0], rax
        mov     [r8 + 8], r9

        mov     rax, [rcx + 8]
        mulx    r9, rax, rax
        add     [r8 + 8], rax
        adc     r9, 0
        mov     [r8 + 16], r9

        mov     qword [r8 + 24], 0

        ret


if BMI2_ENABLED = 1
  bi_mul_128_64 = bi_mul_128_64_bmi2
else
  bi_mul_128_64 = bi_mul_128_64_basic
end if

end if

