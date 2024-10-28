if ~ definite ecp_assert_equal_hex_256

include '../../src/math/ecc/ecp_try_read_hex_256.inc'
include 'ecp_assert_equal_256.inc'

;Asserts two ecp256 values to be equal
;input
;  rcx - expected hex
;  rdx - actual
ecp_assert_equal_hex_256:
virtual at rsp
  label .locals_start
    .expected ECPoint256
    .expected_hex rq 1
    .actual rq 1
  label .locals_end
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.expected_hex], rcx
        mov     [.actual], rdx

        mov     rcx, [.expected_hex]
        lea     rdx, [.expected]
        call    ecp_try_read_hex_256
        
        lea     rcx, [.expected]
        mov     rdx, [.actual]
        call    ecp_assert_equal_256

        leave
        ret

end if