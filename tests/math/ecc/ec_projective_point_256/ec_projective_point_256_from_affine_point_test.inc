__ec_projective_point_256_from_affine_point_test:
virtual at rsp
.locals_start:
   .source_point ECAffinePoint256
   .result_point ECProjectivePoint256
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__ec_projective_point_256_from_affine_point_test'

        lea     rcx, [.source_point]
        lea     rdx, [.source_point_hex]
        call    ec_affine_point_256_try_read_hex

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.result_point]
        lea     rdx, [.source_point]
        call    ec_projective_point_256_from_affine_point
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [.expected_point_hex]
        lea     rdx, [.result_point]
        call    ec_projective_point_256_assert_equal_hex

        add     rsp, .locals_end - .locals_start
        ret

align 16
.source_point_hex:
  db '575611bf4bbc952c0d5b9c3b87147d1ce3381e34f688e2a2d9844761b0dc36c2'
  db 'ca55bd03a22ed3bd3d36ff4c6dc09aa768984a3f32c662640a38af949a384810'
.expected_point_hex:
  db '575611bf4bbc952c0d5b9c3b87147d1ce3381e34f688e2a2d9844761b0dc36c2'
  db 'ca55bd03a22ed3bd3d36ff4c6dc09aa768984a3f32c662640a38af949a384810'
  db '0000000000000000000000000000000000000000000000000000000000000001'
.end: