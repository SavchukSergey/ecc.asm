# ecc.asm tests

# Cpu Info

Intel(R) Core(TM) i7-8700K CPU @ 3.70GHz
## bi_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_zero_128 | :heavy_check_mark: | 0 | 2 | N/A |
| bi_zero_192 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_zero_256 | :heavy_check_mark: | 1 | 5 | 3.00 gops |
| bi_zero_512 | :heavy_check_mark: | 0 | 2 | N/A |
| bi_zero_1024 | :heavy_check_mark: | 8 | 27 | 375.00 mops |

## bi_copy
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_copy_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_copy_192 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_copy_256 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_copy_512 | :heavy_check_mark: | 1 | 1 | 3.00 gops |
| bi_copy_768 | :heavy_check_mark: | 6 | 1021 | 500.00 mops |

## bi_is_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_is_zero_256 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_is_zero_512 | :heavy_check_mark: | 0 | 0 | N/A |

## bi_rnd
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_rnd_64 | :heavy_check_mark: | 5439 | 13867 | 551.57 kops |
| bi_rnd_128 | :heavy_check_mark: | 12163 | 19740 | 246.64 kops |
| bi_rnd_192 | :heavy_check_mark: | 16234 | 26226 | 184.79 kops |
| bi_rnd_256 | :heavy_check_mark: | 21747 | 36296 | 137.95 kops |
| bi_rnd_320 | :heavy_check_mark: | 27155 | 38295 | 110.47 kops |
| bi_rnd_384 | :heavy_check_mark: | 34123 | 45835 | 87.91 kops |
| bi_rnd_448 | :heavy_check_mark: | 37872 | 50409 | 79.21 kops |
| bi_rnd_512 | :heavy_check_mark: | 43334 | 60311 | 69.22 kops |

## bi_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_add_128_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_add_192_192 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_add_256_256 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_add_512_512 | :heavy_check_mark: | 0 | 0 | N/A |

## bi_sub
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_sub_128_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_sub_192_192 | :heavy_check_mark: | 15 | 15 | 200.00 mops |
| bi_sub_256_256 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_sub_512_512 | :heavy_check_mark: | 0 | 0 | N/A |

## bi_lzcnt
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_lzcnt_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_lzcnt_192 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_lzcnt_256 | :heavy_check_mark: | 0 | 0 | N/A |

## bi_shl
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_shl_assign_128_1 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shl_assign_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shl_assign_256_1 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shl_assign_256_64 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shl_assign_256_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shl_assign_256 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shl_assign_512_1 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shl_assign_512_64 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shl_assign_512_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shl_assign_512_256 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shl_assign_512 | :heavy_check_mark: | 19 | 21 | 157.89 mops |

## bi_shr
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_shr_assign_128_1 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shr_assign_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shr_assign_256_1 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shr_assign_256_64 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shr_assign_256_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shr_assign_256 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shr_assign_512_1 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shr_assign_512_64 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shr_assign_512_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shr_assign_512_256 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shr_assign_512 | :heavy_check_mark: | 27 | 39 | 111.11 mops |

## bi_cmp
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_cmp_128_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_cmp_192_192 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_cmp_256_256 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_cmp_512_512 | :heavy_check_mark: | 0 | 0 | N/A |

## bi_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mul_128_64 | :heavy_check_mark: | 59 | 59 | 50.84 mops |
| bi_mul_128_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_192_64 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_256_64 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_256_128 | :heavy_check_mark: | 7 | 45 | 428.57 mops |
| bi_mul_256_256 | :heavy_check_mark: | 52 | 66 | 57.69 mops |
| bi_mul_320_64 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_512_64 | :heavy_check_mark: | 2 | 2 | 1.50 gops |
| bi_mul_512_256 | :heavy_check_mark: | 95 | 125 | 31.57 mops |
| bi_mul_512_512 | :heavy_check_mark: | 373 | 425 | 8.04 mops |

## bi_mul_low
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mul_128_64_low_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_128_128_low_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_192_64_low_192 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_256_64_low_256 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_256_128_low_256 | :heavy_check_mark: | 0 | 39 | N/A |
| bi_mul_256_256_low_256 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_512_64_low_512 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_512_512_low_512 | :heavy_check_mark: | 114 | 168 | 26.31 mops |

