include 'ecc/index.inc'

align 16
__ecc_tests:
        dq __ec_affine_point_256_copy_test
        db 'ec_affine_point_256_copy', 0
        dq __ec_affine_point_256_double_test
        db 'ec_affine_point_256_double', 0
        dq __ec_affine_point_256_shl_test
        db 'ec_affine_point_256_shl', 0
        dq __ec_affine_point_256_add_test
        db 'ec_affine_point_256_add', 0
        dq __ec_affine_point_256_sub_test
        db 'ec_affine_point_256_sub', 0
        dq __ec_affine_point_256_mul_test
        db 'ec_affine_point_256_mul', 0
        dq __ec_affine_point_256_negate_test
        db 'ec_affine_point_256_negate', 0

        dq __ec_projective_point_256_copy_test
        db 'ec_projective_point_256_copy', 0
        dq __ec_projective_point_256_double_test
        db 'ec_projective_point_256_double', 0
        dq __ec_projective_point_256_shl_test
        db 'ec_projective_point_256_shl', 0
        dq __ec_projective_point_256_add_test
        db 'ec_projective_point_256_add', 0
        dq __ec_projective_point_256_sub_test
        db 'ec_projective_point_256_sub', 0
        dq __ec_projective_point_256_mul_test
        db 'ec_projective_point_256_mul', 0
        dq __ec_projective_point_256_negate_test
        db 'ec_projective_point_256_negate', 0
        dq __ec_projective_point_256_from_affine_point_test
        db 'ec_projective_point_256_from_affine_point', 0
        dq __ec_projective_point_256_to_affine_point_test
        db 'ec_projective_point_256_to_affine_point', 0

        dq __ec_projective_mont_point_256_copy_test
        db 'ec_projective_mont_point_256_copy', 0
        dq __ec_projective_mont_point_256_double_test
        db 'ec_projective_mont_point_256_double', 0
        dq __ec_projective_mont_point_256_shl_test
        db 'ec_projective_mont_point_256_shl', 0
        dq __ec_projective_mont_point_256_add_test
        db 'ec_projective_mont_point_256_add', 0
        dq __ec_projective_mont_point_256_sub_test
        db 'ec_projective_mont_point_256_sub', 0
        dq __ec_projective_mont_point_256_mul_test
        db 'ec_projective_mont_point_256_mul', 0
        dq __ec_projective_mont_point_256_negate_test
        db 'ec_projective_mont_point_256_negate', 0
        dq __ec_projective_mont_point_256_from_affine_point_test
        db 'ec_projective_mont_point_256_from_affine_point', 0
        dq __ec_projective_mont_point_256_to_affine_point_test
        db 'ec_projective_mont_point_256_to_affine_point', 0
        dq __ec_projective_mont_point_256_from_projective_point_test
        db 'ec_projective_mont_point_256_from_projective_point', 0
        dq __ec_projective_mont_point_256_to_projective_point_test
        db 'ec_projective_mont_point_256_to_projective_point', 0

        dq 0

