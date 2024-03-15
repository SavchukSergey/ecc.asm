if ~ definite bi_add_128_128

;Adds two bi128 values
;input
; rcx - left value
; rdx - right value
; r8 - result value
; rax - set to 1 if overflow
bi_add_128_128:
        mov     rax, [rcx]
        add     rax, [rdx]
        mov     [r8], rax
        mov     rax, [rcx + 8]
        adc     rax, [rdx + 8]
        mov     [r8 + 8], rax
        setc    al
        movzx   rax, al
        ret
end if

if ~ definite bi_add_256_256

;Adds two bi256 values
;input
; rcx - left value
; rdx - right value
; r8 - result value
; rax - set to 1 if overflow
bi_add_256_256:
        mov     rax, [rcx]
        add     rax, [rdx]
        mov     [r8], rax

        mov     rax, [rcx + 8]
        adc     rax, [rdx + 8]
        mov     [r8 + 8], rax

        mov     rax, [rcx + 16]
        adc     rax, [rdx + 16]
        mov     [r8 + 16], rax

        mov     rax, [rcx + 24]
        adc     rax, [rdx + 24]
        mov     [r8 + 24], rax

        setc    al
        movzx   rax, al
        ret
end if

if ~ definite bi_add_512_512

;Adds two bi256 values
;input
; rcx - left value
; rdx - right value
; r8 - result value
; rax - set to 1 if overflow
bi_add_512_512:
        mov     rax, [rcx]
        add     rax, [rdx]
        mov     [r8], rax

        mov     rax, [rcx + 8]
        adc     rax, [rdx + 8]
        mov     [r8 + 8], rax

        mov     rax, [rcx + 16]
        adc     rax, [rdx + 16]
        mov     [r8 + 16], rax

        mov     rax, [rcx + 24]
        adc     rax, [rdx + 24]
        mov     [r8 + 24], rax

        mov     rax, [rcx + 32]
        adc     rax, [rdx + 32]
        mov     [r8 + 32], rax

        mov     rax, [rcx + 40]
        adc     rax, [rdx + 40]
        mov     [r8 + 40], rax

        mov     rax, [rcx + 48]
        adc     rax, [rdx + 48]
        mov     [r8 + 48], rax

        mov     rax, [rcx + 56]
        adc     rax, [rdx + 56]
        mov     [r8 + 56], rax

        setc    al
        movzx   rax, al
        ret
end if




if ~ definite bi_add_assign_128_128

;Adds two bi128 values
;input
; rcx - left value
; rdx - right value
; rax - set to 1 if overflow
bi_add_assign_128_128:
        mov     rax, [rcx]
        add     [rdx], rax
        setc    al
        movzx   rax, al
        ret
end if

if ~ definite bi_add_assign_256_256

;Adds two bi256 values
;input
; rcx - left value
; rdx - right value
; rax - set to 1 if overflow
bi_add_assign_256_256:
        mov     rax, [rcx]
        add     [rdx], rax
        mov     rax, [rcx + 8]
        adc     [rdx + 8], rax
        setc    al
        movzx   rax, al
        ret
end if

if ~ definite bi_add_assign_512_512

;Adds two bi256 values
;input
; rcx - left value
; rdx - right value
; r8 - result value
; rax - set to 1 if overflow
bi_add_assign_512_512:
        mov     rax, [rcx]
        add     [rdx], rax
        mov     rax, [rcx + 8]
        adc     [rdx + 8], rax
        mov     rax, [rcx + 16]
        adc     [rdx + 16], rax
        mov     rax, [rcx + 24]
        adc     [rdx + 24], rax
        setc    al
        movzx   rax, al
        ret
end if
