if ~ definite bi_lzcnt_512

;Counts leading zero bits
;input
;  rcx - pointer to bi512
;output
;  rax - leading zero bits count
bi_lzcnt_512:
        xor     rax, rax

        lzcnt   rdx, [rcx + 56]
        jnc     .end
        add     rax, rdx

        lzcnt   rdx, [rcx + 48]
        jnc     .end
        add     rax, rdx

        lzcnt   rdx, [rcx + 40]
        jnc     .end
        add     rax, rdx

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

end if