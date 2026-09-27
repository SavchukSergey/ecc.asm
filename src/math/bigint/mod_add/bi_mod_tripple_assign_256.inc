if ~ definite bi_mod_tripple_assign_256

;Tripples bi256 value
;input:
;  rcx - pointer to left bi256 value. The modified value. Must be < modulus
;  rdx - pointer to bi256 modulus
bi_mod_tripple_assign_256:
    CheckRegBi256Alignment rcx, 'bi_mod_tripple_assign_256 rcx'
    CheckRegBi256Alignment rdx, 'bi_mod_tripple_assign_256 rdx'

        push    rbx             ; save caller rbx
        push    r12             ; iteration counter
        sub     rsp, 8          ; keep rsp 16-byte aligned for the calls below

        xor     rax, rax    ;OF = 0, CF = 0

        mov     r8, [rcx]
        mov     rax, r8
        adcx    rax, rax
        adox    rax, r8
        mov     [rcx], rax

        mov     r8, [rcx + 8]
        mov     rax, r8
        adcx    rax, rax
        adox    rax, r8
        mov     [rcx + 8], rax

        mov     r8, [rcx + 16]
        mov     rax, r8
        adcx    rax, rax
        adox    rax, r8
        mov     [rcx + 16], rax

        mov     r8, [rcx + 24]
        mov     rax, r8
        adcx    rax, rax
        adox    rax, r8
        mov     [rcx + 24], rax

;3v = stored + k*2^256, where k = CF + OF (0..2)
;subtract modulus until the full 257-bit value is below it
;(at most 2 subtractions when v < n; capped for unreduced inputs)
        setc    al
        seto    r8b
        add     al, r8b
        movzx   rbx, al         ; rbx = k
        mov     r12, 8          ; defensive cap: correct for any v < 3n, bounded otherwise
.reduce:
        test    rbx, rbx
        jnz     .do_sub
        call    bi_cmp_256_256  ; value (rcx) vs modulus (rdx)
        jb      .done
.do_sub:
        dec     r12
        js      .done           ; cap reached (input was not reduced) - stop, result may be unreduced
        call    bi_sub_assign_256_256    ; value -= modulus; rax = 1 if borrow
        sub     rbx, rax        ; borrow consumed one 2^256 from k
        jmp     .reduce
.done:
        add     rsp, 8
        pop     r12
        pop     rbx
        ret

end if