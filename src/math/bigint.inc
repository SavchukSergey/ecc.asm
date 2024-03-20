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

BigIntegerCode 128
BigIntegerCode 256
BigIntegerCode 512
BigIntegerCode 1024


struc BezoutIdentity256 {
  .a rb __BIG_INTEGER_BYTES_256
  .b rb __BIG_INTEGER_BYTES_256
  .x rb __BIG_INTEGER_BYTES_256
  .y rb __BIG_INTEGER_BYTES_256
}

BezoutIdentity256.sizeof = 4 * __BIG_INTEGER_BYTES_256

virtual at 0
  BezoutIdentity256 BezoutIdentity256
end virtual