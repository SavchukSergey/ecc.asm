
; Converts projective montgomery point to projective point
; input:
;  rcx - pointer to source ECProjectiveMontgomeryPoint256
;  rdx - pointer to destination ECProjectivePoint256
ec_projective_mont_point_256_to_projective_point:
virtual at rsp
.locals_start:
   .source rq 1
   .result rq 1
   .ctx rq 1
   .curve rq 1
   .inv BigInteger256 
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
        mov     [.source], rcx
        mov     [.result], rdx

        mov     rax, [rcx + ECProjectiveMontgomeryPoint256.curve]
        mov     [rdx + ECProjectivePoint256.curve], rax
        lea     rax, [rax + ECCurve256.mont]
        mov     [.ctx], rax

        mov     rcx, [.source]
;        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.x]
        mov     rdx, [.result]
;        lea     rdx, [rdx + ECProjectivePoint256.x]
        mov     r8, [.ctx]
        call    bi_mont_ctx_256_redc_256
  
        mov     rcx, [.source]
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.y]
        mov     rdx, [.result]
        lea     rdx, [rdx + ECProjectivePoint256.y]
        mov     r8, [.ctx]
        call    bi_mont_ctx_256_redc_256

        mov     rcx, [.source]
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.z]
        mov     rdx, [.result]
        lea     rdx, [rdx + ECProjectivePoint256.z]
        mov     r8, [.ctx]
        call    bi_mont_ctx_256_redc_256

        add     rsp, .locals_end - .locals_start
        ret

