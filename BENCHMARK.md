# ecc.asm tests

# Cpu Info

Intel(R) Core(TM) i7-8700K CPU @ 3.70GHz
## bi_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_zero_128 | :heavy_check_mark: | 1 | 3 |
| bi_zero_192 | :heavy_check_mark: | 0 | 0 |
| bi_zero_256 | :heavy_check_mark: | 0 | 1 |
| bi_zero_512 | :heavy_check_mark: | 0 | 1 |
| bi_zero_1024 | :heavy_check_mark: | 0 | 1 |

## bi_copy
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_copy_128 | :heavy_check_mark: | 0 | 4 |
| bi_copy_192 | :heavy_check_mark: | 2 | 2 |
| bi_copy_256 | :heavy_check_mark: | 1 | 14 |
| bi_copy_512 | :heavy_check_mark: | 0 | 1 |

## bi_is_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_is_zero_256 | :heavy_check_mark: | 0 | 2 |
| bi_is_zero_512 | :heavy_check_mark: | 0 | 4 |

## bi_rnd
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_rnd_64 | :heavy_check_mark: | 5465 | 6060 |
| bi_rnd_128 | :heavy_check_mark: | 10961 | 11392 |
| bi_rnd_192 | :heavy_check_mark: | 16368 | 18053 |
| bi_rnd_256 | :heavy_check_mark: | 21717 | 22394 |
| bi_rnd_320 | :heavy_check_mark: | 27309 | 27883 |
| bi_rnd_384 | :heavy_check_mark: | 32879 | 34513 |
| bi_rnd_448 | :heavy_check_mark: | 38370 | 39541 |
| bi_rnd_512 | :heavy_check_mark: | 43518 | 44280 |

## bi_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_add_128_128 | :heavy_check_mark: | 0 | 2 |
| bi_add_192_192 | :heavy_check_mark: | 0 | 2 |
| bi_add_256_256 | :heavy_check_mark: | 0 | 1 |
| bi_add_512_512 | :heavy_check_mark: | 2 | 3 |

## bi_sub
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_sub_128_128 | :heavy_check_mark: | 0 | 1 |
| bi_sub_192_192 | :heavy_check_mark: | 0 | 0 |
| bi_sub_256_256 | :heavy_check_mark: | 1 | 2 |
| bi_sub_512_512 | :heavy_check_mark: | 3 | 4 |

## bi_lzcnt
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_lzcnt_128 | :heavy_check_mark: | 0 | 4 |
| bi_lzcnt_192 | :heavy_check_mark: | 0 | 4 |
| bi_lzcnt_256 | :heavy_check_mark: | 1 | 3 |

## bi_shl
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_shl_assign_128_1 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_128 | :heavy_check_mark: | 0 | 1 |
| bi_shl_assign_256_1 | :heavy_check_mark: | 1 | 2 |
| bi_shl_assign_256_64 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_256_128 | :heavy_check_mark: | 0 | 2 |
| bi_shl_assign_256 | :heavy_check_mark: | 11 | 12 |
| bi_shl_assign_512_1 | :heavy_check_mark: | 5 | 5 |
| bi_shl_assign_512_64 | :heavy_check_mark: | 2 | 3 |
| bi_shl_assign_512_128 | :heavy_check_mark: | 0 | 2 |
| bi_shl_assign_512_256 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_512 | :heavy_check_mark: | 4 | 6 |

## bi_shr
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_shr_assign_128_1 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_128 | :heavy_check_mark: | 1 | 2 |
| bi_shr_assign_256_1 | :heavy_check_mark: | 1 | 2 |
| bi_shr_assign_256_64 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_256_128 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_256 | :heavy_check_mark: | 8 | 9 |
| bi_shr_assign_512_1 | :heavy_check_mark: | 4 | 5 |
| bi_shr_assign_512_64 | :heavy_check_mark: | 2 | 3 |
| bi_shr_assign_512_128 | :heavy_check_mark: | 0 | 2 |
| bi_shr_assign_512_256 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_512 | :heavy_check_mark: | 16 | 22 |

