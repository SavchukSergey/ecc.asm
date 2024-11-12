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

end if