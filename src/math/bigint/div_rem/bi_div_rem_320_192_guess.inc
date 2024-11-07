if ~ definite bi_div_rem_320_192_guess

include 'macro/bi_div_rem_guess_64.inc'

include '../inc/bi_inc_assign_128.inc'
include '../shl/bi_shl_128.inc'
include '../cmp/index.inc'
include '../sub/bi_sub_assign_320_192.inc'
include '../add/index.inc'

include 'bi_div_rem_256_192.inc'
include 'bi_div_rem_320_128.inc'

bi_div_rem_320_192_guess:
    DivRemGuess64_FastSwitch 320, 192
    DivRemGuess64_Prepare 320, 192
virtual at rsp
  label .locals_start
  .delta BigInteger320
  .remainder_shifted BigInteger128
  .guess_128 BigInteger128
  .guess_q BigInteger320

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
	DivRemGuess64_Prolog 320, 192
	DivRemGuess64_DivisorLzcnt 320, 192
	DivRemGuess64_PrepareLoop 320, 192
	DivRemGuess64_ShiftDivisor 320, 192

	DivRemGuess64_Loop 320, 192

.end:
	DivRemGuess64_Epilog 320, 192
	DivRemGuess64_RecheckOnce 320, 192
	DivRemGuess64_RecheckMulti 320, 192

end if