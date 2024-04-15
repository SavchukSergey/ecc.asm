if ~ definite bi_div_rem_512_256_guess

include 'bi_div_rem_guess_64.inc'

include '../add/bi_add_assign_384_384.inc'
include '../cmp/bi_cmp_256_256.inc'
include '../div_rem/bi_div_128_64.inc'
include '../div_rem/bi_div_rem_512_64.inc'
include '../div_rem/bi_div_rem_512_128.inc'
include '../extend_low/bi_extend_384_128.inc'
include '../lzcnt/bi_lzcnt_256.inc'
include '../lzcnt/bi_lzcnt_512.inc'
include '../shl/bi_shl_256.inc'
include '../shl/bi_shl_512.inc'
include '../shl/bi_shl_assign_384.inc'
include '../shl/bi_shl_assign_448.inc'
include '../sub/bi_sub_assign_512_256.inc'
include '../sub/bi_sub_assign_512_512.inc'
include '../inc/bi_inc_assign_384.inc'
include '../mul/bi_mul_256_128.inc'

bi_div_rem_512_256_guess:
    DivRemGuess64_Prepare 512, 256
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1
  .divisor_shifted rb __BIG_INTEGER_BYTES_256

  .remainder_lzcnt rq 1
  .remainder_shifted rb __BIG_INTEGER_BYTES_512

  .guess_128 rb __BIG_INTEGER_BYTES_128
  .delta rb __BIG_INTEGER_BYTES_512
  .guess_q rb __BIG_INTEGER_BYTES_512
  .correction rq 1
  label .locals_end
end virtual
        DivRemGuess64_Prolog 512, 256
        DivRemGuess64_DivisorLzcnt 512, 256
        DivRemGuess64_DivisorSwitch 512, 256

        DivRemGuess64_PrepareLoop 512, 256
        DivRemGuess64_ShiftDivisor 512, 256

        DivRemGuess64_Loop 512, 256
.end:
        add     rsp, .locals_end - .locals_start
        ret
        DivRemGuess64_RecheckOnce 512, 256

end if