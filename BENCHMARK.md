# ecc.asm tests

# Cpu Info

Intel(R) Core(TM) i7-8700K CPU @ 3.70GHz
## bi_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_zero_128 | :heavy_check_mark: | 1 | 1 |
| bi_zero_192 | :heavy_check_mark: | 3 | 4 |
| bi_zero_256 | :heavy_check_mark: | 2 | 5 |
| bi_zero_512 | :heavy_check_mark: | 0 | 0 |
| bi_zero_1024 | :heavy_check_mark: | 1 | 1 |

## bi_copy
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_copy_128 | :heavy_check_mark: | 0 | 0 |
| bi_copy_192 | :heavy_check_mark: | 0 | 0 |
| bi_copy_256 | :heavy_check_mark: | 0 | 0 |
| bi_copy_512 | :heavy_check_mark: | 0 | 0 |

## bi_is_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_is_zero_256 | :heavy_check_mark: | 2 | 12 |
| bi_is_zero_512 | :heavy_check_mark: | 0 | 10 |

## bi_rnd
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_rnd_64 | :heavy_check_mark: | 5524 | 6954 |
| bi_rnd_128 | :heavy_check_mark: | 10963 | 12510 |
| bi_rnd_192 | :heavy_check_mark: | 16419 | 16788 |
| bi_rnd_256 | :heavy_check_mark: | 21893 | 22496 |
| bi_rnd_320 | :heavy_check_mark: | 27370 | 28364 |
| bi_rnd_384 | :heavy_check_mark: | 32881 | 34826 |
| bi_rnd_448 | :heavy_check_mark: | 38120 | 39052 |
| bi_rnd_512 | :heavy_check_mark: | 43788 | 46111 |

## bi_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_add_128_128 | :heavy_check_mark: | 1 | 1 |
| bi_add_192_192 | :heavy_check_mark: | 1 | 2 |
| bi_add_256_256 | :heavy_check_mark: | 0 | 1 |
| bi_add_512_512 | :heavy_check_mark: | 3 | 3 |

## bi_sub
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_sub_128_128 | :heavy_check_mark: | 2 | 2 |
| bi_sub_192_192 | :heavy_check_mark: | 0 | 0 |
| bi_sub_256_256 | :heavy_check_mark: | 1 | 1 |
| bi_sub_512_512 | :heavy_check_mark: | 4 | 5 |

## bi_lzcnt
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_lzcnt_128 | :heavy_check_mark: | 1 | 3 |
| bi_lzcnt_192 | :heavy_check_mark: | 1 | 8 |
| bi_lzcnt_256 | :heavy_check_mark: | 0 | 1 |

## bi_shl
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_shl_assign_128_1 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_128 | :heavy_check_mark: | 1 | 1 |
| bi_shl_assign_256_1 | :heavy_check_mark: | 3 | 7 |
| bi_shl_assign_256_64 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_256_128 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_256 | :heavy_check_mark: | 13 | 13 |
| bi_shl_assign_512_1 | :heavy_check_mark: | 5 | 5 |
| bi_shl_assign_512_64 | :heavy_check_mark: | 3 | 3 |
| bi_shl_assign_512_128 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_512_256 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_512 | :heavy_check_mark: | 5 | 6 |

## bi_shr
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_shr_assign_128_1 | :heavy_check_mark: | 1 | 1 |
| bi_shr_assign_128 | :heavy_check_mark: | 1 | 1 |
| bi_shr_assign_256_1 | :heavy_check_mark: | 2 | 2 |
| bi_shr_assign_256_64 | :heavy_check_mark: | 0 | 4 |
| bi_shr_assign_256_128 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_256 | :heavy_check_mark: | 13 | 13 |
| bi_shr_assign_512_1 | :heavy_check_mark: | 5 | 5 |
| bi_shr_assign_512_64 | :heavy_check_mark: | 3 | 3 |
| bi_shr_assign_512_128 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_512_256 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_512 | :heavy_check_mark: | 21 | 57 |

