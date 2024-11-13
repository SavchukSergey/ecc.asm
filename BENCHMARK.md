# ecc.asm tests

# Cpu Info

Intel(R) Core(TM) i7-8700K CPU @ 3.70GHz
## bi_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_zero_128 | :heavy_check_mark: | 38 | 40 | 78.94 mops |
| bi_zero_192 | :heavy_check_mark: | 3 | 9 | 1.00 gops |
| bi_zero_256 | :heavy_check_mark: | 2 | 7 | 1.50 gops |
| bi_zero_512 | :heavy_check_mark: | 1 | 9 | 3.00 gops |
| bi_zero_1024 | :heavy_check_mark: | 6 | 78 | 500.00 mops |

## bi_copy
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_copy_128 | :heavy_check_mark: | 2 | 64 | 1.50 gops |
| bi_copy_192 | :heavy_check_mark: | 0 | 10 | N/A |
| bi_copy_256 | :heavy_check_mark: | 0 | 15 | N/A |
| bi_copy_512 | :heavy_check_mark: | 2 | 12 | 1.50 gops |
| bi_copy_768 | :heavy_check_mark: | 2 | 9 | 1.50 gops |

## bi_is_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_is_zero_256 | :heavy_check_mark: | 0 | 19 | N/A |
| bi_is_zero_512 | :heavy_check_mark: | 0 | 0 | N/A |

## bi_rnd
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_rnd_64 | :heavy_check_mark: | 8620 | 19679 | 348.02 kops |
| bi_rnd_128 | :heavy_check_mark: | 11997 | 19882 | 250.06 kops |
| bi_rnd_192 | :heavy_check_mark: | 17022 | 30630 | 176.24 kops |
| bi_rnd_256 | :heavy_check_mark: | 21790 | 30591 | 137.67 kops |
| bi_rnd_320 | :heavy_check_mark: | 27091 | 36746 | 110.73 kops |
| bi_rnd_384 | :heavy_check_mark: | 34085 | 48962 | 88.01 kops |
| bi_rnd_448 | :heavy_check_mark: | 39776 | 57829 | 75.42 kops |
| bi_rnd_512 | :heavy_check_mark: | 43391 | 59244 | 69.13 kops |

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
| bi_sub_192_192 | :heavy_check_mark: | 1 | 1 | 3.00 gops |
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
| bi_shl_assign_512 | :heavy_check_mark: | 0 | 0 | N/A |

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
| bi_shr_assign_512_64 | :heavy_check_mark: | 0 | 4 | N/A |
| bi_shr_assign_512_128 | :heavy_check_mark: | 15 | 15 | 200.00 mops |
| bi_shr_assign_512_256 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_shr_assign_512 | :heavy_check_mark: | 3 | 6 | 1.00 gops |

## bi_cmp
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_cmp_128_128 | :heavy_check_mark: | 2 | 2 | 1.50 gops |
| bi_cmp_192_192 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_cmp_256_256 | :heavy_check_mark: | 6 | 6 | 500.00 mops |
| bi_cmp_512_512 | :heavy_check_mark: | 0 | 0 | N/A |

## bi_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mul_128_64 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_128_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_192_64 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_256_64 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_256_128 | :heavy_check_mark: | 14 | 46 | 214.28 mops |
| bi_mul_256_256 | :heavy_check_mark: | 59 | 102 | 50.84 mops |
| bi_mul_320_64 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_512_64 | :heavy_check_mark: | 13 | 13 | 230.76 mops |
| bi_mul_512_256 | :heavy_check_mark: | 102 | 119 | 29.41 mops |
| bi_mul_512_512 | :heavy_check_mark: | 376 | 1558 | 7.97 mops |

## bi_mul_low
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mul_128_64_low_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_128_128_low_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_192_64_low_192 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_256_64_low_256 | :heavy_check_mark: | 4 | 1136 | 750.00 mops |
| bi_mul_256_128_low_256 | :heavy_check_mark: | 7 | 32 | 428.57 mops |
| bi_mul_256_256_low_256 | :heavy_check_mark: | 1 | 1 | 3.00 gops |
| bi_mul_512_64_low_512 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mul_512_512_low_512 | :heavy_check_mark: | 120 | 155 | 25.00 mops |

## bi_square
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_square_128 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_square_256 | :heavy_check_mark: | 42 | 172 | 71.42 mops |

