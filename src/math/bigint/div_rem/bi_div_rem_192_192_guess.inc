if ~ definite bi_div_rem_192_192_guess

bi_div_rem_192_192_guess:
    DivRemGuess64_FastSwitch 192, 192
    DivRemGuess64_Prepare 192, 192
virtual at rsp
  label .locals_start
  .delta BigInteger192
  .remainder_shifted BigInteger128
  .guess_128 BigInteger128

  .divisor_shifted rq 1
  
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1
  
  .correction rq 1
  AlignLocalsStackFrame
  label .locals_end
end virtual
	DivRemGuess64_Prolog 192, 192
	DivRemGuess64_DivisorLzcnt 192, 192
	DivRemGuess64_PrepareLoop 192, 192
	DivRemGuess64_ShiftDivisor 192, 192

	DivRemGuess64_Loop 192, 192

.end:
	DivRemGuess64_Epilog 192, 192
	DivRemGuess64_RecheckOnce 192, 192
	DivRemGuess64_RecheckMulti 192, 192

end if