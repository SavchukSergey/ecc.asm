if ~ definite bi_div_rem_192_128_guess

include 'macro/bi_div_rem_guess_64.inc'

include '../cmp/bi_cmp_192_128.inc'
include '../sub/bi_sub_assign_192_192.inc'

bi_div_rem_192_128_guess:
    DivRemGuess64_FastSwitch 192, 128
    DivRemGuess64_Prepare 192, 128
virtual at rsp
  label .locals_start
  .delta BigInteger192 
  .guess_q BigInteger192
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
	DivRemGuess64_Prolog 192, 128
	DivRemGuess64_DivisorLzcnt 192, 128

	DivRemGuess64_PrepareLoop 192, 128
	DivRemGuess64_ShiftDivisor 192, 128
	DivRemGuess64_Loop 192, 128
.end:
	DivRemGuess64_Epilog 192, 128
	DivRemGuess64_RecheckOnce 192, 128
	DivRemGuess64_RecheckMulti 192, 128

end if