## bi_div_rem
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_div_rem_128_64 | :heavy_check_mark: | 21 | 1115 | 142.85 mops |
| bi_div_rem_128_128 | :heavy_check_mark: | 88 | 1148 | 34.09 mops |
| bi_div_rem_192_64 | :heavy_check_mark: | 42 | 1233 | 71.42 mops |
| bi_div_rem_192_128 | :heavy_check_mark: | 55 | 533 | 54.54 mops |
| bi_div_rem_192_192 | :heavy_check_mark: | 13 | 183 | 230.76 mops |
| bi_div_rem_256_64 | :heavy_check_mark: | 64 | 259 | 46.87 mops |
| bi_div_rem_256_128 | :heavy_check_mark: | 118 | 577 | 25.42 mops |
| bi_div_rem_256_192 | :heavy_check_mark: | 318 | 491 | 9.43 mops |
| bi_div_rem_256_256 | :heavy_check_mark: | 12 | 170 | 250.00 mops |
| bi_div_rem_320_64 | :heavy_check_mark: | 86 | 339 | 34.88 mops |
| bi_div_rem_320_128 | :heavy_check_mark: | 233 | 901 | 12.87 mops |
| bi_div_rem_320_192 | :heavy_check_mark: | 129 | 596 | 23.25 mops |
| bi_div_rem_320_256 | :heavy_check_mark: | 54 | 398 | 55.55 mops |
| bi_div_rem_320_320 | :heavy_check_mark: | 133 | 166 | 22.55 mops |
| bi_div_rem_384_64 | :heavy_check_mark: | 106 | 425 | 28.30 mops |
| bi_div_rem_384_128 | :heavy_check_mark: | 322 | 1204 | 9.31 mops |
| bi_div_rem_384_192 | :heavy_check_mark: | 397 | 890 | 7.55 mops |
| bi_div_rem_448_64 | :heavy_check_mark: | 126 | 502 | 23.80 mops |
| bi_div_rem_448_128 | :heavy_check_mark: | 639 | 1388 | 4.69 mops |
| bi_div_rem_512_64 | :heavy_check_mark: | 147 | 664 | 20.40 mops |
| bi_div_rem_512_128 | :heavy_check_mark: | 680 | 3066 | 4.41 mops |
| bi_div_rem_512_256 | :heavy_check_mark: | 399 | 1185 | 7.51 mops |
| bi_div_rem_512_512 | :heavy_check_mark: | 148 | 187 | 20.27 mops |
| bi_rem_128_64 | :heavy_check_mark: | 22 | 98 | 136.36 mops |
| bi_rem_128_128 | :heavy_check_mark: | 88 | 97 | 34.09 mops |
| bi_rem_192_64 | :heavy_check_mark: | 42 | 171 | 71.42 mops |
| bi_rem_192_128 | :heavy_check_mark: | 43 | 395 | 69.76 mops |
| bi_rem_192_192 | :heavy_check_mark: | 7 | 315 | 428.57 mops |
| bi_rem_256_64 | :heavy_check_mark: | 63 | 253 | 47.61 mops |
| bi_rem_256_128 | :heavy_check_mark: | 99 | 512 | 30.30 mops |
| bi_rem_256_192 | :heavy_check_mark: | 305 | 1771 | 9.83 mops |
| bi_rem_256_256 | :heavy_check_mark: | 13 | 1533 | 230.76 mops |
| bi_rem_320_64 | :heavy_check_mark: | 85 | 345 | 35.29 mops |
| bi_rem_320_128 | :heavy_check_mark: | 164 | 851 | 18.29 mops |
| bi_rem_320_192 | :heavy_check_mark: | 103 | 693 | 29.12 mops |
| bi_rem_320_256 | :heavy_check_mark: | 44 | 359 | 68.18 mops |
| bi_rem_320_320 | :heavy_check_mark: | 137 | 179 | 21.89 mops |
| bi_rem_384_64 | :heavy_check_mark: | 106 | 423 | 28.30 mops |
| bi_rem_384_128 | :heavy_check_mark: | 237 | 983 | 12.65 mops |
| bi_rem_384_192 | :heavy_check_mark: | 307 | 781 | 9.77 mops |
| bi_rem_448_64 | :heavy_check_mark: | 127 | 512 | 23.62 mops |
| bi_rem_448_128 | :heavy_check_mark: | 421 | 1162 | 7.12 mops |
| bi_rem_448_192 | :heavy_check_mark: | 411 | 1027 | 7.29 mops |
| bi_rem_512_64 | :heavy_check_mark: | 145 | 967 | 20.68 mops |
| bi_rem_512_128 | :heavy_check_mark: | 390 | 2259 | 7.69 mops |
| bi_rem_512_256 | :heavy_check_mark: | 274 | 979 | 10.94 mops |
| bi_rem_512_512 | :heavy_check_mark: | 146 | 201 | 20.54 mops |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_add_assign_256_256 | :heavy_check_mark: | 0 | 7 | N/A |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_double_assign_256 | :heavy_check_mark: | 0 | 23 | N/A |

