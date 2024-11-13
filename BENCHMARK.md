# ecc.asm tests

# Cpu Info

AMD Ryzen 7 4800H with Radeon Graphics         
## bi_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_zero_128 | :heavy_check_mark: | 1 | 4 | 3.00 gops |
| bi_zero_192 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_zero_256 | :heavy_check_mark: | 8 | 14 | 375.00 mops |
| bi_zero_512 | :heavy_check_mark: | 8 | 14 | 375.00 mops |
| bi_zero_1024 | :heavy_check_mark: | 8 | 14 | 375.00 mops |

## bi_copy
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_copy_128 | :heavy_check_mark: | 11 | 37 | 272.72 mops |
| bi_copy_192 | :heavy_check_mark: | 8 | 13 | 375.00 mops |
| bi_copy_256 | :heavy_check_mark: | 8 | 30 | 375.00 mops |
| bi_copy_512 | :heavy_check_mark: | 8 | 14 | 375.00 mops |
| bi_copy_768 | :heavy_check_mark: | 8 | 26 | 375.00 mops |

## bi_is_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_is_zero_256 | :heavy_check_mark: | 8 | 16 | 375.00 mops |
| bi_is_zero_512 | :heavy_check_mark: | 8 | 13 | 375.00 mops |

## bi_rnd
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_rnd_64 | :heavy_check_mark: | 9549 | 11239 | 314.16 kops |
| bi_rnd_128 | :heavy_check_mark: | 20075 | 22182 | 149.43 kops |
| bi_rnd_192 | :heavy_check_mark: | 30013 | 33126 | 99.95 kops |
| bi_rnd_256 | :heavy_check_mark: | 40568 | 43954 | 73.94 kops |
| bi_rnd_320 | :heavy_check_mark: | 50496 | 56389 | 59.41 kops |
| bi_rnd_384 | :heavy_check_mark: | 55259 | 69932 | 54.28 kops |
| bi_rnd_448 | :heavy_check_mark: | 60446 | 73790 | 49.63 kops |
| bi_rnd_512 | :heavy_check_mark: | 69388 | 89840 | 43.23 kops |

## bi_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_add_128_128 | :heavy_check_mark: | 0 | 29 | N/A |
| bi_add_192_192 | :heavy_check_mark: | 1 | 23 | 3.00 gops |
| bi_add_256_256 | :heavy_check_mark: | 1 | 6 | 3.00 gops |
| bi_add_512_512 | :heavy_check_mark: | 3 | 17 | 1.00 gops |

## bi_sub
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_sub_128_128 | :heavy_check_mark: | 1 | 43 | 3.00 gops |
| bi_sub_192_192 | :heavy_check_mark: | 0 | 6 | N/A |
| bi_sub_256_256 | :heavy_check_mark: | 1 | 77 | 3.00 gops |
| bi_sub_512_512 | :heavy_check_mark: | 3 | 8 | 1.00 gops |

## bi_lzcnt
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_lzcnt_128 | :heavy_check_mark: | 1 | 10 | 3.00 gops |
| bi_lzcnt_192 | :heavy_check_mark: | 4 | 11 | 750.00 mops |
| bi_lzcnt_256 | :heavy_check_mark: | 3 | 10 | 1.00 gops |

## bi_shl
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_shl_assign_128_1 | :heavy_check_mark: | 1 | 8 | 3.00 gops |
| bi_shl_assign_128 | :heavy_check_mark: | 1 | 7 | 3.00 gops |
| bi_shl_assign_256_1 | :heavy_check_mark: | 1 | 7 | 3.00 gops |
| bi_shl_assign_256_64 | :heavy_check_mark: | 1 | 6 | 3.00 gops |
| bi_shl_assign_256_128 | :heavy_check_mark: | 8 | 11 | 375.00 mops |
| bi_shl_assign_256 | :heavy_check_mark: | 4 | 8 | 750.00 mops |
| bi_shl_assign_512_1 | :heavy_check_mark: | 1 | 6 | 3.00 gops |
| bi_shl_assign_512_64 | :heavy_check_mark: | 1 | 7 | 3.00 gops |
| bi_shl_assign_512_128 | :heavy_check_mark: | 8 | 11 | 375.00 mops |
| bi_shl_assign_512_256 | :heavy_check_mark: | 8 | 11 | 375.00 mops |
| bi_shl_assign_512 | :heavy_check_mark: | 13 | 16 | 230.76 mops |

