if ~ definite bi_div_rem_384_192_guess

bi_div_rem_384_192_guess:
    DivRemGuess64_FastSwitch 384, 192
    DivRemGuess64_Prepare 384, 192
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
	DivRemGuess64_Prolog 384, 192
	DivRemGuess64_DivisorLzcnt 384, 192

	DivRemGuess64_PrepareLoop 384, 192
	DivRemGuess64_ShiftDivisor 384, 192

	DivRemGuess64_Loop 384, 192

.end:
	DivRemGuess64_Epilog 384, 192
	DivRemGuess64_RecheckOnce 384, 192
	DivRemGuess64_RecheckMulti 384, 192

end if