# ecc.asm tests

# Cpu Info

12th Gen Intel(R) Core(TM) i5-12600K
## bi_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_zero_128 | :heavy_check_mark: | 0 | 5 | N/A |
| bi_zero_192 | :heavy_check_mark: | 0 | 5 | N/A |
| bi_zero_256 | :heavy_check_mark: | 16 | 22 | 187.50 mops |
| bi_zero_512 | :heavy_check_mark: | 16 | 32 | 187.50 mops |
| bi_zero_1024 | :heavy_check_mark: | 17 | 22 | 176.47 mops |

## bi_copy
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_copy_128 | :heavy_check_mark: | 16 | 23 | 187.50 mops |
| bi_copy_192 | :heavy_check_mark: | 16 | 20 | 187.50 mops |
| bi_copy_256 | :heavy_check_mark: | 16 | 33 | 187.50 mops |
| bi_copy_512 | :heavy_check_mark: | 17 | 41 | 176.47 mops |
| bi_copy_768 | :heavy_check_mark: | 17 | 21 | 176.47 mops |

## bi_is_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_is_zero_256 | :heavy_check_mark: | 15 | 24 | 200.00 mops |
| bi_is_zero_512 | :heavy_check_mark: | 15 | 41 | 200.00 mops |

## bi_rnd
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_rnd_64 | :heavy_check_mark: | 6533 | 6605 | 459.20 kops |
| bi_rnd_128 | :heavy_check_mark: | 13170 | 13246 | 227.79 kops |
| bi_rnd_192 | :heavy_check_mark: | 19676 | 19925 | 152.47 kops |
| bi_rnd_256 | :heavy_check_mark: | 26439 | 26588 | 113.46 kops |
| bi_rnd_320 | :heavy_check_mark: | 33131 | 33491 | 90.54 kops |
| bi_rnd_384 | :heavy_check_mark: | 39785 | 39868 | 75.40 kops |
| bi_rnd_448 | :heavy_check_mark: | 46422 | 46699 | 64.62 kops |
| bi_rnd_512 | :heavy_check_mark: | 53086 | 56243 | 56.51 kops |

## bi_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_add_128_128 | :heavy_check_mark: | 72 | 72 | 41.66 mops |
| bi_add_192_192 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_add_256_256 | :heavy_check_mark: | 9 | 9 | 333.33 mops |
| bi_add_512_512 | :heavy_check_mark: | 0 | 7 | N/A |

## bi_sub
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_sub_128_128 | :heavy_check_mark: | 25 | 25 | 120.00 mops |
| bi_sub_192_192 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_sub_256_256 | :heavy_check_mark: | 48 | 48 | 62.50 mops |
| bi_sub_512_512 | :heavy_check_mark: | 3 | 43 | 1.00 gops |

## bi_lzcnt
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_lzcnt_128 | :heavy_check_mark: | 0 | 27 | N/A |
| bi_lzcnt_192 | :heavy_check_mark: | 0 | 145 | N/A |
| bi_lzcnt_256 | :heavy_check_mark: | 0 | 29 | N/A |

## bi_shl
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_shl_assign_128_1 | :heavy_check_mark: | 23 | 23 | 130.43 mops |
| bi_shl_assign_128 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_shl_assign_256_1 | :heavy_check_mark: | 0 | 5 | N/A |
| bi_shl_assign_256_64 | :heavy_check_mark: | 1 | 2 | 3.00 gops |
| bi_shl_assign_256_128 | :heavy_check_mark: | 12 | 17 | 250.00 mops |
| bi_shl_assign_256 | :heavy_check_mark: | 4 | 13 | 750.00 mops |
| bi_shl_assign_512_1 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_shl_assign_512_64 | :heavy_check_mark: | 0 | 2 | N/A |
| bi_shl_assign_512_128 | :heavy_check_mark: | 12 | 17 | 250.00 mops |
| bi_shl_assign_512_256 | :heavy_check_mark: | 12 | 15 | 250.00 mops |
| bi_shl_assign_512 | :heavy_check_mark: | 17 | 23 | 176.47 mops |

