if ~ definite bi_is_zero_256

include '../config.inc'

;Checks if bi256 value is zero
;input
;  rcx - pointer to result
;output
;  rax - 1 if value is zero, 0 otherwise
bi_is_zero_256_basic:
        xor     rax, rax
        or      rax, [rcx]
        or      rax, [rcx + 8]
        or      rax, [rcx + 16]
        or      rax, [rcx + 24]
        setz    al
        movzx   rax, al
        ret

bi_is_zero_256_avx2:
        vmovdqu ymm1, [rcx]
        vptest  ymm1, ymm1
        setz    al
        movzx   rax, al
        ret

if AVX2_ENABLED = 1
  bi_is_zero_256 = bi_is_zero_256_avx2
else
  bi_is_zero_256 = bi_is_zero_256_basic
end if

end if