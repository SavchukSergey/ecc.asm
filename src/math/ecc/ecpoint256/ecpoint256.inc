
if ~ definite ecpoint256

include '../../bigint.inc'

ecpoint256:

struc ECPoint256 {
  BigInteger256 .x
  BigInteger256 .y
}

virtual at 0
  ECPoint256 ECPoint256
end virtual

end if