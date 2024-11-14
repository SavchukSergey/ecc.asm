;@docs-ignore

if ~ definite ec_projective_point_256

ec_projective_point_256:

struc ECProjectivePoint256 {
  .x BigInteger256
  .y BigInteger256
  .z BigInteger256
  .curve rq 1
}

virtual at 0
  ECProjectivePoint256 ECProjectivePoint256
end virtual

__EC_PROJECTIVE_POINT_256_HEX_DIGITS = __BIG_INTEGER_HEX_DIGITS_256 * 3

end if