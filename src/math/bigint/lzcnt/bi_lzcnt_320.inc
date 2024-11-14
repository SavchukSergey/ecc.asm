;Counts leading zero bits of bi320
;input:
;  rcx - pointer to bi320
;output:
;  rax - leading zero bits count
bi_lzcnt_320:
        xor     rax, rax

        lzcnt   rdx, [rcx + 32]
        jnc     .end
        add     rax, rdx

        lzcnt   rdx, [rcx + 24]
        jnc     .end
        add     rax, rdx

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