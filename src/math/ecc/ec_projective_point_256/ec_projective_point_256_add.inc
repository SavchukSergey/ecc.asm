if ~ definite ec_projective_point_256_add

;Adds to ECProjectivePoint256 points
;input:
;  rcx - pointer to left ECProjectivePoint256 point
;  rdx - pointer to right ECProjectivePoint256 point
;  r8 - pointer to ECProjectivePoint256 result
ec_projective_point_256_add:
virtual at rsp
  label .locals_start
  .left rq 1
  .right rq 1
  .curve rq 1
  .result rq 1
  .modulus BigInteger256
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

    PrologCheckStackAligned 'ec_projective_point_256_add'
    CheckRegAligned rcx, 'ec_projective_point_256_add rcx'
    CheckRegAligned rdx, 'ec_projective_point_256_add rdx'
    CheckRegAligned r8, 'ec_projective_point_256_add r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     r9, [rcx + ECProjectivePoint256.curve]
        mov     [.curve], r9
        mov     [r8 + ECProjectivePoint256.curve], r9
        lea     r9, [r9 + ECCurve256.modulus]
        mov     [.modulus], r9

        mov     rcx, [.left]
        call    ec_projective_point_256_is_infinity
        jz      .use_right

        mov     rcx, [.right]
        call    ec_projective_point_256_is_infinity
        jz      .use_left

;lxz = left.X.ModMul(right.Z, Modulus)
        mov     rcx, [.left]
;        lea     rcx, [rcx + ECProjectivePoint256.x]
        mov     rdx, [.right]
        lea     rdx, [rdx + ECProjectivePoint256.z]
        mov     r8, [.modulus]
        lea     r9, [.lxz]
        call    bi_mod_mul_256_256

;rxz = right.X.ModMul(left.Z, Modulus)
        mov     rcx, [.right]
;        lea     rcx, [rcx + ECProjectivePoint256.x]
        mov     rdx, [.left]
        lea     rdx, [rdx + ECProjectivePoint256.z]
        mov     r8, [.modulus]
        lea     r9, [.rxz]
        call    bi_mod_mul_256_256

;lyz = left.Y.ModMul(right.Z, modulus)
        mov     rcx, [.left]
        lea     rcx, [rcx + ECProjectivePoint256.y]
        mov     rdx, [.right]
        lea     rdx, [rdx + ECProjectivePoint256.z]
        mov     r8, [.modulus]
        lea     r9, [.lyz]
        call    bi_mod_mul_256_256

;ryz = right.Y.ModMul(left.Z, modulus)
        mov     rcx, [.right]
        lea     rcx, [rcx + ECProjectivePoint256.y]
        mov     rdx, [.left]
        lea     rdx, [rdx + ECProjectivePoint256.z]
        mov     r8, [.modulus]
        lea     r9, [.ryz]
        call    bi_mod_mul_256_256

;dx = lxz.ModSub(rxz, Modulus)
        lea     rcx, [.lxz]
        lea     rdx, [.rxz]
        mov     r8, [.modulus]
        lea     r9, [.dx]
        call    bi_mod_sub_256_256
        jz      .same_x

;dy = lyz.ModSub(ryz, Modulus)
        lea     rcx, [.lyz]
        lea     rdx, [.ryz]
        mov     r8, [.modulus]
        lea     r9, [.dy]
        call    bi_mod_sub_256_256

;dx2 = dx.ModSquare(Modulus)
        lea     rcx, [.dx]
        mov     rdx, [.modulus]
        lea     r8, [.dx2]
        call    bi_mod_square_256

;dx3 = dx2.ModMul(dx, Modulus)
        lea     rcx, [.dx2]
        lea     rdx, [.dx]
        mov     r8, [.modulus]
        lea     r9, [.dx3]
        call    bi_mod_mul_256_256

;dy2 = dx.ModSquare(Modulus)
        lea     rcx, [.dy]
        mov     rdx, [.modulus]
        lea     r8, [.dy2]
        call    bi_mod_square_256

