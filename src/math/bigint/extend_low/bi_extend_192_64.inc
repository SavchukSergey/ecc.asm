if ~ definite bi_extend_192_64

bi_extend_192_64:
        mov     [rcx + 0], rdx
        mov     qword [rcx + 8], 0
        mov     qword [rcx + 16], 0
        ret

end if