struct TestContext
  measure_start rq 1
  measure_end rq 1
  measures_count rq 1
  measures_total rq 1
  measures_min rq 1
  measures_avg rq 1
ends

TestContextReg equ r12

get_cpu_timestamp:
        push    rcx rdx
        xor     rax, rax
        cpuid
;        lfence
        rdtsc
        shl     rdx, 32
        or      rdx, rax
        mov     rdx, rax
        pop     rdx rcx
        ret

test_context_init:
virtual at TestContextReg
  .context TestContext
end virtual
        mov     qword [.context.measure_start], 0
        mov     qword [.context.measure_end], 0
        mov     qword [.context.measures_count], 0
        mov     qword [.context.measures_total], 0
        mov     qword [.context.measures_min], -1
        ret

test_context_start_measure:
virtual at TestContextReg
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
virtual at TestContextReg
  .context TestContext
end virtual
        push    rax
        pushfq
        call    get_cpu_timestamp
        mov     [.context.measure_end], rax
        inc     [.context.measures_count]
        mov     rax, [.context.measure_end]
        sub     rax, [.context.measure_start]
        sub     rax, [calibration_shift]
        add     [.context.measures_total], rax

        cmp     rax, [.context.measures_min]
        jae     .longer
        mov     [.context.measures_min], rax
.longer:
        push    rdx
        xor     rdx, rdx
        mov     rax, [.context.measures_total]
        div     qword [.context.measures_count]
        mov     [.context.measures_avg], rax
        pop     rdx

        mov     qword [.context.measure_start], 0
        mov     qword [.context.measure_end], 0

        popfq
        pop     rax
        ret
