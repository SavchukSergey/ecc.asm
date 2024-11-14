# ecc.asm tests

# Cpu Info

12th Gen Intel(R) Core(TM) i5-12600K
## bi_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_zero_128 | :heavy_check_mark: | 0 | 6 | N/A |
| bi_zero_192 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_zero_256 | :heavy_check_mark: | 15 | 22 | 200.00 mops |
| bi_zero_512 | :heavy_check_mark: | 15 | 20 | 200.00 mops |
| bi_zero_1024 | :heavy_check_mark: | 17 | 33 | 176.47 mops |

## bi_copy
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_copy_128 | :heavy_check_mark: | 16 | 36 | 187.50 mops |
| bi_copy_192 | :heavy_check_mark: | 16 | 34 | 187.50 mops |
| bi_copy_256 | :heavy_check_mark: | 15 | 23 | 200.00 mops |
| bi_copy_512 | :heavy_check_mark: | 16 | 23 | 187.50 mops |
| bi_copy_768 | :heavy_check_mark: | 16 | 33 | 187.50 mops |

## bi_is_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_is_zero_256 | :heavy_check_mark: | 14 | 24 | 214.28 mops |
| bi_is_zero_512 | :heavy_check_mark: | 15 | 369 | 200.00 mops |

## bi_rnd
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_rnd_64 | :heavy_check_mark: | 5252 | 6915 | 571.21 kops |
| bi_rnd_128 | :heavy_check_mark: | 13102 | 13804 | 228.97 kops |
| bi_rnd_192 | :heavy_check_mark: | 19783 | 20013 | 151.64 kops |
| bi_rnd_256 | :heavy_check_mark: | 26442 | 29093 | 113.45 kops |
| bi_rnd_320 | :heavy_check_mark: | 33129 | 33385 | 90.55 kops |
| bi_rnd_384 | :heavy_check_mark: | 39790 | 48617 | 75.39 kops |
| bi_rnd_448 | :heavy_check_mark: | 46000 | 46724 | 65.21 kops |
| bi_rnd_512 | :heavy_check_mark: | 53058 | 56245 | 56.54 kops |

## bi_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_add_128_128 | :heavy_check_mark: | 2 | 385 | 1.50 gops |
| bi_add_192_192 | :heavy_check_mark: | 2 | 155 | 1.50 gops |
| bi_add_256_256 | :heavy_check_mark: | 1 | 211 | 3.00 gops |
| bi_add_512_512 | :heavy_check_mark: | 0 | 24 | N/A |

## bi_sub
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_sub_128_128 | :heavy_check_mark: | 0 | 60 | N/A |
| bi_sub_192_192 | :heavy_check_mark: | 0 | 102 | N/A |
| bi_sub_256_256 | :heavy_check_mark: | 0 | 209 | N/A |
| bi_sub_512_512 | :heavy_check_mark: | 0 | 29 | N/A |

## bi_lzcnt
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_lzcnt_128 | :heavy_check_mark: | 0 | 10 | N/A |
| bi_lzcnt_192 | :heavy_check_mark: | 0 | 8 | N/A |
| bi_lzcnt_256 | :heavy_check_mark: | 0 | 9 | N/A |

## bi_shl
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_shl_assign_128_1 | :heavy_check_mark: | 1 | 70 | 3.00 gops |
| bi_shl_assign_128 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_shl_assign_256_1 | :heavy_check_mark: | 0 | 17 | N/A |
| bi_shl_assign_256_64 | :heavy_check_mark: | 14 | 14 | 214.28 mops |
| bi_shl_assign_256_128 | :heavy_check_mark: | 12 | 16 | 250.00 mops |
| bi_shl_assign_256 | :heavy_check_mark: | 6 | 12 | 500.00 mops |
| bi_shl_assign_512_1 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_shl_assign_512_64 | :heavy_check_mark: | 0 | 3 | N/A |
| bi_shl_assign_512_128 | :heavy_check_mark: | 13 | 17 | 230.76 mops |
| bi_shl_assign_512_256 | :heavy_check_mark: | 13 | 17 | 230.76 mops |
| bi_shl_assign_512 | :heavy_check_mark: | 18 | 50 | 166.66 mops |

