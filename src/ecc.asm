format pe64 console DLL
entry DllEntryPoint

include 'win64a.inc'

section '.text' code readable executable

proc DllEntryPoint hinstDLL,fdwReason,lpvReserved
        mov     eax,TRUE
        ret
endp


include 'macro/align.inc'
include 'math/bigint.inc'
include 'math/bigint/index.inc'
include 'math/ecc/index.inc'

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
         bi_is_zero_512, 'bi_is_zero_512', \
\
         bi_copy_128, 'bi_copy_128', \
         bi_copy_256, 'bi_copy_256', \
         bi_copy_512, 'bi_copy_512', \
\
         bi_try_read_hex_128, 'bi_try_read_hex_128', \
         bi_try_read_hex_192, 'bi_try_read_hex_192', \
         bi_try_read_hex_256, 'bi_try_read_hex_256', \
         bi_try_read_hex_512, 'bi_try_read_hex_512', \
         bi_try_read_hex_1024, 'bi_try_read_hex_1024', \
\
         bi_add_128_128, 'bi_add_128_128', \
         bi_add_256_256, 'bi_add_256_256', \
         bi_add_512_512, 'bi_add_512_512', \
\
         bi_add_assign_128_128, 'bi_add_assign_128_128', \
         bi_add_assign_192_128, 'bi_add_assign_192_128', \
         bi_add_assign_192_192, 'bi_add_assign_192_192', \
         bi_add_assign_256_128, 'bi_add_assign_256_128', \
         bi_add_assign_256_256, 'bi_add_assign_256_256', \
         bi_add_assign_320_128, 'bi_add_assign_320_128', \
         bi_add_assign_320_256, 'bi_add_assign_320_256', \
         bi_add_assign_384_128, 'bi_add_assign_384_128', \
         bi_add_assign_384_256, 'bi_add_assign_384_256', \
         bi_add_assign_384_384, 'bi_add_assign_384_384', \
         bi_add_assign_448_128, 'bi_add_assign_448_128', \
         bi_add_assign_448_256, 'bi_add_assign_448_256', \
         bi_add_assign_448_448, 'bi_add_assign_448_448', \
         bi_add_assign_512_256, 'bi_add_assign_512_256', \
         bi_add_assign_512_512, 'bi_add_assign_512_512', \
         bi_add_assign_640_512, 'bi_add_assign_640_512', \
         bi_add_assign_768_512, 'bi_add_assign_768_512', \
         bi_add_assign_1024_512, 'bi_add_assign_1024_512', \
         bi_add_assign_1024_1024, 'bi_add_assign_1024_1024', \
\
         bi_sub_128_128, 'bi_sub_128_128', \
         bi_sub_256_256, 'bi_sub_256_256', \
         bi_sub_512_512, 'bi_sub_512_512', \
\
         bi_sub_assign_128_128, 'bi_sub_assign_128_128', \
         bi_sub_assign_256_128, 'bi_sub_assign_256_128', \
         bi_sub_assign_256_256, 'bi_sub_assign_256_256', \
         bi_sub_assign_384_384, 'bi_sub_assign_384_384', \
         bi_sub_assign_448_448, 'bi_sub_assign_448_448', \
         bi_sub_assign_512_128, 'bi_sub_assign_512_128', \
         bi_sub_assign_512_192, 'bi_sub_assign_512_192', \
         bi_sub_assign_512_256, 'bi_sub_assign_512_256', \
         bi_sub_assign_512_320, 'bi_sub_assign_512_320', \
         bi_sub_assign_512_384, 'bi_sub_assign_512_384', \
         bi_sub_assign_512_448, 'bi_sub_assign_512_448', \
         bi_sub_assign_512_512, 'bi_sub_assign_512_512', \
\
         bi_inc_assign_128, 'bi_inc_assign_128', \
         bi_inc_assign_192, 'bi_inc_assign_192', \
         bi_inc_assign_256, 'bi_inc_assign_256', \
         bi_inc_assign_384, 'bi_inc_assign_384', \
         bi_inc_assign_448, 'bi_inc_assign_448', \
         bi_inc_assign_512, 'bi_inc_assign_512', \
\
         bi_dec_assign_256, 'bi_dec_assign_256', \
