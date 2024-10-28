
if ~ definite ecpoint256

include '../../bigint.inc'

ecpoint256:

struc ECPoint256 {
  .x BigInteger256
  .y BigInteger256
}

virtual at 0
  ECPoint256 ECPoint256
end virtual

end if