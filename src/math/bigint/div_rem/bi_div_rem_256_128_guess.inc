if ~ definite bi_div_rem_256_128_guess

include 'macro/bi_div_rem_guess_64.inc'

include '../add/bi_add_assign_192_192.inc'
include '../cmp/bi_cmp_128_128.inc'
include '../copy/bi_copy_256.inc'
include '../div_rem/bi_div_128_64.inc'
include '../div_rem/bi_div_rem_256_64.inc'
include '../extend_low/bi_extend_assign_192_64.inc'
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
  BigInteger256 .delta

  .guess_64:
  .guess_128:
  BigInteger256 .guess

  BigInteger128 .remainder_shifted

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
	DivRemGuess64_Prolog 256, 128
	DivRemGuess64_DivisorLzcnt 256, 128
	DivRemGuess64_DivisorSwitch 256, 128

	DivRemGuess64_PrepareLoop 256, 128
	DivRemGuess64_ShiftDivisor 256, 128
	DivRemGuess64_Loop 256, 128
.end:
	add	rsp, .locals_end - .locals_start
	ret
	DivRemGuess64_RecheckOnce 256, 128

end if