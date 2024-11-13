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

        lea     rcx, [.lxz]
        lea     rdx, [.rxz]
        call    bi_cmp_256_256
        jz      .same_x

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