## bi_shr
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_shr_assign_128_1 | :heavy_check_mark: | 1 | 2 | 3.00 gops |
| bi_shr_assign_128 | :heavy_check_mark: | 0 | 9 | N/A |
| bi_shr_assign_256_1 | :heavy_check_mark: | 0 | 26 | N/A |
| bi_shr_assign_256_64 | :heavy_check_mark: | 1 | 1 | 3.00 gops |
| bi_shr_assign_256_128 | :heavy_check_mark: | 11 | 17 | 272.72 mops |
| bi_shr_assign_256 | :heavy_check_mark: | 4 | 12 | 750.00 mops |
| bi_shr_assign_512_1 | :heavy_check_mark: | 0 | 5 | N/A |
| bi_shr_assign_512_64 | :heavy_check_mark: | 1 | 2 | 3.00 gops |
| bi_shr_assign_512_128 | :heavy_check_mark: | 11 | 16 | 272.72 mops |
| bi_shr_assign_512_256 | :heavy_check_mark: | 12 | 18 | 250.00 mops |
| bi_shr_assign_512 | :heavy_check_mark: | 24 | 28 | 125.00 mops |

## bi_cmp
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_cmp_128_128 | :heavy_check_mark: | 3 | 4 | 1.00 gops |
| bi_cmp_192_192 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_cmp_256_256 | :heavy_check_mark: | 0 | 2 | N/A |
| bi_cmp_512_512 | :heavy_check_mark: | 2 | 7 | 1.50 gops |

## bi_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mul_128_64 | :heavy_check_mark: | 521 | 521 | 5.75 mops |
| bi_mul_128_128 | :heavy_check_mark: | 0 | 6 | N/A |
| bi_mul_192_64 | :heavy_check_mark: | 1 | 3 | 3.00 gops |
| bi_mul_256_64 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_mul_256_128 | :heavy_check_mark: | 11 | 33 | 272.72 mops |
| bi_mul_256_256 | :heavy_check_mark: | 35 | 65 | 85.71 mops |
| bi_mul_320_64 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_mul_512_64 | :heavy_check_mark: | 3 | 8 | 1.00 gops |
| bi_mul_512_256 | :heavy_check_mark: | 55 | 110 | 54.54 mops |
| bi_mul_512_512 | :heavy_check_mark: | 185 | 225 | 16.21 mops |

## bi_mul_low
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mul_128_64_low_128 | :heavy_check_mark: | 3 | 8 | 1.00 gops |
| bi_mul_128_128_low_128 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_mul_192_64_low_192 | :heavy_check_mark: | 0 | 3 | N/A |
| bi_mul_256_64_low_256 | :heavy_check_mark: | 5 | 5 | 600.00 mops |
| bi_mul_256_128_low_256 | :heavy_check_mark: | 8 | 25 | 375.00 mops |
| bi_mul_256_256_low_256 | :heavy_check_mark: | 5 | 12 | 600.00 mops |
| bi_mul_512_64_low_512 | :heavy_check_mark: | 3 | 8 | 1.00 gops |
| bi_mul_512_512_low_512 | :heavy_check_mark: | 64 | 87 | 46.87 mops |

## bi_square
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_square_128 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_square_256 | :heavy_check_mark: | 41 | 72 | 73.17 mops |

