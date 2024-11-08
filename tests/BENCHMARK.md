# ecc.asm tests

## bi_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_zero_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 1 | 2 |
| bi_zero_192 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 1 | 6 |
| bi_zero_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 0 | 0 |
| bi_zero_512 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 2 | 2 |
| bi_zero_1024 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 4 | 4 |

## bi_copy
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_copy_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 0 | 0 |
| bi_copy_192 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 1 | 1 |
| bi_copy_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 1 | 1 |
| bi_copy_512 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 2 | 21 |

## bi_is_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_is_zero_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 0 | 4 |
| bi_is_zero_512 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 0 | 0 |

## bi_rnd
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_rnd_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 6642 | 7223 |
| bi_rnd_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 13298 | 14997 |
| bi_rnd_192 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 19949 | 20740 |
| bi_rnd_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 26600 | 27422 |
| bi_rnd_320 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 33250 | 33471 |
| bi_rnd_384 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 39902 | 112523 |
| bi_rnd_448 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 46554 | 57399 |
| bi_rnd_512 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 53203 | 56929 |

## bi_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_add_128_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 0 | 6 |
| bi_add_192_192 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 1 | 1 |
| bi_add_256_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 1 | 2 |
| bi_add_512_512 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 3 | 4 |

## bi_sub
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_sub_128_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 0 | 7 |
| bi_sub_192_192 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 1 | 3 |
| bi_sub_256_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 1 | 3 |
| bi_sub_512_512 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 3 | 6 |

## bi_lzcnt
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_lzcnt_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 0 | 6 |
| bi_lzcnt_192 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 0 | 33 |
| bi_lzcnt_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 0 | 1 |

## bi_shl
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_shl_assign_128_1 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 3 | 3 |
| bi_shl_assign_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 2 | 3 |
| bi_shl_assign_256_1 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 3 | 4 |
| bi_shl_assign_256_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 0 | 1 |
| bi_shl_assign_256_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 0 | 0 |
| bi_shl_assign_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 8 | 8 |
| bi_shl_assign_512_1 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 5 | 5 |
| bi_shl_assign_512_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 3 | 3 |
| bi_shl_assign_512_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 2 | 2 |
| bi_shl_assign_512_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 2 | 2 |
| bi_shl_assign_512 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 3 | 4 |

## bi_shr
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_shr_assign_128_1 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 3 | 4 |
| bi_shr_assign_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 3 | 3 |
| bi_shr_assign_256_1 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 3 | 10 |
| bi_shr_assign_256_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 0 | 1 |
| bi_shr_assign_256_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 0 | 0 |
| bi_shr_assign_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 6 | 6 |
| bi_shr_assign_512_1 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 5 | 5 |
| bi_shr_assign_512_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 3 | 10 |
| bi_shr_assign_512_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 2 | 2 |
| bi_shr_assign_512_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 2 | 2 |
| bi_shr_assign_512 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 7 | 7 |

## bi_cmp
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_cmp_128_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 0 | 1 |
| bi_cmp_192_192 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 1 | 1 |
| bi_cmp_256_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 2 | 2 |
| bi_cmp_512_512 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 5 | 5 |

## bi_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_mul_128_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 1 | 10 |
| bi_mul_128_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 4 | 4 |
| bi_mul_192_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 2 | 2 |
| bi_mul_256_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 3 | 10 |
| bi_mul_256_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 16 | 23 |
| bi_mul_256_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 40 | 49 |
| bi_mul_320_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 4 | 10 |
| bi_mul_512_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 7 | 14 |
| bi_mul_512_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 70 | 79 |
| bi_mul_512_512 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 204 | 219 |

## bi_mul_low
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_mul_128_64_low_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 0 | 1 |
| bi_mul_128_128_low_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 2 | 2 |
| bi_mul_192_64_low_192 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 2 | 9 |
| bi_mul_256_64_low_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 3 | 3 |
| bi_mul_256_128_low_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 13 | 19 |
| bi_mul_256_256_low_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 9 | 16 |
| bi_mul_512_64_low_512 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 6 | 7 |
| bi_mul_512_512_low_512 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 67 | 74 |

## bi_square
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_square_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 2 | 2 |
| bi_square_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 34 | 99 |

## bi_div_rem
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_div_rem_128_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 14 | 136 |
| bi_div_rem_128_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 1 | 17 |
| bi_div_rem_192_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 22 | 35 |
| bi_div_rem_192_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 38 | 159 |
| bi_div_rem_192_192 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 10 | 48 |
| bi_div_rem_256_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 30 | 39 |
| bi_div_rem_256_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 69 | 1099 |
| bi_div_rem_256_192 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 79 | 121 |
| bi_div_rem_256_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 14 | 79 |
| bi_div_rem_320_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 38 | 219 |
| bi_div_rem_320_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 147 | 271 |
| bi_div_rem_320_192 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 74 | 184 |
| bi_div_rem_384_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 46 | 53 |
| bi_div_rem_384_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 160 | 448 |
| bi_div_rem_448_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 55 | 63 |
| bi_div_rem_448_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 402 | 479 |
| bi_div_rem_512_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 60 | 78 |
| bi_div_rem_512_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 410 | 5593 |
| bi_div_rem_512_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 235 | 1837 |
| bi_div_rem_512_512 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 41 | 234 |
| bi_rem_128_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 14 | 6275 |
| bi_rem_128_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 1 | 17 |
| bi_rem_192_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 22 | 163 |
| bi_rem_192_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 33 | 141 |
| bi_rem_192_192 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 7 | 2894 |
| bi_rem_256_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 30 | 47 |
| bi_rem_256_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 62 | 198 |
| bi_rem_512_64 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 63 | 101 |
| bi_rem_512_128 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 284 | 1614 |
| bi_rem_512_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 170 | 364 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_mod_add_assign_256_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 8 | 15 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_mod_double_assign_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 12 | 22 |

## bi_mod_tripple
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_mod_tripple_assign_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 25 | 34 |

## bi_mod_half
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_mod_half_assign_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 14 | 22 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_mod_sub_256_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 5 | 8 |
| bi_mod_sub_assign_256_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 5 | 14 |

## bi_mod_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_mod_mul_256_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 64 | 291 |

## bi_mod_div
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_mod_div_256_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 10831 | 16858 |

## bi_mod_square
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_mod_square_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 63 | 266 |

## bi_mod_cube
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_mod_cube_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 239 | 958 |

## bi_mod_pow
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_mod_pow_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 104467 | 126741 |

## bi_mod_inverse
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_mod_inverse_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 11056 | 11733 |
| bi_mod_inverse_512 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 22421 | 23894 |

## bi_mont
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| bi_mont_ctx_256_init |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 3400 | 3702 |
| bi_mont_ctx_256_convert |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 67 | 119 |
| bi_mont_ctx_256_redc_256 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 60 | 71 |
| bi_mont_ctx_256_redc_512 |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 60 | 73 |
| bi_mont_ctx_256_mul |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 108 | 120 |
| bi_mont_ctx_256_square |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 101 | 116 |
| bi_mont_ctx_256_pow |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 32624 | 56946 |

## ecc
| Name                           | Status | Min CPU ticks | Max CPU ticks |
|--------------------------------|--------|---------------|---------------|
| :---                           |  :---: |         :---: |         :---: |
| ecpoint256_copy |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 2 | 2 |
| secp256k1_point_add |![Static Badge](https://img.shields.io/badge/PASSED-green?style=for-the-badge) | 12682 | 16846 |

