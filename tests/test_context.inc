struct TestContext
  measure_start rq 1
  measure_end rq 1
  measure_loop rq 1
  measures_count rq 1
  measures_total rq 1
  measures_min rq 1
  measures_max rq 1
  measures_avg rq 1
  assert_fails rq 1
ends

TestContextReg equ r12

get_cpu_timestamp:
        push    rbx rcx rdx
        xor     rax, rax
        cpuid
        rdtsc
        shl     rdx, 32
        or      rdx, rax
        mov     rdx, rax
        pop     rdx rcx rbx
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
        mov     qword [.context.measures_max], 0
        mov     qword [.context.assert_fails], 0
        ret

TEST_MEASURE_CHUNK = 5000

test_context_measure_dec_chunk:
virtual at TestContextReg
  .context TestContext
end virtual
        dec     [.context.measure_loop]
        ret


test_context_start_measure:
virtual at TestContextReg
  .context TestContext
end virtual
        push    rax
        pushfq
        call    get_cpu_timestamp
        mov     [.context.measure_start], rax
        mov     [.context.measure_loop], TEST_MEASURE_CHUNK
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
        mov     rax, [.context.measure_end]
        sub     rax, [.context.measure_start]
        cmp     [.context.measure_loop], TEST_MEASURE_CHUNK
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
        mov     qword [.context.measure_start], 0
        mov     qword [.context.measure_end], 0

        popfq
        pop     rax
        ret

test_context_finalize:
virtual at TestContextReg
  .context TestContext
end virtual
        push    rdx
        xor     rdx, rdx
        mov     rax, [.context.measures_total]
        div     qword [.context.measures_count]
        mov     [.context.measures_avg], rax
        pop     rdx
        ret

test_context_assert_fail:
virtual at TestContextReg
  .context TestContext
end virtual
        inc     [.context.assert_fails]
        ret