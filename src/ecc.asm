format pe64 console DLL
entry DllEntryPoint

include 'win64a.inc'

section '.text' code readable executable

proc DllEntryPoint hinstDLL,fdwReason,lpvReserved
        mov     eax,TRUE
        ret
endp


include 'math/bigint.inc'
include 'ecc_win64_api.inc'

section '.edata' export data readable

  export 'ecc.dll',\
         BigIntegerAdd_128, 'bi128_add', \
         BigIntegerAdd_256, 'bi256_add', \
         BigIntegerAdd_512, 'bi512_add', \
\
         BigIntegerBitClear_128, 'bi128_bit_clear', \
         BigIntegerBitClear_256, 'bi256_bit_clear', \
         BigIntegerBitClear_512, 'bi512_bit_clear', \
\
         BigIntegerBitSet_128, 'bi128_bit_set', \
         BigIntegerBitSet_256, 'bi256_bit_set', \
         BigIntegerBitSet_512, 'bi512_bit_set', \
\
         BigIntegerCmp_128, 'bi128_cmp', \
         BigIntegerCmp_256, 'bi256_cmp', \
         BigIntegerCmp_512, 'bi512_cmp', \
\
         BigIntegerExtendHigh1_128, 'bi128_extend_bi64_high', \
         BigIntegerExtendHigh1_256, 'bi256_extend_bi128_high', \
         BigIntegerExtendHigh1_512, 'bi512_extend_bi256_high', \
\
         BigIntegerExtendHigh2_128, 'bi128_extend_bi32_high', \
         BigIntegerExtendHigh2_256, 'bi256_extend_bi64_high', \
         BigIntegerExtendHigh2_512, 'bi512_extend_bi128_high', \
\
         BigIntegerExtendHighU64_128, 'bi128_extend_u64_high', \
         BigIntegerExtendHighU64_256, 'bi256_extend_u64_high', \
         BigIntegerExtendHighU64_512, 'bi512_extend_u64_high', \
\
         BigIntegerExtendLow1_128, 'bi128_extend_bi64_low', \
         BigIntegerExtendLow1_256, 'bi256_extend_bi128_low', \
         BigIntegerExtendLow1_512, 'bi512_extend_bi256_low', \
\
         BigIntegerExtendLow2_128, 'bi128_extend_bi32_low', \
         BigIntegerExtendLow2_256, 'bi256_extend_bi64_low', \
         BigIntegerExtendLow2_512, 'bi512_extend_bi128_low', \
\
         BigIntegerExtendLowU64_128, 'bi128_extend_u64_low', \
         BigIntegerExtendLowU64_256, 'bi256_extend_u64_low', \
         BigIntegerExtendLowU64_512, 'bi512_extend_u64_low', \
\
         BigIntegerRnd_128, 'bi128_rnd', \
         BigIntegerRnd_256, 'bi256_rnd', \
         BigIntegerRnd_512, 'bi512_rnd', \
\
         BigIntegerSub_128, 'bi128_sub', \
         BigIntegerSub_256, 'bi256_sub', \
         BigIntegerSub_512, 'bi512_sub', \
\
         BigIntegerZero_128, 'bi128_zero', \
         BigIntegerZero_256, 'bi256_zero', \
         BigIntegerZero_512, 'bi512_zero'
