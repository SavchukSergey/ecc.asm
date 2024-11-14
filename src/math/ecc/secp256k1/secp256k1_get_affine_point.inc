secp256k1_get_affine_point:
virtual at rsp
  label .locals_start
  .multiplier rq 1
  .result rq 1
  .generator_pm ECProjectiveMontgomeryPoint256
  .result_pm ECProjectiveMontgomeryPoint256

  AlignLocalsStackFrame
  label .locals_end
end virtual
    sub     rsp, .locals_end - .locals_start
    mov     [.multiplier], rcx
    mov     [.result], rdx

    lea     rcx, [.generator_pm]
    lea     rdx, [secp256k1_gx]
    call    ec_projective_mont_point_256_from_affine_point

    lea     rcx, [.generator_pm]
    mov     rdx, [.multiplier]
    lea     r8, [.result_pm]
    call    ec_projective_mont_point_256_mul

    lea     rcx, [.result_pm]
    mov     rdx, [.result]
    call    ec_projective_mont_point_256_to_affine_point

    add     rsp, .locals_end - .locals_start
    ret