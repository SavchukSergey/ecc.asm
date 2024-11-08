# ecc.asm tests

## bi_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_zero_128 | :heavy_check_mark: | 1 | 1 |
| bi_zero_192 | :heavy_check_mark: | 1 | 1 |
| bi_zero_256 | :heavy_check_mark: | 0 | 0 |
| bi_zero_512 | :heavy_check_mark: | 1 | 1 |
| bi_zero_1024 | :heavy_check_mark: | 1 | 1 |

## bi_copy
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_copy_128 | :heavy_check_mark: | 1 | 1 |
| bi_copy_192 | :heavy_check_mark: | 0 | 0 |
| bi_copy_256 | :heavy_check_mark: | 1 | 1 |
| bi_copy_512 | :heavy_check_mark: | 1 | 1 |

## bi_is_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_is_zero_256 | :heavy_check_mark: | 0 | 6 |
| bi_is_zero_512 | :heavy_check_mark: | 0 | 1 |

## bi_rnd
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_rnd_64 | :heavy_check_mark: | 9747 | 10638 |
| bi_rnd_128 | :heavy_check_mark: | 20066 | 21156 |
| bi_rnd_192 | :heavy_check_mark: | 28056 | 31726 |
| bi_rnd_256 | :heavy_check_mark: | 39214 | 42132 |
| bi_rnd_320 | :heavy_check_mark: | 50239 | 54202 |
| bi_rnd_384 | :heavy_check_mark: | 58761 | 62846 |
| bi_rnd_448 | :heavy_check_mark: | 71719 | 78372 |
| bi_rnd_512 | :heavy_check_mark: | 81673 | 84755 |

## bi_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_add_128_128 | :heavy_check_mark: | 0 | 0 |
| bi_add_192_192 | :heavy_check_mark: | 1 | 1 |
| bi_add_256_256 | :heavy_check_mark: | 1 | 1 |
| bi_add_512_512 | :heavy_check_mark: | 2 | 2 |

## bi_sub
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_sub_128_128 | :heavy_check_mark: | 1 | 8 |
| bi_sub_192_192 | :heavy_check_mark: | 0 | 5 |
| bi_sub_256_256 | :heavy_check_mark: | 1 | 1 |
| bi_sub_512_512 | :heavy_check_mark: | 1 | 3 |

## bi_lzcnt
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_lzcnt_128 | :heavy_check_mark: | 0 | 1 |
| bi_lzcnt_192 | :heavy_check_mark: | 1 | 8 |
| bi_lzcnt_256 | :heavy_check_mark: | 1 | 2 |

## bi_shl
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_shl_assign_128_1 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_128 | :heavy_check_mark: | 1 | 1 |
| bi_shl_assign_256_1 | :heavy_check_mark: | 1 | 1 |
| bi_shl_assign_256_64 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_256_128 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_256 | :heavy_check_mark: | 4 | 4 |
| bi_shl_assign_512_1 | :heavy_check_mark: | 1 | 1 |
| bi_shl_assign_512_64 | :heavy_check_mark: | 1 | 3 |
| bi_shl_assign_512_128 | :heavy_check_mark: | 0 | 4 |
| bi_shl_assign_512_256 | :heavy_check_mark: | 1 | 1 |
| bi_shl_assign_512 | :heavy_check_mark: | 3 | 10 |

## bi_shr
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_shr_assign_128_1 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_128 | :heavy_check_mark: | 1 | 3 |
| bi_shr_assign_256_1 | :heavy_check_mark: | 1 | 1 |
| bi_shr_assign_256_64 | :heavy_check_mark: | 1 | 1 |
| bi_shr_assign_256_128 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_256 | :heavy_check_mark: | 5 | 11 |
| bi_shr_assign_512_1 | :heavy_check_mark: | 1 | 1 |
| bi_shr_assign_512_64 | :heavy_check_mark: | 1 | 1 |
| bi_shr_assign_512_128 | :heavy_check_mark: | 1 | 1 |
| bi_shr_assign_512_256 | :heavy_check_mark: | 0 | 4 |
| bi_shr_assign_512 | :heavy_check_mark: | 8 | 8 |

## bi_cmp
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_cmp_128_128 | :heavy_check_mark: | 1 | 1 |
| bi_cmp_192_192 | :heavy_check_mark: | 1 | 3 |
| bi_cmp_256_256 | :heavy_check_mark: | 1 | 2 |
| bi_cmp_512_512 | :heavy_check_mark: | 1 | 1 |

## bi_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mul_128_64 | :heavy_check_mark: | 1 | 4 |
| bi_mul_128_128 | :heavy_check_mark: | 1 | 1 |
| bi_mul_192_64 | :heavy_check_mark: | 1 | 6 |
| bi_mul_256_64 | :heavy_check_mark: | 2 | 2 |
| bi_mul_256_128 | :heavy_check_mark: | 14 | 17 |
| bi_mul_256_256 | :heavy_check_mark: | 36 | 41 |
| bi_mul_320_64 | :heavy_check_mark: | 2 | 2 |
| bi_mul_512_64 | :heavy_check_mark: | 6 | 8 |
| bi_mul_512_256 | :heavy_check_mark: | 65 | 70 |
| bi_mul_512_512 | :heavy_check_mark: | 197 | 212 |

