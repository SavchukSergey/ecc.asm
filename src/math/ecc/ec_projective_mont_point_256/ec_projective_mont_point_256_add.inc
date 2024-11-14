if ~ definite ec_projective_mont_point_256_add

;Adds to ECProjectiveMontgomeryPoint256 points
;input:
;  rcx - pointer to left ECProjectiveMontgomeryPoint256 point
;  rdx - pointer to right ECProjectiveMontgomeryPoint256 point
;  r8 - pointer to ECProjectiveMontgomeryPoint256 result
ec_projective_mont_point_256_add:
virtual at rsp
  label .locals_start
  .left rq 1
  .right rq 1
  .curve rq 1
  .ctx rq 1
  .result rq 1
  .lxz BigInteger256
  .rxz BigInteger256
  .lyz BigInteger256
  .ryz BigInteger256
  .dx BigInteger256
  .dy BigInteger256
  .dx2 BigInteger256
  .dx3 BigInteger256
  .dy2 BigInteger256
  .z2 BigInteger256
  .xd BigInteger256
  .w BigInteger256
  .t1 BigInteger256
  .t2 BigInteger256
  .t3 BigInteger256

  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'ec_projective_mont_point_256_add'
    CheckRegAligned rcx, 'ec_projective_mont_point_256_add rcx'
    CheckRegAligned rdx, 'ec_projective_mont_point_256_add rdx'
    CheckRegAligned r8, 'ec_projective_mont_point_256_add r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     r9, [rcx + ECProjectiveMontgomeryPoint256.curve]
        mov     [.curve], r9
        mov     [r8 + ECProjectiveMontgomeryPoint256.curve], r9

        mov     rax, [.curve]
        lea     rax, [rax + ECCurve256.mont]
        mov     [.ctx], rax

        mov     rcx, [.left]
        call    ec_projective_mont_point_256_is_infinity
        jz      .use_right

        mov     rcx, [.right]
        call    ec_projective_mont_point_256_is_infinity
        jz      .use_left

;lxz = left.X.ModMul(right.Z, ctx)
        mov     rcx, [.left]
;        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.x]
        mov     rdx, [.right]
        lea     rdx, [rdx + ECProjectiveMontgomeryPoint256.z]
        mov     r8, [.ctx]
        lea     r9, [.lxz]
        call    bi_mont_ctx_256_mul

;rxz = right.X.ModMul(left.Z, ctx)
        mov     rcx, [.right]
;        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.x]
        mov     rdx, [.left]
        lea     rdx, [rdx + ECProjectiveMontgomeryPoint256.z]
        mov     r8, [.ctx]
        lea     r9, [.rxz]
        call    bi_mont_ctx_256_mul

;lyz = left.Y.ModMul(right.Z, ctx)
        mov     rcx, [.left]
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.y]
        mov     rdx, [.right]
        lea     rdx, [rdx + ECProjectiveMontgomeryPoint256.z]
        mov     r8, [.ctx]
        lea     r9, [.lyz]
        call    bi_mont_ctx_256_mul

;ryz = right.Y.ModMul(left.Z, ctx)
        mov     rcx, [.right]
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.y]
        mov     rdx, [.left]
        lea     rdx, [rdx + ECProjectiveMontgomeryPoint256.z]
        mov     r8, [.ctx]
        lea     r9, [.ryz]
        call    bi_mont_ctx_256_mul

;dx = lxz.ModSub(rxz, ctx)
        lea     rcx, [.lxz]
        lea     rdx, [.rxz]
        mov     r8, [.ctx]
        lea     r9, [.dx]
        call    bi_mont_ctx_256_sub
        jz      .same_x

;dy = lyz.ModSub(ryz, ctx)
        lea     rcx, [.lyz]
        lea     rdx, [.ryz]
        mov     r8, [.ctx]
        lea     r9, [.dy]
        call    bi_mont_ctx_256_sub

;dx2 = dx.ModSquare(ctx)
        lea     rcx, [.dx]
        mov     rdx, [.ctx]
        lea     r8, [.dx2]
        call    bi_mont_ctx_256_square

;dx3 = dx2.ModMul(dx, ctx)
        lea     rcx, [.dx2]
        lea     rdx, [.dx]
        mov     r8, [.ctx]
        lea     r9, [.dx3]
        call    bi_mont_ctx_256_mul

