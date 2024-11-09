# ecc.asm tests

# Cpu Info

Intel(R) Core(TM) i7-8700K CPU @ 3.70GHz
## bi_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_zero_128 | :heavy_check_mark: | 0 | 0 |
| bi_zero_192 | :heavy_check_mark: | 0 | 0 |
| bi_zero_256 | :heavy_check_mark: | 0 | 11 |
| bi_zero_512 | :heavy_check_mark: | 0 | 0 |
| bi_zero_1024 | :heavy_check_mark: | 1 | 1 |

## bi_copy
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_copy_128 | :heavy_check_mark: | 15 | 160 |
| bi_copy_192 | :heavy_check_mark: | 3 | 30 |
| bi_copy_256 | :heavy_check_mark: | 15 | 17 |
| bi_copy_512 | :heavy_check_mark: | 0 | 0 |

## bi_is_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_is_zero_256 | :heavy_check_mark: | 0 | 9 |
| bi_is_zero_512 | :heavy_check_mark: | 0 | 1 |

## bi_rnd
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_rnd_64 | :heavy_check_mark: | 5925 | 7063 |
| bi_rnd_128 | :heavy_check_mark: | 11705 | 13146 |
| bi_rnd_192 | :heavy_check_mark: | 17696 | 19283 |
| bi_rnd_256 | :heavy_check_mark: | 22917 | 26424 |
| bi_rnd_320 | :heavy_check_mark: | 28543 | 29490 |
| bi_rnd_384 | :heavy_check_mark: | 34127 | 34765 |
| bi_rnd_448 | :heavy_check_mark: | 39947 | 42379 |
| bi_rnd_512 | :heavy_check_mark: | 45685 | 47921 |

## bi_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_add_128_128 | :heavy_check_mark: | 0 | 0 |
| bi_add_192_192 | :heavy_check_mark: | 0 | 1 |
| bi_add_256_256 | :heavy_check_mark: | 0 | 0 |
| bi_add_512_512 | :heavy_check_mark: | 3 | 7 |

## bi_sub
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_sub_128_128 | :heavy_check_mark: | 1 | 2 |
| bi_sub_192_192 | :heavy_check_mark: | 0 | 0 |
| bi_sub_256_256 | :heavy_check_mark: | 1 | 2 |
| bi_sub_512_512 | :heavy_check_mark: | 3 | 3 |

## bi_lzcnt
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_lzcnt_128 | :heavy_check_mark: | 0 | 2 |
| bi_lzcnt_192 | :heavy_check_mark: | 1 | 6 |
| bi_lzcnt_256 | :heavy_check_mark: | 0 | 2 |

## bi_shl
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_shl_assign_128_1 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_128 | :heavy_check_mark: | 3 | 3 |
| bi_shl_assign_256_1 | :heavy_check_mark: | 2 | 2 |
| bi_shl_assign_256_64 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_256_128 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_256 | :heavy_check_mark: | 14 | 19 |
| bi_shl_assign_512_1 | :heavy_check_mark: | 5 | 5 |
| bi_shl_assign_512_64 | :heavy_check_mark: | 3 | 3 |
| bi_shl_assign_512_128 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_512_256 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_512 | :heavy_check_mark: | 5 | 5 |

## bi_shr
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_shr_assign_128_1 | :heavy_check_mark: | 3 | 3 |
| bi_shr_assign_128 | :heavy_check_mark: | 2 | 2 |
| bi_shr_assign_256_1 | :heavy_check_mark: | 1 | 1 |
| bi_shr_assign_256_64 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_256_128 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_256 | :heavy_check_mark: | 14 | 20 |
| bi_shr_assign_512_1 | :heavy_check_mark: | 5 | 5 |
| bi_shr_assign_512_64 | :heavy_check_mark: | 3 | 3 |
| bi_shr_assign_512_128 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_512_256 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_512 | :heavy_check_mark: | 19 | 26 |

