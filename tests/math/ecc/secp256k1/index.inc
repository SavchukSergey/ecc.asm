include 'secp256k1_get_affine_point_test.inc'

align 16
__secp256k1_tests:
    dq __secp256k1_get_affine_point_test
    db 'secp256k1_get_affine_point', 0
    dq 0