if ~ definite bi_rem_512_256

include 'bi_div_rem_512_256.inc'
include 'bi_rem_512_128.inc'

bi_rem_512_256:
    DivRemGuess64_Prepare 512, 256
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .remainder rq 1

  .divisor_lzcnt rq 1
  .divisor_shifted rb __BIG_INTEGER_BYTES_256

  .remainder_lzcnt rq 1
  .remainder_shifted rb __BIG_INTEGER_BYTES_512

  .guess_128 rb __BIG_INTEGER_BYTES_128
  .delta rb __BIG_INTEGER_BYTES_512
  .correction rq 1
  label .locals_end
end virtual
        RemGuess64_Prolog 512, 256
        DivRemGuess64_DivisorLzcnt 512, 256
        RemGuess64_DivisorSwitch 512, 256

        RemGuess64_PrepareLoop 512, 256
        DivRemGuess64_ShiftDivisor 512, 256

        RemGuess64_Loop 512, 256
.end:
        add     rsp, .locals_end - .locals_start
        ret
        RemGuess64_RecheckOnce 512, 256

end if