## bi_shr
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_shr_assign_128_1 | :heavy_check_mark: | 18 | 18 | 166.66 mops |
| bi_shr_assign_128 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_shr_assign_256_1 | :heavy_check_mark: | 1 | 34 | 3.00 gops |
| bi_shr_assign_256_64 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shr_assign_256_128 | :heavy_check_mark: | 11 | 17 | 272.72 mops |
| bi_shr_assign_256 | :heavy_check_mark: | 4 | 11 | 750.00 mops |
| bi_shr_assign_512_1 | :heavy_check_mark: | 0 | 5 | N/A |
| bi_shr_assign_512_64 | :heavy_check_mark: | 1 | 1 | 3.00 gops |
| bi_shr_assign_512_128 | :heavy_check_mark: | 13 | 21 | 230.76 mops |
| bi_shr_assign_512_256 | :heavy_check_mark: | 11 | 18 | 272.72 mops |
| bi_shr_assign_512 | :heavy_check_mark: | 23 | 32 | 130.43 mops |

## bi_cmp
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_cmp_128_128 | :heavy_check_mark: | 4 | 4 | 750.00 mops |
| bi_cmp_192_192 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_cmp_256_256 | :heavy_check_mark: | 0 | 3 | N/A |
| bi_cmp_512_512 | :heavy_check_mark: | 2 | 9 | 1.50 gops |

## bi_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mul_128_64 | :heavy_check_mark: | 447 | 447 | 6.71 mops |
| bi_mul_128_128 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_mul_192_64 | :heavy_check_mark: | 0 | 3 | N/A |
| bi_mul_256_64 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_mul_256_128 | :heavy_check_mark: | 11 | 43 | 272.72 mops |
| bi_mul_256_256 | :heavy_check_mark: | 35 | 58 | 85.71 mops |
| bi_mul_320_64 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_mul_512_64 | :heavy_check_mark: | 2 | 8 | 1.50 gops |
| bi_mul_512_256 | :heavy_check_mark: | 64 | 106 | 46.87 mops |
| bi_mul_512_512 | :heavy_check_mark: | 210 | 230 | 14.28 mops |

## bi_mul_low
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mul_128_64_low_128 | :heavy_check_mark: | 0 | 6 | N/A |
| bi_mul_128_128_low_128 | :heavy_check_mark: | 2 | 4 | 1.50 gops |
| bi_mul_192_64_low_192 | :heavy_check_mark: | 0 | 6 | N/A |
| bi_mul_256_64_low_256 | :heavy_check_mark: | 0 | 617 | N/A |
| bi_mul_256_128_low_256 | :heavy_check_mark: | 8 | 23 | 375.00 mops |
| bi_mul_256_256_low_256 | :heavy_check_mark: | 5 | 10 | 600.00 mops |
| bi_mul_512_64_low_512 | :heavy_check_mark: | 2 | 7 | 1.50 gops |
| bi_mul_512_512_low_512 | :heavy_check_mark: | 67 | 86 | 44.77 mops |

## bi_square
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_square_128 | :heavy_check_mark: | 2 | 7 | 1.50 gops |
| bi_square_256 | :heavy_check_mark: | 46 | 69 | 65.21 mops |