## bi_mul_low
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mul_128_64_low_128 | :heavy_check_mark: | 1 | 1 |
| bi_mul_128_128_low_128 | :heavy_check_mark: | 0 | 0 |
| bi_mul_192_64_low_192 | :heavy_check_mark: | 1 | 3 |
| bi_mul_256_64_low_256 | :heavy_check_mark: | 1 | 1 |
| bi_mul_256_128_low_256 | :heavy_check_mark: | 11 | 53 |
| bi_mul_256_256_low_256 | :heavy_check_mark: | 5 | 8 |
| bi_mul_512_64_low_512 | :heavy_check_mark: | 5 | 5 |
| bi_mul_512_512_low_512 | :heavy_check_mark: | 69 | 74 |

## bi_square
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_square_128 | :heavy_check_mark: | 1 | 2 |
| bi_square_256 | :heavy_check_mark: | 29 | 34 |

## bi_div_rem
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_div_rem_128_64 | :heavy_check_mark: | 12 | 88 |
| bi_div_rem_128_128 | :heavy_check_mark: | 2 | 31 |
| bi_div_rem_192_64 | :heavy_check_mark: | 22 | 171 |
| bi_div_rem_192_128 | :heavy_check_mark: | 39 | 103 |
| bi_div_rem_192_192 | :heavy_check_mark: | 20 | 76 |
| bi_div_rem_256_64 | :heavy_check_mark: | 31 | 136 |
| bi_div_rem_256_128 | :heavy_check_mark: | 78 | 196 |
| bi_div_rem_256_192 | :heavy_check_mark: | 98 | 124 |
| bi_div_rem_256_256 | :heavy_check_mark: | 18 | 79 |
| bi_div_rem_320_64 | :heavy_check_mark: | 40 | 163 |
| bi_div_rem_320_128 | :heavy_check_mark: | 138 | 266 |
| bi_div_rem_320_192 | :heavy_check_mark: | 98 | 190 |
| bi_div_rem_384_64 | :heavy_check_mark: | 50 | 204 |
| bi_div_rem_384_128 | :heavy_check_mark: | 210 | 383 |
| bi_div_rem_448_64 | :heavy_check_mark: | 59 | 234 |
| bi_div_rem_448_128 | :heavy_check_mark: | 332 | 449 |
| bi_div_rem_512_64 | :heavy_check_mark: | 69 | 286 |
| bi_div_rem_512_128 | :heavy_check_mark: | 381 | 680 |
| bi_div_rem_512_256 | :heavy_check_mark: | 246 | 453 |
| bi_div_rem_512_512 | :heavy_check_mark: | 50 | 53 |
| bi_rem_128_64 | :heavy_check_mark: | 12 | 68 |
| bi_rem_128_128 | :heavy_check_mark: | 3 | 61 |
| bi_rem_192_64 | :heavy_check_mark: | 22 | 89 |
| bi_rem_192_128 | :heavy_check_mark: | 35 | 115 |
| bi_rem_192_192 | :heavy_check_mark: | 16 | 104 |
| bi_rem_256_64 | :heavy_check_mark: | 31 | 120 |
| bi_rem_256_128 | :heavy_check_mark: | 61 | 184 |
| bi_rem_512_64 | :heavy_check_mark: | 69 | 274 |
| bi_rem_512_128 | :heavy_check_mark: | 250 | 589 |
| bi_rem_512_256 | :heavy_check_mark: | 165 | 337 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_add_assign_256_256 | :heavy_check_mark: | 8 | 10 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_double_assign_256 | :heavy_check_mark: | 14 | 17 |

## bi_mod_tripple
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_tripple_assign_256 | :heavy_check_mark: | 16 | 22 |

## bi_mod_half
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_half_assign_256 | :heavy_check_mark: | 13 | 48 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_sub_256_256 | :heavy_check_mark: | 3 | 7 |
| bi_mod_sub_assign_256_256 | :heavy_check_mark: | 6 | 9 |

## bi_mod_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_mul_256_256 | :heavy_check_mark: | 67 | 239 |

## bi_mod_div
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_div_256_256 | :heavy_check_mark: | 9172 | 10848 |

## bi_mod_square
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_square_256 | :heavy_check_mark: | 57 | 233 |

## bi_mod_cube
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_cube_256 | :heavy_check_mark: | 217 | 473 |

## bi_mod_pow
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_pow_256 | :heavy_check_mark: | 100965 | 101533 |

## bi_mod_inverse
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_inverse_256 | :heavy_check_mark: | 9408 | 9639 |
| bi_mod_inverse_512 | :heavy_check_mark: | 24608 | 25274 |

## bi_mont
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mont_ctx_256_init | :heavy_check_mark: | 3204 | 3252 |
| bi_mont_ctx_256_convert | :heavy_check_mark: | 71 | 112 |
| bi_mont_ctx_256_redc_256 | :heavy_check_mark: | 66 | 74 |
| bi_mont_ctx_256_redc_512 | :heavy_check_mark: | 67 | 71 |
| bi_mont_ctx_256_mul | :heavy_check_mark: | 111 | 122 |
| bi_mont_ctx_256_square | :heavy_check_mark: | 105 | 149 |
| bi_mont_ctx_256_pow | :heavy_check_mark: | 33785 | 53666 |

## ecc
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| ecpoint256_copy | :heavy_check_mark: | 0 | 0 |
| secp256k1_point_add | :heavy_check_mark: | 11032 | 11621 |

