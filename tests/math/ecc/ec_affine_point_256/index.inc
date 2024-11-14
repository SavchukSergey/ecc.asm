include 'ec_affine_point_256_copy_test.inc'
include 'ec_affine_point_256_add_test.inc'
include 'ec_affine_point_256_sub_test.inc'
include 'ec_affine_point_256_double_test.inc'
include 'ec_affine_point_256_shl_test.inc'
include 'ec_affine_point_256_mul_test.inc'
include 'ec_affine_point_256_negate_test.inc'

align 16
__ec_affine_point_tests:
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
    dq 0