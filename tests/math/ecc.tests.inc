include 'ecc/index.inc'

align 16
__secp256k1_tests:
        dq __ec_affine_point_256_copy_test
        db 'ec_affine_point_256_copy', 0
        dq __ec_affine_point_256_double_test
        db 'ec_affine_point_256_double', 0
        dq __ec_affine_point_256_add_test
        db 'ec_affine_point_256_add', 0
        dq __ec_projective_point_256_copy_test
        db 'ec_projective_point_256_copy', 0
        dq __ec_projective_point_256_from_affine_point_test
        db 'ec_projective_point_256_from_affine_point', 0
        dq __ec_projective_point_256_to_affine_point_test
        db 'ec_projective_point_256_to_affine_point', 0
        dq 0

