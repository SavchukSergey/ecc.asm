if ~ definite bi_div_rem_384_320_guess

include 'macro/bi_div_rem_guess_64.inc'

include '../cmp/index.inc'
include '../sub/index.inc'

include 'bi_div_rem_320_320.inc'
include 'bi_div_rem_384_256.inc'

bi_div_rem_384_320_guess:
    DivRemGuess64_FastSwitch 384, 320
    DivRemGuess64_Prepare 384, 320
virtual at rsp
  label .locals_start
  .delta BigInteger384
  .guess_q BigInteger384
  .remainder_shifted BigInteger128
  .guess_128 BigInteger128

  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1

  .divisor_shifted rq 1

  .correction rq 1
  label .locals_end
end virtual
	DivRemGuess64_Prolog 384, 320
	DivRemGuess64_DivisorLzcnt 384, 320

	DivRemGuess64_PrepareLoop 384, 320
	DivRemGuess64_ShiftDivisor 384, 320

	DivRemGuess64_Loop 384, 320
.end:
	DivRemGuess64_Epilog 384, 320
	DivRemGuess64_RecheckOnce 384, 320
	DivRemGuess64_RecheckMulti 384, 320

end if