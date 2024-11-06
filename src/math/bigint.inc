if ~ definite bigint

bigint:

macro BigIntegerCode bits {
__BIG_INTEGER_BITS_#bits = #bits
__BIG_INTEGER_BYTES_#bits = __BIG_INTEGER_BITS_#bits / 8
__BIG_INTEGER_WORDS_#bits = __BIG_INTEGER_BYTES_#bits / 2
__BIG_INTEGER_DWORDS_#bits = __BIG_INTEGER_WORDS_#bits / 2
__BIG_INTEGER_QWORDS_#bits = __BIG_INTEGER_DWORDS_#bits / 2
__BIG_INTEGER_HEX_DIGITS_#bits = __BIG_INTEGER_BITS_#bits / 4

}

struc BigInteger64 {
  rb __BIG_INTEGER_BYTES_64
}
struc BigInteger128 {
  rb __BIG_INTEGER_BYTES_128
}
struc BigInteger192 {
  rb __BIG_INTEGER_BYTES_192
}
struc BigInteger256 {
  rb __BIG_INTEGER_BYTES_256
}
struc BigInteger320 {
  rb __BIG_INTEGER_BYTES_320
}
struc BigInteger384 {
  rb __BIG_INTEGER_BYTES_384
}
struc BigInteger512 {
  rb __BIG_INTEGER_BYTES_512
}
struc BigInteger576 {
  rb __BIG_INTEGER_BYTES_576
}
struc BigInteger768 {
  rb __BIG_INTEGER_BYTES_768
}
struc BigInteger1024 {
  rb __BIG_INTEGER_BYTES_1024
}


BigIntegerCode 64
BigIntegerCode 128
BigIntegerCode 192
BigIntegerCode 256
BigIntegerCode 320
BigIntegerCode 384
BigIntegerCode 512
BigIntegerCode 576
BigIntegerCode 768
BigIntegerCode 1024


macro BigInteger name, bits {
  if bits = 64
    name BigInteger64
  else if bits = 128
    name BigInteger128
  else if bits = 192
    name BigInteger192
  else if bits = 256
    name BigInteger256
  else if bits = 320
    name BigInteger320
  else if bits = 384
    name BigInteger384
  else if bits = 512
    name BigInteger512
  else if bits = 576
    name BigInteger576
  else if bits = 768
    name BigInteger768
  else if bits = 1024
    name BigInteger1024
  else
    display 'unknown BigInteger '
    display name
    display ', '
    DisplayDec bits
    display 13, 10
    err
  end if
}

struc BezoutIdentity256 {
  .a BigInteger256
  .b BigInteger256
  .x BigInteger256
  .y BigInteger256
}

BezoutIdentity256.sizeof = 4 * __BIG_INTEGER_BYTES_256

virtual at 0
  BezoutIdentity256 BezoutIdentity256
end virtual

end if