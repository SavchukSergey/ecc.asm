secp256k1_get_affine_point:
virtual at rsp
  label .locals_start
  .multiplier rq 1
  .result rq 1
  .result_pm ECProjectiveMontgomeryPoint256
  .cache_pm ECProjectiveMontgomeryPoint256
  .cache_pointer rq 1
  .byte_index rq 1

  AlignLocalsStackFrame
  label .locals_end
end virtual
    sub     rsp, .locals_end - .locals_start
    mov     [.multiplier], rcx
    mov     [.result], rdx

    mov     [.result_pm + ECProjectiveMontgomeryPoint256.curve], secp256k1
    mov     [.cache_pm + ECProjectiveMontgomeryPoint256.curve], secp256k1

    lea     rcx, [.cache_pm + ECProjectiveMontgomeryPoint256.z]
    lea     rdx, [secp256k1_mont_rm]
    Fast_Copy 256

    lea     rcx, [.result_pm]
    call    ec_projective_mont_point_256_set_infinity

    mov     [.byte_index], 0
.loop:
    mov     rax, [.byte_index]
    mov     rdx, [.multiplier]
    mov     dl, byte [rdx + rax]
    movzx   rdx, dl
    shl     rax, 8
    add     rdx, rax
    shl     rdx, 6                             ;64 byte per cached point
    add     rdx, secp256k1_mp_cache_data
    mov     [.cache_pointer], rdx

    lea     rcx, [.cache_pm]
    Fast_Copy 256 * 2

    lea     rcx, [.result_pm]
    lea     rdx, [.cache_pm]
    call    ec_projective_mont_point_256_add_assign

    inc     [.byte_index]
    cmp     [.byte_index], __BIG_INTEGER_BYTES_256
    jb      .loop

    lea     rcx, [.result_pm]
    mov     rdx, [.result]
    call    ec_projective_mont_point_256_to_affine_point

    add     rsp, .locals_end - .locals_start
    ret