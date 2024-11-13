__ec_projective_mont_point_256_to_affine_point_test:
virtual at rsp
.locals_start:
   .source_point ECProjectiveMontgomeryPoint256
   .result_point ECAffinePoint256
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__ec_projective_mont_point_256_to_affine_point_test'

        lea     rcx, [.source_point]
        lea     rdx, [.source_point_hex]
        mov     r8, secp256k1
        call    ec_projective_mont_point_256_try_read_hex

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.source_point]
        lea     rdx, [.result_point]
        call    ec_projective_mont_point_256_to_affine_point
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [.expected_point_hex]
        lea     rdx, [.result_point]
        call    ec_affine_point_256_assert_equal_hex

        add     rsp, .locals_end - .locals_start
        ret

align 16
.source_point_hex:
  db '96e6b51d86cc74119556e2dad4965d5f385b8f72ab12613a2d7f3bcf74a81385'
  db '6bc8994d2ff8b18e145821876517018ba9b7c533b221e9dfb639e5bfd55abdc4'
  db '6e2c90fc3b29f9af00159d56fcfb4f80f2fea7c4fb96f0a5966664a8931caa3c'
.expected_point_hex:
  db '262331267d5dc527a9b4225337671f75228e97ea7137ea78a3fa7314bd1cedae'
  db 'cd35a5325fb802543006d5891056c9bde2b3683a58c945ec80d74b180baf78ee'
.end: