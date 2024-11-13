__ec_projective_mont_point_256_from_affine_point_test:
virtual at rsp
.locals_start:
   .source_point ECAffinePoint256
   .result_point ECProjectiveMontgomeryPoint256
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__ec_projective_mont_point_256_from_affine_point_test'

        lea     rcx, [.source_point]
        lea     rdx, [.source_point_hex]
        mov     r8, secp256k1
        call    ec_affine_point_256_try_read_hex

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.result_point]
        lea     rdx, [.source_point]
        call    ec_projective_mont_point_256_from_affine_point
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [.expected_point_hex]
        lea     rdx, [.result_point]
        call    ec_projective_mont_point_256_assert_equal_hex

        add     rsp, .locals_end - .locals_start
        ret

align 16
.source_point_hex:
  db '262331267d5dc527a9b4225337671f75228e97ea7137ea78a3fa7314bd1cedae'
  db 'cd35a5325fb802543006d5891056c9bde2b3683a58c945ec80d74b180baf78ee'
.expected_point_hex:
  db '09ac590c1c918eb1dfde1f0b931da5f35369b032ba60497eb211521d47b7d446'
  db '897377937d47b8d45a6bb9d53deb55e8877a0c9958fb26b08e8abb02c273a45f'
  db '00000000000000000000000000000000000000000000000000000001000003d1'
.end: