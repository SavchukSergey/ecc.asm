if ~ definite bi_shl_index

bi_shl_index equ 0

include 'bi_shl_128.inc'
include 'bi_shl_256.inc'
include 'bi_shl_384.inc'
include 'bi_shl_512.inc'

include 'bi_shl_assign_128_1.inc'
include 'bi_shl_assign_256_1.inc'
include 'bi_shl_assign_256_64.inc'
include 'bi_shl_assign_256_128.inc'
include 'bi_shl_assign_512_1.inc'
include 'bi_shl_assign_512_64.inc'
include 'bi_shl_assign_512_128.inc'
include 'bi_shl_assign_512_256.inc'

include 'bi_shl_assign_128.inc'
include 'bi_shl_assign_192.inc'
include 'bi_shl_assign_256.inc'
include 'bi_shl_assign_320.inc'
include 'bi_shl_assign_384.inc'
include 'bi_shl_assign_448.inc'
include 'bi_shl_assign_512.inc'

end if