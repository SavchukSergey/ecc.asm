# ecc.asm tests

# Cpu Info

12th Gen Intel(R) Core(TM) i5-12600K
## bi_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_zero_128 | :heavy_check_mark: | 1 | 31 |
| bi_zero_192 | :heavy_check_mark: | 1 | 9 |
| bi_zero_256 | :heavy_check_mark: | 18 | 23 |
| bi_zero_512 | :heavy_check_mark: | 17 | 34 |
| bi_zero_1024 | :heavy_check_mark: | 18 | 24 |

## bi_copy
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_copy_128 | :heavy_check_mark: | 18 | 33 |
| bi_copy_192 | :heavy_check_mark: | 17 | 34 |
| bi_copy_256 | :heavy_check_mark: | 18 | 23 |
| bi_copy_512 | :heavy_check_mark: | 18 | 35 |
| bi_copy_768 | :heavy_check_mark: | 17 | 27 |

## bi_is_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_is_zero_256 | :heavy_check_mark: | 16 | 23 |
| bi_is_zero_512 | :heavy_check_mark: | 17 | 23 |

## bi_rnd
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_rnd_64 | :heavy_check_mark: | 6528 | 6629 |
| bi_rnd_128 | :heavy_check_mark: | 13167 | 13243 |
| bi_rnd_192 | :heavy_check_mark: | 19770 | 19914 |
| bi_rnd_256 | :heavy_check_mark: | 26469 | 26564 |
| bi_rnd_320 | :heavy_check_mark: | 32960 | 33430 |
| bi_rnd_384 | :heavy_check_mark: | 39553 | 39857 |
| bi_rnd_448 | :heavy_check_mark: | 46416 | 54429 |
| bi_rnd_512 | :heavy_check_mark: | 53015 | 59222 |

## bi_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_add_128_128 | :heavy_check_mark: | 0 | 33 |
| bi_add_192_192 | :heavy_check_mark: | 13 | 21 |
| bi_add_256_256 | :heavy_check_mark: | 0 | 5 |
| bi_add_512_512 | :heavy_check_mark: | 1 | 8 |

## bi_sub
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_sub_128_128 | :heavy_check_mark: | 0 | 11 |
| bi_sub_192_192 | :heavy_check_mark: | 0 | 69 |
| bi_sub_256_256 | :heavy_check_mark: | 0 | 3 |
| bi_sub_512_512 | :heavy_check_mark: | 0 | 8 |

## bi_lzcnt
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_lzcnt_128 | :heavy_check_mark: | 0 | 28 |
| bi_lzcnt_192 | :heavy_check_mark: | 0 | 9 |
| bi_lzcnt_256 | :heavy_check_mark: | 0 | 8 |

## bi_shl
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_shl_assign_128_1 | :heavy_check_mark: | 3 | 22 |
| bi_shl_assign_128 | :heavy_check_mark: | 0 | 7 |
| bi_shl_assign_256_1 | :heavy_check_mark: | 0 | 6 |
| bi_shl_assign_256_64 | :heavy_check_mark: | 2 | 19 |
| bi_shl_assign_256_128 | :heavy_check_mark: | 14 | 17 |
| bi_shl_assign_256 | :heavy_check_mark: | 7 | 19 |
| bi_shl_assign_512_1 | :heavy_check_mark: | 2 | 7 |
| bi_shl_assign_512_64 | :heavy_check_mark: | 0 | 3 |
| bi_shl_assign_512_128 | :heavy_check_mark: | 13 | 18 |
| bi_shl_assign_512_256 | :heavy_check_mark: | 14 | 15 |
| bi_shl_assign_512 | :heavy_check_mark: | 18 | 24 |

## bi_shr
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_shr_assign_128_1 | :heavy_check_mark: | 1 | 4 |
| bi_shr_assign_128 | :heavy_check_mark: | 1 | 8 |
| bi_shr_assign_256_1 | :heavy_check_mark: | 0 | 3 |
| bi_shr_assign_256_64 | :heavy_check_mark: | 0 | 2 |
| bi_shr_assign_256_128 | :heavy_check_mark: | 14 | 18 |
| bi_shr_assign_256 | :heavy_check_mark: | 6 | 15 |
| bi_shr_assign_512_1 | :heavy_check_mark: | 2 | 6 |
| bi_shr_assign_512_64 | :heavy_check_mark: | 0 | 4 |
| bi_shr_assign_512_128 | :heavy_check_mark: | 15 | 34 |
| bi_shr_assign_512_256 | :heavy_check_mark: | 13 | 19 |
| bi_shr_assign_512 | :heavy_check_mark: | 26 | 28 |

