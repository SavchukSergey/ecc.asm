format pe64 console DLL
entry DllEntryPoint

include 'win64a.inc'

section '.text' code readable executable

proc DllEntryPoint hinstDLL,fdwReason,lpvReserved
        mov     eax,TRUE
        ret
endp


include 'math/bigint.inc'
include 'math/bigint/zero/index.inc'
include 'math/bigint/is_zero/index.inc'
include 'math/bigint/one/index.inc'
include 'math/bigint/add/index.inc'
include 'math/bigint/sub/index.inc'
include 'math/bigint/inc/index.inc'
include 'math/bigint/dec/index.inc'
include 'math/bigint/cmp/index.inc'
include 'math/bigint/shl/index.inc'
include 'math/bigint/shr/index.inc'
include 'math/bigint/mul/index.inc'
include 'math/bigint/mul_low/index.inc'
include 'math/bigint/extend_low/index.inc'
include 'math/bigint/bit_clear/index.inc'
include 'math/bigint/bit_set/index.inc'
include 'math/bigint/bit_check/index.inc'
include 'math/bigint/mod_add/index.inc'
include 'math/bigint/mod_sub/index.inc'
include 'math/bigint/mod_mul/index.inc'
include 'math/bigint/mod_inverse/index.inc'
include 'math/bigint/euclid_ext/index.inc'
include 'math/bigint/index.inc'
include 'ecc_win64_api.inc'

section '.edata' export data readable

  export 'ecc.dll',\
         bi_zero_128, 'bi_zero_128', \
         bi_zero_256, 'bi_zero_256', \
         bi_zero_512, 'bi_zero_512', \
         bi_zero_1024, 'bi_zero_1024', \
\
         bi_one_128, 'bi_one_128', \
         bi_one_256, 'bi_one_256', \
         bi_one_512, 'bi_one_512', \
         bi_one_1024, 'bi_one_1024', \
\
         bi_is_zero_256, 'bi_is_zero_256', \
\
         bi_copy_128, 'bi_copy_128', \
         bi_copy_256, 'bi_copy_256', \
\
         bi_try_read_hex_128, 'bi_try_read_hex_128', \
         bi_try_read_hex_256, 'bi_try_read_hex_256', \
         bi_try_read_hex_512, 'bi_try_read_hex_512', \
         bi_try_read_hex_1024, 'bi_try_read_hex_1024', \
\
         bi_add_128_128, 'bi_add_128_128', \
         bi_add_256_256, 'bi_add_256_256', \
         bi_add_512_512, 'bi_add_512_512', \
\
         bi_add_assign_128_128, 'bi_add_assign_128_128', \
         bi_add_assign_256_256, 'bi_add_assign_256_256', \
         bi_add_assign_512_512, 'bi_add_assign_512_512', \
         bi_add_assign_1024_1024, 'bi_add_assign_1024_1024', \
\
         bi_sub_128_128, 'bi_sub_128_128', \
         bi_sub_256_256, 'bi_sub_256_256', \
         bi_sub_512_512, 'bi_sub_512_512', \
\
         bi_sub_assign_128_128, 'bi_sub_assign_128_128', \
         bi_sub_assign_256_128, 'bi_sub_assign_256_128', \
         bi_sub_assign_256_256, 'bi_sub_assign_256_256', \
         bi_sub_assign_512_512, 'bi_sub_assign_512_512', \
\
         bi_inc_assign_128, 'bi_inc_assign_128', \
         bi_inc_assign_256, 'bi_inc_assign_256', \
\
         bi_dec_assign_256, 'bi_dec_assign_256', \
\
         bi_cmp_128_128, 'bi_cmp_128_128', \
         bi_cmp_256_128, 'bi_cmp_256_128', \
         bi_cmp_256_256, 'bi_cmp_256_256', \
         bi_cmp_512_512, 'bi_cmp_512_512', \
         bi_cmp_1024_1024, 'bi_cmp_1024_1024', \
\
         bi_shl_assign_128_1, 'bi_shl_assign_128_1', \
         bi_shl_assign_256_1, 'bi_shl_assign_256_1', \
         bi_shl_assign_512_1, 'bi_shl_assign_512_1', \
\
         bi_shl_assign_128, 'bi_shl_assign_128', \
         bi_shl_assign_256, 'bi_shl_assign_256', \
         bi_shl_assign_512, 'bi_shl_assign_512', \
