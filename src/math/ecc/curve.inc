struc ECCurve256 {
  .modulus BigInteger256
  .a BigInteger256
  .b BigInteger256

; Generator Affine Popint
  .gx BigInteger256
  .gy BigInteger256
  .gcurve rq 1

  .n BigInteger256
  .h BigInteger256
  .mont MontgomeryContext256
}

virtual at 0
  ECCurve256 ECCurve256
end virtual