## bi_cmp
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_cmp_128_128 | :heavy_check_mark: | 0 | 6 |
| bi_cmp_192_192 | :heavy_check_mark: | 0 | 5 |
| bi_cmp_256_256 | :heavy_check_mark: | 0 | 5 |
| bi_cmp_512_512 | :heavy_check_mark: | 2 | 8 |

## bi_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mul_128_64 | :heavy_check_mark: | 0 | 449 |
| bi_mul_128_128 | :heavy_check_mark: | 0 | 7 |
| bi_mul_192_64 | :heavy_check_mark: | 0 | 13 |
| bi_mul_256_64 | :heavy_check_mark: | 0 | 6 |
| bi_mul_256_128 | :heavy_check_mark: | 13 | 32 |
| bi_mul_256_256 | :heavy_check_mark: | 37 | 75 |
| bi_mul_320_64 | :heavy_check_mark: | 1 | 6 |
| bi_mul_512_64 | :heavy_check_mark: | 3 | 31 |
| bi_mul_512_256 | :heavy_check_mark: | 55 | 103 |
| bi_mul_512_512 | :heavy_check_mark: | 186 | 237 |

## bi_mul_low
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mul_128_64_low_128 | :heavy_check_mark: | 0 | 5 |
| bi_mul_128_128_low_128 | :heavy_check_mark: | 0 | 4 |
| bi_mul_192_64_low_192 | :heavy_check_mark: | 0 | 5 |
| bi_mul_256_64_low_256 | :heavy_check_mark: | 0 | 5 |
| bi_mul_256_128_low_256 | :heavy_check_mark: | 10 | 21 |
| bi_mul_256_256_low_256 | :heavy_check_mark: | 7 | 12 |
| bi_mul_512_64_low_512 | :heavy_check_mark: | 3 | 13 |
| bi_mul_512_512_low_512 | :heavy_check_mark: | 67 | 424 |

## bi_square
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_square_128 | :heavy_check_mark: | 0 | 7 |
| bi_square_256 | :heavy_check_mark: | 47 | 73 |

## bi_div_rem
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_div_rem_128_64 | :heavy_check_mark: | 8 | 388 |
| bi_div_rem_128_128 | :heavy_check_mark: | 0 | 46 |
| bi_div_rem_192_64 | :heavy_check_mark: | 16 | 22 |
| bi_div_rem_192_128 | :heavy_check_mark: | 53 | 179 |
| bi_div_rem_192_192 | :heavy_check_mark: | 27 | 639 |
| bi_div_rem_256_64 | :heavy_check_mark: | 23 | 31 |
| bi_div_rem_256_128 | :heavy_check_mark: | 89 | 230 |
| bi_div_rem_256_192 | :heavy_check_mark: | 98 | 706 |
| bi_div_rem_256_256 | :heavy_check_mark: | 30 | 638 |
| bi_div_rem_320_64 | :heavy_check_mark: | 31 | 11141 |
| bi_div_rem_320_128 | :heavy_check_mark: | 152 | 400 |
| bi_div_rem_320_192 | :heavy_check_mark: | 99 | 233 |
| bi_div_rem_320_256 | :heavy_check_mark: | 53 | 225 |
| bi_div_rem_320_320 | :heavy_check_mark: | 56 | 385 |
| bi_div_rem_384_64 | :heavy_check_mark: | 40 | 48 |
| bi_div_rem_384_128 | :heavy_check_mark: | 199 | 520 |
| bi_div_rem_384_192 | :heavy_check_mark: | 250 | 347 |
| bi_div_rem_448_64 | :heavy_check_mark: | 47 | 56 |
| bi_div_rem_448_128 | :heavy_check_mark: | 384 | 510 |
| bi_div_rem_512_64 | :heavy_check_mark: | 55 | 63 |
| bi_div_rem_512_128 | :heavy_check_mark: | 422 | 1128 |
| bi_div_rem_512_256 | :heavy_check_mark: | 265 | 455 |
| bi_div_rem_512_512 | :heavy_check_mark: | 52 | 85 |
| bi_rem_128_64 | :heavy_check_mark: | 8 | 13 |
| bi_rem_128_128 | :heavy_check_mark: | 0 | 606 |
| bi_rem_192_64 | :heavy_check_mark: | 16 | 22 |
| bi_rem_192_128 | :heavy_check_mark: | 48 | 140 |
| bi_rem_192_192 | :heavy_check_mark: | 25 | 113 |
| bi_rem_256_64 | :heavy_check_mark: | 22 | 31 |
| bi_rem_256_128 | :heavy_check_mark: | 75 | 230 |
| bi_rem_256_192 | :heavy_check_mark: | 89 | 128 |
| bi_rem_256_256 | :heavy_check_mark: | 30 | 121 |
| bi_rem_320_64 | :heavy_check_mark: | 31 | 580 |
| bi_rem_320_128 | :heavy_check_mark: | 123 | 270 |
| bi_rem_320_192 | :heavy_check_mark: | 83 | 186 |
| bi_rem_320_256 | :heavy_check_mark: | 52 | 676 |
| bi_rem_320_320 | :heavy_check_mark: | 51 | 74 |
| bi_rem_384_64 | :heavy_check_mark: | 39 | 46 |
| bi_rem_384_128 | :heavy_check_mark: | 153 | 958 |
| bi_rem_384_192 | :heavy_check_mark: | 208 | 301 |
| bi_rem_448_64 | :heavy_check_mark: | 47 | 52 |
| bi_rem_448_128 | :heavy_check_mark: | 278 | 921 |
| bi_rem_448_192 | :heavy_check_mark: | 284 | 380 |
| bi_rem_512_64 | :heavy_check_mark: | 55 | 657 |
| bi_rem_512_128 | :heavy_check_mark: | 307 | 1074 |
| bi_rem_512_256 | :heavy_check_mark: | 183 | 409 |
| bi_rem_512_512 | :heavy_check_mark: | 51 | 88 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_add_assign_256_256 | :heavy_check_mark: | 9 | 51 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_double_assign_256 | :heavy_check_mark: | 2 | 386 |

