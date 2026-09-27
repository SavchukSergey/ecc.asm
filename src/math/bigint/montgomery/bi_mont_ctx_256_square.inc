if ~ definite bi_mont_ctx_256_square

;Squares bi256 value in montgomery form:
;  result = value * value * 2^-256 mod modulus
;The fused CIOS multiplication is faster than composing a dedicated
;256-bit square with a separate REDC pass
;input:
;  rcx - pointer to bi256 montgomery value
;  rdx - pointer to MontgomeryContext256
;  r8  - pointer to bi256 result (may alias the value)
bi_mont_ctx_256_square:
        mov     r9, r8
        mov     r8, rdx
        mov     rdx, rcx
        jmp     bi_mont_ctx_256_mul

end if
