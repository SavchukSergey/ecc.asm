if ~ definite bi_sub_128_128

;Subs two bi128 values
;input
; rcx - left value
; rdx - right value
; r8 - result value
; rax - set to 1 if overflow
bi_sub_128_128:
        mov     rax, [rcx]
        sub     rax, [rdx]
        mov     [r8], rax
        mov     rax, [rcx + 8]
        sbb     rax, [rdx + 8]
        mov     [r8 + 8], rax
        setc    al
        movzx   rax, al
        ret
end if

if ~ definite bi_sub_256_256

;Subs two bi256 values
;input
; rcx - left value
; rdx - right value
; r8 - result value
; rax - set to 1 if overflow
bi_sub_256_256:
        mov     rax, [rcx]
        sub     rax, [rdx]
        mov     [r8], rax

        mov     rax, [rcx + 8]
        sbb     rax, [rdx + 8]
        mov     [r8 + 8], rax

        mov     rax, [rcx + 16]
        sbb     rax, [rdx + 16]
        mov     [r8 + 16], rax

        mov     rax, [rcx + 24]
        sbb     rax, [rdx + 24]
        mov     [r8 + 24], rax

        setc    al
        movzx   rax, al
        ret
end if

if ~ definite bi_sub_512_512

;Subs two bi256 values
;input
; rcx - left value
; rdx - right value
; r8 - result value
; rax - set to 1 if overflow
bi_sub_512_512:
        mov     rax, [rcx]
        sub     rax, [rdx]
        mov     [r8], rax

        mov     rax, [rcx + 8]
        sbb     rax, [rdx + 8]
        mov     [r8 + 8], rax

        mov     rax, [rcx + 16]
        sbb     rax, [rdx + 16]
        mov     [r8 + 16], rax

        mov     rax, [rcx + 24]
        sbb     rax, [rdx + 24]
        mov     [r8 + 24], rax

        mov     rax, [rcx + 32]
        sbb     rax, [rdx + 32]
        mov     [r8 + 32], rax

        mov     rax, [rcx + 40]
        sbb     rax, [rdx + 40]
        mov     [r8 + 40], rax

        mov     rax, [rcx + 48]
        sbb     rax, [rdx + 48]
        mov     [r8 + 48], rax

        mov     rax, [rcx + 56]
        sbb     rax, [rdx + 56]
        mov     [r8 + 56], rax

        setc    al
        movzx   rax, al
        ret
end if




if ~ definite bi_sub_assign_128_128

;Subs two bi128 values
;input
; rcx - left value
; rdx - right value
; rax - set to 1 if overflow
bi_sub_assign_128_128:
        mov     rax, [rcx]
        sub     [rdx], rax
        mov     rax, [rcx + 8]
        sbb     [rdx + 8], rax
        setc    al
        movzx   rax, al
        ret
end if

if ~ definite bi_sub_assign_256_256

;Subs two bi256 values
;input
; rcx - left value
; rdx - right value
; rax - set to 1 if overflow
bi_sub_assign_256_256:
        mov     rax, [rcx]
        sub     [rdx], rax
        mov     rax, [rcx + 8]
        sbb     [rdx + 8], rax
        mov     rax, [rcx + 16]
        sbb     [rdx + 16], rax
        mov     rax, [rcx + 24]
        sbb     [rdx + 24], rax
        setc    al
        movzx   rax, al
        ret
end if

if ~ definite bi_sub_assign_512_512

;Subs two bi256 values
;input
; rcx - left value
; rdx - right value
; r8 - result value
; rax - set to 1 if overflow
bi_sub_assign_512_512:
        mov     rax, [rcx]
        sub     [rdx], rax
        mov     rax, [rcx + 8]
        sbb     [rdx + 8], rax
        mov     rax, [rcx + 16]
        sbb     [rdx + 16], rax
        mov     rax, [rcx + 24]
        sbb     [rdx + 24], rax
        mov     rax, [rcx + 32]
        sbb     [rdx + 32], rax
        mov     rax, [rcx + 40]
        sbb     [rdx + 40], rax
        mov     rax, [rcx + 48]
        sbb     [rdx + 48], rax
        mov     rax, [rcx + 56]
        sbb     [rdx + 56], rax
        setc    al
        movzx   rax, al
        ret
end if
