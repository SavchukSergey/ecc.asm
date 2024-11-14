;Counts leading zero bits of bi192
;input:
;  rcx - pointer to bi192
;output:
;  rax - leading zero bits count
bi_lzcnt_192:
        xor     rax, rax

        lzcnt   rdx, [rcx + 16]
        jnc     .end
        add     rax, rdx

        lzcnt   rdx, [rcx + 8]
        jnc     .end
        add     rax, rdx

        lzcnt   rdx, [rcx + 0]
.end:
        add     rax, rdx
        ret
