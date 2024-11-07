if ~ definite bi_div_rem_256_256_guess

include 'macro/bi_div_rem_guess_64.inc'

include '../inc/bi_inc_assign_128.inc'
include '../shl/bi_shl_128.inc'
include 'bi_div_rem_256_192.inc'

bi_div_rem_256_256_guess:
    DivRemGuess64_FastSwitch 256, 256
    DivRemGuess64_Prepare 256, 256
virtual at rsp
  label .locals_start
  .delta BigInteger256
  .remainder_shifted BigInteger128
  .guess_128 BigInteger128
  .guess_q BigInteger256

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
	DivRemGuess64_Prolog 256, 256
	DivRemGuess64_DivisorLzcnt 256, 256
	DivRemGuess64_PrepareLoop 256, 256
	DivRemGuess64_ShiftDivisor 256, 256

	DivRemGuess64_Loop 256, 256

.end:
	DivRemGuess64_Epilog 256, 256
	DivRemGuess64_RecheckOnce 256, 256
	DivRemGuess64_RecheckMulti 256, 256

end if