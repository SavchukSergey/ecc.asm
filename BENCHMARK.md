# ecc.asm tests

# Cpu Info

AMD Ryzen 7 4800H with Radeon Graphics         
## bi_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_zero_128 | :heavy_check_mark: | 1 | 6 | 3.00 gops |
| bi_zero_192 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_zero_256 | :heavy_check_mark: | 8 | 11 | 375.00 mops |
| bi_zero_512 | :heavy_check_mark: | 8 | 11 | 375.00 mops |
| bi_zero_1024 | :heavy_check_mark: | 8 | 11 | 375.00 mops |

## bi_copy
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_copy_128 | :heavy_check_mark: | 8 | 13 | 375.00 mops |
| bi_copy_192 | :heavy_check_mark: | 0 | 29 | N/A |
| bi_copy_256 | :heavy_check_mark: | 8 | 13 | 375.00 mops |
| bi_copy_512 | :heavy_check_mark: | 10 | 14 | 300.00 mops |
| bi_copy_768 | :heavy_check_mark: | 8 | 24 | 375.00 mops |

## bi_is_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_is_zero_256 | :heavy_check_mark: | 8 | 11 | 375.00 mops |
| bi_is_zero_512 | :heavy_check_mark: | 8 | 11 | 375.00 mops |

## bi_rnd
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_rnd_64 | :heavy_check_mark: | 10019 | 15834 | 299.43 kops |
| bi_rnd_128 | :heavy_check_mark: | 20058 | 22801 | 149.56 kops |
| bi_rnd_192 | :heavy_check_mark: | 29957 | 31920 | 100.14 kops |
| bi_rnd_256 | :heavy_check_mark: | 40540 | 44928 | 74.00 kops |
| bi_rnd_320 | :heavy_check_mark: | 50825 | 53337 | 59.02 kops |
| bi_rnd_384 | :heavy_check_mark: | 61146 | 63047 | 49.06 kops |
| bi_rnd_448 | :heavy_check_mark: | 71579 | 75059 | 41.91 kops |
| bi_rnd_512 | :heavy_check_mark: | 81725 | 85184 | 36.70 kops |

## bi_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_add_128_128 | :heavy_check_mark: | 1 | 16 | 3.00 gops |
| bi_add_192_192 | :heavy_check_mark: | 1 | 6 | 3.00 gops |
| bi_add_256_256 | :heavy_check_mark: | 1 | 6 | 3.00 gops |
| bi_add_512_512 | :heavy_check_mark: | 1 | 24 | 3.00 gops |

## bi_sub
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_sub_128_128 | :heavy_check_mark: | 0 | 17 | N/A |
| bi_sub_192_192 | :heavy_check_mark: | 1 | 4 | 3.00 gops |
| bi_sub_256_256 | :heavy_check_mark: | 0 | 7 | N/A |
| bi_sub_512_512 | :heavy_check_mark: | 1 | 27 | 3.00 gops |

## bi_lzcnt
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_lzcnt_128 | :heavy_check_mark: | 1 | 24 | 3.00 gops |
| bi_lzcnt_192 | :heavy_check_mark: | 3 | 13 | 1.00 gops |
| bi_lzcnt_256 | :heavy_check_mark: | 1 | 8 | 3.00 gops |

## bi_shl
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_shl_assign_128_1 | :heavy_check_mark: | 0 | 3 | N/A |
| bi_shl_assign_128 | :heavy_check_mark: | 1 | 4 | 3.00 gops |
| bi_shl_assign_256_1 | :heavy_check_mark: | 0 | 3 | N/A |
| bi_shl_assign_256_64 | :heavy_check_mark: | 1 | 6 | 3.00 gops |
| bi_shl_assign_256_128 | :heavy_check_mark: | 8 | 11 | 375.00 mops |
| bi_shl_assign_256 | :heavy_check_mark: | 4 | 8 | 750.00 mops |
| bi_shl_assign_512_1 | :heavy_check_mark: | 0 | 6 | N/A |
| bi_shl_assign_512_64 | :heavy_check_mark: | 1 | 4 | 3.00 gops |
| bi_shl_assign_512_128 | :heavy_check_mark: | 8 | 13 | 375.00 mops |
| bi_shl_assign_512_256 | :heavy_check_mark: | 8 | 11 | 375.00 mops |
| bi_shl_assign_512 | :heavy_check_mark: | 13 | 17 | 230.76 mops |