\
         bi_shl_128, 'bi_shl_128', \
         bi_shl_256, 'bi_shl_256', \
\
         bi_shr_assign_128_1, 'bi_shr_assign_128_1', \
         bi_shr_assign_256_1, 'bi_shr_assign_256_1', \
         bi_shr_assign_512_1, 'bi_shr_assign_512_1', \
\
         bi_shr_assign_128, 'bi_shr_assign_128', \
\
         bi_mul_64_64, 'bi_mul_64_64', \
         bi_mul_128_64, 'bi_mul_128_64', \
         bi_mul_128_128, 'bi_mul_128_128', \
         bi_mul_256_64, 'bi_mul_256_64', \
         bi_mul_256_256, 'bi_mul_256_256', \
         bi_mul_512_512, 'bi_mul_512_512' ,\
\
         bi_mul_low_64_64, 'bi_mul_low_64_64', \
         bi_mul_low_128_128, 'bi_mul_low_128_128', \
         bi_mul_low_256_128, 'bi_mul_low_256_128', \
         bi_mul_low_256_256, 'bi_mul_low_256_256', \
         bi_mul_low_512_512, 'bi_mul_low_512_512' ,\
\
         bi_div_128_64, 'bi_div_128_64', \
\
         bi_div_rem_128_64, 'bi_div_rem_128_64', \
         bi_div_rem_128_128, 'bi_div_rem_128_128', \
         bi_div_rem_256_64, 'bi_div_rem_256_64', \
         bi_div_rem_256_128, 'bi_div_rem_256_128', \
         bi_div_rem_256_256, 'bi_div_rem_256_256', \
         bi_div_rem_512_512, 'bi_div_rem_512_512', \
\
         bi_bit_clear_128, 'bi_bit_clear_128',\
         bi_bit_clear_256, 'bi_bit_clear_256',\
         bi_bit_clear_512, 'bi_bit_clear_512',\
\
         bi_bit_set_128, 'bi_bit_set_128',\
         bi_bit_set_256, 'bi_bit_set_256',\
         bi_bit_set_512, 'bi_bit_set_512',\
\
         bi_bit_check_128, 'bi_bit_check_128',\
         bi_bit_check_256, 'bi_bit_check_256',\
         bi_bit_check_512, 'bi_bit_check_512',\
\
         bi_lzcnt_128, 'bi_lzcnt_128',\
         bi_lzcnt_256, 'bi_lzcnt_256',\
         bi_lzcnt_512, 'bi_lzcnt_512',\
\
         bi_extend_128_64, 'bi_extend_128_64',\
         bi_extend_256_64, 'bi_extend_256_64',\
         bi_extend_256_128, 'bi_extend_256_128',\
         bi_extend_512_64, 'bi_extend_512_64',\
         bi_extend_512_256, 'bi_extend_512_256',\
\
         bi_mod_add_assign_256_256, 'bi_mod_add_assign_256_256',\
\
         bi_mod_double_assign_256_256, 'bi_mod_double_assign_256_256',\
\
         bi_mod_sub_assign_256_256, 'bi_mod_sub_assign_256_256',\
\
         bi_mod_mul_256_256, 'bi_mod_mul_256_256',\
\
         bi_mod_inverse_256, 'bi_mod_inverse_256',\
\
         bi_euclid_ext_256, 'bi_euclid_ext_256'


;\
;\
;         BigIntegerExtendHigh1_128, 'bi128_extend_bi64_high', \
;         BigIntegerExtendHigh1_256, 'bi256_extend_bi128_high', \
;         BigIntegerExtendHigh1_512, 'bi512_extend_bi256_high', \
;\
;         BigIntegerExtendHigh2_128, 'bi128_extend_bi32_high', \
;         BigIntegerExtendHigh2_256, 'bi256_extend_bi64_high', \
;         BigIntegerExtendHigh2_512, 'bi512_extend_bi128_high', \
;\
;         BigIntegerExtendHighU64_128, 'bi128_extend_u64_high', \
;         BigIntegerExtendHighU64_256, 'bi256_extend_u64_high', \
;         BigIntegerExtendHighU64_512, 'bi512_extend_u64_high', \
;\
;         BigIntegerRnd_128, 'bi128_rnd', \
;         BigIntegerRnd_256, 'bi256_rnd', \
;         BigIntegerRnd_512, 'bi512_rnd', \
;\
