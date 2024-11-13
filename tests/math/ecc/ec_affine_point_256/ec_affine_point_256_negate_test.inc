__ec_affine_point_256_negate_test:
virtual at rsp
.locals_start:
  .source ECAffinePoint256
  .target ECAffinePoint256
  AlignLocalsStackFrame
.locals_end:
end virtual
    sub     rsp, .locals_end - .locals_start

    lea     rcx, [.source]
    lea     rdx, [.source_hex]
    mov     r8, secp256k1
    call    ec_affine_point_256_try_read_hex

    call    test_context_start_measure
.chunk_loop:
    lea     rcx, [.source]
    lea     rdx, [.target]
    call    ec_affine_point_256_negate
    call    test_context_measure_dec_chunk
    jnz     .chunk_loop
    call    test_context_end_measure

    lea     rcx, [.expected_hex]
    lea     rdx, [.target]
    call    ec_affine_point_256_assert_equal_hex

    add     rsp, .locals_end - .locals_start
    ret

align 16
.source_hex:
  db '575611bf4bbc952c0d5b9c3b87147d1ce3381e34f688e2a2d9844761b0dc36c2'
  db 'ca55bd03a22ed3bd3d36ff4c6dc09aa768984a3f32c662640a38af949a384810'

.expected_hex:
  db '575611bf4bbc952c0d5b9c3b87147d1ce3381e34f688e2a2d9844761b0dc36c2'
  db '35aa42fc5dd12c42c2c900b3923f65589767b5c0cd399d9bf5c7506a65c7b41f'