## bi_div_rem
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_div_rem_128_64 | :heavy_check_mark: | 6 | 13 | 500.00 mops |
| bi_div_rem_128_128 | :heavy_check_mark: | 1 | 43 | 3.00 gops |
| bi_div_rem_192_64 | :heavy_check_mark: | 14 | 19 | 214.28 mops |
| bi_div_rem_192_128 | :heavy_check_mark: | 53 | 142 | 56.60 mops |
| bi_div_rem_192_192 | :heavy_check_mark: | 26 | 1580 | 115.38 mops |
| bi_div_rem_256_64 | :heavy_check_mark: | 22 | 30 | 136.36 mops |
| bi_div_rem_256_128 | :heavy_check_mark: | 91 | 205 | 32.96 mops |
| bi_div_rem_256_192 | :heavy_check_mark: | 96 | 135 | 31.25 mops |
| bi_div_rem_256_256 | :heavy_check_mark: | 28 | 132 | 107.14 mops |
| bi_div_rem_320_64 | :heavy_check_mark: | 30 | 37 | 100.00 mops |
| bi_div_rem_320_128 | :heavy_check_mark: | 155 | 323 | 19.35 mops |
| bi_div_rem_320_192 | :heavy_check_mark: | 97 | 217 | 30.92 mops |
| bi_div_rem_320_256 | :heavy_check_mark: | 52 | 827 | 57.69 mops |
| bi_div_rem_320_320 | :heavy_check_mark: | 49 | 83 | 61.22 mops |
| bi_div_rem_384_64 | :heavy_check_mark: | 37 | 45 | 81.08 mops |
| bi_div_rem_384_128 | :heavy_check_mark: | 191 | 489 | 15.70 mops |
| bi_div_rem_384_192 | :heavy_check_mark: | 238 | 639 | 12.60 mops |
| bi_div_rem_448_64 | :heavy_check_mark: | 45 | 50 | 66.66 mops |
| bi_div_rem_448_128 | :heavy_check_mark: | 383 | 492 | 7.83 mops |
| bi_div_rem_512_64 | :heavy_check_mark: | 54 | 600 | 55.55 mops |
| bi_div_rem_512_128 | :heavy_check_mark: | 427 | 6370 | 7.02 mops |
| bi_div_rem_512_256 | :heavy_check_mark: | 266 | 991 | 11.27 mops |
| bi_div_rem_512_512 | :heavy_check_mark: | 52 | 90 | 57.69 mops |
| bi_rem_128_64 | :heavy_check_mark: | 6 | 14 | 500.00 mops |
| bi_rem_128_128 | :heavy_check_mark: | 0 | 475 | N/A |
| bi_rem_192_64 | :heavy_check_mark: | 14 | 371 | 214.28 mops |
| bi_rem_192_128 | :heavy_check_mark: | 53 | 4581 | 56.60 mops |
| bi_rem_192_192 | :heavy_check_mark: | 28 | 981 | 107.14 mops |
| bi_rem_256_64 | :heavy_check_mark: | 25 | 699 | 120.00 mops |
| bi_rem_256_128 | :heavy_check_mark: | 75 | 237 | 40.00 mops |
| bi_rem_256_192 | :heavy_check_mark: | 87 | 695 | 34.48 mops |
| bi_rem_256_256 | :heavy_check_mark: | 29 | 632 | 103.44 mops |
| bi_rem_320_64 | :heavy_check_mark: | 29 | 39 | 103.44 mops |
| bi_rem_320_128 | :heavy_check_mark: | 127 | 825 | 23.62 mops |
| bi_rem_320_192 | :heavy_check_mark: | 80 | 211 | 37.50 mops |
| bi_rem_320_256 | :heavy_check_mark: | 49 | 120 | 61.22 mops |
| bi_rem_320_320 | :heavy_check_mark: | 49 | 79 | 61.22 mops |
| bi_rem_384_64 | :heavy_check_mark: | 37 | 44 | 81.08 mops |
| bi_rem_384_128 | :heavy_check_mark: | 151 | 391 | 19.86 mops |
| bi_rem_384_192 | :heavy_check_mark: | 199 | 966 | 15.07 mops |
| bi_rem_448_64 | :heavy_check_mark: | 45 | 53 | 66.66 mops |
| bi_rem_448_128 | :heavy_check_mark: | 280 | 439 | 10.71 mops |
| bi_rem_448_192 | :heavy_check_mark: | 278 | 404 | 10.79 mops |
| bi_rem_512_64 | :heavy_check_mark: | 54 | 944 | 55.55 mops |
| bi_rem_512_128 | :heavy_check_mark: | 311 | 1650 | 9.64 mops |
| bi_rem_512_256 | :heavy_check_mark: | 184 | 365 | 16.30 mops |
| bi_rem_512_512 | :heavy_check_mark: | 50 | 121 | 60.00 mops |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_add_assign_256_256 | :heavy_check_mark: | 3 | 17 | 1.00 gops |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_double_assign_256 | :heavy_check_mark: | 2 | 33 | 1.50 gops |

## bi_mod_tripple
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_tripple_assign_256 | :heavy_check_mark: | 0 | 107 | N/A |

## bi_mod_half
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_half_assign_256 | :heavy_check_mark: | 4 | 48 | 750.00 mops |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_sub_256_256 | :heavy_check_mark: | 16 | 588 | 187.50 mops |
| bi_mod_sub_assign_256_256 | :heavy_check_mark: | 0 | 17 | N/A |

## bi_mod_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_mul_256_256 | :heavy_check_mark: | 84 | 311 | 35.71 mops |

## bi_mod_div
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_div_256_256 | :heavy_check_mark: | 10328 | 19293 | 290.47 kops |

## bi_mod_square
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_square_256 | :heavy_check_mark: | 77 | 944 | 38.96 mops |

## bi_mod_cube
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_cube_256 | :heavy_check_mark: | 228 | 1193 | 13.15 mops |

