if ~ definite Console_WriteChar

;input
;  al - character to put
Console_WriteChar:
        push    rax rcx rdx r8 r9 r10 rbx
        mov     bl, al
        sub     rsp, 0x40
        mov     rcx, STD_OUTPUT_HANDLE
        call    [GetStdHandle]
        mov     rcx, rax
        lea     rdx, [rsp + 0x38]
        mov     [rdx], bl
        mov     r8, 1
        lea     r9, [rsp + 0x30]
        mov     qword [rsp + 0x20], 0
        call    [WriteFile]
        add     rsp, 0x40
        pop     rbx r10 r9 r8 rdx rcx rax
        ret

end if

