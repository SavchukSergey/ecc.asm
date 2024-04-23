macro BigIntegerCode bits {
__BIG_INTEGER_BITS_#bits = #bits
__BIG_INTEGER_BYTES_#bits = __BIG_INTEGER_BITS_#bits / 8
__BIG_INTEGER_WORDS_#bits = __BIG_INTEGER_BYTES_#bits / 2
__BIG_INTEGER_DWORDS_#bits = __BIG_INTEGER_WORDS_#bits / 2
__BIG_INTEGER_QWORDS_#bits = __BIG_INTEGER_DWORDS_#bits / 2
__BIG_INTEGER_HEX_DIGITS_#bits = __BIG_INTEGER_BITS_#bits / 4

struct BigInteger#bits
  union
    bytes rb __BIG_INTEGER_BYTES_#bits
    words rw __BIG_INTEGER_WORDS_#bits
    dwords rd __BIG_INTEGER_DWORDS_#bits
    qwords rq __BIG_INTEGER_QWORDS_#bits
  ends
ends

struct BigIntegerHex#bits
  data rb __BIG_INTEGER_HEX_DIGITS_#bits
ends

}

BigIntegerCode 64
BigIntegerCode 128
BigIntegerCode 256
BigIntegerCode 512
BigIntegerCode 1024


;todo: replace __BIG_INTEGER_BYTES_128 with BigInteger128
macro BigInteger128 name {
  name rb __BIG_INTEGER_BYTES_128
}

;todo: replace __BIG_INTEGER_BYTES_256 with BigInteger256
macro BigInteger256 name {
  name rb __BIG_INTEGER_BYTES_256
}

;todo: replace __BIG_INTEGER_BYTES_512 with BigInteger512
macro BigInteger512 name {
  name rb __BIG_INTEGER_BYTES_512
}

;todo: replace __BIG_INTEGER_BYTES_1024 with BigInteger1024
macro BigInteger1024 name {
  name rb __BIG_INTEGER_BYTES_1024
}

macro BigInteger name, bits {
  if bits = 128
    BigInteger128 name
  else if bits = 256
    BigInteger256 name
  else if bits = 512
    BigInteger512 name
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
  BigInteger256 .a
  BigInteger256 .b
  BigInteger256 .x
  BigInteger256 .y
}

BezoutIdentity256.sizeof = 4 * __BIG_INTEGER_BYTES_256

virtual at 0
  BezoutIdentity256 BezoutIdentity256
end virtual