## bi_mod_tripple
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_tripple_assign_256 | :heavy_check_mark: | 2 | 239 |

## bi_mod_half
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_half_assign_256 | :heavy_check_mark: | 8 | 381 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_sub_256_256 | :heavy_check_mark: | 18 | 54 |
| bi_mod_sub_assign_256_256 | :heavy_check_mark: | 3 | 24 |

## bi_mod_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_mul_256_256 | :heavy_check_mark: | 83 | 323 |

## bi_mod_div
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_div_256_256 | :heavy_check_mark: | 10294 | 13066 |

## bi_mod_square
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_square_256 | :heavy_check_mark: | 76 | 318 |

## bi_mod_cube
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_cube_256 | :heavy_check_mark: | 243 | 643 |

## bi_mod_pow
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_pow_256 | :heavy_check_mark: | 108761 | 120320 |

## bi_mod_inverse
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_inverse_256 | :heavy_check_mark: | 11004 | 12353 |
| bi_mod_inverse_512 | :heavy_check_mark: | 20438 | 24918 |

## bi_mont
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mont_ctx_256_init | :heavy_check_mark: | 3212 | 4049 |
| bi_mont_ctx_256_convert | :heavy_check_mark: | 81 | 140 |
| bi_mont_ctx_256_redc_256 | :heavy_check_mark: | 76 | 90 |
| bi_mont_ctx_256_redc_512 | :heavy_check_mark: | 76 | 96 |
| bi_mont_ctx_256_mul | :heavy_check_mark: | 111 | 486 |
| bi_mont_ctx_256_square | :heavy_check_mark: | 110 | 127 |
| bi_mont_ctx_256_pow | :heavy_check_mark: | 30030 | 47771 |

## ecc
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| ec_affine_point_256_copy | :heavy_check_mark: | 10 | 400 |
| ec_affine_point_256_double | :heavy_check_mark: | 11224 | 13710 |
| ec_affine_point_256_shl | :heavy_check_mark: | 19 | 24685 |
| ec_affine_point_256_add | :heavy_check_mark: | 11917 | 12741 |
| ec_affine_point_256_sub | :heavy_check_mark: | 12015 | 13277 |
| ec_affine_point_256_mul | :heavy_check_mark: | 4110016 | 4225802 |
| ec_affine_point_256_negate | :heavy_check_mark: | 13 | 106 |
| ec_projective_point_256_copy | :heavy_check_mark: | 15 | 47 |
| ec_projective_point_256_from_affine_point | :heavy_check_mark: | 19 | 43 |
| ec_projective_point_256_to_affine_point | :heavy_check_mark: | 10915 | 12177 |

