if ~ definite __MontgomeryContext256

__MontgomeryContext256:

struc MontgomeryContext256 {
  .modulus BigInteger256
  .r BigInteger512
  .rm BigInteger256
  .mod_inv_r BigInteger256           ; mod_inv_r * modulus = -1 mod r
}

virtual at 0
  MontgomeryContext256 MontgomeryContext256
end virtual

MontgomeryContext256.sizeof = ((256 + 512 + 256 + 256) / 8)
end if