## bi_shr
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_shr_assign_128_1 | :heavy_check_mark: | 1 | 4 | 3.00 gops |
| bi_shr_assign_128 | :heavy_check_mark: | 1 | 6 | 3.00 gops |
| bi_shr_assign_256_1 | :heavy_check_mark: | 1 | 4 | 3.00 gops |
| bi_shr_assign_256_64 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_shr_assign_256_128 | :heavy_check_mark: | 8 | 13 | 375.00 mops |
| bi_shr_assign_256 | :heavy_check_mark: | 6 | 10 | 500.00 mops |
| bi_shr_assign_512_1 | :heavy_check_mark: | 1 | 6 | 3.00 gops |
| bi_shr_assign_512_64 | :heavy_check_mark: | 1 | 6 | 3.00 gops |
| bi_shr_assign_512_128 | :heavy_check_mark: | 8 | 13 | 375.00 mops |
| bi_shr_assign_512_256 | :heavy_check_mark: | 8 | 13 | 375.00 mops |
| bi_shr_assign_512 | :heavy_check_mark: | 19 | 49 | 157.89 mops |

## bi_cmp
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_cmp_128_128 | :heavy_check_mark: | 3 | 11 | 1.00 gops |
| bi_cmp_192_192 | :heavy_check_mark: | 1 | 11 | 3.00 gops |
| bi_cmp_256_256 | :heavy_check_mark: | 3 | 8 | 1.00 gops |
| bi_cmp_512_512 | :heavy_check_mark: | 3 | 8 | 1.00 gops |

## bi_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mul_128_64 | :heavy_check_mark: | 1 | 414 | 3.00 gops |
| bi_mul_128_128 | :heavy_check_mark: | 3 | 11 | 1.00 gops |
| bi_mul_192_64 | :heavy_check_mark: | 1 | 13 | 3.00 gops |
| bi_mul_256_64 | :heavy_check_mark: | 1 | 7 | 3.00 gops |
| bi_mul_256_128 | :heavy_check_mark: | 16 | 23 | 187.50 mops |
| bi_mul_256_256 | :heavy_check_mark: | 37 | 48 | 81.08 mops |
| bi_mul_320_64 | :heavy_check_mark: | 3 | 7 | 1.00 gops |
| bi_mul_512_64 | :heavy_check_mark: | 6 | 11 | 500.00 mops |
| bi_mul_512_256 | :heavy_check_mark: | 65 | 104 | 46.15 mops |
| bi_mul_512_512 | :heavy_check_mark: | 203 | 332 | 14.77 mops |

## bi_mul_low
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mul_128_64_low_128 | :heavy_check_mark: | 1 | 6 | 3.00 gops |
| bi_mul_128_128_low_128 | :heavy_check_mark: | 1 | 21 | 3.00 gops |
| bi_mul_192_64_low_192 | :heavy_check_mark: | 1 | 7 | 3.00 gops |
| bi_mul_256_64_low_256 | :heavy_check_mark: | 1 | 7 | 3.00 gops |
| bi_mul_256_128_low_256 | :heavy_check_mark: | 13 | 21 | 230.76 mops |
| bi_mul_256_256_low_256 | :heavy_check_mark: | 6 | 11 | 500.00 mops |
| bi_mul_512_64_low_512 | :heavy_check_mark: | 6 | 11 | 500.00 mops |
| bi_mul_512_512_low_512 | :heavy_check_mark: | 71 | 82 | 42.25 mops |

## bi_square
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_square_128 | :heavy_check_mark: | 3 | 7 | 1.00 gops |
| bi_square_256 | :heavy_check_mark: | 37 | 69 | 81.08 mops |

