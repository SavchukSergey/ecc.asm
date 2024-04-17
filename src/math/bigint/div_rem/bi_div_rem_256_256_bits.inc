if ~ definite bi_div_rem_256_256_bits

include '../bit_set/bi_bit_set_256.inc'
include '../cmp/bi_cmp_256_256.inc'
include '../copy/bi_copy_256.inc'
include '../extend_low/bi_extend_512_256.inc'
include '../shl/bi_shl_assign_512_1.inc'
include '../sub/bi_sub_assign_256_256.inc'
include '../zero/bi_zero_256.inc'

bi_div_rem_256_256_bits:
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1
  BigInteger256 .divisor_shifted

  .divisor_lzcnt rq 1
  .remainder_lzcnt rq 1
  .bit rq 1
  .total_shift rq 1

  AlignLocalsStackFrame
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start

        PrologCheckStackAligned 'bi_div_rem_256_256_bits'
        CheckRegAligned rcx, 'bi_div_rem_256_256_bits rcx'
        CheckRegAligned rdx, 'bi_div_rem_256_256_bits rdx'
        CheckRegAligned r8, 'bi_div_rem_256_256_bits r8'
        CheckRegAligned r9, 'bi_div_rem_256_256_bits r9'

        mov     [.dividend], rcx
        mov     [.divisor], rdx
        mov     [.quotient], r8
        mov     [.remainder], r9

        mov     rcx, [.divisor]
        call    bi_lzcnt_256
        mov     [.divisor_lzcnt], rax

        mov     rcx, [.divisor]
        lea     rdx, [.divisor_shifted]
        mov     r8, [.divisor_lzcnt]
        call    bi_shl_256

        mov     rcx, [.quotient]
        call    bi_zero_256

        mov     rcx, [.remainder]
        mov     rdx, [.dividend]
        call    bi_copy_256

        mov     rax, [.divisor_lzcnt]
        mov     [.bit], rax

        mov     [.total_shift], 0
.loop:
        mov     rcx, [.remainder]
        call    bi_lzcnt_256
        mov     [.remainder_lzcnt], rax

        sub     [.bit], rax
        jc      .loop_end

        mov     rcx, [.remainder]
        mov     rdx, [.remainder_lzcnt]
        call    bi_shl_assign_256

        mov     rax, [.remainder_lzcnt]
        add     [.total_shift], rax

        mov     rcx, [.remainder]
        lea     rdx, [.divisor_shifted]
        call    bi_cmp_256_256
        jb      .bit_zero
.bit_one:
        mov     rcx, [.remainder]
        lea     rdx, [.divisor_shifted]
        call    bi_sub_assign_256_256

        mov     rcx, [.quotient]
        mov     rdx, [.bit]
        call    bi_bit_set_256
        
        jmp     .loop
.bit_zero:
        sub     [.bit], 1
        jc      .loop_end

 ;next shift guaranteed to be successful
        mov     rcx, [.remainder]
        call    bi_shl_assign_256_1 ; overflow to 257 bit but it does not matter

        inc     [.total_shift]

        mov     rcx, [.remainder]
        lea     rdx, [.divisor_shifted]
        call    bi_sub_assign_256_256

        mov     rcx, [.quotient]
        mov     rdx, [.bit]
        call    bi_bit_set_256

        jmp     .loop
.loop_end:

        mov     rcx, [.remainder]
        mov     rdx, [.total_shift]
        call    bi_shr_assign_256

        add     rsp, .locals_end - .locals_start
        ret

end if