test_output_rps:
virtual at rsp
  label .locals_start
  AlignLocalsStackFrame
  label .locals_end
end virtual
    push    rbx rsi
    sub     rsp, .locals_end - .locals_start

    cmp     rcx, -1
    je      .na

    cmp     rcx, 1000000000
    jae     .giga_ops
    cmp     rcx, 1000000
    jae     .mega_ops
    cmp     rcx, 1000
    jae     .kilo_ops

    call    Console_WriteUInt64
    lea     rsi, [.ops_msg]
    call    Console_WriteString
.end:
    add     rsp, .locals_end - .locals_start
    pop     rsi rbx
    ret
.na:
    lea     rsi, [.na_msg]
    call    Console_WriteString
    jmp     .end
.kilo_ops:
    mov     rbx, 1000
    lea     rsi, [.kilo_ops_msg]
    jmp     .write_fractional
.mega_ops:
    mov     rbx, 1000000
    lea     rsi, [.mega_ops_msg]
    jmp     .write_fractional
.giga_ops:
    mov     rbx, 1000000000
    lea     rsi, [.giga_ops_msg]
    jmp     .write_fractional

.write_fractional:
    push    rcx
    xor     rdx, rdx
    mov     rax, rcx
    div     rbx
    mov     rcx, rax
    call    Console_WriteUInt64
    mov     al, '.'
    call    Console_WriteChar

    mov     rax, rdx                ;remainder
    mov     rdx, 10
    mul     rdx
    xor     rdx, rdx
    div     rbx
    add     al, '0'
    call    Console_WriteChar

    mov     rax, rdx                ;remainder
    mov     rdx, 10
    mul     rdx
    xor     rdx, rdx
    div     rbx
    add     al, '0'
    call    Console_WriteChar

    pop     rcx

    call    Console_WriteString
    jmp     .end
    
.ops_msg db ' ops', 0
.kilo_ops_msg db ' kops', 0
.mega_ops_msg db ' mops', 0
.giga_ops_msg db ' gops', 0
.na_msg db 'N/A', 0