## bi_cmp
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_cmp_128_128 | :heavy_check_mark: | 0 | 0 |
| bi_cmp_192_192 | :heavy_check_mark: | 4 | 4 |
| bi_cmp_256_256 | :heavy_check_mark: | 5 | 6 |
| bi_cmp_512_512 | :heavy_check_mark: | 14 | 15 |

## bi_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mul_128_64 | :heavy_check_mark: | 0 | 1 |
| bi_mul_128_128 | :heavy_check_mark: | 4 | 4 |
| bi_mul_192_64 | :heavy_check_mark: | 2 | 11 |
| bi_mul_256_64 | :heavy_check_mark: | 3 | 15 |
| bi_mul_256_128 | :heavy_check_mark: | 36 | 39 |
| bi_mul_256_256 | :heavy_check_mark: | 81 | 88 |
| bi_mul_320_64 | :heavy_check_mark: | 5 | 5 |
| bi_mul_512_64 | :heavy_check_mark: | 11 | 12 |
| bi_mul_512_256 | :heavy_check_mark: | 126 | 131 |
| bi_mul_512_512 | :heavy_check_mark: | 414 | 421 |

## bi_mul_low
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mul_128_64_low_128 | :heavy_check_mark: | 0 | 0 |
| bi_mul_128_128_low_128 | :heavy_check_mark: | 2 | 2 |
| bi_mul_192_64_low_192 | :heavy_check_mark: | 1 | 2 |
| bi_mul_256_64_low_256 | :heavy_check_mark: | 4 | 5 |
| bi_mul_256_128_low_256 | :heavy_check_mark: | 28 | 33 |
| bi_mul_256_256_low_256 | :heavy_check_mark: | 13 | 14 |
| bi_mul_512_64_low_512 | :heavy_check_mark: | 11 | 11 |
| bi_mul_512_512_low_512 | :heavy_check_mark: | 145 | 151 |

## bi_square
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_square_128 | :heavy_check_mark: | 2 | 8 |
| bi_square_256 | :heavy_check_mark: | 65 | 74 |

