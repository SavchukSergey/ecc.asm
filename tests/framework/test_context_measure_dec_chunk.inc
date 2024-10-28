if ~ definite test_context_measure_dec_chunk

test_context_measure_dec_chunk:
virtual at TestContextReg
  .context TestContext
end virtual
        dec     [.context.measure_loop]
        ret

end if