## bi_square
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_square_128 | :heavy_check_mark: | 47 | 47 | 63.82 mops |
| bi_square_256 | :heavy_check_mark: | 42 | 87 | 71.42 mops |

## bi_div_rem
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_div_rem_128_64 | :heavy_check_mark: | 15 | 660 | 200.00 mops |
| bi_div_rem_128_128 | :heavy_check_mark: | 84 | 95 | 35.71 mops |
| bi_div_rem_192_64 | :heavy_check_mark: | 35 | 165 | 85.71 mops |
| bi_div_rem_192_128 | :heavy_check_mark: | 50 | 430 | 60.00 mops |
| bi_div_rem_192_192 | :heavy_check_mark: | 16 | 337 | 187.50 mops |
| bi_div_rem_256_64 | :heavy_check_mark: | 56 | 1685 | 53.57 mops |
| bi_div_rem_256_128 | :heavy_check_mark: | 111 | 1459 | 27.02 mops |
| bi_div_rem_256_192 | :heavy_check_mark: | 311 | 3123 | 9.64 mops |
| bi_div_rem_256_256 | :heavy_check_mark: | 32 | 268 | 93.75 mops |
| bi_div_rem_320_64 | :heavy_check_mark: | 78 | 342 | 38.46 mops |
| bi_div_rem_320_128 | :heavy_check_mark: | 225 | 925 | 13.33 mops |
| bi_div_rem_320_192 | :heavy_check_mark: | 124 | 581 | 24.19 mops |
| bi_div_rem_320_256 | :heavy_check_mark: | 47 | 380 | 63.82 mops |
| bi_div_rem_320_320 | :heavy_check_mark: | 158 | 200 | 18.98 mops |
| bi_div_rem_384_64 | :heavy_check_mark: | 100 | 418 | 30.00 mops |
| bi_div_rem_384_128 | :heavy_check_mark: | 315 | 1182 | 9.52 mops |
| bi_div_rem_384_192 | :heavy_check_mark: | 389 | 888 | 7.71 mops |
| bi_div_rem_448_64 | :heavy_check_mark: | 118 | 495 | 25.42 mops |
| bi_div_rem_448_128 | :heavy_check_mark: | 629 | 1374 | 4.76 mops |
| bi_div_rem_512_64 | :heavy_check_mark: | 140 | 1441 | 21.42 mops |
| bi_div_rem_512_128 | :heavy_check_mark: | 637 | 2902 | 4.70 mops |
| bi_div_rem_512_256 | :heavy_check_mark: | 393 | 1641 | 7.63 mops |
| bi_div_rem_512_512 | :heavy_check_mark: | 178 | 230 | 16.85 mops |
| bi_rem_128_64 | :heavy_check_mark: | 14 | 81 | 214.28 mops |
| bi_rem_128_128 | :heavy_check_mark: | 82 | 724 | 36.58 mops |
| bi_rem_192_64 | :heavy_check_mark: | 34 | 162 | 88.23 mops |
| bi_rem_192_128 | :heavy_check_mark: | 35 | 387 | 85.71 mops |
| bi_rem_192_192 | :heavy_check_mark: | 0 | 857 | N/A |
| bi_rem_256_64 | :heavy_check_mark: | 55 | 247 | 54.54 mops |
| bi_rem_256_128 | :heavy_check_mark: | 90 | 513 | 33.33 mops |
| bi_rem_256_192 | :heavy_check_mark: | 302 | 935 | 9.93 mops |
| bi_rem_256_256 | :heavy_check_mark: | 32 | 231 | 93.75 mops |
| bi_rem_320_64 | :heavy_check_mark: | 78 | 342 | 38.46 mops |
| bi_rem_320_128 | :heavy_check_mark: | 158 | 823 | 18.98 mops |
| bi_rem_320_192 | :heavy_check_mark: | 97 | 556 | 30.92 mops |
| bi_rem_320_256 | :heavy_check_mark: | 41 | 1068 | 73.17 mops |
| bi_rem_320_320 | :heavy_check_mark: | 154 | 197 | 19.48 mops |
| bi_rem_384_64 | :heavy_check_mark: | 100 | 424 | 30.00 mops |
| bi_rem_384_128 | :heavy_check_mark: | 227 | 1041 | 13.21 mops |
| bi_rem_384_192 | :heavy_check_mark: | 300 | 776 | 10.00 mops |
| bi_rem_448_64 | :heavy_check_mark: | 119 | 501 | 25.21 mops |
| bi_rem_448_128 | :heavy_check_mark: | 412 | 1638 | 7.28 mops |
| bi_rem_448_192 | :heavy_check_mark: | 401 | 1030 | 7.48 mops |
| bi_rem_512_64 | :heavy_check_mark: | 141 | 582 | 21.27 mops |
| bi_rem_512_128 | :heavy_check_mark: | 380 | 1703 | 7.89 mops |
| bi_rem_512_256 | :heavy_check_mark: | 272 | 1054 | 11.02 mops |
| bi_rem_512_512 | :heavy_check_mark: | 173 | 213 | 17.34 mops |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_add_assign_256_256 | :heavy_check_mark: | 0 | 5 | N/A |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_double_assign_256 | :heavy_check_mark: | 2 | 12 | 1.50 gops |