## bi_cmp
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_cmp_128_128 | :heavy_check_mark: | 0 | 1 |
| bi_cmp_192_192 | :heavy_check_mark: | 3 | 4 |
| bi_cmp_256_256 | :heavy_check_mark: | 5 | 6 |
| bi_cmp_512_512 | :heavy_check_mark: | 14 | 15 |

## bi_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mul_128_64 | :heavy_check_mark: | 0 | 1 |
| bi_mul_128_128 | :heavy_check_mark: | 4 | 5 |
| bi_mul_192_64 | :heavy_check_mark: | 2 | 3 |
| bi_mul_256_64 | :heavy_check_mark: | 3 | 4 |
| bi_mul_256_128 | :heavy_check_mark: | 35 | 37 |
| bi_mul_256_256 | :heavy_check_mark: | 79 | 81 |
| bi_mul_320_64 | :heavy_check_mark: | 5 | 6 |
| bi_mul_512_64 | :heavy_check_mark: | 11 | 12 |
| bi_mul_512_256 | :heavy_check_mark: | 126 | 130 |
| bi_mul_512_512 | :heavy_check_mark: | 415 | 417 |

## bi_mul_low
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mul_128_64_low_128 | :heavy_check_mark: | 0 | 0 |
| bi_mul_128_128_low_128 | :heavy_check_mark: | 2 | 3 |
| bi_mul_192_64_low_192 | :heavy_check_mark: | 2 | 2 |
| bi_mul_256_64_low_256 | :heavy_check_mark: | 3 | 3 |
| bi_mul_256_128_low_256 | :heavy_check_mark: | 28 | 28 |
| bi_mul_256_256_low_256 | :heavy_check_mark: | 13 | 16 |
| bi_mul_512_64_low_512 | :heavy_check_mark: | 11 | 13 |
| bi_mul_512_512_low_512 | :heavy_check_mark: | 144 | 146 |

## bi_square
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_square_128 | :heavy_check_mark: | 1 | 3 |
| bi_square_256 | :heavy_check_mark: | 64 | 66 |

