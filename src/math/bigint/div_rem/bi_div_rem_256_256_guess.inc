if ~ definite bi_div_rem_256_256_guess

include 'bi_div_rem_guess_64.inc'

include '../copy/bi_copy_256.inc'
include '../cmp/bi_cmp_256_256.inc'
include '../div_rem/bi_div_128_64.inc'
include '../div_rem/bi_div_rem_256_128.inc'
include '../div_rem/bi_div_rem_256_64.inc'
include '../inc/bi_inc_assign_256.inc'
include '../lzcnt/bi_lzcnt_256.inc'
include '../mul_low/bi_mul_low_256_64.inc'
include '../mul_low/bi_mul_low_256_128.inc'
include '../shl/bi_shl_256.inc'
include '../shl/bi_shl_assign_256.inc'
include '../zero/bi_zero_256.inc'

bi_div_rem_256_256_guess:
    DivRemGuess64_Prepare 256, 256
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1
  .remainder_lzcnt rq 1
  
  .divisor_shifted rb __BIG_INTEGER_BYTES_256
  .remainder_shifted rb __BIG_INTEGER_BYTES_256

  .guess_128 rb __BIG_INTEGER_BYTES_128
  .delta rb __BIG_INTEGER_BYTES_256
  .correction rq 1
  AlignLocalsStackFrame
  label .locals_end
end virtual
        DivRemGuess64_Prolog 256, 256
        DivRemGuess64_DivisorLzcnt 256, 256
        DivRemGuess64_DivisorSwitch 256, 256
        DivRemGuess64_PrepareLoop 256, 256
        DivRemGuess64_ShiftDivisor 256, 256

        DivRemGuess64_Loop 256, 256

.end:
        add     rsp, .locals_end - .locals_start
        ret
        DivRemGuess64_RecheckOnce 256, 256

end if