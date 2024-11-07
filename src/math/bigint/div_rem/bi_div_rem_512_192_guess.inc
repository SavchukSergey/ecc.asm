if ~ definite bi_div_rem_512_192_guess

;include 'macro/bi_div_rem_guess_64.inc'

include '../add/bi_add_assign_256_192.inc'
include '../add/bi_add_assign_448_192.inc'
include '../add/bi_add_assign_448_448.inc'
include '../cmp/bi_cmp_512_192.inc'
include '../extend_low/index.inc'
include '../lzcnt/bi_lzcnt_192.inc'
include '../mul/bi_mul_192_64.inc'
include '../sub/bi_sub_assign_512_192.inc'
include '../shl/index.inc'
include '../inc/index.inc'
include '../zero/bi_zero_320.inc'

bi_div_rem_512_192_guess:
    DivRemGuess64_FastSwitch 512, 192
    DivRemGuess64_Prepare 512, 192
virtual at rsp
  label .locals_start
  .delta BigInteger512
  .guess_q BigInteger512
  .remainder_shifted BigInteger128
  .guess_128 BigInteger128

  .divisor_shifted rq 1

  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1

  .correction rq 1
  label .locals_end
end virtual
	DivRemGuess64_Prolog 512, 192
	DivRemGuess64_DivisorLzcnt 512, 192

	DivRemGuess64_PrepareLoop 512, 192
	DivRemGuess64_ShiftDivisor 512, 192

	DivRemGuess64_Loop 512, 192

.end:
	DivRemGuess64_Epilog 512, 192
	DivRemGuess64_RecheckOnce 512, 192
	DivRemGuess64_RecheckMulti 512, 192

end if