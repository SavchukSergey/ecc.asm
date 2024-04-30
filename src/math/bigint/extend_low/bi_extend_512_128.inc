if ~ definite bi_extend_512_128

bi_extend_512_128:
    CheckRegBi512Alignment rcx, 'bi_extend_512_128 rcx'
    CheckRegBi128Alignment rdx, 'bi_extend_512_128 rdx'

        mov     rax, [rdx + 0]
        mov     [rcx + 0], rax
        mov     rax, [rdx + 8]
        mov     [rcx + 8], rax
        mov     qword [rcx + 16], 0
        mov     qword [rcx + 24], 0
        mov     qword [rcx + 32], 0
        mov     qword [rcx + 40], 0
        mov     qword [rcx + 48], 0
        mov     qword [rcx + 56], 0

        ret

end if