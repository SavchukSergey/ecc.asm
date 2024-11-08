if ~ definite bi_assert_equal_hex_384

;Asserts two bi384 values to be equal
;input
;  rcx - expected hex
;  rdx - actual
bi_assert_equal_hex_384:
virtual at rsp
  label .locals_start
    .expected BigInteger384
    .expected_hex rq 1
    .actual rq 1
  label .locals_end
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.expected_hex], rcx
        mov     [.actual], rdx

        mov     rcx, [.expected_hex]
        lea     rdx, [.expected]
        call    bi_try_read_hex_384
        
        lea     rcx, [.expected]
        mov     rdx, [.actual]
        call    bi_assert_equal_384

        leave
        ret

end if