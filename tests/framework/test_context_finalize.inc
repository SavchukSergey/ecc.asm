if ~ definite test_context_finalize

test_context_finalize:
virtual at TestContextReg
  .context TestContext
end virtual
        push    rdx
        xor     rdx, rdx
        mov     rax, [.context.measures_total]
        cmp     qword [.context.measures_count], 0
        jz      .empty
        div     qword [.context.measures_count]
.empty:
        mov     [.context.measures_avg], rax
        pop     rdx
        ret

end if