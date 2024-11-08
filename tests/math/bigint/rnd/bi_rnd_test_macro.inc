if ~ definite __bi_rnd_macro

__bi_rnd_macro equ 0

macro BiRndTestCoreMacro bits {
virtual at rsp
.locals_start:
  .counter rq 1
  BigInteger .prev, bits
  GuardPreField
  BigInteger .current, bits
  GuardPostField
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned '__bi_rnd_test_core_macro'

if bits > 64
        lea      rcx, [.prev]
        Call_Zero bits
        lea      rcx, [.current]
        Call_Zero bits
else
        mov      qword [.prev], 0
        mov      qword [.current], 0
end if

        GuardInit

        mov      [.counter], 100
.loop:
if bits > 64
        lea      rcx, [.current]
        Call_Rnd bits
        lea      rcx, [.prev]
        lea      rdx, [.current]
        Call_Cmp bits, bits
else
        Call_Rnd bits
        cmp      rax, [.current]
end if
        jnz      .not_equal
        call     test_context_assert_fail
.not_equal:

if bits > 64
        lea      rcx, [.prev]
        lea      rdx, [.current]
        Call_Copy bits
else
        mov      rax, [.current]
        mov      [.prev], rax
end if
        dec      [.counter]
        jnz      .loop

        GuardCheck

        add     rsp, .locals_end - .locals_start
        ret
}

macro BiRndTestPerformanceCoreMacro bits {
virtual at rsp
.locals_start:
  BigInteger .value, bits
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned '__bi_rnd_test_performance_core_macro'

        call     test_context_start_measure
.chunk_loop:
if bits > 64
        lea      rcx, [.value]
        Call_Rnd bits
else
        Call_Rnd bits
end if
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        add     rsp, .locals_end - .locals_start
        ret
}
end if