if ~ definite bi_assert_equal_hex_256

include '../../src/math/bigint/hex/bi_try_read_hex_256.inc'

;Asserts two bi256 values to be equal
;input
;  rcx - expected hex
;  rdx - actual
bi_assert_equal_hex_256:
virtual at rsp
  label .locals_start
    .expected BigInteger256
    .expected_hex rq 1
    .actual rq 1
  label .locals_end
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.expected_hex], rcx
        mov     [.actual], rdx

        mov     rcx, [.expected_hex]
        lea     rdx, [.expected]
        call    bi_try_read_hex_256
        
        lea     rcx, [.expected]
        mov     rdx, [.actual]
        call    bi_assert_equal_256

        leave
        ret

end if