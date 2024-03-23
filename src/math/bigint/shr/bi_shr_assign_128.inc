if ~ definite bi_shr_assign_128

; Shifts right
;input
;  rcx - pointer to bi128
;  rdx - bits count
bi_shr_assign_128:
        cmp     rdx, 128
        jae     .zero
        cmp     rdx, 64
        jb      .shift_64_ok
        ;shrd does not work with 64+ bit shifts
        mov     rax, [rcx + 8]
        mov     [rcx], rax
        mov     qword [rcx + 8], 0
        sub     rdx, 64
.shift_64_ok:

        xchg    rcx, rdx

        mov     rax, [rdx + 8]
        shrd    [rdx + 0], rax, cl
        shr     qword [rdx + 8], cl

        xchg    rcx, rdx

        ret

.zero:
        mov     qword [rcx], 0
        mov     qword [rcx + 8], 0
        ret
end if


