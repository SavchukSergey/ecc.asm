if ~ definite test_context_init

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

end if