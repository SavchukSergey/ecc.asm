
; Converts projective point to projective point
; input:
;  rcx - pointer to source ECProjectiveMontgomeryPoint256
;  rdx - pointer to destination ECProjectivePoint256
ec_projective_mont_point_256_to_projective_mont_point:
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
        mov     r8, [rcx + ECProjectiveMontgomeryPoint256.curve]
        mov     [.curve], r8

        mov     [rdx + ECProjectivePoint256.curve], r8

        mov     rcx, [.source]
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.z]
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
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.y]
        lea     rdx, [.inv]
        mov     r8, [.curve]
        lea     r8, [r8 + ECCurve256.modulus]
        mov     r9, [.result]
        lea     r9, [r9 + ECProjectivePoint256.y]
        call    bi_mod_mul_256_256

        add     rsp, .locals_end - .locals_start
        ret

