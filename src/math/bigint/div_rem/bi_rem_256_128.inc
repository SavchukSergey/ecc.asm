if ~ definite bi_rem_256_128

bi_rem_256_128:
    DivRemGuess64_Prepare 256, 128
virtual at rsp
  label .locals_start
  BigInteger256 .delta
  BigInteger128 .remainder_shifted
  BigInteger128 .guess_128

  .dividend rq 1
  .divisor rq 1
  .remainder rq 1
  .correction rq 1

  .divisor_lzcnt rq 1
  .remainder_lzcnt rq 1

  .divisor_shifted rq 1

  AlignLocalsStackFrame

  label .locals_end
end virtual
        RemGuess64_Prolog 256, 128
        DivRemGuess64_DivisorLzcnt 256, 128
        RemGuess64_DivisorSwitch 256, 128

        RemGuess64_PrepareLoop 256, 128
        DivRemGuess64_ShiftDivisor 256, 128

        RemGuess64_Loop 256, 128
.end:
	DivRemGuess64_Epilog 256, 128
        RemGuess64_RecheckOnce 256, 128

end if