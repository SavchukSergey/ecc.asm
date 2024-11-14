;Counts leading zero bits of bi128
;input:
;  rcx - pointer to bi128
;output:
;  rax - leading zero bits count
bi_lzcnt_128:
        xor     rax, rax

        lzcnt   rdx, [rcx + 8]
        jnc     .end
        add     rax, rdx

        lzcnt   rdx, [rcx + 0]
.end:
        add     rax, rdx
        ret
