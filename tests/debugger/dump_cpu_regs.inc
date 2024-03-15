if ~ definite debugger_dump_cpu_regs

macro debugger_dump_cpu_reg value, reg_label {
        push    rsi
        mov     rsi, reg_label
        call    Console_WriteString
        pop     rsi
        push    rax
        mov     rax, value
        call    Console_WriteUInt64Hex
        pop     rax
        push    rsi
        mov     rsi, .tab_separator
        call    Console_WriteString
        pop     rsi
}

debugger_dump_cpu_regs:
        call    Console_WriteLine
        call    Console_WriteLine


        debugger_dump_cpu_reg rax, .rax
        debugger_dump_cpu_reg rbx, .rbx
        debugger_dump_cpu_reg rcx, .rcx
        debugger_dump_cpu_reg rdx, .rdx
        call    Console_WriteLine
        debugger_dump_cpu_reg rsi, .rsi
        debugger_dump_cpu_reg rdi, .rdi
        debugger_dump_cpu_reg rbp, .rbp
        debugger_dump_cpu_reg rsp, .rsp
        call    Console_WriteLine
        debugger_dump_cpu_reg r8, .r8
        debugger_dump_cpu_reg r9, .r9
        debugger_dump_cpu_reg r10, .r10
        debugger_dump_cpu_reg r11, .r11
        call    Console_WriteLine
        debugger_dump_cpu_reg r12, .r12
        debugger_dump_cpu_reg r13, .r13
        debugger_dump_cpu_reg r14, .r14
        debugger_dump_cpu_reg r15, .r15

        call    Console_WriteLine
        call    Console_WriteLine
        ret
.rax db 'RAX = ', 0
.rbx db 'RBX = ', 0
.rcx db 'RCX = ', 0
.rdx db 'RDX = ', 0
.rsi db 'RSI = ', 0
.rdi db 'RDI = ', 0
.rbp db 'RBP = ', 0
.rsp db 'RSP = ', 0
.r8 db 'R8  = ', 0
.r9 db 'R9  = ', 0
.r10 db 'R10 = ', 0
.r11 db 'R11 = ', 0
.r12 db 'R12 = ', 0
.r13 db 'R13 = ', 0
.r14 db 'R14 = ', 0
.r15 db 'R15 = ', 0

.tab_separator db '    ', 0

;input
;  rax - value to dump
Console_WriteUInt64Hex:
        push    rax rcx rdx
        mov     rdx, rax
        mov     rcx, 16
.loop:
        rol     rdx, 1
        rcl     rax, 1
        rol     rdx, 1
        rcl     rax, 1
        rol     rdx, 1
        rcl     rax, 1
        rol     rdx, 1
        rcl     rax, 1
        and     rax, 0x0f
        add     rax, '0'
        cmp     rax, '9'
        jbe     .digit
        add     rax, 'a' - '9' - 1
.digit:
        call    Console_WriteChar
        loop    .loop
        pop     rdx rcx rax
        ret
