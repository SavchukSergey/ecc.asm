;@docs-ignore

if ~ definite secp256k1

align 16
secp256k1:
secp256k1_p:
  ; db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'
  dq 0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff

secp256k1_a:
  ; db '0000000000000000000000000000000000000000000000000000000000000000'
  dq 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000

secp256k1_b:
  ; db '0000000000000000000000000000000000000000000000000000000000000007'
  dq 0x0000000000000007, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000

;Generator ECAffinePoint256
secp256k1_gx:
  ; db '79be667ef9dcbbac55a06295ce870b07029bfcdb2dce28d959f2815b16f81798'
  dq 0x59f2815b16f81798, 0x029bfcdb2dce28d9, 0x55a06295ce870b07, 0x79be667ef9dcbbac
secp256k1_gy:
  ; db '483ada7726a3c4655da4fbfc0e1108a8fd17b448a68554199c47d08ffb10d4b8'
  dq 0x9c47d08ffb10d4b8, 0xfd17b448a6855419, 0x5da4fbfc0e1108a8, 0x483ada7726a3c465
dq secp256k1

secp256k1_n:
  ; db 'fffffffffffffffffffffffffffffffebaaedce6af48a03bbfd25e8cd0364141'
  dq 0xbfd25e8cd0364141, 0xbaaedce6af48a03b, 0xfffffffffffffffe, 0xffffffffffffffff

secp256k1_h:
  ; db '0000000000000000000000000000000000000000000000000000000000000001'
  dq 0x0000000000000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000

secp256k1_mont_modulus:
  ; db 'fffffffffffffffffffffffffffffffffffffffffffffffffffffffefffffc2f'
  dq 0xfffffffefffffc2f, 0xffffffffffffffff, 0xffffffffffffffff, 0xffffffffffffffff

secp256k1_mont_r:
  ; db '00000000000000000000000000000000000000000000000000000000000000010000000000000000000000000000000000000000000000000000000000000000'
  dq 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000, 0x0000000000000001, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000

secp256k1_mont_rm:
  ; db '00000000000000000000000000000000000000000000000000000001000003d1'
  dq 0x00000001000003d1, 0x0000000000000000, 0x0000000000000000, 0x0000000000000000

secp256k1_mont_mod_inv_r:
  ; db 'c9bd1905155383999c46c2c295f2b761bcb223fedc24a059d838091dd2253531'
  dq 0xd838091dd2253531, 0xbcb223fedc24a059, 0x9c46c2c295f2b761, 0xc9bd190515538399

end if