;z2 = left.Z.ModMul(right.Z, Modulus);
        mov     rcx, [.left]
        lea     rcx, [rcx + ECProjectivePoint256.z]
        mov     rdx, [.right]
        lea     rdx, [rdx + ECProjectivePoint256.z]
        mov     r8, [.modulus]
        lea     r9, [.z2]
        call    bi_mod_mul_256_256

;xd = lxz.ModAdd(rxz, Modulus)
        lea     rcx, [.lxz]
        lea     rdx, [.rxz]
        mov     r8, [.modulus]
        lea     r9, [.xd]
        call    bi_mod_add_256_256

;t1 =  dx2.ModMul(xd, Modulus)
        lea     rcx, [.dx2]
        lea     rdx, [.xd]
        mov     r8, [.modulus]
        lea     r9, [.t1]
        call    bi_mod_mul_256_256

;w = dy2.ModMul(z2, Modulus).ModSub(t1, Modulus)
        lea     rcx, [.dy2]
        lea     rdx, [.z2]
        mov     r8, [.modulus]
        lea     r9, [.w]
        call    bi_mod_mul_256_256
        lea     rcx, [.w]
        lea     rdx, [.t1]
        mov     r8, [.modulus]
        call    bi_mod_sub_assign_256_256

;resX = dx.ModMul(w, Modulus)
        lea     rcx, [.dx]
        lea     rdx, [.w]
        mov     r8, [.modulus]
        mov     r9, [.result]
;        lea     r9, [r9 + ECProjectivePoint256.x]
        call    bi_mod_mul_256_256

;t2 =  lxz.ModMul(dx2, Modulus).ModSub(w, Modulus)
        lea     rcx, [.lxz]
        lea     rdx, [.dx2]
        mov     r8, [.modulus]
        lea     r9, [.t2]
        call    bi_mod_mul_256_256
        lea     rcx, [.t2]
        lea     rdx, [.w]
        mov     r8, [.modulus]
        call    bi_mod_sub_assign_256_256

;t3 = lyz.ModMul(dx3, Modulus)
        lea     rcx, [.lyz]
        lea     rdx, [.dx3]
        mov     r8, [.modulus]
        lea     r9, [.t3]
        call    bi_mod_mul_256_256

;resY = dy.ModMul(t2, Modulus).ModSub(t3, Modulus);
        lea     rcx, [.dy]
        lea     rdx, [.t2]
        mov     r8, [.modulus]
        mov     r9, [.result]
        lea     r9, [r9 + ECProjectivePoint256.y]
        call    bi_mod_mul_256_256
        mov     rcx, [.result]
        lea     rcx, [rcx + ECProjectivePoint256.y]
        lea     rdx, [.t3]
        mov     r8, [.modulus]
        call    bi_mod_sub_assign_256_256

;resZ = dx3.ModMul(z2, Modulus);
        lea     rcx, [.dx3]
        lea     rdx, [.z2]
        mov     r8, [.modulus]
        mov     r9, [.result]
        lea     r9, [r9 + ECProjectivePoint256.z]
        call    bi_mod_mul_256_256

        add     rsp, .locals_end - .locals_start
        ret 

.same_x:
        lea     rcx, [.lyz]
        lea     rdx, [.ryz]
        call    bi_cmp_256_256
        jz      .double
.infinity:
        mov     rcx, [.result]
        call    ec_projective_point_256_set_infinity
        add     rsp, .locals_end - .locals_start
        ret 

.double:
        mov     rcx, [.left]
        mov     rdx, [.result]
        call    ec_projective_point_256_double
        add     rsp, .locals_end - .locals_start
        ret

.use_right:
        mov     rcx, [.result]
        mov     rdx, [.right]
        call    ec_projective_point_256_copy
        add     rsp, .locals_end - .locals_start
        ret      

.use_left:
        mov     rcx, [.result]
        mov     rdx, [.left]
        call    ec_projective_point_256_copy
        add     rsp, .locals_end - .locals_start
        ret  

end if