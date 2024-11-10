# ecc.asm tests

# Cpu Info

Intel(R) Core(TM) i7-8700K CPU @ 3.70GHz
## bi_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_zero_128 | :heavy_check_mark: | 0 | 0 |
| bi_zero_192 | :heavy_check_mark: | 0 | 0 |
| bi_zero_256 | :heavy_check_mark: | 0 | 0 |
| bi_zero_512 | :heavy_check_mark: | 0 | 0 |
| bi_zero_1024 | :heavy_check_mark: | 0 | 0 |

## bi_copy
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_copy_128 | :heavy_check_mark: | 0 | 0 |
| bi_copy_192 | :heavy_check_mark: | 0 | 0 |
| bi_copy_256 | :heavy_check_mark: | 0 | 0 |
| bi_copy_512 | :heavy_check_mark: | 0 | 0 |

## bi_is_zero
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_is_zero_256 | :heavy_check_mark: | 0 | 7 |
| bi_is_zero_512 | :heavy_check_mark: | 0 | 5 |

## bi_rnd
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_rnd_64 | :heavy_check_mark: | 5466 | 6350 |
| bi_rnd_128 | :heavy_check_mark: | 10950 | 12138 |
| bi_rnd_192 | :heavy_check_mark: | 16418 | 17157 |
| bi_rnd_256 | :heavy_check_mark: | 21995 | 25652 |
| bi_rnd_320 | :heavy_check_mark: | 27397 | 31266 |
| bi_rnd_384 | :heavy_check_mark: | 32888 | 35566 |
| bi_rnd_448 | :heavy_check_mark: | 38334 | 41287 |
| bi_rnd_512 | :heavy_check_mark: | 43866 | 45513 |

## bi_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_add_128_128 | :heavy_check_mark: | 1 | 5 |
| bi_add_192_192 | :heavy_check_mark: | 0 | 1 |
| bi_add_256_256 | :heavy_check_mark: | 0 | 0 |
| bi_add_512_512 | :heavy_check_mark: | 2 | 2 |

## bi_sub
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_sub_128_128 | :heavy_check_mark: | 0 | 1 |
| bi_sub_192_192 | :heavy_check_mark: | 0 | 0 |
| bi_sub_256_256 | :heavy_check_mark: | 0 | 6 |
| bi_sub_512_512 | :heavy_check_mark: | 2 | 2 |

## bi_lzcnt
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_lzcnt_128 | :heavy_check_mark: | 2 | 2 |
| bi_lzcnt_192 | :heavy_check_mark: | 4 | 4 |
| bi_lzcnt_256 | :heavy_check_mark: | 0 | 1 |

## bi_shl
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_shl_assign_128_1 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_128 | :heavy_check_mark: | 1 | 1 |
| bi_shl_assign_256_1 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_256_64 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_256_128 | :heavy_check_mark: | 10 | 10 |
| bi_shl_assign_256 | :heavy_check_mark: | 17 | 18 |
| bi_shl_assign_512_1 | :heavy_check_mark: | 4 | 9 |
| bi_shl_assign_512_64 | :heavy_check_mark: | 2 | 2 |
| bi_shl_assign_512_128 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_512_256 | :heavy_check_mark: | 0 | 0 |
| bi_shl_assign_512 | :heavy_check_mark: | 2 | 2 |

## bi_shr
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_shr_assign_128_1 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_128 | :heavy_check_mark: | 1 | 2 |
| bi_shr_assign_256_1 | :heavy_check_mark: | 0 | 1 |
| bi_shr_assign_256_64 | :heavy_check_mark: | 1 | 2 |
| bi_shr_assign_256_128 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_256 | :heavy_check_mark: | 9 | 14 |
| bi_shr_assign_512_1 | :heavy_check_mark: | 4 | 4 |
| bi_shr_assign_512_64 | :heavy_check_mark: | 2 | 2 |
| bi_shr_assign_512_128 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_512_256 | :heavy_check_mark: | 0 | 0 |
| bi_shr_assign_512 | :heavy_check_mark: | 15 | 18 |

