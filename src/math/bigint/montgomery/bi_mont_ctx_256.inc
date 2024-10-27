if ~ definite __MontgomeryContext256

__MontgomeryContext256:

struc MontgomeryContext256 {
  BigInteger256 .modulus
  BigInteger512 .r
  BigInteger256 .rm
  BigInteger256 .beta
}

virtual at 0
  MontgomeryContext256 MontgomeryContext256
end virtual

MontgomeryContext256.sizeof = ((256 + 512 + 256 + 256) / 8)
end if