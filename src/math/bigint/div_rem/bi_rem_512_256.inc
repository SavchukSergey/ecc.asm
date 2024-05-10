if ~ definite bi_rem_512_256

include 'bi_div_rem_512_256.inc'
include 'bi_rem_512_128.inc'

bi_rem_512_256:
    DivRemGuess64_Prepare 512, 256
virtual at rsp
  label .locals_start
  BigInteger512 .delta
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
        RemGuess64_Prolog 512, 256
        DivRemGuess64_DivisorLzcnt 512, 256
        RemGuess64_DivisorSwitch 512, 256

        RemGuess64_PrepareLoop 512, 256
        DivRemGuess64_ShiftDivisor 512, 256

        RemGuess64_Loop 512, 256
.end:
	DivRemGuess64_Epilog 512, 256
        RemGuess64_RecheckOnce 512, 256

end if