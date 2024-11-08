if ~ definite bi_rem_192_192

bi_rem_192_192:
    DivRemGuess64_Prepare 192, 192
virtual at rsp
  label .locals_start
  .delta BigInteger192
  .remainder_shifted BigInteger128
  .guess_128 BigInteger128
  .guess_192 BigInteger192
  .guess_q BigInteger192

  .dividend rq 1
  .divisor rq 1
  .remainder rq 1
  .correction rq 1

  .divisor_lzcnt rq 1

  .divisor_shifted rq 1

  AlignLocalsStackFrame

  label .locals_end
end virtual
        RemGuess64_Prolog 192, 192
        DivRemGuess64_DivisorLzcnt 192, 192
        RemGuess64_DivisorSwitch 192, 192

        RemGuess64_PrepareLoop 192, 192
        DivRemGuess64_ShiftDivisor 192, 192

        RemGuess64_Loop 192, 192
.end:
	DivRemGuess64_Epilog 192, 192
        RemGuess64_RecheckOnce 192, 192
        RemGuess64_RecheckMulti 192, 192

end if