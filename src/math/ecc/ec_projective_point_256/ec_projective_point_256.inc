if ~ definite ec_projective_point_256

ec_projective_point_256:

struc ECProjectivePoint256 {
  .x BigInteger256
  .y BigInteger256
  .z BigInteger256
}

virtual at 0
  ECProjectivePoint256 ECProjectivePoint256
end virtual

end if