## bi_div_rem
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_div_rem_128_64 | :heavy_check_mark: | 41 | 108 |
| bi_div_rem_128_128 | :heavy_check_mark: | 3 | 124 |
| bi_div_rem_192_64 | :heavy_check_mark: | 61 | 189 |
| bi_div_rem_192_128 | :heavy_check_mark: | 67 | 365 |
| bi_div_rem_192_192 | :heavy_check_mark: | 28 | 337 |
| bi_div_rem_256_64 | :heavy_check_mark: | 85 | 298 |
| bi_div_rem_256_128 | :heavy_check_mark: | 143 | 544 |
| bi_div_rem_256_192 | :heavy_check_mark: | 328 | 391 |
| bi_div_rem_256_256 | :heavy_check_mark: | 32 | 337 |
| bi_div_rem_320_64 | :heavy_check_mark: | 103 | 357 |
| bi_div_rem_320_128 | :heavy_check_mark: | 245 | 785 |
| bi_div_rem_320_192 | :heavy_check_mark: | 154 | 574 |
| bi_div_rem_320_256 | :heavy_check_mark: | 74 | 368 |
| bi_div_rem_320_320 | :heavy_check_mark: | 159 | 163 |
| bi_div_rem_384_64 | :heavy_check_mark: | 125 | 445 |
| bi_div_rem_384_128 | :heavy_check_mark: | 341 | 1150 |
| bi_div_rem_384_192 | :heavy_check_mark: | 402 | 810 |
| bi_div_rem_448_64 | :heavy_check_mark: | 144 | 533 |
| bi_div_rem_448_128 | :heavy_check_mark: | 682 | 1301 |
| bi_div_rem_512_64 | :heavy_check_mark: | 165 | 606 |
| bi_div_rem_512_128 | :heavy_check_mark: | 702 | 1889 |
| bi_div_rem_512_256 | :heavy_check_mark: | 424 | 1285 |
| bi_div_rem_512_512 | :heavy_check_mark: | 164 | 170 |
| bi_rem_128_64 | :heavy_check_mark: | 39 | 124 |
| bi_rem_128_128 | :heavy_check_mark: | 2 | 106 |
| bi_rem_192_64 | :heavy_check_mark: | 61 | 208 |
| bi_rem_192_128 | :heavy_check_mark: | 56 | 316 |
| bi_rem_192_192 | :heavy_check_mark: | 23 | 315 |
| bi_rem_256_64 | :heavy_check_mark: | 82 | 274 |
| bi_rem_256_128 | :heavy_check_mark: | 121 | 488 |
| bi_rem_256_192 | :heavy_check_mark: | 323 | 364 |
| bi_rem_256_256 | :heavy_check_mark: | 32 | 178 |
| bi_rem_320_64 | :heavy_check_mark: | 103 | 357 |
| bi_rem_320_128 | :heavy_check_mark: | 189 | 705 |
| bi_rem_320_192 | :heavy_check_mark: | 123 | 527 |
| bi_rem_320_256 | :heavy_check_mark: | 65 | 338 |
| bi_rem_320_320 | :heavy_check_mark: | 152 | 160 |
| bi_rem_384_64 | :heavy_check_mark: | 124 | 438 |
| bi_rem_384_128 | :heavy_check_mark: | 247 | 911 |
| bi_rem_384_192 | :heavy_check_mark: | 306 | 751 |
| bi_rem_448_64 | :heavy_check_mark: | 144 | 523 |
| bi_rem_448_128 | :heavy_check_mark: | 455 | 1114 |
| bi_rem_448_192 | :heavy_check_mark: | 486 | 1176 |
| bi_rem_512_64 | :heavy_check_mark: | 166 | 606 |
| bi_rem_512_128 | :heavy_check_mark: | 410 | 1392 |
| bi_rem_512_256 | :heavy_check_mark: | 303 | 1077 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_add_assign_256_256 | :heavy_check_mark: | 12 | 18 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_double_assign_256 | :heavy_check_mark: | 26 | 48 |

## bi_mod_tripple
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_tripple_assign_256 | :heavy_check_mark: | 31 | 39 |

## bi_mod_half
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_half_assign_256 | :heavy_check_mark: | 27 | 28 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_sub_256_256 | :heavy_check_mark: | 7 | 15 |
| bi_mod_sub_assign_256_256 | :heavy_check_mark: | 8 | 10 |

## bi_mod_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_mul_256_256 | :heavy_check_mark: | 115 | 405 |

## bi_mod_div
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_div_256_256 | :heavy_check_mark: | 24312 | 27986 |

## bi_mod_square
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_square_256 | :heavy_check_mark: | 103 | 390 |

## bi_mod_cube
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_cube_256 | :heavy_check_mark: | 352 | 943 |

## bi_mod_pow
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_pow_256 | :heavy_check_mark: | 166651 | 167432 |

## bi_mod_inverse
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_inverse_256 | :heavy_check_mark: | 26387 | 26844 |
| bi_mod_inverse_512 | :heavy_check_mark: | 52483 | 52799 |

## bi_mont
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mont_ctx_256_init | :heavy_check_mark: | 6865 | 7058 |
| bi_mont_ctx_256_convert | :heavy_check_mark: | 125 | 171 |
| bi_mont_ctx_256_redc_256 | :heavy_check_mark: | 119 | 125 |
| bi_mont_ctx_256_redc_512 | :heavy_check_mark: | 121 | 125 |
| bi_mont_ctx_256_mul | :heavy_check_mark: | 208 | 210 |
| bi_mont_ctx_256_square | :heavy_check_mark: | 196 | 203 |
| bi_mont_ctx_256_pow | :heavy_check_mark: | 59930 | 95172 |

## ecc
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| ecpoint256_copy | :heavy_check_mark: | 0 | 0 |
| secp256k1_point_add | :heavy_check_mark: | 28623 | 29336 |