## bi_div_rem
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_div_rem_128_64 | :heavy_check_mark: | 6 | 598 | 500.00 mops |
| bi_div_rem_128_128 | :heavy_check_mark: | 0 | 647 | N/A |
| bi_div_rem_192_64 | :heavy_check_mark: | 14 | 19 | 214.28 mops |
| bi_div_rem_192_128 | :heavy_check_mark: | 53 | 149 | 56.60 mops |
| bi_div_rem_192_192 | :heavy_check_mark: | 26 | 640 | 115.38 mops |
| bi_div_rem_256_64 | :heavy_check_mark: | 22 | 26 | 136.36 mops |
| bi_div_rem_256_128 | :heavy_check_mark: | 89 | 383 | 33.70 mops |
| bi_div_rem_256_192 | :heavy_check_mark: | 97 | 705 | 30.92 mops |
| bi_div_rem_256_256 | :heavy_check_mark: | 29 | 651 | 103.44 mops |
| bi_div_rem_320_64 | :heavy_check_mark: | 30 | 36 | 100.00 mops |
| bi_div_rem_320_128 | :heavy_check_mark: | 153 | 759 | 19.60 mops |
| bi_div_rem_320_192 | :heavy_check_mark: | 97 | 224 | 30.92 mops |
| bi_div_rem_320_256 | :heavy_check_mark: | 51 | 161 | 58.82 mops |
| bi_div_rem_320_320 | :heavy_check_mark: | 50 | 79 | 60.00 mops |
| bi_div_rem_384_64 | :heavy_check_mark: | 37 | 44 | 81.08 mops |
| bi_div_rem_384_128 | :heavy_check_mark: | 189 | 481 | 15.87 mops |
| bi_div_rem_384_192 | :heavy_check_mark: | 244 | 312 | 12.29 mops |
| bi_div_rem_448_64 | :heavy_check_mark: | 45 | 53 | 66.66 mops |
| bi_div_rem_448_128 | :heavy_check_mark: | 388 | 495 | 7.73 mops |
| bi_div_rem_512_64 | :heavy_check_mark: | 54 | 61 | 55.55 mops |
| bi_div_rem_512_128 | :heavy_check_mark: | 429 | 1169 | 6.99 mops |
| bi_div_rem_512_256 | :heavy_check_mark: | 266 | 1005 | 11.27 mops |
| bi_div_rem_512_512 | :heavy_check_mark: | 52 | 89 | 57.69 mops |
| bi_rem_128_64 | :heavy_check_mark: | 6 | 583 | 500.00 mops |
| bi_rem_128_128 | :heavy_check_mark: | 0 | 374 | N/A |
| bi_rem_192_64 | :heavy_check_mark: | 14 | 224 | 214.28 mops |
| bi_rem_192_128 | :heavy_check_mark: | 48 | 269 | 62.50 mops |
| bi_rem_192_192 | :heavy_check_mark: | 24 | 638 | 125.00 mops |
| bi_rem_256_64 | :heavy_check_mark: | 21 | 238 | 142.85 mops |
| bi_rem_256_128 | :heavy_check_mark: | 83 | 3832 | 36.14 mops |
| bi_rem_256_192 | :heavy_check_mark: | 95 | 137 | 31.57 mops |
| bi_rem_256_256 | :heavy_check_mark: | 34 | 651 | 88.23 mops |
| bi_rem_320_64 | :heavy_check_mark: | 33 | 39 | 90.90 mops |
| bi_rem_320_128 | :heavy_check_mark: | 131 | 728 | 22.90 mops |
| bi_rem_320_192 | :heavy_check_mark: | 88 | 232 | 34.09 mops |
| bi_rem_320_256 | :heavy_check_mark: | 52 | 126 | 57.69 mops |
| bi_rem_320_320 | :heavy_check_mark: | 55 | 112 | 54.54 mops |
| bi_rem_384_64 | :heavy_check_mark: | 41 | 49 | 73.17 mops |
| bi_rem_384_128 | :heavy_check_mark: | 160 | 376 | 18.75 mops |
| bi_rem_384_192 | :heavy_check_mark: | 210 | 1052 | 14.28 mops |
| bi_rem_448_64 | :heavy_check_mark: | 50 | 58 | 60.00 mops |
| bi_rem_448_128 | :heavy_check_mark: | 294 | 935 | 10.20 mops |
| bi_rem_448_192 | :heavy_check_mark: | 296 | 423 | 10.13 mops |
| bi_rem_512_64 | :heavy_check_mark: | 58 | 67 | 51.72 mops |
| bi_rem_512_128 | :heavy_check_mark: | 327 | 1116 | 9.17 mops |
| bi_rem_512_256 | :heavy_check_mark: | 200 | 915 | 15.00 mops |
| bi_rem_512_512 | :heavy_check_mark: | 56 | 94 | 53.57 mops |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_add_assign_256_256 | :heavy_check_mark: | 6 | 22 | 500.00 mops |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_double_assign_256 | :heavy_check_mark: | 5 | 37 | 600.00 mops |

## bi_mod_tripple
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_tripple_assign_256 | :heavy_check_mark: | 4 | 47 | 750.00 mops |

## bi_mod_half
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_half_assign_256 | :heavy_check_mark: | 6 | 38 | 500.00 mops |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_sub_256_256 | :heavy_check_mark: | 21 | 30 | 142.85 mops |
| bi_mod_sub_assign_256_256 | :heavy_check_mark: | 3 | 17 | 1.00 gops |

## bi_mod_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_mul_256_256 | :heavy_check_mark: | 82 | 311 | 36.58 mops |

## bi_mod_div
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_div_256_256 | :heavy_check_mark: | 10363 | 16117 | 289.49 kops |

## bi_mod_square
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_square_256 | :heavy_check_mark: | 76 | 301 | 39.47 mops |

## bi_mod_cube
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_cube_256 | :heavy_check_mark: | 224 | 1206 | 13.39 mops |

## bi_mod_pow
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_pow_256 | :heavy_check_mark: | 104803 | 336731 | 28.62 kops |