;dy2 = dx.ModSquare(ctx)
        lea     rcx, [.dy]
        mov     rdx, [.ctx]
        lea     r8, [.dy2]
        call    bi_mont_ctx_256_square

;z2 = left.Z.ModMul(right.Z, ctx)
        mov     rcx, [.left]
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.z]
        mov     rdx, [.right]
        lea     rdx, [rdx + ECProjectiveMontgomeryPoint256.z]
        mov     r8, [.ctx]
        lea     r9, [.z2]
        call    bi_mont_ctx_256_mul

;xd = lxz.ModAdd(rxz, ctx)
        lea     rcx, [.lxz]
        lea     rdx, [.rxz]
        mov     r8, [.ctx]
        lea     r9, [.xd]
        call    bi_mont_ctx_256_add

;t1 =  dx2.ModMul(xd, ctx)
        lea     rcx, [.dx2]
        lea     rdx, [.xd]
        mov     r8, [.ctx]
        lea     r9, [.t1]
        call    bi_mont_ctx_256_mul

;w = dy2.ModMul(z2, ctx).ModSub(t1, ctx)
        lea     rcx, [.dy2]
        lea     rdx, [.z2]
        mov     r8, [.ctx]
        lea     r9, [.w]
        call    bi_mont_ctx_256_mul
        lea     rcx, [.w]
        lea     rdx, [.t1]
        mov     r8, [.ctx]
        call    bi_mont_ctx_256_sub_assign

;resX = dx.ModMul(w, ctx)
        lea     rcx, [.dx]
        lea     rdx, [.w]
        mov     r8, [.ctx]
        mov     r9, [.result]
;        lea     r9, [r9 + ECProjectiveMontgomeryPoint256.x]
        call    bi_mont_ctx_256_mul

;t2 =  lxz.ModMul(dx2, ctx).ModSub(w, ctx)
        lea     rcx, [.lxz]
        lea     rdx, [.dx2]
        mov     r8, [.ctx]
        lea     r9, [.t2]
        call    bi_mont_ctx_256_mul
        lea     rcx, [.t2]
        lea     rdx, [.w]
        mov     r8, [.ctx]
        call    bi_mont_ctx_256_sub_assign

;t3 = lyz.ModMul(dx3, ctx)
        lea     rcx, [.lyz]
        lea     rdx, [.dx3]
        mov     r8, [.ctx]
        lea     r9, [.t3]
        call    bi_mont_ctx_256_mul

;resY = dy.ModMul(t2, ctx).ModSub(t3, ctx);
        lea     rcx, [.dy]
        lea     rdx, [.t2]
        mov     r8, [.ctx]
        mov     r9, [.result]
        lea     r9, [r9 + ECProjectiveMontgomeryPoint256.y]
        call    bi_mont_ctx_256_mul
        mov     rcx, [.result]
        lea     rcx, [rcx + ECProjectiveMontgomeryPoint256.y]
        lea     rdx, [.t3]
        mov     r8, [.ctx]
        call    bi_mont_ctx_256_sub_assign

;resZ = dx3.ModMul(z2, ctx);
        lea     rcx, [.dx3]
        lea     rdx, [.z2]
        mov     r8, [.ctx]
        mov     r9, [.result]
        lea     r9, [r9 + ECProjectiveMontgomeryPoint256.z]
        call    bi_mont_ctx_256_mul

        add     rsp, .locals_end - .locals_start
        ret 

.same_x:
        lea     rcx, [.lyz]
        lea     rdx, [.ryz]
        call    bi_cmp_256_256
        jz      .double
.infinity:
        mov     rcx, [.result]
        call    ec_projective_mont_point_256_set_infinity
        add     rsp, .locals_end - .locals_start
        ret 

.double:
        mov     rcx, [.left]
        mov     rdx, [.result]
        call    ec_projective_mont_point_256_double
        add     rsp, .locals_end - .locals_start
        ret

.use_right:
        mov     rcx, [.result]
        mov     rdx, [.right]
        call    ec_projective_mont_point_256_copy
        add     rsp, .locals_end - .locals_start
        ret      

.use_left:
        mov     rcx, [.result]
        mov     rdx, [.left]
        call    ec_projective_mont_point_256_copy
        add     rsp, .locals_end - .locals_start
        ret  

end if