## bi_div_rem
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_div_rem_128_64 | :heavy_check_mark: | 42 | 110 |
| bi_div_rem_128_128 | :heavy_check_mark: | 3 | 113 |
| bi_div_rem_192_64 | :heavy_check_mark: | 61 | 195 |
| bi_div_rem_192_128 | :heavy_check_mark: | 67 | 334 |
| bi_div_rem_192_192 | :heavy_check_mark: | 27 | 163 |
| bi_div_rem_256_64 | :heavy_check_mark: | 83 | 278 |
| bi_div_rem_256_128 | :heavy_check_mark: | 139 | 518 |
| bi_div_rem_256_192 | :heavy_check_mark: | 328 | 349 |
| bi_div_rem_256_256 | :heavy_check_mark: | 33 | 169 |
| bi_div_rem_320_64 | :heavy_check_mark: | 103 | 359 |
| bi_div_rem_320_128 | :heavy_check_mark: | 253 | 818 |
| bi_div_rem_320_192 | :heavy_check_mark: | 144 | 540 |
| bi_div_rem_320_256 | :heavy_check_mark: | 74 | 353 |
| bi_div_rem_320_320 | :heavy_check_mark: | 161 | 167 |
| bi_div_rem_384_64 | :heavy_check_mark: | 128 | 444 |
| bi_div_rem_384_128 | :heavy_check_mark: | 330 | 1159 |
| bi_div_rem_384_192 | :heavy_check_mark: | 425 | 840 |
| bi_div_rem_448_64 | :heavy_check_mark: | 144 | 526 |
| bi_div_rem_448_128 | :heavy_check_mark: | 655 | 1282 |
| bi_div_rem_512_64 | :heavy_check_mark: | 166 | 608 |
| bi_div_rem_512_128 | :heavy_check_mark: | 678 | 1783 |
| bi_div_rem_512_256 | :heavy_check_mark: | 422 | 1120 |
| bi_div_rem_512_512 | :heavy_check_mark: | 165 | 181 |
| bi_rem_128_64 | :heavy_check_mark: | 39 | 118 |
| bi_rem_128_128 | :heavy_check_mark: | 2 | 1480 |
| bi_rem_192_64 | :heavy_check_mark: | 61 | 193 |
| bi_rem_192_128 | :heavy_check_mark: | 55 | 317 |
| bi_rem_192_192 | :heavy_check_mark: | 23 | 321 |
| bi_rem_256_64 | :heavy_check_mark: | 82 | 276 |
| bi_rem_256_128 | :heavy_check_mark: | 116 | 482 |
| bi_rem_256_192 | :heavy_check_mark: | 316 | 340 |
| bi_rem_256_256 | :heavy_check_mark: | 34 | 206 |
| bi_rem_320_64 | :heavy_check_mark: | 103 | 361 |
| bi_rem_320_128 | :heavy_check_mark: | 182 | 699 |
| bi_rem_320_192 | :heavy_check_mark: | 119 | 530 |
| bi_rem_320_256 | :heavy_check_mark: | 64 | 342 |
| bi_rem_320_320 | :heavy_check_mark: | 155 | 167 |
| bi_rem_384_64 | :heavy_check_mark: | 124 | 449 |
| bi_rem_384_128 | :heavy_check_mark: | 248 | 962 |
| bi_rem_384_192 | :heavy_check_mark: | 320 | 760 |
| bi_rem_448_64 | :heavy_check_mark: | 144 | 527 |
| bi_rem_448_128 | :heavy_check_mark: | 405 | 1101 |
| bi_rem_448_192 | :heavy_check_mark: | 428 | 979 |
| bi_rem_512_64 | :heavy_check_mark: | 166 | 624 |
| bi_rem_512_128 | :heavy_check_mark: | 408 | 1398 |
| bi_rem_512_256 | :heavy_check_mark: | 302 | 919 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_add_assign_256_256 | :heavy_check_mark: | 11 | 25 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_double_assign_256 | :heavy_check_mark: | 28 | 38 |

## bi_mod_tripple
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_tripple_assign_256 | :heavy_check_mark: | 29 | 40 |

## bi_mod_half
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_half_assign_256 | :heavy_check_mark: | 24 | 37 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_sub_256_256 | :heavy_check_mark: | 7 | 20 |
| bi_mod_sub_assign_256_256 | :heavy_check_mark: | 9 | 23 |

## bi_mod_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_mul_256_256 | :heavy_check_mark: | 114 | 409 |

## bi_mod_div
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_div_256_256 | :heavy_check_mark: | 24329 | 29139 |

## bi_mod_square
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_square_256 | :heavy_check_mark: | 104 | 395 |

## bi_mod_cube
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_cube_256 | :heavy_check_mark: | 358 | 877 |

## bi_mod_pow
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_pow_256 | :heavy_check_mark: | 167358 | 169006 |

## bi_mod_inverse
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_inverse_256 | :heavy_check_mark: | 26548 | 26897 |
| bi_mod_inverse_512 | :heavy_check_mark: | 52277 | 52608 |

## bi_mont
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mont_ctx_256_init | :heavy_check_mark: | 6884 | 8269 |
| bi_mont_ctx_256_convert | :heavy_check_mark: | 126 | 180 |
| bi_mont_ctx_256_redc_256 | :heavy_check_mark: | 121 | 135 |
| bi_mont_ctx_256_redc_512 | :heavy_check_mark: | 119 | 134 |
| bi_mont_ctx_256_mul | :heavy_check_mark: | 207 | 220 |
| bi_mont_ctx_256_square | :heavy_check_mark: | 198 | 213 |
| bi_mont_ctx_256_pow | :heavy_check_mark: | 59760 | 96878 |

## ecc
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| ecpoint256_copy | :heavy_check_mark: | 1 | 10 |
| secp256k1_point_add | :heavy_check_mark: | 28851 | 29051 |

