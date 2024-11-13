if ~ definite bi_console_index

bi_console_index equ 0

include 'consts.inc'
include 'write_char.inc'
include 'write_string.inc'
include 'write_line.inc'

include 'write_u64.inc'
include 'write_u64_hex.inc'
include 'write_u128_hex.inc'
include 'write_u192_hex.inc'
include 'write_u256_hex.inc'
include 'write_u320_hex.inc'
include 'write_u384_hex.inc'
include 'write_u448_hex.inc'
include 'write_u512_hex.inc'
include 'write_u576_hex.inc'
include 'write_u768_hex.inc'
include 'write_u1024_hex.inc'

include 'write_ec_affine_point_256_hex.inc'
include 'write_ec_projective_point_256_hex.inc'
include 'write_ec_projective_mont_point_256_hex.inc'

end if
