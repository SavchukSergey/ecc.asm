format pe64 console DLL
entry DllEntryPoint

include 'win64a.inc'

section '.text' code readable executable

proc DllEntryPoint hinstDLL,fdwReason,lpvReserved
        mov     eax,TRUE
        ret
endp

macro BigIntegerWin64RndProc bits {
proc BigIntegerRnd_#bits result
        push     rax
        mov      rax, rcx
        call     __bi_rnd_#bits
        pop      rax
        ret
endp
}

macro BigIntegerWin64Procs bits {
        BigIntegerWin64RndProc bits
}

BigIntegerWin64Procs 128
BigIntegerWin64Procs 256
BigIntegerWin64Procs 512

include 'math/bigint.inc'

section '.edata' export data readable

  export 'ecc.dll',\
         BigIntegerRnd_128, 'bi128_rnd', \
         BigIntegerRnd_256, 'bi256_rnd', \
         BigIntegerRnd_512, 'bi512_rnd'
