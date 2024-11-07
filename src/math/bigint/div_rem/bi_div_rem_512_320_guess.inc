if ~ definite bi_div_rem_512_320_guess

include 'macro/bi_div_rem_guess_64.inc'

include '../add/index.inc'
include '../cmp/index.inc'

include 'bi_div_rem_448_320.inc'
include 'bi_div_rem_512_256.inc'

bi_div_rem_512_320_guess:
    DivRemGuess64_FastSwitch 512, 320
    DivRemGuess64_Prepare 512, 320
virtual at rsp
  label .locals_start
  .delta BigInteger512
  .guess_q BigInteger512
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
	DivRemGuess64_Prolog 512, 320
	DivRemGuess64_DivisorLzcnt 512, 320

	DivRemGuess64_PrepareLoop 512, 320
	DivRemGuess64_ShiftDivisor 512, 320

	DivRemGuess64_Loop 512, 320
.end:
	DivRemGuess64_Epilog 512, 320
	DivRemGuess64_RecheckOnce 512, 320
	DivRemGuess64_RecheckMulti 512, 320

end if