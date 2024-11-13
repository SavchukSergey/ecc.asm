__ec_projective_mont_point_256_copy_test:
virtual at rsp
.locals_start:
  .source ECProjectiveMontgomeryPoint256
  .target ECProjectiveMontgomeryPoint256
.locals_end:
end virtual
    enter   .locals_end - .locals_start, 0  
    lea     rcx, [.source]
    lea     rdx, [.source_hex]
    mov     r8, secp256k1
    call    ec_projective_mont_point_256_try_read_hex

    call    test_context_start_measure
.chunk_loop:
    lea     rcx, [.target]
    lea     rdx, [.source]
    call    ec_projective_mont_point_256_copy
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
    call    test_context_end_measure

    lea     rcx, [.source_hex]
    lea     rdx, [.target]
    call    ec_projective_mont_point_256_assert_equal_hex

    leave
    ret

align 16
.source_hex:
  db '575611bf4bbc952c0d5b9c3b87147d1ce3381e34f688e2a2d9844761b0dc36c2'
  db 'ca55bd03a22ed3bd3d36ff4c6dc09aa768984a3f32c662640a38af949a384810'
  db '0000000000000000000000000000000000000000000000000000000000000001'