\
         bi_cmp_128_128, 'bi_cmp_128_128', \
         bi_cmp_192_192, 'bi_cmp_192_192', \
         bi_cmp_256_128, 'bi_cmp_256_128', \
         bi_cmp_256_256, 'bi_cmp_256_256', \
         bi_cmp_512_128, 'bi_cmp_512_128', \
         bi_cmp_512_256, 'bi_cmp_512_256', \
         bi_cmp_512_512, 'bi_cmp_512_512', \
         bi_cmp_1024_1024, 'bi_cmp_1024_1024', \
\
         bi_shl_assign_128_1, 'bi_shl_assign_128_1', \
         bi_shl_assign_256_1, 'bi_shl_assign_256_1', \
         bi_shl_assign_256_64, 'bi_shl_assign_256_64', \
         bi_shl_assign_256_128, 'bi_shl_assign_256_128', \
         bi_shl_assign_512_1, 'bi_shl_assign_512_1', \
         bi_shl_assign_512_64, 'bi_shl_assign_512_64', \
         bi_shl_assign_512_128, 'bi_shl_assign_512_128', \
         bi_shl_assign_512_256, 'bi_shl_assign_512_256', \
\
         bi_shl_assign_128, 'bi_shl_assign_128', \
         bi_shl_assign_192, 'bi_shl_assign_192', \
         bi_shl_assign_256, 'bi_shl_assign_256', \
         bi_shl_assign_384, 'bi_shl_assign_384', \
         bi_shl_assign_448, 'bi_shl_assign_448', \
         bi_shl_assign_512, 'bi_shl_assign_512', \
\
         bi_shl_128, 'bi_shl_128', \
         bi_shl_256, 'bi_shl_256', \
         bi_shl_512, 'bi_shl_512', \
\
         bi_shr_assign_128_1, 'bi_shr_assign_128_1', \
         bi_shr_assign_256_1, 'bi_shr_assign_256_1', \
         bi_shr_assign_256_64, 'bi_shr_assign_256_64', \
         bi_shr_assign_256_128, 'bi_shr_assign_256_128', \
         bi_shr_assign_512_1, 'bi_shr_assign_512_1', \
         bi_shr_assign_512_64, 'bi_shr_assign_512_64', \
         bi_shr_assign_512_128, 'bi_shr_assign_512_128', \
         bi_shr_assign_512_256, 'bi_shr_assign_512_256', \
\
         bi_shr_assign_128, 'bi_shr_assign_128', \
         bi_shr_assign_256, 'bi_shr_assign_256', \
         bi_shr_assign_512, 'bi_shr_assign_512', \
\
         bi_shr_128, 'bi_shr_128', \
         bi_shr_256, 'bi_shr_256', \
         bi_shr_512, 'bi_shr_512', \
\
         bi_mul_64_64, 'bi_mul_64_64', \
         bi_mul_128_64, 'bi_mul_128_64', \
         bi_mul_128_128, 'bi_mul_128_128', \
         bi_mul_192_64, 'bi_mul_192_64', \
         bi_mul_256_64, 'bi_mul_256_64', \
         bi_mul_256_256, 'bi_mul_256_256', \
         bi_mul_256_128, 'bi_mul_256_128', \
         bi_mul_512_64, 'bi_mul_512_64' ,\
         bi_mul_512_256, 'bi_mul_512_256' ,\
         bi_mul_512_512, 'bi_mul_512_512' ,\
\
         bi_mul_low_64_64, 'bi_mul_low_64_64', \
         bi_mul_low_128_64, 'bi_mul_low_128_64', \
         bi_mul_low_128_128, 'bi_mul_low_128_128', \
         bi_mul_low_256_64, 'bi_mul_low_256_64', \
         bi_mul_low_256_128, 'bi_mul_low_256_128', \
         bi_mul_low_256_256, 'bi_mul_low_256_256', \
         bi_mul_low_512_64, 'bi_mul_low_512_64' ,\
         bi_mul_low_512_512, 'bi_mul_low_512_512' ,\
\
         bi_square_64, 'bi_square_64' ,\
         bi_square_128, 'bi_square_128' ,\
         bi_square_256, 'bi_square_256' ,\
\
         bi_div_128_64, 'bi_div_128_64', \
         bi_rem_128_64, 'bi_rem_128_64', \
         bi_rem_256_128, 'bi_rem_256_128', \
         bi_rem_512_64, 'bi_rem_512_64', \
         bi_rem_512_128, 'bi_rem_512_128', \
         bi_rem_512_256, 'bi_rem_512_256', \
