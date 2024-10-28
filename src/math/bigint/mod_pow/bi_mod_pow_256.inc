if ~ definite bi_mod_pow_256

include '../one/bi_one_256.inc'
include '../copy/bi_copy_256.inc'
include '../bit_check/bi_bit_check_256.inc'

bi_mod_pow_256:
virtual at rsp
  label .locals_start
    .acc BigInteger256
    .temp BigInteger256
    .value rq 1
    .exponent rq 1
    .modulus rq 1
    .result rq 1
    .bit rq 1
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start
        mov     [.value], rcx
        mov     [.exponent], rdx
        mov     [.modulus], r8
        mov     [.result], r9

        mov     rcx, [.result]
        call    bi_one_256

        lea     rcx, [.acc]
        mov     rdx, [.value]
        call    bi_copy_256

        mov     [.bit], 0
.loop:
        mov     rcx, [.exponent]
        mov     rdx, [.bit]
        call    bi_bit_check_256
        test    rax, rax
        jz      .zero_bit

        mov     rcx, [.result]
        lea     rdx, [.acc]
        mov     r8, [.modulus]
        lea     r9, [.temp]
        call    bi_mod_mul_256_256

        mov     rcx, [.result]
        lea     rdx, [.temp]
        call    bi_copy_256
 .zero_bit:
        lea     rcx, [.acc]
        mov     rdx, [.modulus]
        lea     r8, [.temp]
        call    bi_mod_square_256

        lea     rcx, [.acc]
        lea     rdx, [.temp]
        call    bi_copy_256

        inc     [.bit]
        cmp     [.bit], 256
        jb      .loop

        add     rsp, .locals_end - .locals_start
        ret

end if