## bi_shr
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_shr_assign_128_1 | :heavy_check_mark: | 0 | 3 | N/A |
| bi_shr_assign_128 | :heavy_check_mark: | 1 | 6 | 3.00 gops |
| bi_shr_assign_256_1 | :heavy_check_mark: | 1 | 6 | 3.00 gops |
| bi_shr_assign_256_64 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_shr_assign_256_128 | :heavy_check_mark: | 7 | 10 | 428.57 mops |
| bi_shr_assign_256 | :heavy_check_mark: | 6 | 10 | 500.00 mops |
| bi_shr_assign_512_1 | :heavy_check_mark: | 1 | 4 | 3.00 gops |
| bi_shr_assign_512_64 | :heavy_check_mark: | 1 | 4 | 3.00 gops |
| bi_shr_assign_512_128 | :heavy_check_mark: | 8 | 13 | 375.00 mops |
| bi_shr_assign_512_256 | :heavy_check_mark: | 8 | 11 | 375.00 mops |
| bi_shr_assign_512 | :heavy_check_mark: | 17 | 26 | 176.47 mops |

## bi_cmp
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_cmp_128_128 | :heavy_check_mark: | 1 | 7 | 3.00 gops |
| bi_cmp_192_192 | :heavy_check_mark: | 1 | 6 | 3.00 gops |
| bi_cmp_256_256 | :heavy_check_mark: | 0 | 8 | N/A |
| bi_cmp_512_512 | :heavy_check_mark: | 3 | 29 | 1.00 gops |

## bi_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mul_128_64 | :heavy_check_mark: | 1 | 364 | 3.00 gops |
| bi_mul_128_128 | :heavy_check_mark: | 1 | 7 | 3.00 gops |
| bi_mul_192_64 | :heavy_check_mark: | 1 | 6 | 3.00 gops |
| bi_mul_256_64 | :heavy_check_mark: | 3 | 7 | 1.00 gops |
| bi_mul_256_128 | :heavy_check_mark: | 14 | 23 | 214.28 mops |
| bi_mul_256_256 | :heavy_check_mark: | 26 | 33 | 115.38 mops |
| bi_mul_320_64 | :heavy_check_mark: | 3 | 13 | 1.00 gops |
| bi_mul_512_64 | :heavy_check_mark: | 7 | 20 | 428.57 mops |
| bi_mul_512_256 | :heavy_check_mark: | 65 | 87 | 46.15 mops |
| bi_mul_512_512 | :heavy_check_mark: | 162 | 187 | 18.51 mops |

## bi_mul_low
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mul_128_64_low_128 | :heavy_check_mark: | 1 | 24 | 3.00 gops |
| bi_mul_128_128_low_128 | :heavy_check_mark: | 1 | 24 | 3.00 gops |
| bi_mul_192_64_low_192 | :heavy_check_mark: | 1 | 4 | 3.00 gops |
| bi_mul_256_64_low_256 | :heavy_check_mark: | 1 | 6 | 3.00 gops |
| bi_mul_256_128_low_256 | :heavy_check_mark: | 13 | 21 | 230.76 mops |
| bi_mul_256_256_low_256 | :heavy_check_mark: | 7 | 11 | 428.57 mops |
| bi_mul_512_64_low_512 | :heavy_check_mark: | 7 | 10 | 428.57 mops |
| bi_mul_512_512_low_512 | :heavy_check_mark: | 58 | 69 | 51.72 mops |

## bi_square
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_square_128 | :heavy_check_mark: | 1 | 7 | 3.00 gops |
| bi_square_256 | :heavy_check_mark: | 19 | 23 | 157.89 mops |

