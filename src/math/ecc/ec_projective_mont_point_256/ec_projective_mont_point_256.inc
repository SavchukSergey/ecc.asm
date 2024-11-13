if ~ definite ec_projective_mont_point_256

ec_projective_mont_point_256:

struc ECProjectiveMontgomeryPoint256 {
  .x BigInteger256
  .y BigInteger256
  .z BigInteger256
  .curve rq 1
}

virtual at 0
  ECProjectiveMontgomeryPoint256 ECProjectiveMontgomeryPoint256
end virtual

__EC_PROJECTIVE_MONTGOMERY_POINT_256_HEX_DIGITS = __BIG_INTEGER_HEX_DIGITS_256 * 3

end if