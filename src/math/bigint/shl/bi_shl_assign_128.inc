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