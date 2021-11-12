format pe64 console DLL
entry DllEntryPoint

include 'win64a.inc'

section '.text' code readable executable

proc DllEntryPoint hinstDLL,fdwReason,lpvReserved
        mov     eax,TRUE
        ret
endp

proc BigInteger128_Rand result
        push     rax
        mov      rax, rcx
        call     bi128_rnd
        pop      rax
endp

include 'math/bigint.inc'

section '.edata' export data readable

  export 'ecc.dll',\
         BigInteger128_Rand, 'BigInteger128_Rand'
