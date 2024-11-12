if ~ definite ec_affine_point_256

ec_affine_point_256:

struc ECAffinePoint256 {
  .x BigInteger256
  .y BigInteger256
  .curve rq 1
}

virtual at 0
  ECAffinePoint256 ECAffinePoint256
end virtual

__EC_AFFINE_POINT_256_HEX_DIGITS = __BIG_INTEGER_HEX_DIGITS_256 + __BIG_INTEGER_HEX_DIGITS_256

end if