## bi_mod_tripple
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_tripple_assign_256 | :heavy_check_mark: | 9 | 75 | 333.33 mops |

## bi_mod_half
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_half_assign_256 | :heavy_check_mark: | 3 | 15 | 1.00 gops |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_sub_256_256 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mod_sub_assign_256_256 | :heavy_check_mark: | 11 | 11 | 272.72 mops |

## bi_mod_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_mul_256_256 | :heavy_check_mark: | 90 | 1080 | 33.33 mops |

## bi_mod_div
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_div_256_256 | :heavy_check_mark: | 24328 | 28616 | 123.31 kops |

## bi_mod_square
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_square_256 | :heavy_check_mark: | 77 | 399 | 38.96 mops |

## bi_mod_cube
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_cube_256 | :heavy_check_mark: | 324 | 1255 | 9.25 mops |

## bi_mod_pow
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_pow_256 | :heavy_check_mark: | 163061 | 170030 | 18.39 kops |

## bi_mod_inverse
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_inverse_256 | :heavy_check_mark: | 26609 | 27743 | 112.74 kops |
| bi_mod_inverse_512 | :heavy_check_mark: | 52130 | 55550 | 57.54 kops |

## bi_mont
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mont_ctx_256_init | :heavy_check_mark: | 6774 | 7459 | 442.86 kops |
| bi_mont_ctx_256_convert | :heavy_check_mark: | 97 | 176 | 30.92 mops |
| bi_mont_ctx_256_redc_256 | :heavy_check_mark: | 92 | 586 | 32.60 mops |
| bi_mont_ctx_256_redc_512 | :heavy_check_mark: | 92 | 106 | 32.60 mops |
| bi_mont_ctx_256_mul | :heavy_check_mark: | 176 | 192 | 17.04 mops |
| bi_mont_ctx_256_square | :heavy_check_mark: | 165 | 663 | 18.18 mops |
| bi_mont_ctx_256_pow | :heavy_check_mark: | 59610 | 97477 | 50.32 kops |

## ecc
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| ec_affine_point_256_copy | :heavy_check_mark: | 0 | 0 | N/A |
| ec_affine_point_256_double | :heavy_check_mark: | 27803 | 31325 | 107.90 kops |
| ec_affine_point_256_shl | :heavy_check_mark: | 0 | 61571 | N/A |
| ec_affine_point_256_add | :heavy_check_mark: | 28722 | 40393 | 104.44 kops |
| ec_affine_point_256_sub | :heavy_check_mark: | 28712 | 34417 | 104.48 kops |
| ec_affine_point_256_mul | :heavy_check_mark: | 9894717 | 10355739 | 303 ops |
| ec_affine_point_256_negate | :heavy_check_mark: | 0 | 0 | N/A |
| ec_projective_point_256_copy | :heavy_check_mark: | 0 | 0 | N/A |
| ec_projective_point_256_double | :heavy_check_mark: | 4668 | 7201 | 642.67 kops |
| ec_projective_point_256_add | :heavy_check_mark: | 6311 | 7465 | 475.36 kops |
| ec_projective_point_256_from_affine_point | :heavy_check_mark: | 3 | 3 | 1.00 gops |
| ec_projective_point_256_to_affine_point | :heavy_check_mark: | 26799 | 27313 | 111.94 kops |