## bi_mod_pow
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_pow_256 | :heavy_check_mark: | 108965 | 118598 | 27.53 kops |

## bi_mod_inverse
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_inverse_256 | :heavy_check_mark: | 10899 | 12178 | 275.25 kops |
| bi_mod_inverse_512 | :heavy_check_mark: | 21373 | 31233 | 140.36 kops |

## bi_mont
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mont_ctx_256_init | :heavy_check_mark: | 3259 | 3901 | 920.52 kops |
| bi_mont_ctx_256_convert | :heavy_check_mark: | 87 | 323 | 34.48 mops |
| bi_mont_ctx_256_redc_256 | :heavy_check_mark: | 76 | 289 | 39.47 mops |
| bi_mont_ctx_256_redc_512 | :heavy_check_mark: | 74 | 96 | 40.54 mops |
| bi_mont_ctx_256_mul | :heavy_check_mark: | 119 | 140 | 25.21 mops |
| bi_mont_ctx_256_square | :heavy_check_mark: | 115 | 138 | 26.08 mops |
| bi_mont_ctx_256_cube | :heavy_check_mark: | 243 | 925 | 12.34 mops |
| bi_mont_ctx_256_pow | :heavy_check_mark: | 32849 | 53400 | 91.32 kops |

## ec_affine_point
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| ec_affine_point_256_copy | :heavy_check_mark: | 12 | 22 | 250.00 mops |
| ec_affine_point_256_double | :heavy_check_mark: | 11686 | 13736 | 256.71 kops |
| ec_affine_point_256_shl | :heavy_check_mark: | 21 | 30051 | 142.85 mops |
| ec_affine_point_256_add | :heavy_check_mark: | 12412 | 13662 | 241.70 kops |
| ec_affine_point_256_sub | :heavy_check_mark: | 12431 | 13210 | 241.33 kops |
| ec_affine_point_256_mul | :heavy_check_mark: | 4134315 | 4607594 | 725 ops |
| ec_affine_point_256_negate | :heavy_check_mark: | 22 | 52 | 136.36 mops |

## ec_projective_point
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| ec_projective_point_256_copy | :heavy_check_mark: | 14 | 52 | 214.28 mops |
| ec_projective_point_256_double | :heavy_check_mark: | 3021 | 4284 | 993.04 kops |
| ec_projective_point_256_shl | :heavy_check_mark: | 19 | 7412 | 157.89 mops |
| ec_projective_point_256_add | :heavy_check_mark: | 3909 | 4604 | 767.45 kops |
| ec_projective_point_256_sub | :heavy_check_mark: | 3937 | 4713 | 762.00 kops |
| ec_projective_point_256_mul | :heavy_check_mark: | 1254804 | 1391655 | 2.39 kops |
| ec_projective_point_256_negate | :heavy_check_mark: | 22 | 52 | 136.36 mops |
| ec_projective_point_256_from_affine_point | :heavy_check_mark: | 21 | 396 | 142.85 mops |
| ec_projective_point_256_to_affine_point | :heavy_check_mark: | 11315 | 12446 | 265.13 kops |

## ec_projective_mont_point
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| ec_projective_mont_point_256_copy | :heavy_check_mark: | 13 | 45 | 230.76 mops |
| ec_projective_mont_point_256_double | :heavy_check_mark: | 1486 | 2107 | 2.01 mops |
| ec_projective_mont_point_256_shl | :heavy_check_mark: | 28 | 4756 | 107.14 mops |
| ec_projective_mont_point_256_add | :heavy_check_mark: | 1598 | 3776 | 1.87 mops |
| ec_projective_mont_point_256_sub | :heavy_check_mark: | 1613 | 1930 | 1.85 mops |
| ec_projective_mont_point_256_mul | :heavy_check_mark: | 590258 | 634612 | 5.08 kops |
| ec_projective_mont_point_256_negate | :heavy_check_mark: | 16 | 382 | 187.50 mops |
| ec_projective_mont_point_256_from_affine_point | :heavy_check_mark: | 209 | 302 | 14.35 mops |
| ec_projective_mont_point_256_to_affine_point | :heavy_check_mark: | 11073 | 12539 | 270.92 kops |
| ec_projective_mont_point_256_from_projective_point | :heavy_check_mark: | 291 | 478 | 10.30 mops |
| ec_projective_mont_point_256_to_projective_point | :heavy_check_mark: | 197 | 215 | 15.22 mops |

