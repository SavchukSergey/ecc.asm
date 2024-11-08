if ~ definite bi_div_rem_320_256_guess

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