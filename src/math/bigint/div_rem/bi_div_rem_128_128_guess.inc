if ~ definite bi_div_rem_128_128_guess

include 'macro/bi_div_rem_guess_64.inc'

include '../copy/bi_copy_128.inc'
include '../cmp/bi_cmp_128_128.inc'
include '../div_rem/bi_div_128_64.inc'
include '../inc/bi_inc_assign_128.inc'
include '../lzcnt/bi_lzcnt_128.inc'
include '../mul_low/bi_mul_low_128_64.inc'
include '../shl/bi_shl_128.inc'
include '../shl/bi_shl_assign_128.inc'
include '../sub/bi_sub_assign_128_128.inc'
include '../zero/bi_zero_128.inc'

bi_div_rem_128_128_guess:
    DivRemGuess64_Prepare 128, 128
virtual at rsp
  label .locals_start
  BigInteger128 .remainder_shifted
  BigInteger128 .guess_128
  BigInteger128 .delta

  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1
  .remainder_lzcnt rq 1

  .divisor_shifted rq 1

  .correction rq 1
  AlignLocalsStackFrame
  label .locals_end
end virtual
	DivRemGuess64_Prolog 128, 128
	DivRemGuess64_DivisorLzcnt 128, 128
	DivRemGuess64_DivisorSwitch 128, 128
	DivRemGuess64_PrepareLoop 128, 128
	DivRemGuess64_ShiftDivisor 128, 128
	DivRemGuess64_Loop 128, 128
.end:
	DivRemGuess64_Epilog 128, 128

	DivRemGuess64_RecheckOnce 128, 128

end if