## bi_mod_inverse
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_inverse_256 | :heavy_check_mark: | 10441 | 11114 | 287.32 kops |
| bi_mod_inverse_512 | :heavy_check_mark: | 19641 | 21020 | 152.74 kops |

## bi_mont
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mont_ctx_256_init | :heavy_check_mark: | 3102 | 4491 | 967.11 kops |
| bi_mont_ctx_256_convert | :heavy_check_mark: | 74 | 148 | 40.54 mops |
| bi_mont_ctx_256_redc_256 | :heavy_check_mark: | 68 | 181 | 44.11 mops |
| bi_mont_ctx_256_redc_512 | :heavy_check_mark: | 68 | 91 | 44.11 mops |
| bi_mont_ctx_256_mul | :heavy_check_mark: | 101 | 130 | 29.70 mops |
| bi_mont_ctx_256_square | :heavy_check_mark: | 102 | 1915 | 29.41 mops |
| bi_mont_ctx_256_cube | :heavy_check_mark: | 218 | 1197 | 13.76 mops |
| bi_mont_ctx_256_pow | :heavy_check_mark: | 29825 | 65524 | 100.58 kops |

## ec_affine_point
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| ec_affine_point_256_copy | :heavy_check_mark: | 11 | 62 | 272.72 mops |
| ec_affine_point_256_double | :heavy_check_mark: | 11178 | 16752 | 268.38 kops |
| ec_affine_point_256_shl | :heavy_check_mark: | 16 | 24798 | 187.50 mops |
| ec_affine_point_256_add | :heavy_check_mark: | 11907 | 13030 | 251.95 kops |
| ec_affine_point_256_sub | :heavy_check_mark: | 11957 | 12580 | 250.89 kops |
| ec_affine_point_256_mul | :heavy_check_mark: | 4131116 | 4949425 | 726 ops |
| ec_affine_point_256_negate | :heavy_check_mark: | 15 | 88 | 200.00 mops |

## ec_projective_point
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| ec_projective_point_256_copy | :heavy_check_mark: | 10 | 53 | 300.00 mops |
| ec_projective_point_256_double | :heavy_check_mark: | 3001 | 3848 | 999.66 kops |
| ec_projective_point_256_shl | :heavy_check_mark: | 20 | 7037 | 150.00 mops |
| ec_projective_point_256_add | :heavy_check_mark: | 3988 | 4808 | 752.25 kops |
| ec_projective_point_256_sub | :heavy_check_mark: | 3933 | 4710 | 762.77 kops |
| ec_projective_point_256_mul | :heavy_check_mark: | 1231410 | 1412735 | 2.43 kops |
| ec_projective_point_256_negate | :heavy_check_mark: | 15 | 31 | 200.00 mops |
| ec_projective_point_256_from_affine_point | :heavy_check_mark: | 13 | 96 | 230.76 mops |
| ec_projective_point_256_to_affine_point | :heavy_check_mark: | 10852 | 12172 | 276.44 kops |

## ec_projective_mont_point
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| ec_projective_mont_point_256_copy | :heavy_check_mark: | 9 | 16 | 333.33 mops |
| ec_projective_mont_point_256_double | :heavy_check_mark: | 1404 | 2027 | 2.13 mops |
| ec_projective_mont_point_256_shl | :heavy_check_mark: | 19 | 3729 | 157.89 mops |
| ec_projective_mont_point_256_add | :heavy_check_mark: | 1547 | 1909 | 1.93 mops |
| ec_projective_mont_point_256_sub | :heavy_check_mark: | 1547 | 2351 | 1.93 mops |
| ec_projective_mont_point_256_mul | :heavy_check_mark: | 593013 | 692385 | 5.05 kops |
| ec_projective_mont_point_256_negate | :heavy_check_mark: | 24 | 34 | 125.00 mops |
| ec_projective_mont_point_256_from_affine_point | :heavy_check_mark: | 221 | 506 | 13.57 mops |
| ec_projective_mont_point_256_to_affine_point | :heavy_check_mark: | 12115 | 13030 | 247.62 kops |
| ec_projective_mont_point_256_from_projective_point | :heavy_check_mark: | 304 | 427 | 9.86 mops |
| ec_projective_mont_point_256_to_projective_point | :heavy_check_mark: | 208 | 267 | 14.42 mops |

## secp256k1
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| secp256k1_get_affine_point | :heavy_check_mark: | 66798 | 89302 | 44.91 kops |

