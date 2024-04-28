include '../../src/math/ecc/ecp_try_read_hex_256.inc'
include 'ecc/index.inc'

align 16
__secp256k1_tests:
        dq __ecpoint256_copy_test
        db 'ecpoint256_copy', 0
        dq __secp256k1_point_add_test
        db 'secp256k1_point_add', 0
        dq 0

