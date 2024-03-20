if ~ definite bi_is_zero_256

;Checks if bi256 value is zero
;input
;  rcx - pointer to result
;output
;  rax - 1 if value is zero, 0 otherwise
bi_is_zero_256:
        xor     rax, rax
        or      rax, [rcx]
        or      rax, [rcx + 8]
        or      rax, [rcx + 16]
        or      rax, [rcx + 24]
        setz    al
        movzx   rax, al
        ret

end if