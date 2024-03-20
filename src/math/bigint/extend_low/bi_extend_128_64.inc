if ~ definite bi_extend_128_64

bi_extend_128_64:
        mov     [rcx + 0], rdx
        mov     qword [rcx + 8], 0
        ret

end if