## bi_div_rem
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_div_rem_128_64 | :heavy_check_mark: | 10 | 68 | 300.00 mops |
| bi_div_rem_128_128 | :heavy_check_mark: | 3 | 65 | 1.00 gops |
| bi_div_rem_192_64 | :heavy_check_mark: | 20 | 84 | 150.00 mops |
| bi_div_rem_192_128 | :heavy_check_mark: | 52 | 156 | 57.69 mops |
| bi_div_rem_192_192 | :heavy_check_mark: | 23 | 91 | 130.43 mops |
| bi_div_rem_256_64 | :heavy_check_mark: | 29 | 164 | 103.44 mops |
| bi_div_rem_256_128 | :heavy_check_mark: | 79 | 248 | 37.97 mops |
| bi_div_rem_256_192 | :heavy_check_mark: | 103 | 177 | 29.12 mops |
| bi_div_rem_256_256 | :heavy_check_mark: | 30 | 842 | 100.00 mops |
| bi_div_rem_320_64 | :heavy_check_mark: | 39 | 201 | 76.92 mops |
| bi_div_rem_320_128 | :heavy_check_mark: | 153 | 313 | 19.60 mops |
| bi_div_rem_320_192 | :heavy_check_mark: | 104 | 229 | 28.84 mops |
| bi_div_rem_320_256 | :heavy_check_mark: | 66 | 142 | 45.45 mops |
| bi_div_rem_320_320 | :heavy_check_mark: | 55 | 124 | 54.54 mops |
| bi_div_rem_384_64 | :heavy_check_mark: | 48 | 210 | 62.50 mops |
| bi_div_rem_384_128 | :heavy_check_mark: | 216 | 461 | 13.88 mops |
| bi_div_rem_384_192 | :heavy_check_mark: | 268 | 413 | 11.19 mops |
| bi_div_rem_448_64 | :heavy_check_mark: | 58 | 717 | 51.72 mops |
| bi_div_rem_448_128 | :heavy_check_mark: | 327 | 513 | 9.17 mops |
| bi_div_rem_512_64 | :heavy_check_mark: | 66 | 313 | 45.45 mops |
| bi_div_rem_512_128 | :heavy_check_mark: | 378 | 1183 | 7.93 mops |
| bi_div_rem_512_256 | :heavy_check_mark: | 238 | 468 | 12.60 mops |
| bi_div_rem_512_512 | :heavy_check_mark: | 59 | 101 | 50.84 mops |
| bi_rem_128_64 | :heavy_check_mark: | 10 | 545 | 300.00 mops |
| bi_rem_128_128 | :heavy_check_mark: | 3 | 597 | 1.00 gops |
| bi_rem_192_64 | :heavy_check_mark: | 20 | 104 | 150.00 mops |
| bi_rem_192_128 | :heavy_check_mark: | 55 | 153 | 54.54 mops |
| bi_rem_192_192 | :heavy_check_mark: | 29 | 122 | 103.44 mops |
| bi_rem_256_64 | :heavy_check_mark: | 29 | 114 | 103.44 mops |
| bi_rem_256_128 | :heavy_check_mark: | 79 | 235 | 37.97 mops |
| bi_rem_256_192 | :heavy_check_mark: | 107 | 172 | 28.03 mops |
| bi_rem_256_256 | :heavy_check_mark: | 33 | 113 | 90.90 mops |
| bi_rem_320_64 | :heavy_check_mark: | 39 | 180 | 76.92 mops |
| bi_rem_320_128 | :heavy_check_mark: | 127 | 298 | 23.62 mops |
| bi_rem_320_192 | :heavy_check_mark: | 90 | 213 | 33.33 mops |
| bi_rem_320_256 | :heavy_check_mark: | 52 | 191 | 57.69 mops |
| bi_rem_320_320 | :heavy_check_mark: | 53 | 104 | 56.60 mops |
| bi_rem_384_64 | :heavy_check_mark: | 48 | 175 | 62.50 mops |
| bi_rem_384_128 | :heavy_check_mark: | 174 | 429 | 17.24 mops |
| bi_rem_384_192 | :heavy_check_mark: | 226 | 313 | 13.27 mops |
| bi_rem_448_64 | :heavy_check_mark: | 58 | 242 | 51.72 mops |
| bi_rem_448_128 | :heavy_check_mark: | 271 | 442 | 11.07 mops |
| bi_rem_448_192 | :heavy_check_mark: | 256 | 838 | 11.71 mops |
| bi_rem_512_64 | :heavy_check_mark: | 66 | 258 | 45.45 mops |
| bi_rem_512_128 | :heavy_check_mark: | 262 | 1163 | 11.45 mops |
| bi_rem_512_256 | :heavy_check_mark: | 180 | 451 | 16.66 mops |
| bi_rem_512_512 | :heavy_check_mark: | 74 | 120 | 40.54 mops |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_add_assign_256_256 | :heavy_check_mark: | 10 | 21 | 300.00 mops |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_double_assign_256 | :heavy_check_mark: | 8 | 59 | 375.00 mops |

## bi_mod_tripple
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_tripple_assign_256 | :heavy_check_mark: | 7 | 29 | 428.57 mops |

