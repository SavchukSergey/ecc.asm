include 'math/bigint/rnd/rnd.inc'

macro BigIntegerWin64RndProc bits {

BigIntegerRnd bits

BigIntegerRnd_#bits:
        push     rax
        mov      rax, rcx
        call     __bi_rnd_#bits
        pop      rax
        ret
}


macro BigIntegerWin64Procs bits, dbits {
        BigIntegerWin64RndProc bits
}


;BigIntegerWin64Procs 128, 256
;BigIntegerWin64Procs 256, 512
;BigIntegerWin64Procs 512, 1024