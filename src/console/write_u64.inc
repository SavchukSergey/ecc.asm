include 'write_char.inc'

;input
; rax - value to dump
Console_WriteUInt64:
        test    rax, rax
        jne     .not_zero
        push    rax
        mov     al, '0'
        call    Console_WriteChar
        pop     rax
        ret
.not_zero:
        push    rax rbx rcx rdx
        lea     rcx, [Console_Pow10_UInt64]
        mov     rbx, rax
.loop:
        mov     rax, rbx
        xor     rdx, rdx
        div     qword [rcx]
        test    rax, rax
        jnz     .value_loop

        mov     rbx, rdx
        add     rcx, 8

        cmp     qword [rcx], 0
        jne     .loop
        jmp     .end
.value_loop:
        mov     rax, rbx
        xor     rdx, rdx
        div     qword [rcx]
        add     al, '0'
        call    Console_WriteChar

        mov     rbx, rdx
        add     rcx, 8

        cmp     qword [rcx], 0
        jne     .value_loop
.end:
        pop     rdx rcx rbx rax
        ret

Console_Pow10_UInt64:
        dq  10000000000000000000    ;18,446,744,073,709,551,615
        dq  1000000000000000000
        dq  100000000000000000
        dq  10000000000000000
        dq  1000000000000000
        dq  100000000000000
        dq  10000000000000
        dq  1000000000000
        dq  100000000000
        dq  10000000000
        dq  1000000000
        dq  100000000
        dq  10000000
        dq  1000000
        dq  100000
        dq  10000
        dq  1000
        dq  100
        dq  10
        dq  1
        dq  0