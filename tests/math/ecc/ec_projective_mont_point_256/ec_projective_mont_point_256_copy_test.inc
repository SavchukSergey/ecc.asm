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
  db '96e6b51d86cc74119556e2dad4965d5f385b8f72ab12613a2d7f3bcf74a81385'
  db '6bc8994d2ff8b18e145821876517018ba9b7c533b221e9dfb639e5bfd55abdc4'
  db '6e2c90fc3b29f9af00159d56fcfb4f80f2fea7c4fb96f0a5966664a8931caa3c'