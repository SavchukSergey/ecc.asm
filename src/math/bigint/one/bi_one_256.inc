if ~ definite bi_one_256

;Sets 1 to bi256 value
;input
; rcx - pointer to result
bi_one_256:
        xor     rax, rax
        mov     qword [rcx], 1
        mov     [rcx + 8], rax
        mov     [rcx + 16], rax
        mov     [rcx + 24], rax
        ret

end if