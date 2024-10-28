if ~ definite bi_div_rem_256_256_full_bits

include '../bit_set/bi_bit_set_256.inc'
include '../cmp/bi_cmp_256_256.inc'
include '../copy/bi_copy_256.inc'
include '../extend_low/bi_extend_512_256.inc'
include '../shl/bi_shl_assign_512_1.inc'
include '../sub/bi_sub_assign_256_256.inc'
include '../zero/bi_zero_256.inc'

bi_div_rem_256_256_full_bits:
virtual at rsp
  label .locals_start
  .value BigInteger512
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1
  .bit rq 1
  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        PrologCheckStackAligned 'bi_div_rem_256_256_full_bits'
        CheckRegAligned rcx, 'bi_div_rem_256_256_full_bits rcx'
        CheckRegAligned rdx, 'bi_div_rem_256_256_full_bits rdx'
        CheckRegAligned r8, 'bi_div_rem_256_256_full_bits r8'
        CheckRegAligned r9, 'bi_div_rem_256_256_full_bits r9'

        mov     [.dividend], rcx
        mov     [.divisor], rdx
        mov     [.quotient], r8
        mov     [.remainder], r9

        lea     rcx, [.value]
        mov     rdx, [.dividend]
        call    bi_extend_512_256

        mov     rcx, [.quotient]
        call    bi_zero_256

        mov     [.bit], 255

.loop:
        ;todo: shift just 256-bit value with carry like as "rol" opcode where carry is read from dividend
        lea     rcx, [.value]
        call    bi_shl_assign_512_1

        lea     rcx, [.value + 32]
        mov     rdx, [.divisor]
        call    bi_cmp_256_256
        cmp     al, -1
        je      .below
        lea     rcx, [.value + 32]
        mov     rdx, [.divisor]
        call    bi_sub_assign_256_256

        mov     rcx, [.quotient]
        mov     rdx, [.bit]
        call    bi_bit_set_256
.below:
        sub     [.bit], 1
        jnc     .loop

        mov     rcx, [.remainder]
        lea     rdx, [.value + 32]
        call    bi_copy_256

        add     rsp, .locals_end - .locals_start
        ret

end if