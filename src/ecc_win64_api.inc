include 'math/bigint/cmp/cmp.inc'
include 'math/bigint/rnd/rnd.inc'
include 'math/bigint/zero/zero.inc'

macro BigIntegerWin64CmpProc bits {

BigIntegerCmp bits

BigIntegerCmp_#bits:
        push     rbx
        mov      rax, rcx
        mov      rbx, rdx
        call     __bi_cmp_#bits
        pop      rbx
        ret
}


macro BigIntegerWin64RndProc bits {

BigIntegerRnd bits

BigIntegerRnd_#bits:
        push     rax
        mov      rax, rcx
        call     __bi_rnd_#bits
        pop      rax
        ret

}

macro BigIntegerWin64ZeroProc bits {

BigIntegerZero bits

BigIntegerZero_#bits:
        push     rax
        mov      rax, rcx
        call     __bi_zero_#bits
        pop      rax
        ret

}


macro BigIntegerWin64Procs bits {
        BigIntegerWin64CmpProc bits
        BigIntegerWin64RndProc bits
        BigIntegerWin64ZeroProc bits
}

BigIntegerWin64Procs 128
BigIntegerWin64Procs 256
BigIntegerWin64Procs 512