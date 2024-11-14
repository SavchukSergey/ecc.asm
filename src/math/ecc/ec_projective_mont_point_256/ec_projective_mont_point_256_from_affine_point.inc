; Converts ECAffinePoint256 to ECProjectiveMontgomeryPoint256
; input:
;  rcx - pointer to destination ECProjectiveMontgomeryPoint256
;  rdx - pointer to source ECAffinePoint256
ec_projective_mont_point_256_from_affine_point:
virtual at rsp
.locals_start:
   .source rq 1
   .result rq 1
   .ctx rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
        mov     [.result], rcx
        mov     [.source], rdx

        mov     rax, [rdx + ECAffinePoint256.curve]
        mov     [rcx + ECProjectiveMontgomeryPoint256.curve], rax
        lea     rax, [rax + ECCurve256.mont]
        mov     [.ctx], rax

        mov     rcx, [.source]
;        lea     rcx, [rcx + ECAffinePoint256.x]
        mov     rdx, [.result]
;        lea     rdx, [rdx + ECProjectiveMontgomeryPoint256.x]
        mov     r8, [.ctx]
        call    bi_mont_ctx_256_convert
  
        mov     rcx, [.source]
        lea     rcx, [rcx + ECAffinePoint256.y]
        mov     rdx, [.result]
        lea     rdx, [rdx + ECProjectiveMontgomeryPoint256.y]
        mov     r8, [.ctx]
        call    bi_mont_ctx_256_convert

        mov     rcx, [.result]
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.z]
        mov     rdx, [.ctx]
        lea     rdx, [rdx + MontgomeryContext256.rm]
        Fast_Copy 256

        add     rsp, .locals_end - .locals_start
        ret

