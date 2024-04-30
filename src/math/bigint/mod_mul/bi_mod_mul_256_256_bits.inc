if ~ definite bi_mod_mul_256_256_bits

include '../zero/bi_zero_256.inc'
include '../copy/bi_copy_256.inc'
include '../bit_check/bi_bit_check_256.inc'
include '../mod_add/bi_mod_add_assign_256_256.inc'
include '../mod_add/bi_mod_double_assign_256.inc'

bi_mod_mul_256_256_bits:
virtual at rsp
  label .locals_start
    .left rq 1
    .right rq 1
    .modulus rq 1
    .result rq 1
    BigInteger256 .acc
    .bit rq 1
    AlignLocalsStackFrame
    label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'bi_mod_mul_256_256_bits'
    CheckRegAligned rcx, 'bi_mod_mul_256_256_bits rcx'
    CheckRegAligned rdx, 'bi_mod_mul_256_256_bits rdx'
    CheckRegAligned r8, 'bi_mod_mul_256_256_bits r8'

        mov     [.left], rcx
        mov     [.right], rdx
        mov     [.modulus], r8
        mov     [.result], r9

        mov     rcx, [.result]
        call    bi_zero_256

        lea     rcx, [.acc]
        mov     rdx, [.left]
        call    bi_copy_256

        mov     [.bit], 0
.loop:
        mov     rcx, [.right]
        mov     rdx, [.bit]
        call    bi_bit_check_256
        test    rax, rax
        jz      .zero_bit

        mov     rcx, [.result]
        lea     rdx, [.acc]
        mov     r8, [.modulus]
        call    bi_mod_add_assign_256_256
.zero_bit:
        lea     rcx, [.acc]
        mov     rdx, [.modulus]
        call    bi_mod_double_assign_256

        inc     [.bit]
        cmp     [.bit], 256
        jb      .loop

        add     rsp, .locals_end - .locals_start
        ret

end if