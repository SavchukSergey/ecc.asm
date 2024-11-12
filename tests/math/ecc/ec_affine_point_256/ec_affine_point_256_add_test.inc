__ec_affine_point_256_add_test:
virtual at rsp
.locals_start:
   .left ECAffinePoint256
   .right ECAffinePoint256
   .result ECAffinePoint256
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned '__secp256k1_point_add_test'

        mov     rbx,  __ec_affine_point_256_add_test_cases
.loop:
        lea     rcx, [.left]
        lea     rdx, [rbx + 0]
        mov     r8, secp256k1
        call    ec_affine_point_256_try_read_hex

        lea     rcx, [.right]
        lea     rdx, [rbx + 128]
        mov     r8, secp256k1
        call    ec_affine_point_256_try_read_hex

        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
        lea     rdx, [.right]
        lea     r8, [.result]
        call    ec_affine_point_256_add
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        lea     rcx, [rbx + 256]
        lea     rdx, [.result]
        call    ec_affine_point_256_assert_equal_hex

        add     rbx, (__BIG_INTEGER_BYTES_256 * 2) * 2 * 3
        cmp     rbx, __ec_affine_point_256_add_test_cases.end
        jb      .loop

        add     rsp, .locals_end - .locals_start
        ret

;todo: test double point
align 16
__ec_affine_point_256_add_test_cases:
  db '575611bf4bbc952c0d5b9c3b87147d1ce3381e34f688e2a2d9844761b0dc36c2'
  db 'ca55bd03a22ed3bd3d36ff4c6dc09aa768984a3f32c662640a38af949a384810'

  db '88c31a9570e5c79c04a47475309e3ac0ebacf211301d21cec62e7ffd3d129e6d'
  db '342ff1479400c52e08d5eb7c05bdcce3e3c823c387e8c0d7915c3912d356a2ac'

  db 'eda473c95637483eb6a5ed9b105423b57fa1ba8b445e9d38068fafaa8bad4c81'
  db 'b2610880d4374d0ae8f18d33ad776c55c8d217f44b1d6eb846ccced7d1ec7420'

.end: