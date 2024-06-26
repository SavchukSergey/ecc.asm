if ~ definite bi_div_rem_512_128_guess

include 'macro/bi_div_rem_guess_64.inc'

include '../add/bi_add_assign_448_448.inc'
include '../add/bi_add_assign_512_512.inc'
include '../cmp/bi_cmp_512_128.inc'
include '../copy/bi_copy_512.inc'
include '../div_rem/bi_div_128_64.inc'
include '../div_rem/bi_div_rem_512_64.inc'
include '../extend_low/bi_extend_448_128.inc'
include '../inc/bi_inc_assign_448.inc'
include '../lzcnt/bi_lzcnt_128.inc'
include '../lzcnt/bi_lzcnt_512.inc'
include '../shl/bi_shl_128.inc'
include '../shl/bi_shl_512.inc'
include '../shl/bi_shl_assign_512.inc'
include '../shr/bi_shr_assign_128.inc'
include '../sub/bi_sub_assign_512_128.inc'
include '../sub/bi_sub_assign_512_512.inc'
include '../zero/bi_zero_512.inc'

bi_div_rem_512_128_guess:
    DivRemGuess64_Prepare 512, 128
virtual at rsp
  label .locals_start
  BigInteger512 .delta
  BigInteger512 .guess_q
  BigInteger128 .remainder_shifted
  BigInteger128 .guess_128

  .divisor_shifted rq 1

  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1

  .correction rq 1
  label .locals_end
end virtual
	DivRemGuess64_Prolog 512, 128
	DivRemGuess64_DivisorLzcnt 512, 128
	DivRemGuess64_DivisorSwitch 512, 128

	DivRemGuess64_PrepareLoop 512, 128
	DivRemGuess64_ShiftDivisor 512, 128

	DivRemGuess64_Loop 512, 128

.end:
	DivRemGuess64_Epilog 512, 128
	DivRemGuess64_RecheckOnce 512, 128
	DivRemGuess64_RecheckMulti 512, 128

end if