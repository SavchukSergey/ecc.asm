__ec_affine_point_256_shl_test:
virtual at rsp
.locals_start:
  .source ECAffinePoint256
  .target ECAffinePoint256
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
        
        mov     rbx,  __ec_affine_point_256_shl_test_cases
.loop:

        lea     rcx, [.source]
        lea     rdx, [rbx]
        mov     r8, secp256k1
        call    ec_affine_point_256_try_read_hex

        call    test_context_start_measure
    .chunk_loop:
        lea     rcx, [.source]
        mov     rdx, [rbx + __EC_AFFINE_POINT_256_HEX_DIGITS]
        lea     r8, [.target]
        call    ec_affine_point_256_shl
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [rbx + __EC_AFFINE_POINT_256_HEX_DIGITS + 8]
        lea     rdx, [.target]
        call    ec_affine_point_256_assert_equal_hex

        add     rbx, __EC_AFFINE_POINT_256_HEX_DIGITS * 2 + 8
        cmp     rbx, __ec_affine_point_256_shl_test_cases.end
        jb      .loop

        add     rsp, .locals_end - .locals_start
        ret

align 16
__ec_affine_point_256_shl_test_cases:
  db '262331267d5dc527a9b4225337671f75228e97ea7137ea78a3fa7314bd1cedae'
  db 'cd35a5325fb802543006d5891056c9bde2b3683a58c945ec80d74b180baf78ee'
  dq 0
  db '262331267d5dc527a9b4225337671f75228e97ea7137ea78a3fa7314bd1cedae'
  db 'cd35a5325fb802543006d5891056c9bde2b3683a58c945ec80d74b180baf78ee'

  db '262331267d5dc527a9b4225337671f75228e97ea7137ea78a3fa7314bd1cedae'
  db 'cd35a5325fb802543006d5891056c9bde2b3683a58c945ec80d74b180baf78ee'
  dq 1
  db 'e456fcc29e11d05faf31c251089b9a6c09ab1d82aec8672bba416e1cd45d055e'
  db 'f5c02e7c505d6051c94f3ab38bf8a2b8039ec5931e7f7cb3924d7dac1be353e6'

  db '262331267d5dc527a9b4225337671f75228e97ea7137ea78a3fa7314bd1cedae'
  db 'cd35a5325fb802543006d5891056c9bde2b3683a58c945ec80d74b180baf78ee'
  dq 2
  db '33513202c960d2cbb194e4ab5c42dce572153cda471a1de67c48e14b82817e21'
  db '40eadf05d67d14771058661230346b5c3ec2f11d3e8eb67a55a9b4317e5b72fd'

.end: