if ~ definite ec_projective_mont_point_256_assert_equal_hex

;Asserts two ECProjectiveMontgomeryPoint256 values to be equal
;input
;  rcx - expected hex
;  rdx - pointer to actual ECProjectiveMontgomeryPoint256
ec_projective_mont_point_256_assert_equal_hex:
virtual at rsp
  label .locals_start
    .expected ECProjectiveMontgomeryPoint256
    .expected_hex rq 1
    .actual rq 1
  label .locals_end
end virtual
        sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned 'ec_projective_mont_point256_assert_assert_equal_hex'

        mov     [.expected_hex], rcx
        mov     [.actual], rdx
        mov     r8, [rdx + ECProjectiveMontgomeryPoint256.curve]

        lea     rcx, [.expected]
        mov     rdx, [.expected_hex]
        call    ec_projective_mont_point_256_try_read_hex
        
        lea     rcx, [.expected]
        mov     rdx, [.actual]
        call    ec_projective_mont_point_256_assert_equal

        add     rsp, .locals_end - .locals_start
        ret

end if