## bi_mod_tripple
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_tripple_assign_256 | :heavy_check_mark: | 2 | 26 | 1.50 gops |

## bi_mod_half
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_half_assign_256 | :heavy_check_mark: | 0 | 36 | N/A |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_sub_256_256 | :heavy_check_mark: | 0 | 0 | N/A |
| bi_mod_sub_assign_256_256 | :heavy_check_mark: | 0 | 7 | N/A |

## bi_mod_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_mul_256_256 | :heavy_check_mark: | 96 | 444 | 31.25 mops |

## bi_mod_div
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_div_256_256 | :heavy_check_mark: | 24327 | 38816 | 123.31 kops |

## bi_mod_square
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_square_256 | :heavy_check_mark: | 85 | 409 | 35.29 mops |

## bi_mod_cube
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_cube_256 | :heavy_check_mark: | 337 | 853 | 8.90 mops |

## bi_mod_pow
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_pow_256 | :heavy_check_mark: | 163963 | 206734 | 18.29 kops |

## bi_mod_inverse
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mod_inverse_256 | :heavy_check_mark: | 26583 | 36945 | 112.85 kops |
| bi_mod_inverse_512 | :heavy_check_mark: | 53497 | 58829 | 56.07 kops |

## bi_mont
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| bi_mont_ctx_256_init | :heavy_check_mark: | 6793 | 7008 | 441.63 kops |
| bi_mont_ctx_256_convert | :heavy_check_mark: | 104 | 222 | 28.84 mops |
| bi_mont_ctx_256_redc_256 | :heavy_check_mark: | 97 | 136 | 30.92 mops |
| bi_mont_ctx_256_redc_512 | :heavy_check_mark: | 100 | 278 | 30.00 mops |
| bi_mont_ctx_256_mul | :heavy_check_mark: | 185 | 443 | 16.21 mops |
| bi_mont_ctx_256_square | :heavy_check_mark: | 174 | 245 | 17.24 mops |
| bi_mont_ctx_256_pow | :heavy_check_mark: | 59255 | 133179 | 50.62 kops |

## ecc
| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |
| :------------------------------| :----: | ------------: | ------------: |-----: |
| ec_affine_point_256_copy | :heavy_check_mark: | 0 | 0 | N/A |
| ec_affine_point_256_double | :heavy_check_mark: | 27711 | 31885 | 108.26 kops |
| ec_affine_point_256_shl | :heavy_check_mark: | 0 | 78530 | N/A |
| ec_affine_point_256_add | :heavy_check_mark: | 28690 | 31826 | 104.56 kops |
| ec_affine_point_256_sub | :heavy_check_mark: | 28750 | 37881 | 104.34 kops |
| ec_affine_point_256_mul | :heavy_check_mark: | 9954191 | 12337814 | 301 ops |
| ec_affine_point_256_negate | :heavy_check_mark: | 18 | 18 | 166.66 mops |
| ec_projective_point_256_copy | :heavy_check_mark: | 13 | 13 | 230.76 mops |
| ec_projective_point_256_double | :heavy_check_mark: | 4686 | 9281 | 640.20 kops |
| ec_projective_point_256_shl | :heavy_check_mark: | 2 | 13608 | 1.50 gops |
| ec_projective_point_256_add | :heavy_check_mark: | 6329 | 7791 | 474.00 kops |
| ec_projective_point_256_sub | :heavy_check_mark: | 6290 | 9513 | 476.94 kops |
| ec_projective_point_256_mul | :heavy_check_mark: | 1923952 | 1965271 | 1.55 kops |
| ec_projective_point_256_negate | :heavy_check_mark: | 0 | 0 | N/A |
| ec_projective_point_256_from_affine_point | :heavy_check_mark: | 16 | 16 | 187.50 mops |
| ec_projective_point_256_to_affine_point | :heavy_check_mark: | 26897 | 32281 | 111.53 kops |

