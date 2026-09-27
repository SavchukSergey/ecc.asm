if ~ definite bi_mont_ctx_256_mul

;Multiplies two bi256 values in montgomery form:
;  result = left * right * 2^-256 mod modulus
;Fused CIOS (coarsely integrated operand scanning) implementation:
;the product and the montgomery reduction are computed in a single pass
;through register-resident state, replacing the previous composition of a
;full 256x256 multiplication followed by a separate REDC
;input:
;  rcx - pointer to left bi256 montgomery value
;  rdx - pointer to right bi256 montgomery value
;  r8  - pointer to MontgomeryContext256
;  r9  - pointer to bi256 result (may alias left or right)
;note: left and right must be reduced (< modulus)
bi_mont_ctx_256_mul:
        push    rbx rbp rsi rdi r12 r13 r14 r15
        ;register map:
        ; rcx - left pointer        rdx - current row multiplier
        ; rsi - right pointer       rdi - modulus pointer (ctx)
        ; r12 - modulus' low limb   r13 - result pointer
        ; r15 - zero register
        ; r8..r11 - t0..t3          rbx - t4
        ; rax - low halves          rbp, r14 - high halves
        mov     rsi, rdx
        lea     rdi, [r8 + MontgomeryContext256.modulus]
        mov     r12, [r8 + MontgomeryContext256.mod_inv_r]
        mov     r13, r9
        xor     r15d, r15d

        xor     r8d, r8d                ;t0 = 0
        xor     r9d, r9d                ;t1 = 0
        xor     r10d, r10d              ;t2 = 0
        xor     r11d, r11d              ;t3 = 0
        xor     ebx, ebx                ;t4 = 0

macro MONT_CIOS_OUTER a_offset {
        mov     rdx, [rcx + a_offset]
        xor     eax, eax                ;CF = 0, OF = 0
;-------- t += a[i] * right --------
        mulx    r14, rax, [rsi + 0]
        adcx    r8, rax                 ;t0 += lo
        adox    r9, r14                 ;t1 += hi
        mulx    r14, rax, [rsi + 8]
        adcx    r9, rax                 ;t1 += lo
        adox    r10, r14                ;t2 += hi
        mulx    r14, rax, [rsi + 16]
        adcx    r10, rax                ;t2 += lo
        adox    r11, r14                ;t3 += hi
        mulx    r14, rax, [rsi + 24]
        adcx    r11, rax                ;t3 += lo
        adox    rbx, r14                ;t4 += hi
        adcx    rbx, r15                ;t4 += CF
        adox    rbx, r15                ;t4 += OF

;-------- m = t0 * modulus' (mod 2^64);  t = (t + m * modulus) / 2^64 --------
        mov     rdx, r8
        mulx    r14, rax, r12
        mov     rdx, rax                ;rdx = m
        xor     eax, eax                ;CF = 0, OF = 0
        mulx    rbp, rax, [rdi + 0]     ;m*n0: low half discarded (zero by construction)
        add     rax, r8                 ;t0 + lo -> CF
        mulx    r14, rax, [rdi + 8]     ;m*n1
        adcx    rax, r9                 ;+ t1 + CF
        adox    rax, rbp                ;+ hi(n0)
        mov     r8, rax                 ;new t0
        mulx    rbp, rax, [rdi + 16]    ;m*n2
        adcx    rax, r10                ;+ t2 + CF
        adox    rax, r14                ;+ hi(n1)
        mov     r9, rax                 ;new t1
        mulx    r14, rax, [rdi + 24]    ;m*n3
        adcx    rax, r11                ;+ t3 + CF
        adox    rax, rbp                ;+ hi(n2)
        mov     r10, rax                ;new t2
        adcx    rbx, r14                ;t4 += hi(n3) + CF
        adox    rbx, r15                ;t4 += OF
        mov     r11, rbx                ;new t3
        mov     ebx, 0                  ;carry out of the fold becomes new t4
        adox    rbx, r15                ;t4 = OF
        adcx    rbx, r15                ;t4 += CF
}

        MONT_CIOS_OUTER 0
        MONT_CIOS_OUTER 8
        MONT_CIOS_OUTER 16
        MONT_CIOS_OUTER 24

purge MONT_CIOS_OUTER

;-------- finalize: subtract modulus if t >= modulus (or t4 != 0) --------
        test    rbx, rbx
        jnz     .subtract

        mov     rax, r11
        cmp     rax, [rdi + 24]
        jb      .store
        ja      .subtract
        mov     rax, r10
        cmp     rax, [rdi + 16]
        jb      .store
        ja      .subtract
        mov     rax, r9
        cmp     rax, [rdi + 8]
        jb      .store
        ja      .subtract
        mov     rax, r8
        cmp     rax, [rdi]
        jb      .store

.subtract:
        mov     rax, [rdi]
        sub     r8, rax
        mov     rax, [rdi + 8]
        sbb     r9, rax
        mov     rax, [rdi + 16]
        sbb     r10, rax
        mov     rax, [rdi + 24]
        sbb     r11, rax

.store:
        mov     [r13], r8
        mov     [r13 + 8], r9
        mov     [r13 + 16], r10
        mov     [r13 + 24], r11

        pop     r15 r14 r13 r12 rdi rsi rbp rbx
        ret

end if