## bi_cmp
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_cmp_128_128 | :heavy_check_mark: | 0 | 5 |
| bi_cmp_192_192 | :heavy_check_mark: | 4 | 4 |
| bi_cmp_256_256 | :heavy_check_mark: | 5 | 6 |
| bi_cmp_512_512 | :heavy_check_mark: | 13 | 14 |

## bi_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mul_128_64 | :heavy_check_mark: | 1 | 6 |
| bi_mul_128_128 | :heavy_check_mark: | 4 | 5 |
| bi_mul_192_64 | :heavy_check_mark: | 1 | 6 |
| bi_mul_256_64 | :heavy_check_mark: | 4 | 4 |
| bi_mul_256_128 | :heavy_check_mark: | 35 | 41 |
| bi_mul_256_256 | :heavy_check_mark: | 81 | 87 |
| bi_mul_320_64 | :heavy_check_mark: | 5 | 5 |
| bi_mul_512_64 | :heavy_check_mark: | 11 | 11 |
| bi_mul_512_256 | :heavy_check_mark: | 125 | 131 |
| bi_mul_512_512 | :heavy_check_mark: | 414 | 422 |

## bi_mul_low
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mul_128_64_low_128 | :heavy_check_mark: | 1 | 2 |
| bi_mul_128_128_low_128 | :heavy_check_mark: | 1 | 1 |
| bi_mul_192_64_low_192 | :heavy_check_mark: | 1 | 1 |
| bi_mul_256_64_low_256 | :heavy_check_mark: | 3 | 3 |
| bi_mul_256_128_low_256 | :heavy_check_mark: | 28 | 28 |
| bi_mul_256_256_low_256 | :heavy_check_mark: | 12 | 13 |
| bi_mul_512_64_low_512 | :heavy_check_mark: | 11 | 11 |
| bi_mul_512_512_low_512 | :heavy_check_mark: | 144 | 151 |

## bi_square
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_square_128 | :heavy_check_mark: | 2 | 2 |
| bi_square_256 | :heavy_check_mark: | 65 | 73 |

