__ec_projective_mont_point_256_shl_test:
virtual at rsp
.locals_start:
  .source ECProjectiveMontgomeryPoint256
  .target ECProjectiveMontgomeryPoint256
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
        
        mov     rbx,  __ec_projective_mont_point_256_shl_test_cases
.loop:

        lea     rcx, [.source]
        lea     rdx, [rbx]
        mov     r8, secp256k1
        call    ec_projective_mont_point_256_try_read_hex

        call    test_context_start_measure
    .chunk_loop:
        lea     rcx, [.source]
        mov     rdx, [rbx + __EC_PROJECTIVE_MONT_POINT_256_HEX_DIGITS]
        lea     r8, [.target]
        call    ec_projective_mont_point_256_shl
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [rbx + __EC_PROJECTIVE_MONT_POINT_256_HEX_DIGITS + 8]
        lea     rdx, [.target]
        call    ec_projective_mont_point_256_assert_equal_hex

        add     rbx, __EC_PROJECTIVE_MONT_POINT_256_HEX_DIGITS * 2 + 8
        cmp     rbx, __ec_projective_mont_point_256_shl_test_cases.end
        jb      .loop

        add     rsp, .locals_end - .locals_start
        ret

align 16
__ec_projective_mont_point_256_shl_test_cases:
  db '96e6b51d86cc74119556e2dad4965d5f385b8f72ab12613a2d7f3bcf74a81385'
  db '6bc8994d2ff8b18e145821876517018ba9b7c533b221e9dfb639e5bfd55abdc4'
  db '6e2c90fc3b29f9af00159d56fcfb4f80f2fea7c4fb96f0a5966664a8931caa3c'
  dq 0
  db '96e6b51d86cc74119556e2dad4965d5f385b8f72ab12613a2d7f3bcf74a81385'
  db '6bc8994d2ff8b18e145821876517018ba9b7c533b221e9dfb639e5bfd55abdc4'
  db '6e2c90fc3b29f9af00159d56fcfb4f80f2fea7c4fb96f0a5966664a8931caa3c'

  db '96e6b51d86cc74119556e2dad4965d5f385b8f72ab12613a2d7f3bcf74a81385'
  db '6bc8994d2ff8b18e145821876517018ba9b7c533b221e9dfb639e5bfd55abdc4'
  db '6e2c90fc3b29f9af00159d56fcfb4f80f2fea7c4fb96f0a5966664a8931caa3c'
  dq 1
  db '0a84e433b730c6c2ab51c57861d3cc139b407e2f1e731d307e374b81e3e77cda'
  db '441431e24f66fa8af308d4714505b1a0883295db56683c5fb9c8c42ed8080ad1'
  db '5bbd52d7b5b0c5a0a05cb84d4253dc0cc1cde790951ee186504e327ef4c674ce'

  db '96e6b51d86cc74119556e2dad4965d5f385b8f72ab12613a2d7f3bcf74a81385'
  db '6bc8994d2ff8b18e145821876517018ba9b7c533b221e9dfb639e5bfd55abdc4'
  db '6e2c90fc3b29f9af00159d56fcfb4f80f2fea7c4fb96f0a5966664a8931caa3c'
  dq 2
  db '4403a906f093d8089297610822ec2f0953eafed2d1ae218300054a99c2b12b65'
  db '877ee5a8225b4b6be3d380325734f4ee6d88564ffb9c9f26383ff3178b8b1531'
  db 'bb7015dcf9a2386ebb63b84a21ba3a8864d1df6045b71e6fc769306536ac50b7'

.end: