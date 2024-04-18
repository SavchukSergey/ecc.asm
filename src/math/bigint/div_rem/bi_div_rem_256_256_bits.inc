if ~ definite bi_div_rem_256_256_bits

include '../bit_set/bi_bit_set_256.inc'
include '../cmp/bi_cmp_256_256.inc'
include '../copy/bi_copy_256.inc'
include '../extend_low/bi_extend_512_256.inc'
include '../shl/bi_shl_assign_512_1.inc'
include '../sub/bi_sub_assign_256_256.inc'
include '../zero/bi_zero_256.inc'
include 'macro/bi_div_rem_bits.inc'

bi_div_rem_256_256_bits:
  DivRemBits 256, 256

end if