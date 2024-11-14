__ec_projective_mont_point_256_negate_test:
virtual at rsp
.locals_start:
  .source ECProjectiveMontgomeryPoint256
  .target ECProjectiveMontgomeryPoint256
  AlignLocalsStackFrame
.locals_end:
end virtual
    sub     rsp, .locals_end - .locals_start

    lea     rcx, [.source]
    lea     rdx, [.source_hex]
    mov     r8, secp256k1
    call    ec_projective_mont_point_256_try_read_hex

    call    test_context_start_measure
.chunk_loop:
    lea     rcx, [.source]
    lea     rdx, [.target]
    call    ec_projective_mont_point_256_negate
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
    call    test_context_end_measure

    lea     rcx, [.expected_hex]
    lea     rdx, [.target]
    call    ec_projective_mont_point_256_assert_equal_hex

    add     rsp, .locals_end - .locals_start
    ret

align 16
.source_hex:
  db '96e6b51d86cc74119556e2dad4965d5f385b8f72ab12613a2d7f3bcf74a81385'
  db '6bc8994d2ff8b18e145821876517018ba9b7c533b221e9dfb639e5bfd55abdc4'
  db '6e2c90fc3b29f9af00159d56fcfb4f80f2fea7c4fb96f0a5966664a8931caa3c'

.expected_hex:
  db '96e6b51d86cc74119556e2dad4965d5f385b8f72ab12613a2d7f3bcf74a81385'
  db '943766b2d0074e71eba7de789ae8fe7456483acc4dde162049c61a3f2aa53e6b'
  db '6e2c90fc3b29f9af00159d56fcfb4f80f2fea7c4fb96f0a5966664a8931caa3c'
