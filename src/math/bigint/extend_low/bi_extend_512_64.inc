if ~ definite bi_extend_512_64

bi_extend_512_64:
        mov     [rcx + 0], rdx
        mov     qword [rcx + 8], 0
        mov     qword [rcx + 16], 0
        mov     qword [rcx + 24], 0
        mov     qword [rcx + 32], 0
        mov     qword [rcx + 40], 0
        mov     qword [rcx + 48], 0
        mov     qword [rcx + 56], 0

        ret

end if