if ~ definite bi_shl_assign_128_1

; Shifts left
;input
; rcx - value
bi_shl_assign_128_1:
        clc
        rcl     qword [rcx], 1
        rcl     qword [rcx + 8], 1
        ret

end if

if ~ definite bi_shl_assign_256_1

; Shifts left
;input
; rcx - value
bi_shl_assign_256_1:
        clc
        rcl     qword [rcx], 1
        rcl     qword [rcx + 8], 1
        rcl     qword [rcx + 16], 1
        rcl     qword [rcx + 24], 1
        ret

end if

if ~ definite bi_shl_assign_512_1

; Shifts left
;input
; rcx - value
bi_shl_assign_512_1:
        clc
        rcl     qword [rcx], 1
        rcl     qword [rcx + 8], 1
        rcl     qword [rcx + 16], 1
        rcl     qword [rcx + 24], 1
        rcl     qword [rcx + 32], 1
        rcl     qword [rcx + 40], 1
        rcl     qword [rcx + 48], 1
        rcl     qword [rcx + 56], 1
        ret

end if






if ~ definite bi_shl_assign_128

; Shifts left
;input
; rcx - value
; rdx - bits
bi_shl_assign_128:
        cmp     rdx, 128
        jae     .zero
        cmp     rdx, 64
        jb      .shift_64_ok
        mov     rax, [rcx + 0]
        mov     [rcx + 8], rax
        mov     qword [rcx], 0
        sub     rdx, 64
.shift_64_ok:

        xchg    rcx, rdx

        mov     rax, [rdx + 0]
        shld    [rdx + 8], rax, cl
        shl     qword [rdx], cl

        xchg    rcx, rdx

        ret

.zero:
        mov     qword [rcx], 0
        mov     qword [rcx + 8], 0
        ret

end if

if ~ definite bi_shl_assign_256

; Shifts left
;input
; rcx - value
; rdx - bits
bi_shl_assign_256:
        push    rbx rsi rdi

        mov     rbx, rcx
        mov     rcx, rdx

        lea     rdi, [rbx + 32 - 8]

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

        mov     rax, [rbx + 16]
        shld    [rbx + 24], rax, cl
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

if ~ definite bi_shl_assign_512

; Shifts left
;input
; rcx - value
; rdx - bits
bi_shl_assign_512:
        push    rbx rsi rdi

        mov     rbx, rcx
        mov     rcx, rdx

        lea     rdi, [rbx + 64 - 8]

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

        mov     rax, [rbx + 48]
        shld    [rbx + 56], rax, cl
        mov     rax, [rbx + 40]
        shld    [rbx + 48], rax, cl
        mov     rax, [rbx + 32]
        shld    [rbx + 40], rax, cl
        mov     rax, [rbx + 24]
        shld    [rbx + 32], rax, cl
        mov     rax, [rbx + 16]
        shld    [rbx + 24], rax, cl
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