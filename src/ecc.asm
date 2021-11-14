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
         BigIntegerCmp_128, 'bi128_cmp', \
         BigIntegerCmp_256, 'bi256_cmp', \
         BigIntegerCmp_512, 'bi512_cmp', \
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
