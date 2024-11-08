if ~ definite bi_div_rem_512_128_guess

bi_div_rem_512_128_guess:
    DivRemGuess64_FastSwitch 512, 128
    DivRemGuess64_Prepare 512, 128
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
	DivRemGuess64_Prolog 512, 128
	DivRemGuess64_DivisorLzcnt 512, 128

	DivRemGuess64_PrepareLoop 512, 128
	DivRemGuess64_ShiftDivisor 512, 128

	DivRemGuess64_Loop 512, 128

.end:
	DivRemGuess64_Epilog 512, 128
	DivRemGuess64_RecheckOnce 512, 128
	DivRemGuess64_RecheckMulti 512, 128

end if