## bi_mod_half
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_half_assign_256 | :heavy_check_mark: | 8 | 30 | 375.00 mops |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_sub_256_256 | :heavy_check_mark: | 16 | 20 | 187.50 mops |
| bi_mod_sub_assign_256_256 | :heavy_check_mark: | 7 | 17 | 428.57 mops |

## bi_mod_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_mul_256_256 | :heavy_check_mark: | 79 | 290 | 37.97 mops |

## bi_mod_div
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_div_256_256 | :heavy_check_mark: | 9033 | 11729 | 332.11 kops |

## bi_mod_square
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_square_256 | :heavy_check_mark: | 88 | 752 | 34.09 mops |

## bi_mod_cube
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_cube_256 | :heavy_check_mark: | 236 | 575 | 12.71 mops |

## bi_mod_pow
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_pow_256 | :heavy_check_mark: | 103198 | 105152 | 29.07 kops |

## bi_mod_inverse
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_inverse_256 | :heavy_check_mark: | 9515 | 9983 | 315.29 kops |
| bi_mod_inverse_512 | :heavy_check_mark: | 23246 | 24247 | 129.05 kops |

## bi_mont
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mont_ctx_256_init | :heavy_check_mark: | 3167 | 3564 | 947.26 kops |
| bi_mont_ctx_256_convert | :heavy_check_mark: | 93 | 161 | 32.25 mops |
| bi_mont_ctx_256_redc_256 | :heavy_check_mark: | 77 | 90 | 38.96 mops |
| bi_mont_ctx_256_redc_512 | :heavy_check_mark: | 77 | 84 | 38.96 mops |
| bi_mont_ctx_256_mul | :heavy_check_mark: | 122 | 190 | 24.59 mops |
| bi_mont_ctx_256_square | :heavy_check_mark: | 113 | 190 | 26.54 mops |
| bi_mont_ctx_256_cube | :heavy_check_mark: | 239 | 261 | 12.55 mops |
| bi_mont_ctx_256_pow | :heavy_check_mark: | 32718 | 56718 | 91.69 kops |

## ecc
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| ec_affine_point_256_copy | :heavy_check_mark: | 8 | 14 | 375.00 mops |
| ec_affine_point_256_double | :heavy_check_mark: | 10630 | 12194 | 282.22 kops |
| ec_affine_point_256_shl | :heavy_check_mark: | 17 | 22826 | 176.47 mops |
| ec_affine_point_256_add | :heavy_check_mark: | 10734 | 11218 | 279.48 kops |
| ec_affine_point_256_sub | :heavy_check_mark: | 10576 | 11126 | 283.66 kops |
| ec_affine_point_256_mul | :heavy_check_mark: | 3782164 | 3834912 | 793 ops |
| ec_affine_point_256_negate | :heavy_check_mark: | 19 | 35 | 157.89 mops |
| ec_projective_point_256_copy | :heavy_check_mark: | 11 | 17 | 272.72 mops |
| ec_projective_point_256_double | :heavy_check_mark: | 2901 | 3319 | 1.03 mops |
| ec_projective_point_256_shl | :heavy_check_mark: | 23 | 9431 | 130.43 mops |
| ec_projective_point_256_add | :heavy_check_mark: | 4060 | 4806 | 738.91 kops |
| ec_projective_point_256_sub | :heavy_check_mark: | 3958 | 4387 | 757.95 kops |
| ec_projective_point_256_mul | :heavy_check_mark: | 1197856 | 1258110 | 2.50 kops |
| ec_projective_point_256_negate | :heavy_check_mark: | 19 | 36 | 157.89 mops |
| ec_projective_point_256_from_affine_point | :heavy_check_mark: | 16 | 77 | 187.50 mops |
| ec_projective_point_256_to_affine_point | :heavy_check_mark: | 9818 | 10527 | 305.56 kops |
| ec_projective_mont_point_256_copy | :heavy_check_mark: | 13 | 39 | 230.76 mops |
| ec_projective_mont_point_256_double | :heavy_check_mark: | 1500 | 1978 | 2.00 mops |
| ec_projective_mont_point_256_from_affine_point | :heavy_check_mark: | 243 | 1628 | 12.34 mops |
| ec_projective_mont_point_256_to_affine_point | :heavy_check_mark: | 10047 | 10859 | 298.59 kops |
| ec_projective_mont_point_256_from_projective_point | :heavy_check_mark: | 356 | 396 | 8.42 mops |
| ec_projective_mont_point_256_to_projective_point | :heavy_check_mark: | 226 | 235 | 13.27 mops |

