if ~ definite bi_extend_384_128

bi_extend_384_128:
        mov     rax, [rdx + 0]
        mov     [rcx + 0], rax
        mov     rax, [rdx + 8]
        mov     [rcx + 8], rax
        mov     qword [rcx + 16], 0
        mov     qword [rcx + 24], 0
        mov     qword [rcx + 32], 0
        mov     qword [rcx + 40], 0

        ret

end if