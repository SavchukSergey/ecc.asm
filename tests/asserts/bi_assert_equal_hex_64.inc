if ~ definite bi_assert_equal_hex_64

include '../../src/math/bigint/hex/bi_try_read_hex_64.inc'

;Asserts two bi64 values to be equal
;input
;  rcx - expected hex
;  rdx - actual
bi_assert_equal_hex_64:
virtual at rsp
  label .locals_start
    .expected rb __BIG_INTEGER_BYTES_64
    .expected_hex rq 1
    .actual rq 1
  label .locals_end
end virtual
        enter   .locals_end - .locals_start, 0
        mov     [.expected_hex], rcx
        mov     [.actual], rdx

        mov     rcx, [.expected_hex]
        lea     rdx, [.expected]
        call    bi_try_read_hex_64
        
        mov     rcx, qword [.expected]
        mov     rdx, qword [.actual]
        call    bi_assert_equal_64

        leave
        ret

end if