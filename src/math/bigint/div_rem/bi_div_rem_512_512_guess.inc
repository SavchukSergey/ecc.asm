if ~ definite bi_div_rem_512_512_guess

include 'macro/bi_div_rem_guess_64.inc'

include '../extend_low/bi_extend_256_128.inc'
include '../div_rem/bi_div_rem_512_128.inc'
include '../div_rem/bi_div_rem_512_256.inc'

bi_div_rem_512_512_guess:
    DivRemGuess64_Prepare 512, 512
virtual at rsp
  label .locals_start
  BigInteger512 .delta
  BigInteger256 .guess_q
  BigInteger128 .remainder_shifted
  BigInteger128 .guess_128

  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1
  .remainder_lzcnt rq 1

  .divisor_shifted rq 1

  .correction rq 1
  label .locals_end
end virtual
	DivRemGuess64_Prolog 512, 512
	DivRemGuess64_DivisorLzcnt 512, 512
	DivRemGuess64_DivisorSwitch 512, 512

	DivRemGuess64_PrepareLoop 512, 512
	DivRemGuess64_ShiftDivisor 512, 512

	DivRemGuess64_Loop 512, 512
.end:
	add	rsp, .locals_end - .locals_start
	ret
	DivRemGuess64_RecheckOnce 512, 512

end if