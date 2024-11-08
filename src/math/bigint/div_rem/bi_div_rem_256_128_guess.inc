if ~ definite bi_div_rem_256_128_guess

bi_div_rem_256_128_guess:
    DivRemGuess64_FastSwitch 256, 128
    DivRemGuess64_Prepare 256, 128
virtual at rsp
  label .locals_start
  .delta BigInteger256 
  .guess_q BigInteger256
  .remainder_shifted BigInteger128 
  .guess_128 BigInteger128

  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1

  .divisor_shifted rq 1

  .correction rq 1
  AlignLocalsStackFrame
  label .locals_end
end virtual
	DivRemGuess64_Prolog 256, 128
	DivRemGuess64_DivisorLzcnt 256, 128

	DivRemGuess64_PrepareLoop 256, 128
	DivRemGuess64_ShiftDivisor 256, 128
	DivRemGuess64_Loop 256, 128
.end:
	DivRemGuess64_Epilog 256, 128
	DivRemGuess64_RecheckOnce 256, 128
	DivRemGuess64_RecheckMulti 256, 128

end if