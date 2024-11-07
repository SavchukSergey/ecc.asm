if ~ definite bi_div_rem_384_256_guess

;include 'macro/bi_div_rem_guess_64.inc'

include '../add/bi_add_assign_256_256.inc'
include '../add/bi_add_assign_384_256.inc'
include '../add/bi_add_assign_384_384.inc'
include '../cmp/bi_cmp_384_256.inc'
include '../extend_low/index.inc'
include '../lzcnt/bi_lzcnt_256.inc'
include '../mul/bi_mul_256_64.inc'
include '../sub/bi_sub_assign_384_256.inc'
include '../shl/index.inc'
include '../inc/index.inc'
include '../zero/bi_zero_320.inc'

include 'bi_div_rem_320_256.inc'
include 'bi_div_rem_384_192.inc'

bi_div_rem_384_256_guess:
    DivRemGuess64_FastSwitch 384, 256
    DivRemGuess64_Prepare 384, 256
virtual at rsp
  label .locals_start
  .delta BigInteger384
  .guess_q BigInteger384
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
	DivRemGuess64_Prolog 384, 256
	DivRemGuess64_DivisorLzcnt 384, 256

	DivRemGuess64_PrepareLoop 384, 256
	DivRemGuess64_ShiftDivisor 384, 256

	DivRemGuess64_Loop 384, 256

.end:
	DivRemGuess64_Epilog 384, 256
	DivRemGuess64_RecheckOnce 384, 256
	DivRemGuess64_RecheckMulti 384, 256

end if