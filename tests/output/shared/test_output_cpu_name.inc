test_output_cpu_name:
virtual at rsp
  label .locals_start
  .dwords rd 12
  .tail rd 1
  AlignLocalsStackFrame
  label .locals_end
end virtual
    sub     rsp, .locals_end - .locals_start

    mov     eax, 0x80000002
    cpuid
    mov     [.dwords], eax
    mov     [.dwords + 4], ebx
    mov     [.dwords + 8], ecx
    mov     [.dwords + 12], edx

    mov     eax, 0x80000003
    cpuid
    mov     [.dwords + 16], eax
    mov     [.dwords + 20], ebx
    mov     [.dwords + 24], ecx
    mov     [.dwords + 28], edx

    mov     eax, 0x80000004
    cpuid
    mov     [.dwords + 32], eax
    mov     [.dwords + 36], ebx
    mov     [.dwords + 40], ecx
    mov     [.dwords + 44], edx

    mov     [.tail], 0

    lea     rsi, [.dwords]
    call    Console_WriteString
    call    Console_WriteLine

    add     rsp, .locals_end - .locals_start
    ret
