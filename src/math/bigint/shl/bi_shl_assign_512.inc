if ~ definite bi_shl_assign_512

bi_shl_assign_512:

    CheckRegBi512Alignment rcx, 'bi_shr_assign_512 rcx'
;todo: it is full of write-after-read hazards, may work slower
        mov     rax, 8
        mov     r8, rdx
        shr     r8, 6
        cmp     r8, rax
        cmova   r8, rax

        xchg    rcx, rdx
        xor     rax, rax
        and     rcx, 0x3f
        jmp     qword [.jmp_table + r8 * 8]

align 16
.jmp_table:
  dq      .shift_0, .shift_64, .shift_128, .shift_192, .shift_256, .shift_320, .shift_384, .shift_448, .empty
.empty:
        vpxor   ymm1, ymm1, ymm1
        vmovdqu [rdx], ymm1
        vmovdqu [rdx + 32], ymm1
        ret
.shift_448:
        mov     r8, [rdx + 0]
        shl     r8, cl
        mov     [rdx + 56], r8
        mov     [rdx + 48], rax
        mov     [rdx + 40], rax
        mov     [rdx + 32], rax
        mov     [rdx + 24], rax
        mov     [rdx + 16], rax
        mov     [rdx + 8], rax
        mov     [rdx + 0], rax
        ret
.shift_384:
        mov     r8, [rdx + 0]
        mov     r9, [rdx + 8]
        shld    r9, r8, cl
        shl     r8, cl
        mov     [rdx + 56], r9
        mov     [rdx + 48], r8
        mov     [rdx + 40], rax
        mov     [rdx + 32], rax
        mov     [rdx + 24], rax
        mov     [rdx + 16], rax
        mov     [rdx + 8], rax
        mov     [rdx + 0], rax
        ret
.shift_320:
        push    r10
        mov     r8, [rdx + 0]
        mov     r9, [rdx + 8]
        mov     r10, [rdx + 16]
        shld    r10, r9, cl
        shld    r9, r8, cl
        shl     r8, cl
        mov     [rdx + 56], r10
        mov     [rdx + 48], r9
        mov     [rdx + 40], r8
        mov     [rdx + 32], rax
        mov     [rdx + 24], rax
        mov     [rdx + 16], rax
        mov     [rdx + 8], rax
        mov     [rdx + 0], rax
        pop     r10
        ret
.shift_256:
    and       rcx, 0x3f
    vmovq     xmm3, rcx
    sub       rcx, 64
    neg       rcx
    vmovq     xmm4, rcx
    
    vmovdqu   ymm1, [rdx + 0]
    vpermq    ymm2, ymm1, 10010000b
    vpand     ymm2, ymm2, yword [.mask_remove_low_u64]
    
    vpsllq    ymm1, ymm1, xmm3
    vpsrlq    ymm2, ymm2, xmm4
    vpor      ymm1, ymm1, ymm2

    vmovdqu   [rdx + 32], ymm1

    vpxor     ymm1, ymm1, ymm1
    vmovdqu   [rdx + 0], ymm1
    ret
align 16
.mask_remove_low_u64   dq 0, -1, -1, -1

.shift_192:
        push    r10 r11 r12
        mov     r8, [rdx + 0]
        mov     r9, [rdx + 8]
        mov     r10, [rdx + 16]
        mov     r11, [rdx + 24]
        mov     r12, [rdx + 32]
        shld    r12, r11, cl
        shld    r11, r10, cl
        shld    r10, r9, cl
        shld    r9, r8, cl
        shl     r8, cl
        mov     [rdx + 56], r12
        mov     [rdx + 48], r11
        mov     [rdx + 40], r10
        mov     [rdx + 32], r9
        mov     [rdx + 24], r8
        mov     [rdx + 16], rax
        mov     [rdx + 8], rax
        mov     [rdx + 0], rax
        pop     r12 r11 r10
        ret
.shift_128:
        push    r10 r11 r12 r13
        mov     r8, [rdx + 0]
        mov     r9, [rdx + 8]
        mov     r10, [rdx + 16]
        mov     r11, [rdx + 24]
        mov     r12, [rdx + 32]
        mov     r13, [rdx + 40]
        shld    r13, r12, cl
        shld    r12, r11, cl
        shld    r11, r10, cl
        shld    r10, r9, cl
        shld    r9, r8, cl
        shl     r8, cl
        mov     [rdx + 56], r13
        mov     [rdx + 48], r12
        mov     [rdx + 40], r11
        mov     [rdx + 32], r10
        mov     [rdx + 24], r9
        mov     [rdx + 16], r8
        mov     [rdx + 8], rax
        mov     [rdx + 0], rax
        pop     r13 r12 r11 r10
        ret
.shift_64:
        push    r10 r11 r12 r13 r14
        mov     r8, [rdx + 0]
        mov     r9, [rdx + 8]
        mov     r10, [rdx + 16]
        mov     r11, [rdx + 24]
        mov     r12, [rdx + 32]
        mov     r13, [rdx + 40]
        mov     r14, [rdx + 48]
        shld    r14, r13, cl
        shld    r13, r12, cl
        shld    r12, r11, cl
        shld    r11, r10, cl
        shld    r10, r9, cl
        shld    r9, r8, cl
        shl     r8, cl
        mov     [rdx + 56], r14
        mov     [rdx + 48], r13
        mov     [rdx + 40], r12
        mov     [rdx + 32], r11
        mov     [rdx + 24], r10
        mov     [rdx + 16], r9
        mov     [rdx + 8], r8
        mov     [rdx + 0], rax
        pop     r14 r13 r12 r11 r10
        ret
.shift_0:
        mov     rax, [rdx + 48]
        shld    [rdx + 56], rax, cl
        mov     rax, [rdx + 40]
        shld    [rdx + 48], rax, cl
        mov     rax, [rdx + 32]
        shld    [rdx + 40], rax, cl
        mov     rax, [rdx + 24]
        shld    [rdx + 32], rax, cl
        mov     rax, [rdx + 16]
        shld    [rdx + 24], rax, cl
        mov     rax, [rdx + 8]
        shld    [rdx + 16], rax, cl
        mov     rax, [rdx + 0]
        shld    [rdx + 8], rax, cl
        shl     qword [rdx], cl
        ret
end if