## bi_div_rem
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_div_rem_128_64 | :heavy_check_mark: | 10 | 82 | 300.00 mops |
| bi_div_rem_128_128 | :heavy_check_mark: | 3 | 499 | 1.00 gops |
| bi_div_rem_192_64 | :heavy_check_mark: | 20 | 84 | 150.00 mops |
| bi_div_rem_192_128 | :heavy_check_mark: | 53 | 169 | 56.60 mops |
| bi_div_rem_192_192 | :heavy_check_mark: | 23 | 74 | 130.43 mops |
| bi_div_rem_256_64 | :heavy_check_mark: | 29 | 114 | 103.44 mops |
| bi_div_rem_256_128 | :heavy_check_mark: | 85 | 678 | 35.29 mops |
| bi_div_rem_256_192 | :heavy_check_mark: | 103 | 164 | 29.12 mops |
| bi_div_rem_256_256 | :heavy_check_mark: | 29 | 494 | 103.44 mops |
| bi_div_rem_320_64 | :heavy_check_mark: | 39 | 146 | 76.92 mops |
| bi_div_rem_320_128 | :heavy_check_mark: | 137 | 322 | 21.89 mops |
| bi_div_rem_320_192 | :heavy_check_mark: | 100 | 216 | 30.00 mops |
| bi_div_rem_320_256 | :heavy_check_mark: | 58 | 142 | 51.72 mops |
| bi_div_rem_320_320 | :heavy_check_mark: | 62 | 107 | 48.38 mops |
| bi_div_rem_384_64 | :heavy_check_mark: | 49 | 807 | 61.22 mops |
| bi_div_rem_384_128 | :heavy_check_mark: | 213 | 451 | 14.08 mops |
| bi_div_rem_384_192 | :heavy_check_mark: | 223 | 2729 | 13.45 mops |
| bi_div_rem_448_64 | :heavy_check_mark: | 58 | 278 | 51.72 mops |
| bi_div_rem_448_128 | :heavy_check_mark: | 345 | 506 | 8.69 mops |
| bi_div_rem_512_64 | :heavy_check_mark: | 68 | 314 | 44.11 mops |
| bi_div_rem_512_128 | :heavy_check_mark: | 372 | 1080 | 8.06 mops |
| bi_div_rem_512_256 | :heavy_check_mark: | 236 | 513 | 12.71 mops |
| bi_div_rem_512_512 | :heavy_check_mark: | 59 | 93 | 50.84 mops |
| bi_rem_128_64 | :heavy_check_mark: | 10 | 81 | 300.00 mops |
| bi_rem_128_128 | :heavy_check_mark: | 1 | 417 | 3.00 gops |
| bi_rem_192_64 | :heavy_check_mark: | 20 | 580 | 150.00 mops |
| bi_rem_192_128 | :heavy_check_mark: | 52 | 152 | 57.69 mops |
| bi_rem_192_192 | :heavy_check_mark: | 30 | 156 | 100.00 mops |
| bi_rem_256_64 | :heavy_check_mark: | 29 | 114 | 103.44 mops |
| bi_rem_256_128 | :heavy_check_mark: | 81 | 235 | 37.03 mops |
| bi_rem_256_192 | :heavy_check_mark: | 107 | 153 | 28.03 mops |
| bi_rem_256_256 | :heavy_check_mark: | 32 | 140 | 93.75 mops |
| bi_rem_320_64 | :heavy_check_mark: | 39 | 146 | 76.92 mops |
| bi_rem_320_128 | :heavy_check_mark: | 122 | 296 | 24.59 mops |
| bi_rem_320_192 | :heavy_check_mark: | 87 | 206 | 34.48 mops |
| bi_rem_320_256 | :heavy_check_mark: | 49 | 162 | 61.22 mops |
| bi_rem_320_320 | :heavy_check_mark: | 46 | 81 | 65.21 mops |
| bi_rem_384_64 | :heavy_check_mark: | 48 | 175 | 62.50 mops |
| bi_rem_384_128 | :heavy_check_mark: | 188 | 367 | 15.95 mops |
| bi_rem_384_192 | :heavy_check_mark: | 188 | 298 | 15.95 mops |
| bi_rem_448_64 | :heavy_check_mark: | 58 | 280 | 51.72 mops |
| bi_rem_448_128 | :heavy_check_mark: | 248 | 432 | 12.09 mops |
| bi_rem_448_192 | :heavy_check_mark: | 261 | 384 | 11.49 mops |
| bi_rem_512_64 | :heavy_check_mark: | 68 | 494 | 44.11 mops |
| bi_rem_512_128 | :heavy_check_mark: | 256 | 1155 | 11.71 mops |
| bi_rem_512_256 | :heavy_check_mark: | 177 | 381 | 16.94 mops |
| bi_rem_512_512 | :heavy_check_mark: | 75 | 119 | 40.00 mops |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_add_assign_256_256 | :heavy_check_mark: | 8 | 20 | 375.00 mops |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_double_assign_256 | :heavy_check_mark: | 8 | 37 | 375.00 mops |

## bi_mod_tripple
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_tripple_assign_256 | :heavy_check_mark: | 7 | 30 | 428.57 mops |

## bi_mod_half
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_half_assign_256 | :heavy_check_mark: | 8 | 26 | 375.00 mops |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_sub_256_256 | :heavy_check_mark: | 13 | 20 | 230.76 mops |
| bi_mod_sub_assign_256_256 | :heavy_check_mark: | 6 | 16 | 500.00 mops |

## bi_mod_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_mul_256_256 | :heavy_check_mark: | 62 | 284 | 48.38 mops |

## bi_mod_div
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_div_256_256 | :heavy_check_mark: | 8633 | 10498 | 347.50 kops |

## bi_mod_square
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_square_256 | :heavy_check_mark: | 56 | 246 | 53.57 mops |

