struct TestContext
  measure_start rq 1
  measure_end rq 1
ends

get_cpu_timestamp:
        push    rcx rdx
        rdtscp
        shl     rdx, 32
        or      rdx, rax
        mov     rdx, rax
        pop     rdx rcx
        ret

test_context_init:
virtual at r8
  .context TestContext
end virtual
        mov     qword [.context.measure_start], 0
        mov     qword [.context.measure_end], 0
        ret

test_context_start_measure:
virtual at r8
  .context TestContext
end virtual
        push    rax
        pushfq
        call    get_cpu_timestamp
        mov     [.context.measure_start], rax
        popfq
        pop     rax
        ret

test_context_end_measure:
virtual at r8
  .context TestContext
end virtual
        push    rax
        pushfq
        call    get_cpu_timestamp
        mov     [.context.measure_end], rax
        popfq
        pop     rax
        ret


