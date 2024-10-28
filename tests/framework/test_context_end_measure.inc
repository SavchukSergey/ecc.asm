if ~ definite test_context_end_measure

test_context_end_measure:
virtual at TestContextReg
  .context TestContext
end virtual
        push    rax
        pushfq
        call    get_cpu_timestamp
        mov     [.context.measure_end], rax
        mov     rax, [.context.measure_end]
        sub     rax, [.context.measure_start]
        jc      .wrong_cpu
        cmp     qword [.context.measure_loop], TEST_MEASURE_CHUNK
        je      .single
        push    rbx
        xor     rdx, rdx
        mov     rbx, TEST_MEASURE_CHUNK
        sub     rbx, [.context.measure_loop]
        div     rbx
        pop     rbx
.single:
        sub     rax, [calibration_shift]
        jc      .overflow
.no_overflow:
        inc     [.context.measures_count]
        add     [.context.measures_total], rax

        cmp     rax, [.context.measures_min]
        jae     .longer_min
        mov     [.context.measures_min], rax
.longer_min:

        cmp     rax, [.context.measures_max]
        jbe     .shorter_max
        mov     [.context.measures_max], rax
.shorter_max:

.overflow:
.wrong_cpu:
        mov     qword [.context.measure_start], 0
        mov     qword [.context.measure_end], 0

        popfq
        pop     rax
        ret

end if