## bi_cmp
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_cmp_128_128 | :heavy_check_mark: | 0 | 0 |
| bi_cmp_192_192 | :heavy_check_mark: | 2 | 3 |
| bi_cmp_256_256 | :heavy_check_mark: | 4 | 9 |
| bi_cmp_512_512 | :heavy_check_mark: | 13 | 14 |

## bi_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mul_128_64 | :heavy_check_mark: | 0 | 4 |
| bi_mul_128_128 | :heavy_check_mark: | 3 | 3 |
| bi_mul_192_64 | :heavy_check_mark: | 2 | 7 |
| bi_mul_256_64 | :heavy_check_mark: | 2 | 3 |
| bi_mul_256_128 | :heavy_check_mark: | 35 | 40 |
| bi_mul_256_256 | :heavy_check_mark: | 80 | 85 |
| bi_mul_320_64 | :heavy_check_mark: | 4 | 10 |
| bi_mul_512_64 | :heavy_check_mark: | 10 | 10 |
| bi_mul_512_256 | :heavy_check_mark: | 128 | 153 |
| bi_mul_512_512 | :heavy_check_mark: | 412 | 419 |

## bi_mul_low
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mul_128_64_low_128 | :heavy_check_mark: | 0 | 0 |
| bi_mul_128_128_low_128 | :heavy_check_mark: | 0 | 5 |
| bi_mul_192_64_low_192 | :heavy_check_mark: | 0 | 0 |
| bi_mul_256_64_low_256 | :heavy_check_mark: | 2 | 6 |
| bi_mul_256_128_low_256 | :heavy_check_mark: | 27 | 32 |
| bi_mul_256_256_low_256 | :heavy_check_mark: | 11 | 12 |
| bi_mul_512_64_low_512 | :heavy_check_mark: | 10 | 10 |
| bi_mul_512_512_low_512 | :heavy_check_mark: | 144 | 150 |

## bi_square
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_square_128 | :heavy_check_mark: | 1 | 6 |
| bi_square_256 | :heavy_check_mark: | 64 | 76 |

## bi_div_rem
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_div_rem_128_64 | :heavy_check_mark: | 41 | 109 |
| bi_div_rem_128_128 | :heavy_check_mark: | 3 | 113 |
| bi_div_rem_192_64 | :heavy_check_mark: | 60 | 193 |
| bi_div_rem_192_128 | :heavy_check_mark: | 70 | 342 |
| bi_div_rem_192_192 | :heavy_check_mark: | 26 | 199 |
| bi_div_rem_256_64 | :heavy_check_mark: | 82 | 279 |
| bi_div_rem_256_128 | :heavy_check_mark: | 142 | 528 |
| bi_div_rem_256_192 | :heavy_check_mark: | 333 | 359 |
| bi_div_rem_256_256 | :heavy_check_mark: | 32 | 163 |
| bi_div_rem_320_64 | :heavy_check_mark: | 102 | 358 |
| bi_div_rem_320_128 | :heavy_check_mark: | 257 | 827 |
| bi_div_rem_320_192 | :heavy_check_mark: | 148 | 570 |
| bi_div_rem_320_256 | :heavy_check_mark: | 72 | 343 |
| bi_div_rem_320_320 | :heavy_check_mark: | 161 | 166 |
| bi_div_rem_384_64 | :heavy_check_mark: | 123 | 440 |
| bi_div_rem_384_128 | :heavy_check_mark: | 323 | 1164 |
| bi_div_rem_384_192 | :heavy_check_mark: | 436 | 842 |
| bi_div_rem_448_64 | :heavy_check_mark: | 143 | 533 |
| bi_div_rem_448_128 | :heavy_check_mark: | 672 | 1271 |
| bi_div_rem_512_64 | :heavy_check_mark: | 166 | 608 |
| bi_div_rem_512_128 | :heavy_check_mark: | 696 | 2968 |
| bi_div_rem_512_256 | :heavy_check_mark: | 405 | 1175 |
| bi_div_rem_512_512 | :heavy_check_mark: | 165 | 172 |
| bi_rem_128_64 | :heavy_check_mark: | 38 | 111 |
| bi_rem_128_128 | :heavy_check_mark: | 0 | 121 |
| bi_rem_192_64 | :heavy_check_mark: | 61 | 198 |
| bi_rem_192_128 | :heavy_check_mark: | 56 | 335 |
| bi_rem_192_192 | :heavy_check_mark: | 22 | 329 |
| bi_rem_256_64 | :heavy_check_mark: | 81 | 275 |
| bi_rem_256_128 | :heavy_check_mark: | 117 | 483 |
| bi_rem_256_192 | :heavy_check_mark: | 320 | 330 |
| bi_rem_256_256 | :heavy_check_mark: | 33 | 179 |
| bi_rem_320_64 | :heavy_check_mark: | 102 | 358 |
| bi_rem_320_128 | :heavy_check_mark: | 196 | 700 |
| bi_rem_320_192 | :heavy_check_mark: | 124 | 546 |
| bi_rem_320_256 | :heavy_check_mark: | 62 | 331 |
| bi_rem_320_320 | :heavy_check_mark: | 153 | 163 |
| bi_rem_384_64 | :heavy_check_mark: | 124 | 447 |
| bi_rem_384_128 | :heavy_check_mark: | 252 | 957 |
| bi_rem_384_192 | :heavy_check_mark: | 334 | 752 |
| bi_rem_448_64 | :heavy_check_mark: | 146 | 527 |
| bi_rem_448_128 | :heavy_check_mark: | 426 | 1081 |
| bi_rem_448_192 | :heavy_check_mark: | 456 | 976 |
| bi_rem_512_64 | :heavy_check_mark: | 164 | 612 |
| bi_rem_512_128 | :heavy_check_mark: | 406 | 1354 |
| bi_rem_512_256 | :heavy_check_mark: | 297 | 892 |
| bi_rem_512_512 | :heavy_check_mark: | 163 | 170 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_add_assign_256_256 | :heavy_check_mark: | 12 | 18 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_double_assign_256 | :heavy_check_mark: | 28 | 34 |

