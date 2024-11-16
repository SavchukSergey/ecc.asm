;Squares bi256 value
;input:
; rcx - pointer to bi256 value
; rdx - pointer to bi512 result
bi_square_256:
virtual at rsp
.locals_start:
  .temp BigInteger256
  .value rq 1
  .result rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        push    r8 r9
        sub     rsp, .locals_end - .locals_start

        PrologCheckStackAligned 'bi_square_256'
        CheckRegBi256Alignment rcx, 'bi_square_256 rcx'
        CheckRegBi512Alignment rdx, 'bi_square_256 rdx'

        mov     [.value], rcx
        mov     [.result], rdx

        xor     rax, rax               ;CF = 0, OF = 0

        mov     r8, rcx
        mov     r9, rdx

; d * d
        mov     rdx, [r8 + 0]
        mulx    rdx, rax, rdx
        mov     [r9 + 0], rax
        mov     [r9 + 8], rdx

; c * c
        mov     rdx, [r8 + 8]
        mulx    rdx, rax, rdx
        mov     [r9 + 16], rax
        mov     [r9 + 24], rdx

; b * b
        mov     rdx, [r8 + 16]
        mulx    rdx, rax, rdx
        mov     [r9 + 32], rax
        mov     [r9 + 40], rdx

; a * a
        mov     rdx, [r8 + 24]
        mulx    rdx, rax, rdx
        mov     [r9 + 48], rax
        mov     [r9 + 56], rdx



; c * d
        mov     rcx, [r8 + 8]
        mov     rdx, [r8 + 0]
        mulx    rdx, rax, rcx
        adcx    rax, rax
        adcx    rdx, rdx                   ;CF = carry for [.result + 24]
        adox    rax, [r9 + 8]
        adox    rdx, [r9 + 16]             ;OF = carry for [.result + 24]
        mov     [r9 + 8], rax
        mov     [r9 + 16], rdx

; a * d
        mov     rcx, [r8 + 24]
        mov     rdx, [r8 + 0]
        mulx    rdx, rax, rcx
        adcx    rax, rax
        adcx    rdx, rdx                   ;CF = carry for [.result + 40]
        adox    rax, [r9 + 24]
        adox    rdx, [r9 + 32]             ;OF = carry for [.result + 40]
        mov     [r9 + 24], rax
        mov     [r9 + 32], rdx

; a * b
        mov     rcx, [r8 + 24]
        mov     rdx, [r8 + 16]
        mulx    rdx, rax, rcx
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
        mov     rcx, [r8 + 16]
        mov     rdx, [r8 + 0]
        mulx    rdx, rax, rcx
        adcx    rax, rax
        adcx    rdx, rdx                   ;CF = carry for [.result + 32]
        adox    rax, [r9 + 16]
        adox    rdx, [r9 + 24]             ;OF = carry for [.result + 32]
        mov     [r9 + 16], rax
        mov     [r9 + 24], rdx


; a * c
        mov     rcx, [r8 + 24]
        mov     rdx, [r8 + 8]
        mulx    rdx, rax, rcx
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
        mov     rcx, [r8 + 16]
        mov     rdx, [r8 + 8]
        mulx    rdx, rax, rcx
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

        add     rsp, .locals_end - .locals_start
        pop     r9 r8
        ret