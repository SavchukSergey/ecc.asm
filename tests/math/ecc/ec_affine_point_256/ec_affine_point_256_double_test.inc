__ec_affine_point_256_double_test:
virtual at rsp
.locals_start:
  .source ECAffinePoint256
  .target ECAffinePoint256
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
        call    ec_affine_point_256_double
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
  db '262331267d5dc527a9b4225337671f75228e97ea7137ea78a3fa7314bd1cedae'
  db 'cd35a5325fb802543006d5891056c9bde2b3683a58c945ec80d74b180baf78ee'

.expected_hex:
  db 'e456fcc29e11d05faf31c251089b9a6c09ab1d82aec8672bba416e1cd45d055e'
  db 'f5c02e7c505d6051c94f3ab38bf8a2b8039ec5931e7f7cb3924d7dac1be353e6'