## bi_mod_tripple
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_tripple_assign_256 | :heavy_check_mark: | 28 | 36 |

## bi_mod_half
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_half_assign_256 | :heavy_check_mark: | 24 | 30 |

## bi_mod_add
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_sub_256_256 | :heavy_check_mark: | 6 | 17 |
| bi_mod_sub_assign_256_256 | :heavy_check_mark: | 9 | 11 |

## bi_mod_mul
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_mul_256_256 | :heavy_check_mark: | 114 | 408 |

## bi_mod_div
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_div_256_256 | :heavy_check_mark: | 24185 | 27629 |

## bi_mod_square
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_square_256 | :heavy_check_mark: | 103 | 388 |

## bi_mod_cube
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_cube_256 | :heavy_check_mark: | 359 | 898 |

## bi_mod_pow
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_pow_256 | :heavy_check_mark: | 164103 | 179712 |

## bi_mod_inverse
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mod_inverse_256 | :heavy_check_mark: | 26533 | 31562 |
| bi_mod_inverse_512 | :heavy_check_mark: | 52650 | 56970 |

## bi_mont
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| bi_mont_ctx_256_init | :heavy_check_mark: | 6890 | 9261 |
| bi_mont_ctx_256_convert | :heavy_check_mark: | 126 | 323 |
| bi_mont_ctx_256_redc_256 | :heavy_check_mark: | 120 | 221 |
| bi_mont_ctx_256_redc_512 | :heavy_check_mark: | 210 | 221 |
| bi_mont_ctx_256_mul | :heavy_check_mark: | 206 | 363 |
| bi_mont_ctx_256_square | :heavy_check_mark: | 196 | 361 |
| bi_mont_ctx_256_pow | :heavy_check_mark: | 59207 | 95984 |

## ecc
| Name                           | Status | Min CPU ticks | Max CPU ticks |
| :------------------------------| :----: | ------------: | ------------: |
| ecpoint256_copy | :heavy_check_mark: | 11 | 27 |
| secp256k1_point_add | :heavy_check_mark: | 28623 | 33211 |

