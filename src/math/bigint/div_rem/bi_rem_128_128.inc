if ~ definite bi_rem_128_128

;Calculates remainder of bi128 divided by u64
;input:
;   rcx - pointer to bi128 dividend
;   rdx - pointer to bi128 divisor
;   r8 - pointer to bi128 remainder
bi_rem_128_128:
    cmp     qword [rdx + 8], 0
    js      .huge_divisor
    cmovz   rdx, [rdx + 0]
    mov     qword [r8 + 8], 0
    jz      bi_rem_128_64


    push    r10 r11
    
    ; copy dividend to remainder. After that pointer to dividend is no longer needed and we can use rcx freely
    vmovdqu xmm0, [rcx]
    vmovdqu [r8], xmm0

    mov     r10, rdx         ;now r10 becomes pointer to divisor, rdx is intensively used

    mov     rdx, [r10 + 0]
    mov     r11, [r10 + 8]

    lzcnt   rcx, r11
    shld    r11, rdx, cl     ; cl is >= 1, as huge divisor are handled separately
    inc     r11
    jz      .max

    mov     rdx, [r8 + 8]
;65 bit arithmetics
;ffff_ffff / 8001_(0000) = 1_fffc
    mov     rax, rdx
    sub     rax, r11
    cmovnc  rdx, rax
    setnc   ch              ;now ch is 65th bit guess value
    mov     rax, [r8 + 0]
    div     r11
    ror     ch, 1
    rcr     rax, 1         ; cl is at least one, so 65-bit value shrinks to 64-bit value
; We must negate cl = 64 - cl, Negate is actually "not" with increment. But we use ror/rcr to first shift, so we have to decrement cl, or we can simply inverse cl
    not     cl
    shr     rax, cl
.guess_ready:

    mov     rdx, [r10 + 0]
    mulx    r11, rdx, rax
    sub     [r8 + 0], rdx
    sbb     [r8 + 8], r11

    mov     rdx, [r10 + 8]
    mulx    r11, rdx, rax
    sub     [r8 + 8], rdx


.check_multi:
    mov     rax, [r8 + 8]
    cmp     rax, [r10 + 8]
    jb      .end
    mov     rax, [r8 + 0]
    cmp     rax, [r10 + 0]
    jb      .end

    mov     rax, [r10 + 0]
    sub     [r8 + 0], rax
    mov     rax, [r10 + 8]
    sbb     [r8 + 8], rax

;    jmp     .check_multi  ;todo: check how many iterations are needed
.end:

    pop     r11 r10
    ret
.max:
    mov     rax, [r8 + 8]
    sub     cl, 64
    neg     cl
    shr     rax, cl
    jmp     .guess_ready

.huge_divisor:
    push    rbx

    mov     rax, [rcx + 0]
    sub     rax, [rdx + 0]
    mov     rbx, [rcx + 8]
    sbb     rbx, [rdx + 8]

    cmovc   rax, [rcx + 0]
    cmovc   rbx, [rcx + 8]

    mov     [r8 + 0], rax
    mov     [r8 + 8], rbx

    pop     rbx
    ret
end if