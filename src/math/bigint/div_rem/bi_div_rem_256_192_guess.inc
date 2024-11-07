if ~ definite bi_div_rem_256_192_guess

include 'macro/bi_div_rem_guess_64.inc'

include '../inc/bi_inc_assign_128.inc'
include '../shl/bi_shl_128.inc'
include '../cmp/index.inc'
include '../sub/bi_sub_assign_256_192.inc'
include 'bi_div_rem_256_128.inc'
include 'bi_div_rem_192_192.inc'

bi_div_rem_256_192_guess:
    DivRemGuess64_FastSwitch 256, 192
    DivRemGuess64_Prepare 256, 192
virtual at rsp
  label .locals_start
  .delta BigInteger256
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
	DivRemGuess64_Prolog 256, 192
	DivRemGuess64_DivisorLzcnt 256, 192
	DivRemGuess64_PrepareLoop 256, 192
	DivRemGuess64_ShiftDivisor 256, 192

	DivRemGuess64_Loop 256, 192

.end:
	DivRemGuess64_Epilog 256, 192
	DivRemGuess64_RecheckOnce 256, 192
	DivRemGuess64_RecheckMulti 256, 192

end if