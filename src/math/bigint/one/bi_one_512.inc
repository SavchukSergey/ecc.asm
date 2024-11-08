if ~ definite bi_one_512

;Sets 1 to bi512 value
;input
; rcx - pointer to result
bi_one_512:
        xor     rax, rax
        mov     qword [rcx], 1
        mov     [rcx + 8], rax
        mov     [rcx + 16], rax
        mov     [rcx + 24], rax
        mov     [rcx + 32], rax
        mov     [rcx + 40], rax
        mov     [rcx + 48], rax
        mov     [rcx + 56], rax
        ret

end if