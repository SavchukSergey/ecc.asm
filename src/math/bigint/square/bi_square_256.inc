;Squares bi256 value
;input:
; rcx - pointer to bi256 value
; rdx - pointer to bi512 result
bi_square_256:
        push    r9

        PrologCheckStackAligned 'bi_square_256'
        CheckRegBi256Alignment rcx, 'bi_square_256 rcx'
        CheckRegBi512Alignment rdx, 'bi_square_256 rdx'

        xor     rax, rax               ;CF = 0, OF = 0

VALUE_PTR_REG equ rcx
        mov     r9, rdx

; d * d
        mov     rdx, [VALUE_PTR_REG + 0]
        mulx    rdx, rax, rdx
        mov     [r9 + 0], rax
        mov     [r9 + 8], rdx

; c * c
        mov     rdx, [VALUE_PTR_REG + 8]
        mulx    rdx, rax, rdx
        mov     [r9 + 16], rax
        mov     [r9 + 24], rdx

; b * b
        mov     rdx, [VALUE_PTR_REG + 16]
        mulx    rdx, rax, rdx
        mov     [r9 + 32], rax
        mov     [r9 + 40], rdx

; a * a
        mov     rdx, [VALUE_PTR_REG + 24]
        mulx    rdx, rax, rdx
        mov     [r9 + 48], rax
        mov     [r9 + 56], rdx



; c * d
        mov     rdx, [VALUE_PTR_REG + 0]
        mulx    rdx, rax, [VALUE_PTR_REG + 8]
        adcx    rax, rax
        adcx    rdx, rdx                   ;CF = carry for [.result + 24]
        adox    rax, [r9 + 8]
        adox    rdx, [r9 + 16]             ;OF = carry for [.result + 24]
        mov     [r9 + 8], rax
        mov     [r9 + 16], rdx

; a * d
        mov     rdx, [VALUE_PTR_REG + 0]
        mulx    rdx, rax, [VALUE_PTR_REG + 24]
        adcx    rax, rax
        adcx    rdx, rdx                   ;CF = carry for [.result + 40]
        adox    rax, [r9 + 24]
        adox    rdx, [r9 + 32]             ;OF = carry for [.result + 40]
        mov     [r9 + 24], rax
        mov     [r9 + 32], rdx

; a * b
        mov     rdx, [VALUE_PTR_REG + 16]
        mulx    rdx, rax, [VALUE_PTR_REG + 24]
        adcx    rax, rax
        adcx    rdx, rdx                   ;CF = carry for [.result + 56]
        adox    rax, [r9 + 40]
        adox    rdx, [r9 + 48]             ;OF = carry for [.result + 56]
        mov     [r9 + 40], rax
        mov     [r9 + 48], rdx

        mov     rax, [r9 + 56]
        mov     rdx, 0
        adox    rax, rdx
        adcx    rax, rdx
        mov     [r9 + 56], rax

        ;OF, CF = 0, because result can never exceed 512 bits
        ;xor     rax, rax               ;CF = 0, OF = 0
; b * d
        mov     rdx, [VALUE_PTR_REG + 0]
        mulx    rdx, rax, [VALUE_PTR_REG + 16]
        adcx    rax, rax
        adcx    rdx, rdx                   ;CF = carry for [.result + 32]
        adox    rax, [r9 + 16]
        adox    rdx, [r9 + 24]             ;OF = carry for [.result + 32]
        mov     [r9 + 16], rax
        mov     [r9 + 24], rdx


; a * c
        mov     rdx, [VALUE_PTR_REG + 8]
        mulx    rdx, rax, [VALUE_PTR_REG + 24]
        adcx    rax, rax
        adcx    rdx, rdx                   ;CF = carry for [.result + 48]
        adox    rax, [r9 + 32]
        adox    rdx, [r9 + 40]             ;OF = carry for [.result + 48]
        mov     [r9 + 32], rax
        mov     [r9 + 40], rdx

        mov     rax, [r9 + 48]
        mov     rdx, 0
        adox    rax, rdx
        adcx    rax, rdx
        mov     [r9 + 48], rax

        mov     rax, [r9 + 56]
        mov     rdx, 0
        adox    rax, rdx
        adcx    rax, rdx
        mov     [r9 + 56], rax

        ;OF, CF = 0, because result can never exceed 512 bits
        ;xor     rax, rax               ;CF = 0, OF = 0
; b * c
        mov     rdx, [VALUE_PTR_REG + 8]
        mulx    rdx, rax, [VALUE_PTR_REG + 16]
        adcx    rax, rax
        adcx    rdx, rdx                   ;CF = carry for [.result + 40]
        adox    rax, [r9 + 24]
        adox    rdx, [r9 + 32]             ;OF = carry for [.result + 40]
        mov     [r9 + 24], rax
        mov     [r9 + 32], rdx


        mov     rax, [r9 + 40]
        mov     rdx, 0
        adox    rax, rdx
        adcx    rax, rdx
        mov     [r9 + 40], rax

        mov     rax, [r9 + 48]
        mov     rdx, 0
        adox    rax, rdx
        adcx    rax, rdx
        mov     [r9 + 48], rax

        mov     rax, [r9 + 56]
        mov     rdx, 0
        adox    rax, rdx
        adcx    rax, rdx
        mov     [r9 + 56], rax

        pop     r9
        ret