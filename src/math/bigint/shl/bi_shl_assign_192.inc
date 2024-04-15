if ~ definite bi_shl_assign_192

; Shifts left
;input
; rcx - value
; rdx - bits
bi_shl_assign_192:
        push    rbx rsi rdi

        mov     rbx, rcx
        mov     rcx, rdx

        lea     rdi, [rbx + 24 - 8]; todo: move below

        mov     rsi, rcx
        shr     rsi, 6
        test    rsi, rsi
        jz      .shift_64_ok

        shl     rsi, 3
        sub     rsi, rdi
        neg     rsi

.shift_64:
        xor     rax, rax
        cmp     rsi, rbx
        cmovae  rax, [rsi]
        mov     [rdi], rax

        sub     rsi, 8
        sub     rdi, 8
        cmp     rdi, rbx
        jae     .shift_64
.shift_64_ok:

        and     rcx, 0x3f
        jz      .loop_ok

        mov     rax, [rbx + 8]
        shld    [rbx + 16], rax, cl
        mov     rax, [rbx + 0]
        shld    [rbx + 8], rax, cl
        shl     qword [rbx], cl

.loop_ok:

.end:
        pop     rdi rsi rbx
        ret

end if