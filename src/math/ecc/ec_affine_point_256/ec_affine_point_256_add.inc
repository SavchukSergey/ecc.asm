if ~ definite ec_affine_point_256_add

;Adds to ECAffinePoint256 points
;input:
;  rcx - pointer to left ECAffinePoint256 point
;  rdx - pointer to right ECAffinePoint256 point
;  r8 - pointer to ECAffinePoint256 result
ec_affine_point_256_add:
virtual at rsp
  label .locals_start
  .dx BigInteger256
  .dy BigInteger256
  .m BigInteger256
  .m2 BigInteger256
  .temp BigInteger256
  .left rq 1
  .right rq 1
  .curve rq 1
  .modulus rq 1
  .result rq 1
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'ec_affine_point_256_add'
    CheckRegAligned rcx, 'ec_affine_point_256_add rcx'
    CheckRegAligned rdx, 'ec_affine_point_256_add rdx'
    CheckRegAligned r8, 'ec_affine_point_256_add r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     r9, [rcx + ECAffinePoint256.curve]
        mov     [.curve], r9
        mov     [r8 + ECAffinePoint256.curve], r9
        mov     r9, [.curve]
        lea     r9, [r9 + ECCurve256.modulus]
        mov     [.modulus], r9

        mov     rcx, [.left]
        call    ec_affine_point_256_is_infinity
        jz      .use_right

        mov     rcx, [.right]
        call    ec_affine_point_256_is_infinity
        jz      .use_left

; dx = right.x - left.x
        mov     rcx, [.right]
        mov     rdx, [.left]
        mov     r8, [.modulus]
        lea     r9, [.dx]
        call    bi_mod_sub_256_256
; dy = right.y - left.y
        mov     rcx, [.right]
        add     rcx, ECAffinePoint256.y
        mov     rdx, [.left]
        add     rdx, ECAffinePoint256.y
        mov     r8, [.modulus]
        lea     r9, [.dy]
        call    bi_mod_sub_256_256

        lea     rcx, [.dx]
        call    bi_is_zero_256
        jz      .same_x

; m = dy / dx
        lea     rcx, [.dy]
        lea     rdx, [.dx]
        mov     r8, [.modulus]
        lea     r9, [.m]
        call    bi_mod_div_256_256
.got_m:
; m2 = m ^ 2
        lea     rcx, [.m]
        mov     rdx, [.modulus]
        lea     r8, [.m2]
        call    bi_mod_square_256

;result.x = m2 - left.x - right.x
        lea     rcx, [.m2]
        mov     rdx, [.left]
        mov     r8, [.modulus]
        mov     r9, [.result]
        call    bi_mod_sub_256_256

        mov     rcx, [.result]
        mov     rdx, [.right]
        mov     r8, [.modulus]
        call    bi_mod_sub_assign_256_256


;result.y = m * (left.x - result.x) - left.y
        mov     rcx, [.left]
        mov     rdx, [.result]
        mov     r8, [.modulus]
        lea     r9, [.temp]
        call    bi_mod_sub_256_256

        lea     rcx, [.temp]
        lea     rdx, [.m]
        mov     r8, [.modulus]
        mov     r9, [.result]
        add     r9, ECAffinePoint256.y
        call    bi_mod_mul_256_256

        mov     rcx, [.result]
        add     rcx, ECAffinePoint256.y
        mov     rdx, [.left]
        add     rdx, ECAffinePoint256.y
        mov     r8, [.modulus]
        call    bi_mod_sub_assign_256_256

        add     rsp, .locals_end - .locals_start
        ret
.same_x:
        lea     rcx, [.dy]
        call    bi_is_zero_256
        jz      .double
.infinity:
        mov     rcx, [.result]
        call    ec_affine_point_256_set_infinity
        add     rsp, .locals_end - .locals_start
        ret 

.double:
        mov     rcx, [.left]
        mov     rdx, [.result]
        call    ec_affine_point_256_double

        add     rsp, .locals_end - .locals_start
        ret 

.use_right:
        mov     rcx, [.result]
        mov     rdx, [.right]
        call    ec_affine_point_256_copy
        add     rsp, .locals_end - .locals_start
        ret      

.use_left:
        mov     rcx, [.result]
        mov     rdx, [.left]
        call    ec_affine_point_256_copy
        add     rsp, .locals_end - .locals_start
        ret  

end if