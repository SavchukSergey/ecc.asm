if ~ definite bi_mont_ctx_256_pow

include '../copy/bi_copy_256.inc'
include '../bit_check/bi_bit_check_256.inc'

bi_mont_ctx_256_pow:
virtual at rsp
  label .locals_start
    .acc_mont BigInteger256
    .temp BigInteger256
    .value_mont rq 1
    .exponent rq 1
    .ctx rq 1
    .result_mont rq 1
    .bit rq 1
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start
        mov     [.value_mont], rcx
        mov     [.exponent], rdx
        mov     [.ctx], r8
        mov     [.result_mont], r9

        mov     rcx, [.result_mont]
        mov     rdx, [.ctx]
        lea     rdx, [rdx + MontgomeryContext256.rm]
        call    bi_copy_256

        lea     rcx, [.acc_mont]
        mov     rdx, [.value_mont]
        call    bi_copy_256

        mov     [.bit], 0
.loop:
        mov     rcx, [.exponent]
        mov     rdx, [.bit]
        call    bi_bit_check_256
        test    rax, rax
        jz      .zero_bit

        mov     rcx, [.result_mont]
        lea     rdx, [.acc_mont]
        mov     r8, [.ctx]
        lea     r9, [.temp]
        call    bi_mont_ctx_256_mul

        mov     rcx, [.result_mont]
        lea     rdx, [.temp]
        call    bi_copy_256
 .zero_bit:
        lea     rcx, [.acc_mont]
        mov     rdx, [.ctx]
        lea     r8, [.temp]
        call    bi_mont_ctx_256_square

        lea     rcx, [.acc_mont]
        lea     rdx, [.temp]
        call    bi_copy_256

        inc     [.bit]
        cmp     [.bit], 256
        jb      .loop

        add     rsp, .locals_end - .locals_start
        ret

end if