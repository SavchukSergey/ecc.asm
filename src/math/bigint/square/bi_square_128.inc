if ~ definite bi_square_128

;Squares bi128 value
;input
; rcx - pointer to bi128 value
; rdx - pointer to bi256 result
bi_square_128_basic:
        mov     r8, rdx

        mov     rax, [rcx + 0]
        mul     qword [rcx + 0]
        mov     [r8 + 0], rax
        mov     [r8 + 8], rdx
        
        mov     qword [r8 + 16], 0
        mov     qword [r8 + 24], 0

        mov     rax, [rcx + 0]
        mul     qword [rcx + 8]
        add     [r8 + 8], rax
        adc     [r8 + 16], rdx
        adc     qword [r8 + 24], 0
        add     [r8 + 8], rax
        adc     [r8 + 16], rdx
        adc     qword [r8 + 24], 0

        mov     rax, [rcx + 8]
        mul     qword [rcx + 8]
        add     [r8 + 16], rax
        adc     [r8 + 24], rdx

        ret

;Multiplies bi128 value by bi128 value
;input
;  rcx - left bi128 value
;  rdx - result bi256 value
bi_square_128_bmi2:
        mov     r8, rdx

        xor     r9, r9                ;CF = 0, OF = 0, r9 = 0

        mov     rdx, [rcx + 0]
        mulx    rdx, rax, rdx
        mov     [r8 + 0], rax
        mov     [r8 + 8], rdx

        mov     rdx, [rcx + 0]
        mulx    rdx, rax, qword [rcx + 8]
        adcx    rax, rax                 ;use adcx to keep OF 
        adcx    rdx, rdx                 ;CF = carry for [r8 + 24]
        adox    rax, [r8 + 8]            ;OF = carry for [r8 + 16]
        mov     [r8 + 8], rax
        mov     [r8 + 16], rdx

        mov     rdx, [rcx + 8]
        mulx    rdx, rax, rdx
        adox    rax, [r8 + 16]           ;CF = carry for [r8 + 24]
        mov     [r8 + 16], rax
        adcx    rdx, r9
        adox    rdx, r9
        mov     [r8 + 24], rdx

        ret

if BMI2_ENABLED = 1
  bi_square_128 = bi_square_128_bmi2
else
  bi_square_128 = bi_square_128_basic
end if

end if