\
         bi_div_rem_128_64, 'bi_div_rem_128_64', \
         bi_div_rem_128_128, 'bi_div_rem_128_128', \
         bi_div_rem_256_64, 'bi_div_rem_256_64', \
         bi_div_rem_256_64, 'bi_div_rem_256_64', \
         bi_div_rem_256_128, 'bi_div_rem_256_128', \
         bi_div_rem_256_256, 'bi_div_rem_256_256', \
         bi_div_rem_512_64, 'bi_div_rem_512_64', \
         bi_div_rem_512_128, 'bi_div_rem_512_128', \
         bi_div_rem_512_256, 'bi_div_rem_512_256', \
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
         bi_lzcnt_192, 'bi_lzcnt_192',\
         bi_lzcnt_256, 'bi_lzcnt_256',\
         bi_lzcnt_512, 'bi_lzcnt_512',\
\
         bi_extend_128_64, 'bi_extend_128_64',\
         bi_extend_192_64, 'bi_extend_192_64',\
         bi_extend_256_64, 'bi_extend_256_64',\
         bi_extend_512_64, 'bi_extend_512_64',\
         bi_extend_192_128, 'bi_extend_192_128',\
         bi_extend_256_128, 'bi_extend_256_128',\
         bi_extend_384_64, 'bi_extend_384_64',\
         bi_extend_384_128, 'bi_extend_384_128',\
         bi_extend_448_64, 'bi_extend_448_64',\
         bi_extend_448_128, 'bi_extend_448_128',\
         bi_extend_512_128, 'bi_extend_512_128',\
         bi_extend_512_256, 'bi_extend_512_256',\
\
         bi_extend_assign_128_64, 'bi_extend_assign_128_64',\
         bi_extend_assign_192_64, 'bi_extend_assign_192_64',\
         bi_extend_assign_384_64, 'bi_extend_assign_384_64',\
         bi_extend_assign_448_64, 'bi_extend_assign_448_64',\
\
         bi_mod_add_assign_256_256, 'bi_mod_add_assign_256_256',\
\
         bi_mod_sub_assign_256_256, 'bi_mod_sub_assign_256_256',\
\
         bi_mod_double_assign_256, 'bi_mod_double_assign_256',\
         bi_mod_tripple_assign_256, 'bi_mod_tripple_assign_256',\
         bi_mod_half_assign_256, 'bi_mod_half_assign_256',\
\
         bi_mod_mul_256_256, 'bi_mod_mul_256_256',\
         bi_mont_ctx_256_init, 'bi_mont_ctx_256_init',\
\
         bi_mod_negate_256, 'bi_mod_negate_256' ,\
         bi_mod_negate_512, 'bi_mod_negate_512' ,\
\
         bi_mod_pow_256, 'bi_mod_pow_256' ,\
\
         bi_mod_div_256_256, 'bi_mod_div_256_256',\
\
         bi_mod_square_256, 'bi_mod_square_256' ,\
         bi_mod_cube_256, 'bi_mod_cube_256' ,\
\
         bi_mod_inverse_256, 'bi_mod_inverse_256',\
         bi_mod_inverse_512, 'bi_mod_inverse_512',\
\
         bi_euclid_ext_256, 'bi_euclid_ext_256',\
\
         bi_mont_ctx_256_init, 'bi_mont_ctx_256_init',\
         bi_mont_ctx_256_convert, 'bi_mont_ctx_256_convert',\
         bi_mont_ctx_256_redc_256, 'bi_mont_ctx_256_redc_256',\
         bi_mont_ctx_256_redc_512, 'bi_mont_ctx_256_redc_512',\
         bi_mont_ctx_256_mul, 'bi_mont_ctx_256_mul',\
         bi_mont_ctx_256_square, 'bi_mont_ctx_256_square',\
         bi_mont_ctx_256_pow, 'bi_mont_ctx_256_pow',\
\
         bi_rnd_128, 'bi_rnd_128', \
         bi_rnd_256, 'bi_rnd_256', \
         bi_rnd_512, 'bi_rnd_512', \
         bi_rnd_1024, 'bi_rnd_1024'