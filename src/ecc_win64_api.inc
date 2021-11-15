include 'math/bigint/add/add.inc'
include 'math/bigint/bit_clear/bit_clear.inc'
include 'math/bigint/bit_set/bit_set.inc'
include 'math/bigint/cmp/cmp.inc'
include 'math/bigint/div_rem/div_rem.inc'
include 'math/bigint/extend_low/extend_low_1.inc'
include 'math/bigint/extend_low/extend_low_2.inc'
include 'math/bigint/extend_low/extend_low_u64.inc'
include 'math/bigint/extend_high/extend_high_1.inc'
include 'math/bigint/extend_high/extend_high_2.inc'
include 'math/bigint/extend_high/extend_high_u64.inc'
include 'math/bigint/rnd/rnd.inc'
include 'math/bigint/shl/shl.inc'
include 'math/bigint/shr/shr.inc'
include 'math/bigint/sub/sub.inc'
include 'math/bigint/zero/zero.inc'

macro BigIntegerWin64AddProc bits {

BigIntegerAdd bits

BigIntegerAdd_#bits:
        push     rax rbx
        mov      rax, rcx
        mov      rbx, rdx
        call     __bi_add_#bits
        pop      rbx rax
        ret
}

macro BigIntegerWin64BitClearProc bits {

BigIntegerBitClear bits

BigIntegerBitClear_#bits:
        push     rax rbx
        mov      rax, rcx
        mov      rbx, rdx
        call     __bi_bit_clear_#bits
        pop      rbx rax
        ret
}

macro BigIntegerWin64BitSetProc bits {

BigIntegerBitSet bits

BigIntegerBitSet_#bits:
        push     rax rbx
        mov      rax, rcx
        mov      rbx, rdx
        call     __bi_bit_set_#bits
        pop      rbx rax
        ret
}

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

macro BigIntegerWin64DivRemProc bits, dbits {

BigIntegerDivRem bits, dbits

BigIntegerDivRem_#bits:
        push     rax rbx rdi rsi
        mov      rax, rcx
        mov      rbx, rdx
        mov      rdi, r8
        mov      rsi, r9
        call     __bi_div_rem_#bits
        pop      rsi rdi rbx rax
        ret
}


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

macro BigIntegerWin64ExtendLowU64Proc bits {

BigIntegerExtendLowU64 bits

BigIntegerExtendLowU64_#bits:
        push     rax rdi
        mov      rax, rcx
        mov      rdi, rdx
        call     __bi_extend_low_u64_#bits
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

macro BigIntegerWin64ShlProc bits {

BigIntegerShl bits

BigIntegerShl_#bits:
        push     rax rbx
        mov      rax, rcx
        mov      rbx, rdx
        call     __bi_shl_#bits
        pop      rbx rax
        ret
}

macro BigIntegerWin64ShrProc bits {

BigIntegerShr bits

BigIntegerShr_#bits:
        push     rax rbx
        mov      rax, rcx
        mov      rbx, rdx
        call     __bi_shr_#bits
        pop      rbx rax
        ret
}

macro BigIntegerWin64SubProc bits {

BigIntegerSub bits

BigIntegerSub_#bits:
        push     rax rbx
        mov      rax, rcx
        mov      rbx, rdx
        call     __bi_sub_#bits
        pop      rbx rax
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

macro BigIntegerWin64Procs bits, dbits {
        BigIntegerWin64AddProc bits
        BigIntegerWin64BitClearProc bits
        BigIntegerWin64BitSetProc bits
        BigIntegerWin64CmpProc bits
        BigIntegerWin64DivRemProc bits, dbits
        BigIntegerWin64ExtendHigh1Proc bits
        BigIntegerWin64ExtendHigh2Proc bits
        BigIntegerWin64ExtendHighU64Proc bits
        BigIntegerWin64ExtendLow1Proc bits
        BigIntegerWin64ExtendLow2Proc bits
        BigIntegerWin64ExtendLowU64Proc bits
        BigIntegerWin64RndProc bits
        BigIntegerWin64ShlProc bits
        BigIntegerWin64ShrProc bits
        BigIntegerWin64SubProc bits
        BigIntegerWin64ZeroProc bits
}

BigIntegerWin64Procs 128, 256
BigIntegerWin64Procs 256, 512
BigIntegerWin64Procs 512, 1024