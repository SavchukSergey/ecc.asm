;Checks if bi512 value is zero
;input:
;  rcx - pointer to bi512 value
;output:
;  rax - 1 if value is zero, 0 otherwise
bi_is_zero_512_basic:
        xor     rax, rax
        or      rax, [rcx]
        or      rax, [rcx + 8]
        or      rax, [rcx + 16]
        or      rax, [rcx + 24]
        or      rax, [rcx + 32]
        or      rax, [rcx + 40]
        or      rax, [rcx + 48]
        or      rax, [rcx + 56]
        setz    al
        movzx   rax, al
        ret

bi_is_zero_512_avx2:
        vmovdqu ymm1, [rcx]
        vmovdqu ymm2, [rcx + 32]
        vpor    ymm1, ymm1, ymm2
        vptest  ymm1, ymm1
        setz    al
        movzx   rax, al
        ret

if AVX2_ENABLED = 1
  bi_is_zero_512 = bi_is_zero_512_avx2
else
  bi_is_zero_512 = bi_is_zero_512_basic
end if
