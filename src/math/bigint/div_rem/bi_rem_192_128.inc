if ~ definite bi_rem_192_128

bi_rem_192_128:
    DivRemGuess64_Prepare 192, 128
virtual at rsp
  label .locals_start
  .delta BigInteger192
  .remainder_shifted BigInteger128
  .guess_128 BigInteger128

  .dividend rq 1
  .divisor rq 1
  .remainder rq 1
  .correction rq 1

  .divisor_lzcnt rq 1

  .divisor_shifted rq 1

  AlignLocalsStackFrame

  label .locals_end
end virtual
        RemGuess64_Prolog 192, 128
        DivRemGuess64_DivisorLzcnt 192, 128
        RemGuess64_DivisorSwitch 192, 128

        RemGuess64_PrepareLoop 192, 128
        DivRemGuess64_ShiftDivisor 192, 128

        RemGuess64_Loop 192, 128
.end:
	DivRemGuess64_Epilog 192, 128
        RemGuess64_RecheckOnce 192, 128
        RemGuess64_RecheckMulti 192, 128

end if