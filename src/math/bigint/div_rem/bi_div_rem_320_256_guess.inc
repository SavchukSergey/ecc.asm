if ~ definite bi_div_rem_320_256_guess

;include 'macro/bi_div_rem_guess_64.inc'

include '../add/bi_add_assign_256_256.inc'
include '../add/bi_add_assign_320_256.inc'
include '../add/bi_add_assign_320_320.inc'
include '../add/bi_add_assign_320_256.inc'
include '../cmp/bi_cmp_320_256.inc'
include '../extend_low/index.inc'
include '../lzcnt/bi_lzcnt_256.inc'
include '../lzcnt/bi_lzcnt_320.inc'
include '../mul/bi_mul_256_64.inc'
include '../sub/bi_sub_assign_320_256.inc'
include '../sub/bi_sub_assign_320_320.inc'
include '../shl/index.inc'
include '../inc/index.inc'
include '../zero/bi_zero_320.inc'
include '../zero/bi_zero_320.inc'
include '../copy/bi_copy_320.inc'

include 'bi_div_rem_256_256.inc'
include 'bi_div_rem_320_192.inc'

bi_div_rem_320_256_guess:
    DivRemGuess64_FastSwitch 320, 256
    DivRemGuess64_Prepare 320, 256
virtual at rsp
  label .locals_start
  .delta BigInteger320
  .guess_q BigInteger320
  .remainder_shifted BigInteger128
  .guess_128 BigInteger256

  .divisor_shifted rq 1

  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1

  .correction rq 1
  label .locals_end
end virtual
	DivRemGuess64_Prolog 320, 256
	DivRemGuess64_DivisorLzcnt 320, 256

	DivRemGuess64_PrepareLoop 320, 256
	DivRemGuess64_ShiftDivisor 320, 256

	DivRemGuess64_Loop 320, 256

.end:
	DivRemGuess64_Epilog 320, 256
	DivRemGuess64_RecheckOnce 320, 256
	DivRemGuess64_RecheckMulti 320, 256

end if