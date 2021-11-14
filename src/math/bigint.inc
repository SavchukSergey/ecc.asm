include 'bigint/extend_low/extend_low.inc'
include 'bigint/extend_low/extend_low_2.inc'
include 'bigint/extend_low/extend_low_u64.inc'
include 'bigint/read_hex.inc'
include 'bigint/shr.inc'
include 'bigint/write_hex.inc'

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

BigIntegerExtend2 bits
BigIntegerExtendU64 bits
BigIntegerReadHex bits
BigIntegerShr bits
BigIntegerWriteHex bits
}



BigIntegerCode 128
BigIntegerCode 256
BigIntegerCode 512

;+-----------------+
;| Rexport methods |
;+-----------------+

;bi128_zero = __bi_zero_128
;bi256_zero = __bi_zero_256
;bi512_zero = __bi_zero_512

;bi128_rnd = __bi_rnd_128
;bi256_rnd = __bi_rnd_256
;bi512_rnd = __bi_rnd_512

;bi128_add_bi128 = __bi_add_128
;bi256_add_bi256 = __bi_add_256
;bi512_add_bi512 = __bi_add_512

;bi128_sub_bi128 = __bi_sub_128
;bi256_sub_bi256 = __bi_sub_256
;bi512_sub_bi512 = __bi_sub_512

;bi128_cmp_bi128 = __bi_cmp_128
;bi256_cmp_bi256 = __bi_cmp_256
;bi512_cmp_bi512 = __bi_cmp_512

;bi_256_extend_bi_128 = __bi_extend_1_256
;bi_512_extend_bi_256 = __bi_extend_1_512

;bi_512_extend_bi_128 = __bi_extend_2_512

;bi_128_extend_u64 = __bi_extend_u64_128
;bi_256_extend_u64 = __bi_extend_u64_256
;bi_512_extend_u64 = __bi_extend_u64_512

;bi128_write_hex = __bi_write_hex_128
;bi256_write_hex = __bi_write_hex_256
;bi512_write_hex = __bi_write_hex_512

