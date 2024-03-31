if ~ definite bi_div_rem_256_128_guess

include 'bi_div_rem_guess_64.inc'

include '../add/bi_add_assign_192_192.inc'
include '../cmp/bi_cmp_128_128.inc'
include '../copy/bi_copy_256.inc'
include '../div_rem/bi_div_128_64.inc'
include '../div_rem/bi_div_rem_256_64.inc'
include '../extend_low/bi_extend_192_128.inc'
include '../inc/bi_inc_assign_192.inc'
include '../lzcnt/bi_lzcnt_256.inc'
include '../mul_low/bi_mul_low_256_128.inc'
include '../shl/bi_shl_256.inc'
include '../shl/bi_shl_assign_192.inc'
include '../shl/bi_shl_assign_256.inc'
include '../sub/bi_sub_assign_256_128.inc'
include '../sub/bi_sub_assign_256_256.inc'
include '../zero/bi_zero_256.inc'

bi_div_rem_256_128_guess:
    DivRemGuess64_Prepare 256, 128
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1
  .divisor_shifted rb __BIG_INTEGER_BYTES_128

  .remainder_lzcnt rq 1
  .remainder_shifted rb __BIG_INTEGER_BYTES_256

  .guess_128 rb __BIG_INTEGER_BYTES_128
  .delta rb __BIG_INTEGER_BYTES_256
  .guess_q rb __BIG_INTEGER_BYTES_256
  .correction rq 1
  label .locals_end
end virtual
        DivRemGuess64_Prolog 256, 128
        DivRemGuess64_DivisorLzcnt 256, 128

        mov     rcx, [.divisor]
        call    bi_lzcnt_128
        add     rax, 128
        mov     [.divisor_lzcnt], rax

        cmp     rax, 256 - 64
        jb      .divisor_large
        mov     rcx, [.dividend]
        mov     rdx, [.divisor]
        mov     rdx, [rdx + 0]
        mov     r8, [.quotient]
        mov     r9, [.remainder]
        call    bi_div_rem_256_64
        jmp     .end
.divisor_large:
        DivRemGuess64_PrepareLoop 256, 128
        DivRemGuess64_ShiftDivisor 256, 128
        DivRemGuess64_Loop 256, 128
.end:
        add     rsp, .locals_end - .locals_start
        ret
        DivRemGuess64_RecheckOnce 256, 128

end if