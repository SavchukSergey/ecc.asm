
; Converts projective point to affine point
; input:
;  rcx - pointer to source ECProjectivePoint256
;  rdx - pointer to destination ECAffinePoint256
;   r8 - pointer to ECCurve256
ec_projective_point_256_to_affine_point:
virtual at rsp
.locals_start:
   .source rq 1
   .result rq 1
   .curve rq 1
   .inv BigInteger256 
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
        mov     [.source], rcx
        mov     [.result], rdx
        mov     [.curve], r8

        mov     rcx, [.source]
        lea     rcx, [rcx + ECProjectivePoint256.z]
        lea     rdx, [r8 + ECCurve256.modulus]
        lea     r8, [.inv]
        call    bi_mod_inverse_256

        mov     rcx, [.source]
        lea     rdx, [.inv]
        mov     r8, [.curve]
        lea     r8, [r8 + ECCurve256.modulus]
        mov     r9, [.result]
        call    bi_mod_mul_256_256
  
        mov     rcx, [.source]
        lea     rcx, [rcx + ECProjectivePoint256.y]
        lea     rdx, [.inv]
        mov     r8, [.curve]
        lea     r8, [r8 + ECCurve256.modulus]
        mov     r9, [.result]
        lea     r9, [r9 + ECAffinePoint256.y]
        call    bi_mod_mul_256_256

        add     rsp, .locals_end - .locals_start
        ret

