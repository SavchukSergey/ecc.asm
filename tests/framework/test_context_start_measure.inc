if ~ definite test_context_start_measure

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

end if