if ~ definite __bi_assert

__bi_assert = 0

include 'bi_assert_equal_64.inc'
include 'bi_assert_equal_128.inc'
include 'bi_assert_equal_192.inc'
include 'bi_assert_equal_256.inc'
include 'bi_assert_equal_320.inc'
include 'bi_assert_equal_384.inc'
include 'bi_assert_equal_448.inc'
include 'bi_assert_equal_512.inc'
include 'bi_assert_equal_576.inc'
include 'bi_assert_equal_768.inc'
include 'bi_assert_equal_1024.inc'

include 'ec_affine_point_256_assert_equal.inc'
include 'ec_projective_point_256_assert_equal.inc'
include 'ec_projective_mont_point_256_assert_equal.inc'

include 'bi_assert_equal_hex_64.inc'
include 'bi_assert_equal_hex_128.inc'
include 'bi_assert_equal_hex_192.inc'
include 'bi_assert_equal_hex_256.inc'
include 'bi_assert_equal_hex_320.inc'
include 'bi_assert_equal_hex_384.inc'
include 'bi_assert_equal_hex_448.inc'
include 'bi_assert_equal_hex_512.inc'
include 'bi_assert_equal_hex_576.inc'
include 'bi_assert_equal_hex_768.inc'
include 'bi_assert_equal_hex_1024.inc'

include 'ec_affine_point_256_assert_equal_hex.inc'
include 'ec_projective_point_256_assert_equal_hex.inc'
include 'ec_projective_mont_point_256_assert_equal_hex.inc'

macro CallBiAssertEqualHex bits {
    if bits = 64
      call    bi_assert_equal_hex_64
    else if bits = 128
      call    bi_assert_equal_hex_128
    else if bits = 192
      call    bi_assert_equal_hex_192
    else if bits = 256
      call    bi_assert_equal_hex_256
    else if bits = 320
      call    bi_assert_equal_hex_320
    else if bits = 384
      call    bi_assert_equal_hex_384
    else if bits = 448
      call    bi_assert_equal_hex_448
    else if bits = 512
      call    bi_assert_equal_hex_512
    else if bits = 576
      call    bi_assert_equal_hex_576
    else if bits = 768
      call    bi_assert_equal_hex_768
    else if bits = 1024
      call    bi_assert_equal_hex_1024
    else
      display 'unknown CallBiAssertEqualHex '
      DisplayDec bits
      display 13, 10
      err 
    end if
}

end if