## bi_div_rem
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_div_rem_128_64 | :heavy_check_mark: | 45 | 1478 |
| bi_div_rem_128_128 | :heavy_check_mark: | 2 | 123 |
| bi_div_rem_192_64 | :heavy_check_mark: | 60 | 194 |
| bi_div_rem_192_128 | :heavy_check_mark: | 64 | 332 |
| bi_div_rem_192_192 | :heavy_check_mark: | 28 | 162 |
| bi_div_rem_256_64 | :heavy_check_mark: | 81 | 276 |
| bi_div_rem_256_128 | :heavy_check_mark: | 140 | 515 |
| bi_div_rem_256_192 | :heavy_check_mark: | 324 | 345 |
| bi_div_rem_256_256 | :heavy_check_mark: | 33 | 182 |
| bi_div_rem_320_64 | :heavy_check_mark: | 103 | 359 |
| bi_div_rem_320_128 | :heavy_check_mark: | 253 | 817 |
| bi_div_rem_320_192 | :heavy_check_mark: | 147 | 538 |
| bi_div_rem_320_256 | :heavy_check_mark: | 75 | 351 |
| bi_div_rem_320_320 | :heavy_check_mark: | 156 | 164 |
| bi_div_rem_384_64 | :heavy_check_mark: | 124 | 443 |
| bi_div_rem_384_128 | :heavy_check_mark: | 329 | 1158 |
| bi_div_rem_384_192 | :heavy_check_mark: | 423 | 841 |
| bi_div_rem_448_64 | :heavy_check_mark: | 148 | 527 |
| bi_div_rem_448_128 | :heavy_check_mark: | 657 | 1285 |
| bi_div_rem_512_64 | :heavy_check_mark: | 167 | 610 |
| bi_div_rem_512_128 | :heavy_check_mark: | 676 | 1802 |
| bi_div_rem_512_256 | :heavy_check_mark: | 422 | 1680 |
| bi_div_rem_512_512 | :heavy_check_mark: | 168 | 240 |
| bi_rem_128_64 | :heavy_check_mark: | 40 | 157 |
| bi_rem_128_128 | :heavy_check_mark: | 3 | 114 |
| bi_rem_192_64 | :heavy_check_mark: | 61 | 193 |
| bi_rem_192_128 | :heavy_check_mark: | 55 | 349 |
| bi_rem_192_192 | :heavy_check_mark: | 23 | 319 |
| bi_rem_256_64 | :heavy_check_mark: | 84 | 277 |
| bi_rem_256_128 | :heavy_check_mark: | 121 | 488 |
| bi_rem_256_192 | :heavy_check_mark: | 321 | 335 |
| bi_rem_256_256 | :heavy_check_mark: | 32 | 161 |
| bi_rem_320_64 | :heavy_check_mark: | 103 | 1700 |
| bi_rem_320_128 | :heavy_check_mark: | 182 | 707 |
| bi_rem_320_192 | :heavy_check_mark: | 124 | 517 |
| bi_rem_320_256 | :heavy_check_mark: | 65 | 342 |
| bi_rem_320_320 | :heavy_check_mark: | 154 | 161 |
| bi_rem_384_64 | :heavy_check_mark: | 123 | 443 |
| bi_rem_384_128 | :heavy_check_mark: | 248 | 959 |
| bi_rem_384_192 | :heavy_check_mark: | 324 | 742 |
| bi_rem_448_64 | :heavy_check_mark: | 147 | 529 |
| bi_rem_448_128 | :heavy_check_mark: | 404 | 1100 |
| bi_rem_448_192 | :heavy_check_mark: | 432 | 972 |
| bi_rem_512_64 | :heavy_check_mark: | 166 | 611 |
| bi_rem_512_128 | :heavy_check_mark: | 411 | 1437 |
| bi_rem_512_256 | :heavy_check_mark: | 303 | 937 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_add_assign_256_256 | :heavy_check_mark: | 12 | 18 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_double_assign_256 | :heavy_check_mark: | 27 | 34 |

## bi_mod_tripple
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_tripple_assign_256 | :heavy_check_mark: | 29 | 37 |

## bi_mod_half
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_half_assign_256 | :heavy_check_mark: | 24 | 30 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_sub_256_256 | :heavy_check_mark: | 7 | 18 |
| bi_mod_sub_assign_256_256 | :heavy_check_mark: | 10 | 12 |

## bi_mod_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_mul_256_256 | :heavy_check_mark: | 115 | 407 |

## bi_mod_div
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_div_256_256 | :heavy_check_mark: | 28984 | 34393 |

## bi_mod_square
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_square_256 | :heavy_check_mark: | 104 | 396 |

## bi_mod_cube
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_cube_256 | :heavy_check_mark: | 357 | 854 |

## bi_mod_pow
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_pow_256 | :heavy_check_mark: | 170103 | 172170 |

## bi_mod_inverse
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_inverse_256 | :heavy_check_mark: | 26645 | 26856 |
| bi_mod_inverse_512 | :heavy_check_mark: | 55404 | 62708 |

## bi_mont
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mont_ctx_256_init | :heavy_check_mark: | 6889 | 6911 |
| bi_mont_ctx_256_convert | :heavy_check_mark: | 125 | 177 |
| bi_mont_ctx_256_redc_256 | :heavy_check_mark: | 119 | 134 |
| bi_mont_ctx_256_redc_512 | :heavy_check_mark: | 119 | 124 |
| bi_mont_ctx_256_mul | :heavy_check_mark: | 207 | 213 |
| bi_mont_ctx_256_square | :heavy_check_mark: | 198 | 208 |
| bi_mont_ctx_256_pow | :heavy_check_mark: | 59866 | 96769 |

## ecc
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| ecpoint256_copy | :heavy_check_mark: | 0 | 0 |
| secp256k1_point_add | :heavy_check_mark: | 28843 | 29701 |