## bi_mod_cube
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_cube_256 | :heavy_check_mark: | 200 | 490 | 15.00 mops |

## bi_mod_pow
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_pow_256 | :heavy_check_mark: | 96083 | 102394 | 31.22 kops |

## bi_mod_inverse
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_inverse_256 | :heavy_check_mark: | 9358 | 10121 | 320.58 kops |
| bi_mod_inverse_512 | :heavy_check_mark: | 21761 | 22994 | 137.86 kops |

## bi_mont
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mont_ctx_256_init | :heavy_check_mark: | 3120 | 3227 | 961.53 kops |
| bi_mont_ctx_256_convert | :heavy_check_mark: | 64 | 516 | 46.87 mops |
| bi_mont_ctx_256_redc_256 | :heavy_check_mark: | 66 | 106 | 45.45 mops |
| bi_mont_ctx_256_redc_512 | :heavy_check_mark: | 66 | 74 | 45.45 mops |
| bi_mont_ctx_256_mul | :heavy_check_mark: | 100 | 104 | 30.00 mops |
| bi_mont_ctx_256_square | :heavy_check_mark: | 85 | 97 | 35.29 mops |
| bi_mont_ctx_256_cube | :heavy_check_mark: | 195 | 268 | 15.38 mops |
| bi_mont_ctx_256_pow | :heavy_check_mark: | 28495 | 44940 | 105.28 kops |

## ec_affine_point
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| ec_affine_point_256_copy | :heavy_check_mark: | 8 | 11 | 375.00 mops |
| ec_affine_point_256_double | :heavy_check_mark: | 10385 | 11668 | 288.87 kops |
| ec_affine_point_256_shl | :heavy_check_mark: | 16 | 22320 | 187.50 mops |
| ec_affine_point_256_add | :heavy_check_mark: | 10402 | 10712 | 288.40 kops |
| ec_affine_point_256_sub | :heavy_check_mark: | 10469 | 10962 | 286.56 kops |
| ec_affine_point_256_mul | :heavy_check_mark: | 3695702 | 3762003 | 811 ops |
| ec_affine_point_256_negate | :heavy_check_mark: | 16 | 23 | 187.50 mops |

## ec_projective_point
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| ec_projective_point_256_copy | :heavy_check_mark: | 11 | 43 | 272.72 mops |
| ec_projective_point_256_double | :heavy_check_mark: | 2688 | 2969 | 1.11 mops |
| ec_projective_point_256_shl | :heavy_check_mark: | 23 | 5772 | 130.43 mops |
| ec_projective_point_256_add | :heavy_check_mark: | 3699 | 4006 | 811.03 kops |
| ec_projective_point_256_sub | :heavy_check_mark: | 3615 | 4105 | 829.87 kops |
| ec_projective_point_256_mul | :heavy_check_mark: | 1111480 | 1123700 | 2.69 kops |
| ec_projective_point_256_negate | :heavy_check_mark: | 17 | 33 | 176.47 mops |
| ec_projective_point_256_from_affine_point | :heavy_check_mark: | 13 | 61 | 230.76 mops |
| ec_projective_point_256_to_affine_point | :heavy_check_mark: | 9760 | 10373 | 307.37 kops |

## ec_projective_mont_point
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| ec_projective_mont_point_256_copy | :heavy_check_mark: | 11 | 26 | 272.72 mops |
| ec_projective_mont_point_256_double | :heavy_check_mark: | 1222 | 1473 | 2.45 mops |
| ec_projective_mont_point_256_shl | :heavy_check_mark: | 21 | 3523 | 142.85 mops |
| ec_projective_mont_point_256_add | :heavy_check_mark: | 1499 | 1796 | 2.00 mops |
| ec_projective_mont_point_256_sub | :heavy_check_mark: | 1506 | 1558 | 1.99 mops |
| ec_projective_mont_point_256_mul | :heavy_check_mark: | 513751 | 566080 | 5.83 kops |
| ec_projective_mont_point_256_negate | :heavy_check_mark: | 17 | 42 | 176.47 mops |
| ec_projective_mont_point_256_from_affine_point | :heavy_check_mark: | 195 | 388 | 15.38 mops |
| ec_projective_mont_point_256_to_affine_point | :heavy_check_mark: | 10164 | 11044 | 295.15 kops |
| ec_projective_mont_point_256_from_projective_point | :heavy_check_mark: | 285 | 320 | 10.52 mops |
| ec_projective_mont_point_256_to_projective_point | :heavy_check_mark: | 197 | 214 | 15.22 mops |

## secp256k1
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| secp256k1_get_affine_point | :heavy_check_mark: | 59158 | 73606 | 50.71 kops |

