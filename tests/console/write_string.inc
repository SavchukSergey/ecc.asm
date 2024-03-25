if ~ definite Console_WriteString

;input
;  rsi - pointer to string
Console_WriteString:
        push    rax rcx rdx rdi r8 r9 r10 rbp
        sub     rsp, 0x38

        mov     rcx, STD_OUTPUT_HANDLE
        call    [GetStdHandle]
        mov     rbp,rax

        mov     rdi,rsi
        or      rcx,-1
        xor     al,al
        repne   scasb
        neg     rcx
        sub     rcx,2

        mov     qword [rsp + 0x20], 0
        lea     r9, [rsp + 0x30]
        mov     r8, rcx
        mov     rdx, rsi
        mov     rcx, rbp
        call    [WriteFile]

        add     rsp, 0x38
        pop     rbp r10 r9 r8 rdi rdx rcx rax
        ret

end if