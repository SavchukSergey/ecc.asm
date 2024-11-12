if ~ definite secp256k1_point_add

;Adds to secp256k1 points
;input:
;  rcx - pointer to left secp256k1 point
;  rdx - pointer to right secp256k1 point
;  r8 - pointer to ECAffinePoint256 result
secp256k1_point_add:
virtual at rsp
  label .locals_start
  .dx BigInteger256
  .dy BigInteger256
  .m BigInteger256
  .m2 BigInteger256
  .temp BigInteger256
  .left rq 1
  .right rq 1
  .result rq 1
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'secp256k1_point_add'
    CheckRegAligned rcx, 'secp256k1_point_add rcx'
    CheckRegAligned rdx, 'secp256k1_point_add rdx'
    CheckRegAligned r8, 'secp256k1_point_add r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.result], r8

        mov     rcx, [.left]
        call    ec_affine_point_256_is_infinity
        jz      .use_right

        mov     rcx, [.right]
        call    ec_affine_point_256_is_infinity
        jz      .use_left

; dx = right.x - left.x
        mov     rcx, [.right]
        mov     rdx, [.left]
        mov     r8, secp256k1_p
        lea     r9, [.dx]
        call    bi_mod_sub_256_256
; dy = right.y - left.y
        mov     rcx, [.right]
        add     rcx, ECAffinePoint256.y
        mov     rdx, [.left]
        add     rdx, ECAffinePoint256.y
        mov     r8, secp256k1_p
        lea     r9, [.dy]
        call    bi_mod_sub_256_256

        lea     rcx, [.dx]
        call    bi_is_zero_256
        jz      .same_x

; m = dy / dx
        lea     rcx, [.dy]
        lea     rdx, [.dx]
        mov     r8, secp256k1_p
        lea     r9, [.m]
        call    bi_mod_div_256_256
.got_m:
; m2 = m ^ 2
        lea     rcx, [.m]
        mov     rdx, secp256k1_p
        lea     r8, [.m2]
        call    bi_mod_square_256

;result.x = m2 - left.x - right.x
        lea     rcx, [.m2]
        mov     rdx, [.left]
        mov     r8, secp256k1_p
        mov     r9, [.result]
        call    bi_mod_sub_256_256

        mov     rcx, [.result]
        mov     rdx, [.right]
        mov     r8, secp256k1_p
        call    bi_mod_sub_assign_256_256


;result.y = m * (left.x - result.x) - left.y
        mov     rcx, [.left]
        mov     rdx, [.result]
        mov     r8, secp256k1_p
        lea     r9, [.temp]
        call    bi_mod_sub_256_256

        lea     rcx, [.temp]
        lea     rdx, [.m]
        mov     r8, secp256k1_p
        mov     r9, [.result]
        add     r9, ECAffinePoint256.y
        call    bi_mod_mul_256_256

        mov     rcx, [.result]
        add     rcx, ECAffinePoint256.y
        mov     rdx, [.left]
        add     rdx, ECAffinePoint256.y
        mov     r8, secp256k1_p
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
;           3 * (left.x ^ 2) + curve.A
; m =    ---------------------------------
;             2 * left.y
        mov     rcx, [.left]
        mov     rdx, secp256k1_p
        lea     r8, [.temp]
        call    bi_mod_square_256

        lea     rcx, [.temp]
        mov     rdx, secp256k1_p
        call    bi_mod_tripple_assign_256

        lea     rcx, [.temp]
        mov     rdx, secp256k1_a
        mov     r8, secp256k1_p
        call    bi_mod_add_assign_256_256

        lea     rcx, [.temp]
        mov     rdx, [.left]
        add     rdx, ECAffinePoint256.y
        mov     r8, secp256k1_p
        lea     r9, [.m]
        call    bi_mod_div_256_256

        lea     rcx, [.m]
        mov     rdx, secp256k1_p
        call    bi_mod_half_assign_256

        jmp     .got_m
.use_right:
        mov     rcx, [.result]
        mov     rdx, [.right]
        call    ec_affine_point_256_copy
        add     rsp, .locals_end - .locals_start
        ret      

.use_left:
        mov     rcx, [.left]
        mov     rdx, [.right]
        call    ec_affine_point_256_copy
        add     rsp, .locals_end - .locals_start
        ret  

end if