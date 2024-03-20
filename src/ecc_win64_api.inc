include 'math/bigint/extend_high/extend_high_1.inc'
include 'math/bigint/extend_high/extend_high_2.inc'
include 'math/bigint/extend_high/extend_high_u64.inc'
include 'math/bigint/rnd/rnd.inc'
include 'math/bigint/read_hex.inc'

macro BigIntegerWin64ExtendHigh1Proc bits {

BigIntegerExtendHigh1 bits

BigIntegerExtendHigh1_#bits:
        push     rax rdi
        mov      rax, rcx
        mov      rdi, rdx
        call     __bi_extend_high_#bits
        pop      rdi rax
        ret
}

macro BigIntegerWin64ExtendHigh2Proc bits {

BigIntegerExtendHigh2 bits

BigIntegerExtendHigh2_#bits:
        push     rax rdi
        mov      rax, rcx
        mov      rdi, rdx
        call     __bi_extend_high_2_#bits
        pop      rdi rax
        ret
}

macro BigIntegerWin64ExtendHighU64Proc bits {

BigIntegerExtendHighU64 bits

BigIntegerExtendHighU64_#bits:
        push     rax rdi
        mov      rax, rcx
        mov      rdi, rdx
        call     __bi_extend_high_u64_#bits
        pop      rdi rax
        ret
}


macro BigIntegerWin64ExtendLow1Proc bits {

BigIntegerExtendLow1 bits

BigIntegerExtendLow1_#bits:
        push     rax rdi
        mov      rax, rcx
        mov      rdi, rdx
        call     __bi_extend_low_#bits
        pop      rdi rax
        ret
}

macro BigIntegerWin64ExtendLow2Proc bits {

BigIntegerExtendLow2 bits

BigIntegerExtendLow2_#bits:
        push     rax rdi
        mov      rax, rcx
        mov      rdi, rdx
        call     __bi_extend_low_2_#bits
        pop      rdi rax
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


macro BigIntegerWin64Procs bits, dbits {
        BigIntegerWin64ExtendHigh1Proc bits
        BigIntegerWin64ExtendHigh2Proc bits
        BigIntegerWin64ExtendHighU64Proc bits
        BigIntegerWin64RndProc bits
}


;BigIntegerWin64Procs 128, 256
;BigIntegerWin64Procs 256, 512
;BigIntegerWin64Procs 512, 1024