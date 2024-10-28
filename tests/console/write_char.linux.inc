if ~ definite Console_WriteChar

;input
;  al - character to put
Console_WriteChar:
        push    rax rcx rdx rsi rdi
        sub     rsp, 8

        lea     rsi, [rsp]
        mov     [rsi], al
	mov     rdx, 1          ; 1 byte
	mov     edi, 1		; STDOUT
	mov     eax, 1		; sys_write
	syscall

        add     rsp, 8
        pop     rdi rsi rdx rcx rax
        ret

end if

