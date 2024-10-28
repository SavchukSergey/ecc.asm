if ~ definite test_context_assert_fail

test_context_assert_fail:
virtual at TestContextReg
  .context TestContext
end virtual
        inc     [.context.assert_fails]
        ret

end if