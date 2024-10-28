if ~ definite Console_WriteString

;input
;  rsi - pointer to string
Console_WriteString:
        push    rax rcx rdx rsi rdi

        cld
        mov     rdi, rsi
        or      rcx, -1
        xor     al, al
        repne   scasb
        neg     rcx
        sub     rcx, 2

	mov      rdx, rcx
	mov      edi, 1		; STDOUT
	mov      eax, 1		; sys_write
	syscall

        pop     rdi rsi rdx rcx rax
        ret

end if