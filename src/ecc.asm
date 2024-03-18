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
include 'math/bigint/add/index.inc'
include 'math/bigint/sub/index.inc'
include 'math/bigint/cmp/index.inc'
include 'math/bigint/shl/index.inc'
include 'math/bigint/shr/shr.inc'
include 'math/bigint/mul/index.inc'
include 'math/bigint/div_rem/div_rem.inc'
include 'math/bigint/bit_clear/bi_bit_clear_256.inc'
include 'math/bigint/bit_set/bi_bit_set_256.inc'
include 'ecc_win64_api.inc'

section '.edata' export data readable

  export 'ecc.dll',\
         bi_zero_128, 'bi_zero_128', \
         bi_zero_256, 'bi_zero_256', \
         bi_zero_512, 'bi_zero_512', \
         bi_zero_1024, 'bi_zero_1024', \
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
         bi_sub_assign_256_256, 'bi_sub_assign_256_256', \
         bi_sub_assign_512_512, 'bi_sub_assign_512_512', \
\
         bi_cmp_128_128, 'bi_cmp_128_128', \
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
         bi_shr_assign_128_1, 'bi_shr_assign_128_1', \
         bi_shr_assign_256_1, 'bi_shr_assign_256_1', \
         bi_shr_assign_512_1, 'bi_shr_assign_512_1', \
\
         bi_mul_64_64, 'bi_mul_64_64', \
         bi_mul_128_128, 'bi_mul_128_128', \
         bi_mul_256_256, 'bi_mul_256_256', \
         bi_mul_512_512, 'bi_mul_512_512' ,\
\
         bi_div_rem_128_128, 'bi_div_rem_128_128', \
         bi_div_rem_256_256, 'bi_div_rem_256_256', \
         bi_div_rem_512_512, 'bi_div_rem_512_512', \
\
         bi_bit_clear_256, 'bi_bit_clear_256',\
\
         bi_bit_set_256, 'bi_bit_set_256',\
\
         bi_extend_512_256, 'bi_extend_512_256'

;\
;\
;         BigIntegerBitCheck_128, 'bi128_bit_check', \
;         BigIntegerBitCheck_256, 'bi256_bit_check', \
;         BigIntegerBitCheck_512, 'bi512_bit_check', \
;;\
;         BigIntegerBitClear_128, 'bi128_bit_clear', \
;         BigIntegerBitClear_512, 'bi512_bit_clear', \
;\
;         BigIntegerBitSet_128, 'bi128_bit_set', \
;;         BigIntegerBitSet_512, 'bi512_bit_set', \
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
;         BigIntegerExtendLow1_128, 'bi128_extend_bi64_low', \
;         BigIntegerExtendLow1_512, 'bi512_extend_bi256_low', \
;\
;         BigIntegerExtendLow2_128, 'bi128_extend_bi32_low', \
;         BigIntegerExtendLow2_256, 'bi256_extend_bi64_low', \
;         BigIntegerExtendLow2_512, 'bi512_extend_bi128_low', \
;\
;         BigIntegerExtendLowU64_128, 'bi128_extend_u64_low', \
;         BigIntegerExtendLowU64_256, 'bi256_extend_u64_low', \
;         BigIntegerExtendLowU64_512, 'bi512_extend_u64_low', \
;\
;         BigIntegerMul_128, 'bi128_mul', \
;         BigIntegerMul_256, 'bi256_mul', \
;         BigIntegerMul_512, 'bi512_mul', \
;\
;         BigIntegerOne_128, 'bi128_one', \
;         BigIntegerOne_256, 'bi256_one', \
;         BigIntegerOne_512, 'bi512_one', \
;\
;         BigIntegerRnd_128, 'bi128_rnd', \
;         BigIntegerRnd_256, 'bi256_rnd', \
;         BigIntegerRnd_512, 'bi512_rnd', \
;\
;         BigIntegerSub_128, 'bi128_sub', \
;         BigIntegerSub_256, 'bi256_sub', \
;         BigIntegerSub_512, 'bi512_sub', \
;\
;         BigIntegerZero_128, 'bi128_zero', \
;         BigIntegerZero_256, 'bi256_zero', \
;         BigIntegerZero_512, 'bi512_zero'
;