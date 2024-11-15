# ecc.asm

Blazing fast library written in pure assembly language that implements big integer math and elliptic curve cryptography

Full list of methods:

| Name                                                                   | Description                                                                      |
|------------------------------------------------------------------------|----------------------------------------------------------------------------------|
| [bi_add_128_128](#bi_add_128_128)                                      | Adds two `bi128` values                                                          |
| [bi_add_192_192](#bi_add_192_192)                                      | Adds two `bi192` values                                                          |
| [bi_add_256_256](#bi_add_256_256)                                      | Adds two `bi256` values                                                          |
| [bi_add_512_512](#bi_add_512_512)                                      | Adds two `bi512` values                                                          |
| [bi_add_assign_128_128](#bi_add_assign_128_128)                        | Adds two `bi128` values and assigns result to the left `bi128` value             |
| [bi_add_assign_192_128](#bi_add_assign_192_128)                        | Adds `bi192` and `bi128` values and assigns result to the left `bi192` value     |
| [bi_add_assign_192_192](#bi_add_assign_192_192)                        | Adds two `bi192` values and assigns result to the left `bi192` value             |
| [bi_add_assign_256_128](#bi_add_assign_256_128)                        | Adds `bi256` and `bi128` values and assigns result to the left `bi256` value     |
| [bi_add_assign_256_192](#bi_add_assign_256_192)                        | Adds `bi256` and `bi192` values and assigns result to the left `bi256` value     |
| [bi_add_assign_256_256](#bi_add_assign_256_256)                        | Adds two `bi256` values and assigns result to the left `bi256` value             |
| [bi_add_assign_320_128](#bi_add_assign_320_128)                        | Adds `bi320` and `bi128` values and assigns result to the left `bi320` value     |
| [bi_add_assign_320_192](#bi_add_assign_320_192)                        | Adds `bi320` and `bi192` values and assigns result to the left `bi320` value     |
| [bi_add_assign_320_256](#bi_add_assign_320_256)                        | Adds `bi320` and `bi256` values and assigns result to the left `bi320` value     |
| [bi_add_assign_320_320](#bi_add_assign_320_320)                        | Adds two `bi320` values and assigns result to the left `bi320` value             |
| [bi_add_assign_384_128](#bi_add_assign_384_128)                        | Adds `bi384` and `bi128` values and assigns result to the left `bi384` value     |
| [bi_add_assign_384_192](#bi_add_assign_384_192)                        | Adds `bi384` and `bi192` values and assigns result to the left `bi384` value     |
| [bi_add_assign_384_256](#bi_add_assign_384_256)                        | Adds `bi384` and `bi256` values and assigns result to the left `bi384` value     |
| [bi_add_assign_384_320](#bi_add_assign_384_320)                        | Adds `bi384` and `bi320` values and assigns result to the left `bi384` value     |
| [bi_add_assign_384_384](#bi_add_assign_384_384)                        | Adds two `bi384` values and assigns result to the left `bi384` value             |
| [bi_add_assign_448_128](#bi_add_assign_448_128)                        | Adds `bi448` and `bi128` values and assigns result to the left `bi448` value     |
| [bi_add_assign_448_192](#bi_add_assign_448_192)                        | Adds `bi448` and `bi192` values and assigns result to the left `bi448` value     |
| [bi_add_assign_448_256](#bi_add_assign_448_256)                        | Adds two `bi448` and `bi256` values and assigns result to the left `bi448` value |
| [bi_add_assign_448_320](#bi_add_assign_448_320)                        | Adds two `bi448` and `bi320` values and assigns result to the left `bi448` value |
| [bi_add_assign_448_384](#bi_add_assign_448_384)                        | Adds two `bi448` and `bi384` values and assigns result to the left `bi448` value |
| [bi_add_assign_448_448](#bi_add_assign_448_448)                        | Adds two `bi448` values and assigns result to the left `bi448` value             |
| [bi_add_assign_512_256](#bi_add_assign_512_256)                        | Adds `bi512` and `bi256` values and assigns result to the left `bi512` value     |
| [bi_add_assign_512_384](#bi_add_assign_512_384)                        | Adds `bi512` and `bi384` values and assigns result to the left `bi512` value     |
| [bi_add_assign_512_448](#bi_add_assign_512_448)                        | Adds `bi512` and `bi448` values and assigns result to the left `bi512` value     |
| [bi_add_assign_512_512](#bi_add_assign_512_512)                        | Adds two `bi512` values and assigns result to the left `bi512` value             |
| [bi_add_assign_576_576](#bi_add_assign_576_576)                        | Adds two `bi576` values and assigns result to the left `bi576` value             |
| [bi_add_assign_640_512](#bi_add_assign_640_512)                        | Adds `bi640` and `bi512` values and assigns result to the left `bi640` value     |
| [bi_add_assign_768_512](#bi_add_assign_768_512)                        | Adds two `bi768` values and assigns result to the left `bi768` value             |
| [bi_add_assign_1024_512](#bi_add_assign_1024_512)                      | Adds `bi1024` and `bi512` values and assigns result to the left `bi1024` value   |
| [bi_add_assign_1024_1024](#bi_add_assign_1024_1024)                    | Adds two `bi1024` values and assigns result to the left `bi1024` value           |
| [bi_bit_check_128](#bi_bit_check_128)                                  | Checks bit in `bi128` value                                                      |
| [bi_bit_check_256](#bi_bit_check_256)                                  | Checks bit in `bi256` value                                                      |
| [bi_bit_check_512](#bi_bit_check_512)                                  | Checks bit in `bi512` value                                                      |
| [bi_bit_clear_128](#bi_bit_clear_128)                                  | Clears a bit in `bi128` value                                                    |
| [bi_bit_clear_256](#bi_bit_clear_256)                                  | Clears a bit in `bi256` value                                                    |
| [bi_bit_clear_512](#bi_bit_clear_512)                                  | Clears a bit in `bi512` value                                                    |
| [bi_bit_set_128](#bi_bit_set_128)                                      | Sets a bit in `bi128` value                                                      |
| [bi_bit_set_256](#bi_bit_set_256)                                      | Sets a bit in `bi256` value                                                      |
| [bi_bit_set_512](#bi_bit_set_512)                                      | Sets a bit in `bi512` value                                                      |
| [bi_cmp_128_128](#bi_cmp_128_128)                                      | Compares two `bi128` values                                                      |
| [bi_cmp_192_128](#bi_cmp_192_128)                                      | Compares `bi192` to `bi128` values                                               |
| [bi_cmp_192_192](#bi_cmp_192_192)                                      | Compares two `bi192` values                                                      |
| [bi_cmp_256_128](#bi_cmp_256_128)                                      | Compares `bi256` to `bi128` values                                               |
| [bi_cmp_256_192](#bi_cmp_256_192)                                      | Compares `bi256` to `bi192` values                                               |
| [bi_cmp_256_256](#bi_cmp_256_256)                                      | Compares two `bi256` values                                                      |
| [bi_cmp_320_128](#bi_cmp_320_128)                                      | Compares `bi320` to `bi128` value                                                |
| [bi_cmp_320_192](#bi_cmp_320_192)                                      | Compares `bi320` to `bi192` values                                               |
| [bi_cmp_320_256](#bi_cmp_320_256)                                      | Compares `bi320` to `bi256` values                                               |
| [bi_cmp_320_320](#bi_cmp_320_320)                                      | Compares two `bi320` values                                                      |
| [bi_cmp_384_128](#bi_cmp_384_128)                                      | Compares `bi384` to `bi128` values                                               |
| [bi_cmp_384_192](#bi_cmp_384_192)                                      | Compares `bi384` to `bi192` values                                               |
| [bi_cmp_384_256](#bi_cmp_384_256)                                      | Compares `bi384` to `bi256` values                                               |
| [bi_cmp_384_320](#bi_cmp_384_320)                                      | Compares `bi384` to `bi320` values                                               |
| [bi_cmp_384_384](#bi_cmp_384_384)                                      | Compares two `bi384` values                                                      |
| [bi_cmp_448_128](#bi_cmp_448_128)                                      | Compares `bi448` to `bi128` values                                               |
| [bi_cmp_448_192](#bi_cmp_448_192)                                      | Compares `bi448` to `bi192` values                                               |
| [bi_cmp_448_256](#bi_cmp_448_256)                                      | Compares `bi448` to `bi256` values                                               |
| [bi_cmp_448_320](#bi_cmp_448_320)                                      | Compares `bi448` to `bi320` values                                               |
| [bi_cmp_448_384](#bi_cmp_448_384)                                      | Compares `bi448` to `bi384` values                                               |
| [bi_cmp_448_448](#bi_cmp_448_448)                                      | Compares two `bi448` values                                                      |
| [bi_cmp_512_128](#bi_cmp_512_128)                                      | Compares `bi512` to `bi128` values                                               |
| [bi_cmp_512_192](#bi_cmp_512_192)                                      | Compares `bi512` to `bi192` values                                               |
| [bi_cmp_512_256](#bi_cmp_512_256)                                      | Compares `bi512` to `bi256` values                                               |
| [bi_cmp_512_320](#bi_cmp_512_320)                                      | Compares `bi512` to `bi320` values                                               |
| [bi_cmp_512_384](#bi_cmp_512_384)                                      | Compares `bi512` to `bi384` values                                               |
| [bi_cmp_512_448](#bi_cmp_512_448)                                      | Compares `bi512` to `bi448` values                                               |
| [bi_cmp_512_512](#bi_cmp_512_512)                                      | Compares two `bi512` values                                                      |
| [bi_cmp_576_576](#bi_cmp_576_576)                                      | Compares two `bi576` values                                                      |
| [bi_cmp_768_768](#bi_cmp_768_768)                                      | Compares two `bi768` values                                                      |
| [bi_cmp_1024_1024](#bi_cmp_1024_1024)                                  | Compares two `bi1024` values                                                     |
| [bi_copy_128](#bi_copy_128)                                            | Copies `bi128` value                                                             |
| [bi_copy_192](#bi_copy_192)                                            | Copies `bi192` value                                                             |
| [bi_copy_256](#bi_copy_256)                                            | Copies `bi256` value                                                             |
| [bi_copy_320](#bi_copy_320)                                            | Copies `bi320` value                                                             |
| [bi_copy_384](#bi_copy_384)                                            | Copies `bi384` value                                                             |
| [bi_copy_448](#bi_copy_448)                                            | Copies `bi448` value                                                             |
| [bi_copy_512](#bi_copy_512)                                            | Copies `bi512` value                                                             |
| [bi_copy_768](#bi_copy_768)                                            | Copies `bi768` value                                                             |
| [bi_dec_assign_256](#bi_dec_assign_256)                                | Decrements `bi256` value                                                         |
| [bi_div_128_64](#bi_div_128_64)                                        | Divides `bi128` by `bi64`                                                        |
| [bi_div_rem_128_64](#bi_div_rem_128_64)                                | Divides `bi128` by `bi64`                                                        |
| [bi_div_rem_128_128](#bi_div_rem_128_128)                              | Divides `bi128` by `bi128`                                                       |
| [bi_div_rem_192_64](#bi_div_rem_192_64)                                | Divides `bi192` by `bi64`                                                        |
| [bi_div_rem_192_128](#bi_div_rem_192_128)                              | Divides `bi192` by `bi128`                                                       |
| [bi_div_rem_192_192](#bi_div_rem_192_192)                              |                                                                                  |
| [bi_div_rem_256_64](#bi_div_rem_256_64)                                | Divides `bi256` by `bi64`                                                        |
| [bi_div_rem_256_128](#bi_div_rem_256_128)                              | Divides `bi256` by `bi128`                                                       |
| [bi_div_rem_256_192](#bi_div_rem_256_192)                              |                                                                                  |
| [bi_div_rem_256_256](#bi_div_rem_256_256)                              | Divides `bi256` by `bi256`                                                       |
| [bi_div_rem_320_64](#bi_div_rem_320_64)                                | Divides `bi320` by `bi64`                                                        |
| [bi_div_rem_320_128](#bi_div_rem_320_128)                              |                                                                                  |
| [bi_div_rem_320_192](#bi_div_rem_320_192)                              |                                                                                  |
| [bi_div_rem_320_256](#bi_div_rem_320_256)                              |                                                                                  |
| [bi_div_rem_320_320](#bi_div_rem_320_320)                              |                                                                                  |
| [bi_div_rem_384_64](#bi_div_rem_384_64)                                |                                                                                  |
| [bi_div_rem_384_128](#bi_div_rem_384_128)                              |                                                                                  |
| [bi_div_rem_384_192](#bi_div_rem_384_192)                              |                                                                                  |
| [bi_div_rem_384_256](#bi_div_rem_384_256)                              |                                                                                  |
| [bi_div_rem_384_320](#bi_div_rem_384_320)                              |                                                                                  |
| [bi_div_rem_384_384](#bi_div_rem_384_384)                              |                                                                                  |
| [bi_div_rem_448_64](#bi_div_rem_448_64)                                |                                                                                  |
| [bi_div_rem_448_128](#bi_div_rem_448_128)                              |                                                                                  |
| [bi_div_rem_448_192](#bi_div_rem_448_192)                              |                                                                                  |
| [bi_div_rem_448_256](#bi_div_rem_448_256)                              |                                                                                  |
| [bi_div_rem_448_320](#bi_div_rem_448_320)                              |                                                                                  |
| [bi_div_rem_448_384](#bi_div_rem_448_384)                              |                                                                                  |
| [bi_div_rem_448_448](#bi_div_rem_448_448)                              |                                                                                  |
| [bi_div_rem_512_64](#bi_div_rem_512_64)                                |                                                                                  |
| [bi_div_rem_512_128](#bi_div_rem_512_128)                              |                                                                                  |
| [bi_div_rem_512_192](#bi_div_rem_512_192)                              |                                                                                  |
| [bi_div_rem_512_256](#bi_div_rem_512_256)                              |                                                                                  |
| [bi_div_rem_512_320](#bi_div_rem_512_320)                              |                                                                                  |
| [bi_div_rem_512_384](#bi_div_rem_512_384)                              |                                                                                  |
| [bi_div_rem_512_448](#bi_div_rem_512_448)                              |                                                                                  |
| [bi_div_rem_512_512](#bi_div_rem_512_512)                              |                                                                                  |
| [bi_euclid_ext_256](#bi_euclid_ext_256)                                |                                                                                  |
| [bi_extend_128_64](#bi_extend_128_64)                                  |                                                                                  |
| [bi_extend_192_64](#bi_extend_192_64)                                  |                                                                                  |
| [bi_extend_192_128](#bi_extend_192_128)                                |                                                                                  |
| [bi_extend_256_64](#bi_extend_256_64)                                  |                                                                                  |
| [bi_extend_256_128](#bi_extend_256_128)                                |                                                                                  |
| [bi_extend_320_128](#bi_extend_320_128)                                |                                                                                  |
| [bi_extend_384_64](#bi_extend_384_64)                                  |                                                                                  |
| [bi_extend_384_128](#bi_extend_384_128)                                |                                                                                  |
| [bi_extend_448_64](#bi_extend_448_64)                                  |                                                                                  |
| [bi_extend_448_128](#bi_extend_448_128)                                |                                                                                  |
| [bi_extend_512_64](#bi_extend_512_64)                                  |                                                                                  |
| [bi_extend_512_128](#bi_extend_512_128)                                |                                                                                  |
| [bi_extend_512_256](#bi_extend_512_256)                                |                                                                                  |
| [bi_extend_assign_128_64](#bi_extend_assign_128_64)                    |                                                                                  |
| [bi_extend_assign_192_64](#bi_extend_assign_192_64)                    |                                                                                  |
| [bi_extend_assign_384_64](#bi_extend_assign_384_64)                    |                                                                                  |
| [bi_extend_assign_448_64](#bi_extend_assign_448_64)                    |                                                                                  |
| [bi_inc_assign_128](#bi_inc_assign_128)                                | Increments `bi128` value                                                         |
| [bi_inc_assign_192](#bi_inc_assign_192)                                | Increments `bi192` value                                                         |
| [bi_inc_assign_256](#bi_inc_assign_256)                                | Increments `bi256` value                                                         |
| [bi_inc_assign_320](#bi_inc_assign_320)                                | Increments `bi320` value                                                         |
| [bi_inc_assign_384](#bi_inc_assign_384)                                | Increments `bi384` value                                                         |
| [bi_inc_assign_448](#bi_inc_assign_448)                                | Increments `bi448` value                                                         |
| [bi_inc_assign_512](#bi_inc_assign_512)                                | Increments `bi512` value                                                         |
| [bi_is_zero_256](#bi_is_zero_256)                                      | Checks if `bi256` value is zero                                                  |
| [bi_is_zero_512](#bi_is_zero_512)                                      | Checks if `bi512` value is zero                                                  |
| [bi_lzcnt_128](#bi_lzcnt_128)                                          | Counts leading zero bits of `bi128`                                              |
| [bi_lzcnt_192](#bi_lzcnt_192)                                          | Counts leading zero bits of `bi192`                                              |
| [bi_lzcnt_256](#bi_lzcnt_256)                                          | Counts leading zero bits of `bi256`                                              |
| [bi_lzcnt_320](#bi_lzcnt_320)                                          | Counts leading zero bits of `bi320`                                              |
| [bi_lzcnt_384](#bi_lzcnt_384)                                          | Counts leading zero bits of `bi384`                                              |
| [bi_lzcnt_448](#bi_lzcnt_448)                                          | Counts leading zero bits of `bi448`                                              |
| [bi_lzcnt_512](#bi_lzcnt_512)                                          | Counts leading zero bits of `bi512`                                              |
| [bi_mod_add_256_256](#bi_mod_add_256_256)                              |                                                                                  |
| [bi_mod_add_assign_256_256](#bi_mod_add_assign_256_256)                |                                                                                  |
| [bi_mod_cube_256](#bi_mod_cube_256)                                    |                                                                                  |
| [bi_mod_div_256_256](#bi_mod_div_256_256)                              |                                                                                  |
| [bi_mod_double_assign_256](#bi_mod_double_assign_256)                  | Doubles `bi256` value                                                            |
| [bi_mod_half_assign_256](#bi_mod_half_assign_256)                      |                                                                                  |
| [bi_mod_inverse_256](#bi_mod_inverse_256)                              | Calculates modular inverse of `bi256`                                            |
| [bi_mod_inverse_512](#bi_mod_inverse_512)                              | Calculates modular inverse of `bi512`                                            |
| [bi_mod_mul_256_256](#bi_mod_mul_256_256)                              | Performs modular multiplication of two `bi256` values                            |
| [bi_mod_negate_256](#bi_mod_negate_256)                                | Negates `bi256` value modulo                                                     |
| [bi_mod_negate_512](#bi_mod_negate_512)                                | Negates `bi512` value modulo                                                     |
| [bi_mod_pow_256](#bi_mod_pow_256)                                      |                                                                                  |
| [bi_mod_square_256](#bi_mod_square_256)                                | Squares `bi256` with modulus                                                     |
| [bi_mod_sub_256_256](#bi_mod_sub_256_256)                              | Subtracts two `bi256` values                                                     |
| [bi_mod_sub_assign_256_256](#bi_mod_sub_assign_256_256)                | Subtracts two `bi256` values                                                     |
| [bi_mod_tripple_assign_256](#bi_mod_tripple_assign_256)                |                                                                                  |
| [bi_mont_ctx_256_add](#bi_mont_ctx_256_add)                            |                                                                                  |
| [bi_mont_ctx_256_add_assign](#bi_mont_ctx_256_add_assign)              | Adds two `bi256` value in montgomery form                                        |
| [bi_mont_ctx_256_convert](#bi_mont_ctx_256_convert)                    |                                                                                  |
| [bi_mont_ctx_256_cube](#bi_mont_ctx_256_cube)                          | Cubes `bi256` value in montgomery form                                           |
| [bi_mont_ctx_256_double_assign](#bi_mont_ctx_256_double_assign)        | Doubles `bi256` value in montgomery form                                         |
| [bi_mont_ctx_256_init](#bi_mont_ctx_256_init)                          |                                                                                  |
| [bi_mont_ctx_256_mul](#bi_mont_ctx_256_mul)                            |                                                                                  |
| [bi_mont_ctx_256_pow](#bi_mont_ctx_256_pow)                            |                                                                                  |
| [bi_mont_ctx_256_redc_256](#bi_mont_ctx_256_redc_256)                  |                                                                                  |
| [bi_mont_ctx_256_redc_512](#bi_mont_ctx_256_redc_512)                  |                                                                                  |
| [bi_mont_ctx_256_square](#bi_mont_ctx_256_square)                      |                                                                                  |
| [bi_mont_ctx_256_sub](#bi_mont_ctx_256_sub)                            |                                                                                  |
| [bi_mont_ctx_256_sub_assign](#bi_mont_ctx_256_sub_assign)              | Subtracts two `bi256` value in montgomery form                                   |
| [bi_mont_ctx_256_tripple_assign](#bi_mont_ctx_256_tripple_assign)      |                                                                                  |
| [bi_mul_192_64_low_192](#bi_mul_192_64_low_192)                        |                                                                                  |
| [bi_mul_256_256_low_256](#bi_mul_256_256_low_256)                      |                                                                                  |
| [bi_mul_64_64](#bi_mul_64_64)                                          |                                                                                  |
| [bi_mul_128_64](#bi_mul_128_64)                                        |                                                                                  |
| [bi_mul_128_128](#bi_mul_128_128)                                      |                                                                                  |
| [bi_mul_128_64_low_128](#bi_mul_128_64_low_128)                        |                                                                                  |
| [bi_mul_128_128_low_128](#bi_mul_128_128_low_128)                      |                                                                                  |
| [bi_mul_192_64](#bi_mul_192_64)                                        | Multiplies `bi192` by `bi64`                                                     |
| [bi_mul_256_64](#bi_mul_256_64)                                        | Multiplies `bi256` value by `bi64` value                                         |
| [bi_mul_256_128](#bi_mul_256_128)                                      |                                                                                  |
| [bi_mul_64_64_low_64](#bi_mul_64_64_low_64)                            |                                                                                  |
| [bi_mul_256_128_low_256](#bi_mul_256_128_low_256)                      |                                                                                  |
| [bi_mul_256_256](#bi_mul_256_256)                                      | Multiplies two `bi256` values                                                    |
| [bi_mul_256_64_low_256](#bi_mul_256_64_low_256)                        |                                                                                  |
| [bi_mul_320_64](#bi_mul_320_64)                                        |                                                                                  |
| [bi_mul_320_64_low_320](#bi_mul_320_64_low_320)                        |                                                                                  |
| [bi_mul_384_64](#bi_mul_384_64)                                        |                                                                                  |
| [bi_mul_384_128](#bi_mul_384_128)                                      |                                                                                  |
| [bi_mul_384_64_low_384](#bi_mul_384_64_low_384)                        |                                                                                  |
| [bi_mul_448_64](#bi_mul_448_64)                                        |                                                                                  |
| [bi_mul_448_128](#bi_mul_448_128)                                      |                                                                                  |
| [bi_mul_448_64_low_448](#bi_mul_448_64_low_448)                        |                                                                                  |
| [bi_mul_512_64](#bi_mul_512_64)                                        |                                                                                  |
| [bi_mul_512_256](#bi_mul_512_256)                                      |                                                                                  |
| [bi_mul_512_512](#bi_mul_512_512)                                      |                                                                                  |
| [bi_mul_512_64_low_512](#bi_mul_512_64_low_512)                        |                                                                                  |
| [bi_mul_512_512_low_512](#bi_mul_512_512_low_512)                      |                                                                                  |
| [bi_one_128](#bi_one_128)                                              |                                                                                  |
| [bi_one_256](#bi_one_256)                                              |                                                                                  |
| [bi_one_512](#bi_one_512)                                              |                                                                                  |
| [bi_one_1024](#bi_one_1024)                                            |                                                                                  |
| [bi_rem_128_64](#bi_rem_128_64)                                        | Calculates remainder of `bi128` dividend by `bi64`                               |
| [bi_rem_128_128](#bi_rem_128_128)                                      |                                                                                  |
| [bi_rem_192_64](#bi_rem_192_64)                                        |                                                                                  |
| [bi_rem_192_128](#bi_rem_192_128)                                      |                                                                                  |
| [bi_rem_192_192](#bi_rem_192_192)                                      |                                                                                  |
| [bi_rem_256_64](#bi_rem_256_64)                                        |                                                                                  |
| [bi_rem_256_128](#bi_rem_256_128)                                      |                                                                                  |
| [bi_rem_256_192](#bi_rem_256_192)                                      |                                                                                  |
| [bi_rem_256_256](#bi_rem_256_256)                                      |                                                                                  |
| [bi_rem_320_64](#bi_rem_320_64)                                        |                                                                                  |
| [bi_rem_320_128](#bi_rem_320_128)                                      |                                                                                  |
| [bi_rem_320_192](#bi_rem_320_192)                                      |                                                                                  |
| [bi_rem_320_256](#bi_rem_320_256)                                      |                                                                                  |
| [bi_rem_320_320](#bi_rem_320_320)                                      |                                                                                  |
| [bi_rem_384_64](#bi_rem_384_64)                                        |                                                                                  |
| [bi_rem_384_128](#bi_rem_384_128)                                      |                                                                                  |
| [bi_rem_384_192](#bi_rem_384_192)                                      | Calculates remainder of `bi384` dividend by `bi192`                              |
| [bi_rem_384_256](#bi_rem_384_256)                                      | Calculates remainder of `bi384` dividend by `bi256`                              |
| [bi_rem_384_320](#bi_rem_384_320)                                      | Calculates remainder of `bi384` dividend by `bi320`                              |
| [bi_rem_384_384](#bi_rem_384_384)                                      | Calculates remainder of `bi384` dividend by `bi384`                              |
| [bi_rem_448_64](#bi_rem_448_64)                                        |                                                                                  |
| [bi_rem_448_128](#bi_rem_448_128)                                      |                                                                                  |
| [bi_rem_448_192](#bi_rem_448_192)                                      |                                                                                  |
| [bi_rem_448_256](#bi_rem_448_256)                                      |                                                                                  |
| [bi_rem_448_320](#bi_rem_448_320)                                      |                                                                                  |
| [bi_rem_448_384](#bi_rem_448_384)                                      |                                                                                  |
| [bi_rem_448_448](#bi_rem_448_448)                                      |                                                                                  |
| [bi_rem_512_64](#bi_rem_512_64)                                        |                                                                                  |
| [bi_rem_512_128](#bi_rem_512_128)                                      |                                                                                  |
| [bi_rem_512_192](#bi_rem_512_192)                                      |                                                                                  |
| [bi_rem_512_256](#bi_rem_512_256)                                      |                                                                                  |
| [bi_rem_512_320](#bi_rem_512_320)                                      |                                                                                  |
| [bi_rem_512_384](#bi_rem_512_384)                                      |                                                                                  |
| [bi_rem_512_448](#bi_rem_512_448)                                      |                                                                                  |
| [bi_rem_512_512](#bi_rem_512_512)                                      |                                                                                  |
| [bi_rnd_64](#bi_rnd_64)                                                |                                                                                  |
| [bi_rnd_128](#bi_rnd_128)                                              |                                                                                  |
| [bi_rnd_192](#bi_rnd_192)                                              |                                                                                  |
| [bi_rnd_256](#bi_rnd_256)                                              |                                                                                  |
| [bi_rnd_320](#bi_rnd_320)                                              |                                                                                  |
| [bi_rnd_384](#bi_rnd_384)                                              |                                                                                  |
| [bi_rnd_448](#bi_rnd_448)                                              |                                                                                  |
| [bi_rnd_512](#bi_rnd_512)                                              |                                                                                  |
| [bi_rnd_1024](#bi_rnd_1024)                                            |                                                                                  |
| [bi_shl_128](#bi_shl_128)                                              |                                                                                  |
| [bi_shl_256](#bi_shl_256)                                              |                                                                                  |
| [bi_shl_384](#bi_shl_384)                                              |                                                                                  |
| [bi_shl_512](#bi_shl_512)                                              |                                                                                  |
| [bi_shl_assign_128](#bi_shl_assign_128)                                |                                                                                  |
| [bi_shl_assign_128_1](#bi_shl_assign_128_1)                            |                                                                                  |
| [bi_shl_assign_192](#bi_shl_assign_192)                                |                                                                                  |
| [bi_shl_assign_256](#bi_shl_assign_256)                                |                                                                                  |
| [bi_shl_assign_256_1](#bi_shl_assign_256_1)                            |                                                                                  |
| [bi_shl_assign_256_64](#bi_shl_assign_256_64)                          |                                                                                  |
| [bi_shl_assign_256_128](#bi_shl_assign_256_128)                        |                                                                                  |
| [bi_shl_assign_320](#bi_shl_assign_320)                                |                                                                                  |
| [bi_shl_assign_384](#bi_shl_assign_384)                                |                                                                                  |
| [bi_shl_assign_448](#bi_shl_assign_448)                                |                                                                                  |
| [bi_shl_assign_512](#bi_shl_assign_512)                                |                                                                                  |
| [bi_shl_assign_512_1](#bi_shl_assign_512_1)                            |                                                                                  |
| [bi_shl_assign_512_64](#bi_shl_assign_512_64)                          |                                                                                  |
| [bi_shl_assign_512_128](#bi_shl_assign_512_128)                        |                                                                                  |
| [bi_shl_assign_512_256](#bi_shl_assign_512_256)                        |                                                                                  |
| [bi_shr_128](#bi_shr_128)                                              | Shifts right `bi128` value                                                       |
| [bi_shr_256](#bi_shr_256)                                              | Shifts right `bi256` value                                                       |
| [bi_shr_512](#bi_shr_512)                                              | Shifts right `bi512` value                                                       |
| [bi_shr_assign_128](#bi_shr_assign_128)                                |                                                                                  |
| [bi_shr_assign_128_1](#bi_shr_assign_128_1)                            |                                                                                  |
| [bi_shr_assign_256](#bi_shr_assign_256)                                |                                                                                  |
| [bi_shr_assign_256_1](#bi_shr_assign_256_1)                            |                                                                                  |
| [bi_shr_assign_256_64](#bi_shr_assign_256_64)                          |                                                                                  |
| [bi_shr_assign_256_128](#bi_shr_assign_256_128)                        |                                                                                  |
| [bi_shr_assign_512](#bi_shr_assign_512)                                |                                                                                  |
| [bi_shr_assign_512_1](#bi_shr_assign_512_1)                            |                                                                                  |
| [bi_shr_assign_512_64](#bi_shr_assign_512_64)                          |                                                                                  |
| [bi_shr_assign_512_128](#bi_shr_assign_512_128)                        |                                                                                  |
| [bi_shr_assign_512_256](#bi_shr_assign_512_256)                        |                                                                                  |
| [bi_square_64](#bi_square_64)                                          | Squares `bi64` value                                                             |
| [bi_square_128](#bi_square_128)                                        | Squares `bi128` value                                                            |
| [bi_square_256](#bi_square_256)                                        | Squares `bi256` value                                                            |
| [bi_sub_128_128](#bi_sub_128_128)                                      |                                                                                  |
| [bi_sub_192_192](#bi_sub_192_192)                                      |                                                                                  |
| [bi_sub_256_256](#bi_sub_256_256)                                      |                                                                                  |
| [bi_sub_512_512](#bi_sub_512_512)                                      |                                                                                  |
| [bi_sub_assign_128_128](#bi_sub_assign_128_128)                        |                                                                                  |
| [bi_sub_assign_192_128](#bi_sub_assign_192_128)                        |                                                                                  |
| [bi_sub_assign_192_192](#bi_sub_assign_192_192)                        |                                                                                  |
| [bi_sub_assign_256_128](#bi_sub_assign_256_128)                        |                                                                                  |
| [bi_sub_assign_256_192](#bi_sub_assign_256_192)                        |                                                                                  |
| [bi_sub_assign_256_256](#bi_sub_assign_256_256)                        |                                                                                  |
| [bi_sub_assign_320_128](#bi_sub_assign_320_128)                        |                                                                                  |
| [bi_sub_assign_320_192](#bi_sub_assign_320_192)                        |                                                                                  |
| [bi_sub_assign_320_256](#bi_sub_assign_320_256)                        |                                                                                  |
| [bi_sub_assign_320_320](#bi_sub_assign_320_320)                        |                                                                                  |
| [bi_sub_assign_384_128](#bi_sub_assign_384_128)                        |                                                                                  |
| [bi_sub_assign_384_192](#bi_sub_assign_384_192)                        |                                                                                  |
| [bi_sub_assign_384_256](#bi_sub_assign_384_256)                        |                                                                                  |
| [bi_sub_assign_384_320](#bi_sub_assign_384_320)                        |                                                                                  |
| [bi_sub_assign_384_384](#bi_sub_assign_384_384)                        |                                                                                  |
| [bi_sub_assign_448_128](#bi_sub_assign_448_128)                        |                                                                                  |
| [bi_sub_assign_448_192](#bi_sub_assign_448_192)                        |                                                                                  |
| [bi_sub_assign_448_256](#bi_sub_assign_448_256)                        |                                                                                  |
| [bi_sub_assign_448_320](#bi_sub_assign_448_320)                        |                                                                                  |
| [bi_sub_assign_448_384](#bi_sub_assign_448_384)                        |                                                                                  |
| [bi_sub_assign_448_448](#bi_sub_assign_448_448)                        |                                                                                  |
| [bi_sub_assign_512_128](#bi_sub_assign_512_128)                        |                                                                                  |
| [bi_sub_assign_512_192](#bi_sub_assign_512_192)                        |                                                                                  |
| [bi_sub_assign_512_256](#bi_sub_assign_512_256)                        |                                                                                  |
| [bi_sub_assign_512_320](#bi_sub_assign_512_320)                        |                                                                                  |
| [bi_sub_assign_512_384](#bi_sub_assign_512_384)                        |                                                                                  |
| [bi_sub_assign_512_448](#bi_sub_assign_512_448)                        |                                                                                  |
| [bi_sub_assign_512_512](#bi_sub_assign_512_512)                        |                                                                                  |
| [bi_try_read_hex_64](#bi_try_read_hex_64)                              |                                                                                  |
| [bi_try_read_hex_128](#bi_try_read_hex_128)                            |                                                                                  |
| [bi_try_read_hex_192](#bi_try_read_hex_192)                            |                                                                                  |
| [bi_try_read_hex_256](#bi_try_read_hex_256)                            |                                                                                  |
| [bi_try_read_hex_320](#bi_try_read_hex_320)                            |                                                                                  |
| [bi_try_read_hex_384](#bi_try_read_hex_384)                            |                                                                                  |
| [bi_try_read_hex_448](#bi_try_read_hex_448)                            |                                                                                  |
| [bi_try_read_hex_512](#bi_try_read_hex_512)                            |                                                                                  |
| [bi_try_read_hex_576](#bi_try_read_hex_576)                            |                                                                                  |
| [bi_try_read_hex_768](#bi_try_read_hex_768)                            |                                                                                  |
| [bi_try_read_hex_1024](#bi_try_read_hex_1024)                          |                                                                                  |
| [bi_zero_128](#bi_zero_128)                                            | Zeroes `bi128` value                                                             |
| [bi_zero_192](#bi_zero_192)                                            | Zeroes `bi192` value                                                             |
| [bi_zero_256](#bi_zero_256)                                            | Zeroes `bi256` value                                                             |
| [bi_zero_320](#bi_zero_320)                                            | Zeroes `bi320` value                                                             |
| [bi_zero_384](#bi_zero_384)                                            | Zeroes `bi384` value                                                             |
| [bi_zero_448](#bi_zero_448)                                            | Zeroes `bi448` value                                                             |
| [bi_zero_512](#bi_zero_512)                                            | Zeroes `bi512` value                                                             |
| [bi_zero_576](#bi_zero_576)                                            | Zeroes `bi576` value                                                             |
| [bi_zero_768](#bi_zero_768)                                            | Zeroes `bi768` value                                                             |
| [bi_zero_1024](#bi_zero_1024)                                          | Zeroes `bi1024` value                                                            |
| [ec_affine_point_256_add](#ec_affine_point_256_add)                    |                                                                                  |
| [ec_affine_point_256_add_assign](#ec_affine_point_256_add_assign)      |                                                                                  |
| [ec_affine_point_256_copy](#ec_affine_point_256_copy)                  |                                                                                  |
| [ec_affine_point_256_double](#ec_affine_point_256_double)              |                                                                                  |
| [ec_affine_point_256_double_assign](#ec_affine_point_256_double_assign) |                                                                                  |
| [ec_affine_point_256_is_infinity](#ec_affine_point_256_is_infinity)    |                                                                                  |
| [ec_affine_point_256_mul](#ec_affine_point_256_mul)                    |                                                                                  |
| [ec_affine_point_256_negate](#ec_affine_point_256_negate)              |                                                                                  |
| [ec_affine_point_256_set_infinity](#ec_affine_point_256_set_infinity)  | Sets `ECAffinePoint256` to infinity                                              |
| [ec_affine_point_256_shl](#ec_affine_point_256_shl)                    |                                                                                  |
| [ec_affine_point_256_shl_assign](#ec_affine_point_256_shl_assign)      |                                                                                  |
| [ec_affine_point_256_sub](#ec_affine_point_256_sub)                    |                                                                                  |
| [ec_affine_point_256_sub_assign](#ec_affine_point_256_sub_assign)      |                                                                                  |
| [ec_affine_point_256_try_read_hex](#ec_affine_point_256_try_read_hex)  |                                                                                  |
| [ec_projective_mont_point_256_add](#ec_projective_mont_point_256_add)  |                                                                                  |
| [ec_projective_mont_point_256_add_assign](#ec_projective_mont_point_256_add_assign) |                                                                                  |
| [ec_projective_mont_point_256_copy](#ec_projective_mont_point_256_copy) |                                                                                  |
| [ec_projective_mont_point_256_double](#ec_projective_mont_point_256_double) |                                                                                  |
| [ec_projective_mont_point_256_double_assign](#ec_projective_mont_point_256_double_assign) |                                                                                  |
| [ec_projective_mont_point_256_from_affine_point](#ec_projective_mont_point_256_from_affine_point) | Converts `ECAffinePoint256` to `ECProjectiveMontgomeryPoint256`                  |
| [ec_projective_mont_point_256_from_projective_point](#ec_projective_mont_point_256_from_projective_point) | Converts `ECProjectivePoint256` to `ECProjectiveMontgomeryPoint256`              |
| [ec_projective_mont_point_256_is_infinity](#ec_projective_mont_point_256_is_infinity) |                                                                                  |
| [ec_projective_mont_point_256_mul](#ec_projective_mont_point_256_mul)  |                                                                                  |
| [ec_projective_mont_point_256_negate](#ec_projective_mont_point_256_negate) |                                                                                  |
| [ec_projective_mont_point_256_set_infinity](#ec_projective_mont_point_256_set_infinity) | Sets `ECProjectiveMontgomeryPoint256` to infinity                                |
| [ec_projective_mont_point_256_shl](#ec_projective_mont_point_256_shl)  |                                                                                  |
| [ec_projective_mont_point_256_shl_assign](#ec_projective_mont_point_256_shl_assign) |                                                                                  |
| [ec_projective_mont_point_256_sub](#ec_projective_mont_point_256_sub)  |                                                                                  |
| [ec_projective_mont_point_256_sub_assign](#ec_projective_mont_point_256_sub_assign) |                                                                                  |
| [ec_projective_mont_point_256_to_affine_point](#ec_projective_mont_point_256_to_affine_point) | Converts `ECProjectiveMontgomeryPoint256` to `ECAffinePoint256`                  |
| [ec_projective_mont_point_256_to_projective_point](#ec_projective_mont_point_256_to_projective_point) | Converts `ECProjectiveMontgomeryPoint256` to `ECProjectivePoint256`              |
| [ec_projective_mont_point_256_try_read_hex](#ec_projective_mont_point_256_try_read_hex) |                                                                                  |
| [ec_projective_point_256_add](#ec_projective_point_256_add)            |                                                                                  |
| [ec_projective_point_256_add_assign](#ec_projective_point_256_add_assign) |                                                                                  |
| [ec_projective_point_256_copy](#ec_projective_point_256_copy)          |                                                                                  |
| [ec_projective_point_256_double](#ec_projective_point_256_double)      |                                                                                  |
| [ec_projective_point_256_double_assign](#ec_projective_point_256_double_assign) |                                                                                  |
| [ec_projective_point_256_from_affine_point](#ec_projective_point_256_from_affine_point) | Converts `ECAffinePoint256` to `ECProjectivePoint256`                            |
| [ec_projective_point_256_is_infinity](#ec_projective_point_256_is_infinity) |                                                                                  |
| [ec_projective_point_256_mul](#ec_projective_point_256_mul)            |                                                                                  |
| [ec_projective_point_256_negate](#ec_projective_point_256_negate)      |                                                                                  |
| [ec_projective_point_256_set_infinity](#ec_projective_point_256_set_infinity) | Sets `ECProjectivePoint256` to infinity                                          |
| [ec_projective_point_256_shl](#ec_projective_point_256_shl)            |                                                                                  |
| [ec_projective_point_256_shl_assign](#ec_projective_point_256_shl_assign) |                                                                                  |
| [ec_projective_point_256_sub](#ec_projective_point_256_sub)            |                                                                                  |
| [ec_projective_point_256_sub_assign](#ec_projective_point_256_sub_assign) |                                                                                  |
| [ec_projective_point_256_to_affine_point](#ec_projective_point_256_to_affine_point) | Converts `ECProjectivePoint256` to `ECAffinePoint256`                            |
| [ec_projective_point_256_try_read_hex](#ec_projective_point_256_try_read_hex) |                                                                                  |
| [secp256k1_get_affine_point](#secp256k1_get_affine_point)              | Calculates `ECAffinePoint256` from `bi256` multiplier                            |

Total 396 functions

## bi_add_128_128

Adds two `bi128` values

Inputs: 

`rcx` - pointer to left `bi128` value

`rdx` - pointer to right `bi128` value

`r8` - pointer to result `bi128`  value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_192_192

Adds two `bi192` values

Inputs: 

`rcx` - pointer to left `bi192` value

`rdx` - pointer to right `bi192` value

`r8` - pointer to result `bi192` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_256_256

Adds two `bi256` values

Inputs: 

`rcx` - pointer to left `bi256` value

`rdx` - pointer to right `bi256` value

`r8` - pointer to result `bi256` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_512_512

Adds two `bi512` values

Inputs: 

`rcx` - left value

`rdx` - right value

`r8` - result value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_128_128

Adds two `bi128` values and assigns result to the left `bi128` value

Inputs: 

`rcx` - pointer to left `bi128` value. The modified value

`rdx` - pointer to right `bi128` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_192_128

Adds `bi192` and `bi128` values and assigns result to the left `bi192` value

Inputs: 

`rcx` - pointer to left `bi192` value. The modified value

`rdx` - pointer to right `bi128` value

Outputs: 

`rax`, `CF` - set to 1 if overflow

`CF` - set to 1 if overflow



## bi_add_assign_192_192

Adds two `bi192` values and assigns result to the left `bi192` value

Inputs: 

`rcx` - pointer to left `bi192` value. The modified value

`rdx` - pointer to right `bi192` value

Outputs: 

`rax`, `CF` - set to 1 if overflow

`CF` - set to 1 if overflow



## bi_add_assign_256_128

Adds `bi256` and `bi128` values and assigns result to the left `bi256` value

Inputs: 

`rcx` - pointer to left `bi256` value. The modified value

`rdx` - pointer to right `bi128` value

Outputs: 

`rax`, `CF` - set to 1 if overflow

`CF` - set to 1 if overflow



## bi_add_assign_256_192

Adds `bi256` and `bi192` values and assigns result to the left `bi256` value

Inputs: 

`rcx` - pointer to left `bi256` value. The modified value

`rdx` - pointer to right `bi192` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_256_256

Adds two `bi256` values and assigns result to the left `bi256` value

Inputs: 

`rcx` - pointer to left `bi256` value. The modified value

`rdx` - pointer to right `bi256` value

Outputs: 

`rax`, `CF` - set to 1 if overflow

`CF` - set to 1 if overflow



## bi_add_assign_320_128

Adds `bi320` and `bi128` values and assigns result to the left `bi320` value

Inputs: 

`rcx` - pointer to left `bi320` value. The modified value

`rdx` - pointer to right `bi320` value

Outputs: 

`rax`, `CF` - set to 1 if overflow

`CF` - set to 1 if overflow



## bi_add_assign_320_192

Adds `bi320` and `bi192` values and assigns result to the left `bi320` value

Inputs: 

`rcx` - pointer to left `bi320` value. The modified value

`rdx` - pointer to right `bi192` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_320_256

Adds `bi320` and `bi256` values and assigns result to the left `bi320` value

Inputs: 

`rcx` - pointer to left `bi320` value. The modified value

`rdx` - pointer to right `bi256` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_320_320

Adds two `bi320` values and assigns result to the left `bi320` value

Inputs: 

`rcx` - left value. The modified value

`rdx` - right value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_384_128

Adds `bi384` and `bi128` values and assigns result to the left `bi384` value

Inputs: 

`rcx` - pointer to left `bi384` value. The modified value

`rdx` - pointer to right `bi128` value

Outputs: 

`rax`, `CF` - set to 1 if overflow

`CF` - set to 1 if overflow



## bi_add_assign_384_192

Adds `bi384` and `bi192` values and assigns result to the left `bi384` value

Inputs: 

`rcx` - pointer to left `bi384` value. The modified value

`rdx` - pointer to right `bi192` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_384_256

Adds `bi384` and `bi256` values and assigns result to the left `bi384` value

Inputs: 

`rcx` - pointer to left `bi384` value. The modified value

`rdx` - pointer to right `bi256` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_384_320

Adds `bi384` and `bi320` values and assigns result to the left `bi384` value

Inputs: 

`rcx` - pointer to left `bi384` value. The modified value

`rdx` - pointer to right `bi320` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_384_384

Adds two `bi384` values and assigns result to the left `bi384` value

Inputs: 

`rcx` - pointer to left `bi384` value. The modified value

`rdx` - pointer to right `bi384` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_448_128

Adds `bi448` and `bi128` values and assigns result to the left `bi448` value

Inputs: 

`rcx` - pointer to left `bi448` value. The modified value

`rdx` - pointer to right `bi128` value

Outputs: 

`rax`, `CF` - set to 1 if overflow

`CF` - set to 1 if overflow



## bi_add_assign_448_192

Adds `bi448` and `bi192` values and assigns result to the left `bi448` value

Inputs: 

`rcx` - pointer to left `bi448` value. The modified value

`rdx` - pointer to right `bi192` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_448_256

Adds two `bi448` and `bi256` values and assigns result to the left `bi448` value

Inputs: 

`rcx` - pointer to left `bi448` value. The modified value

`rdx` - pointer to right `bi256` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_448_320

Adds two `bi448` and `bi320` values and assigns result to the left `bi448` value

Inputs: 

`rcx` - pointer to left `bi448` value. The modified value

`rdx` - pointer to right `bi320` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_448_384

Adds two `bi448` and `bi384` values and assigns result to the left `bi448` value

Inputs: 

`rcx` - pointer to left `bi448` value. The modified value

`rdx` - pointer to right `bi384` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_448_448

Adds two `bi448` values and assigns result to the left `bi448` value

Inputs: 

`rcx` - pointer to left `bi448` value. The modified value

`rdx` - pointer to right `bi448` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_512_256

Adds `bi512` and `bi256` values and assigns result to the left `bi512` value

Inputs: 

`rcx` - pointer to left `bi512` value. The modified value

`rdx` - pointer to right `bi256` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_512_384

Adds `bi512` and `bi384` values and assigns result to the left `bi512` value

Inputs: 

`rcx` - pointer to left `bi512` value. The modified value

`rdx` - pointer to right `bi384` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_512_448

Adds `bi512` and `bi448` values and assigns result to the left `bi512` value

Inputs: 

`rcx` - pointer to left `bi512` value. The modified value

`rdx` - pointer to right `bi448` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_512_512

Adds two `bi512` values and assigns result to the left `bi512` value

Inputs: 

`rcx` - pointer to left `bi512` value. The modified value

`rdx` - pointer to right `bi512` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_576_576

Adds two `bi576` values and assigns result to the left `bi576` value

Inputs: 

`rcx` - left value. The modified value

`rdx` - right value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_640_512

Adds `bi640` and `bi512` values and assigns result to the left `bi640` value

Inputs: 

`rcx` - pointer to left `bi640` value. The modified value

`rdx` - pointer to right `bi512` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_768_512

Adds two `bi768` values and assigns result to the left `bi768` value

Inputs: 

`rcx` - pointer to left `bi768` value. The modified value

`rdx` - pointer to right `bi512` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_1024_512

Adds `bi1024` and `bi512` values and assigns result to the left `bi1024` value

Inputs: 

`rcx` - pointer to left `bi1024` value. The modified value

`rdx` - pointer to right `bi512` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_add_assign_1024_1024

Adds two `bi1024` values and assigns result to the left `bi1024` value

Inputs: 

`rcx` - pointer to left `bi1024` value. The modified value

`rdx` - pointer to right `bi1024` value

Outputs: 

`rax`, `CF` - set to 1 if overflow



## bi_bit_check_128

Checks bit in `bi128` value

Inputs: 

`rcx` - pointer of `bi128` value to test

`rdx` - bit

Outputs: 

`rax` - 1 if bit is set



## bi_bit_check_256

Checks bit in `bi256` value

Inputs: 

`rcx` - pointer of `bi256` value to test

`rdx` - bit

Outputs: 

`rax` - 1 if bit is set



## bi_bit_check_512

Checks bit in `bi512` value

Inputs: 

`rcx` - pointer of `bi512` value to test

`rdx` - bit

Outputs: 

`rax` - 1 if bit is set



## bi_bit_clear_128

Clears a bit in `bi128` value

Inputs: 

`rcx` - pointer to `bi128` value to change

`rdx` - bit



## bi_bit_clear_256

Clears a bit in `bi256` value

Inputs: 

`rcx` - pointer to `bi256` value to change

`rdx` - bit



## bi_bit_clear_512

Clears a bit in `bi512` value

Inputs: 

`rcx` - pointer to `bi512` value to change

`rdx` - bit



## bi_bit_set_128

Sets a bit in `bi128` value

Inputs: 

`rcx` - pointer to `bi128` value to change

`rdx` - bit



## bi_bit_set_256

Sets a bit in `bi256` value

Inputs: 

`rcx` - pointer to `bi256` value to change

`rdx` - bit



## bi_bit_set_512

Sets a bit in `bi512` value

Inputs: 

`rcx` - pointer to `bi512` value to change

`rdx` - bit



## bi_cmp_128_128

Compares two `bi128` values

Inputs: 

`rcx` - pointer to left `bi128` value

`rdx` - pointer to right `bi128` value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_192_128

Compares `bi192` to `bi128` values

Inputs: 

`rcx` - pointer to `bi192` left value

`rdx` - pointer to `bi128` right value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_192_192

Compares two `bi192` values

Inputs: 

`rcx` - pointer to left `bi192` value

`rdx` - pointer to right `bi192` value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_256_128

Compares `bi256` to `bi128` values

Inputs: 

`rcx` - pointer to `bi256` left value

`rdx` - pointer to `bi128` right value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_256_192

Compares `bi256` to `bi192` values

Inputs: 

`rcx` - pointer to `bi256` left value

`rdx` - pointer to `bi192` right value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_256_256

Compares two `bi256` values

Inputs: 

`rcx` - pointer to left `bi256` value

`rdx` - pointer to right `bi256` value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_320_128

Compares `bi320` to `bi128` value

Inputs: 

`rcx` - pointer to left `bi320` value

`rdx` - pointer to right `bi128` value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_320_192

Compares `bi320` to `bi192` values

Inputs: 

`rcx` - pointer to `bi320` left value

`rdx` - pointer to `bi192` right value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_320_256

Compares `bi320` to `bi256` values

Inputs: 

`rcx` - pointer to `bi320` left value

`rdx` - pointer to `bi256` right value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_320_320

Compares two `bi320` values

Inputs: 

`rcx` - pointer to left `bi320` value

`rdx` - pointer to right `bi320` value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_384_128

Compares `bi384` to `bi128` values

Inputs: 

`rcx` - pointer to `bi384` left value

`rdx` - pointer to `bi128` right value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_384_192

Compares `bi384` to `bi192` values

Inputs: 

`rcx` - pointer to `bi384` left value

`rdx` - pointer to `bi192` right value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_384_256

Compares `bi384` to `bi256` values

Inputs: 

`rcx` - pointer to `bi384` left value

`rdx` - pointer to `bi256` right value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_384_320

Compares `bi384` to `bi320` values

Inputs: 

`rcx` - pointer to left `bi384` value

`rdx` - pointer to right bi20 value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_384_384

Compares two `bi384` values

Inputs: 

`rcx` - pointer to left `bi384` value

`rdx` - pointer to right `bi384` value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_448_128

Compares `bi448` to `bi128` values

Inputs: 

`rcx` - pointer to `bi448` left value

`rdx` - pointer to `bi128` right value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_448_192

Compares `bi448` to `bi192` values

Inputs: 

`rcx` - pointer to `bi448` left value

`rdx` - pointer to `bi192` right value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_448_256

Compares `bi448` to `bi256` values

Inputs: 

`rcx` - pointer to `bi448` left value

`rdx` - pointer to `bi256` right value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_448_320

Compares `bi448` to `bi320` values

Inputs: 

`rcx` - pointer to left `bi448` value

`rdx` - pointer to right `bi320` value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_448_384

Compares `bi448` to `bi384` values

Inputs: 

`rcx` - pointer to left `bi448` value

`rdx` - pointer to right `bi384` value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_448_448

Compares two `bi448` values

Inputs: 

`rcx` - pointer to left `bi448` value

`rdx` - pointer to right `bi448` value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_512_128

Compares `bi512` to `bi128` values

Inputs: 

`rcx` - pointer to `bi512` left value

`rdx` - pointer to `bi128` right value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_512_192

Compares `bi512` to `bi192` values

Inputs: 

`rcx` - pointer to `bi512` left value

`rdx` - pointer to `bi192` right value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_512_256

Compares `bi512` to `bi256` values

Inputs: 

`rcx` - pointer to `bi512` left value

`rdx` - pointer to `bi256` right value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_512_320

Compares `bi512` to `bi320` values

Inputs: 

`rcx` - pointer to left `bi512` value

`rdx` - pointer to right `bi320` value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_512_384

Compares `bi512` to `bi384` values

Inputs: 

`rcx` - pointer to left `bi512` value

`rdx` - pointer to right `bi384` value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_512_448

Compares `bi512` to `bi448` values

Inputs: 

`rcx` - pointer to left `bi512` value

`rdx` - pointer to right `bi448` value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_512_512

Compares two `bi512` values

Inputs: 

`rcx` - pointer to left `bi512` value

`rdx` - pointer to right `bi512` value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_576_576

Compares two `bi576` values

Inputs: 

`rcx` - pointer to left `bi576` value

`rdx` - pointer to right `bi576` value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_768_768

Compares two `bi768` values

Inputs: 

`rcx` - pointer to left `bi768` value

`rdx` - pointer to right `bi768` value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_cmp_1024_1024

Compares two `bi1024` values

Inputs: 

`rcx` - left `bi1024` value

`rdx` - right `bi1024` value

Outputs: 

`rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise



## bi_copy_128

Copies `bi128` value

Inputs: 

`rcx` - pointer to destination `bi128`

`rdx` - pointer to source `bi128`



## bi_copy_192

Copies `bi192` value

Inputs: 

`rcx` - pointer to destination `bi192`

`rdx` - pointer to source `bi192`



## bi_copy_256

Copies `bi256` value

Inputs: 

`rcx` - pointer to destination `bi256`

`rdx` - pointer to source `bi256`



## bi_copy_320

Copies `bi320` value

Inputs: 

`rcx` - pointer to destination `bi320`

`rdx` - pointer to source `bi320`



## bi_copy_384

Copies `bi384` value

Inputs: 

`rcx` - pointer to destination `bi384`

`rdx` - pointer to source `bi384`



## bi_copy_448

Copies `bi448` value

Inputs: 

`rcx` - pointer to destination `bi448`

`rdx` - pointer to source `bi448`



## bi_copy_512

Copies `bi512` value

Inputs: 

`rcx` - pointer to destination `bi512`

`rdx` - pointer to source `bi512`



## bi_copy_768

Copies `bi768` value

Inputs: 

`rcx` - pointer to destination `bi768`

`rdx` - pointer to source `bi768`



## bi_dec_assign_256

Decrements `bi256` value

Inputs: 

`rcx` - pointer to left `bi256` value. The modified value

Outputs: 

`rax`, `CF` - set to 1 if overflow

`CF` - set to 1 if overflow



## bi_div_128_64

Divides `bi128` by `bi64`

Inputs: 

`rcx` - pointer to `bi128` dividend

`rdx` - `bi64` divisor

`r8` - pointer to `bi128` quotient



## bi_div_rem_128_64

Divides `bi128` by `bi64`

Inputs: 

`rcx` - pointer to `bi128` dividend

`rdx` - `bi64` divisor

`r8` - pointer to `bi128` quotient

`r9` - pointer to `bi64` remainder



## bi_div_rem_128_128

Divides `bi128` by `bi128`

Inputs: 

`rcx` - pointer to `bi128` dividend

`rdx` - pointer to `bi128` divisor

`r8` - pointer to `bi128` quotient

`r9` - pointer to `bi128` remainder



## bi_div_rem_192_64

Divides `bi192` by `bi64`

Inputs: 

`rcx` - pointer to `bi192` divident

`rdx` - `bi64` divisor

`r8` - pointer to `bi192` quotient

`r9` - pointer to `bi64` remainder



## bi_div_rem_192_128

Divides `bi192` by `bi128`

Inputs: 

`rcx` - pointer to `bi192` divident

`rdx` - pointer to `bi128` divisor

`r8` - pointer to `bi192` quotient

`r9` - pointer to `bi128` remainder



## bi_div_rem_192_192





## bi_div_rem_256_64

Divides `bi256` by `bi64`

Inputs: 

`rcx` - pointer to `bi256` divident

`rdx` - `bi64` divisor

`r8` - pointer to `bi256` quotient

`r9` - pointer to `bi64` remainder



## bi_div_rem_256_128

Divides `bi256` by `bi128`

Inputs: 

`rcx` - pointer to `bi256` divident

`rdx` - pointer to `bi128` divisor

`r8` - pointer to `bi256` quotient

`r9` - pointer to `bi128` remainder



## bi_div_rem_256_192





## bi_div_rem_256_256

Divides `bi256` by `bi256`

Inputs: 

`rcx` - pointer to `bi256` divident

`rdx` - pointer to `bi256` divisor

`r8` - pointer to `bi256` quotient

`r9` - pointer to `bi256` remainder

include 'bi_div_rem_256_256_full_bits.inc'

bi_div_rem_256_256 equ bi_div_rem_256_256_full_bits

include 'bi_div_rem_256_256_bits.inc'

bi_div_rem_256_256 equ bi_div_rem_256_256_bits



## bi_div_rem_320_64

Divides `bi320` by `bi64`

Inputs: 

`rcx` - pointer to `bi320` divident

`rdx` - `bi64` divisor

`r8` - pointer to `bi320` quotient

`r9` - pointer to `bi64` remainder



## bi_div_rem_320_128





## bi_div_rem_320_192





## bi_div_rem_320_256





## bi_div_rem_320_320





## bi_div_rem_384_64





## bi_div_rem_384_128





## bi_div_rem_384_192





## bi_div_rem_384_256





## bi_div_rem_384_320





## bi_div_rem_384_384





## bi_div_rem_448_64





## bi_div_rem_448_128





## bi_div_rem_448_192





## bi_div_rem_448_256





## bi_div_rem_448_320





## bi_div_rem_448_384





## bi_div_rem_448_448





## bi_div_rem_512_64





## bi_div_rem_512_128





## bi_div_rem_512_192





## bi_div_rem_512_256





## bi_div_rem_512_320





## bi_div_rem_512_384





## bi_div_rem_512_448





## bi_div_rem_512_512





## bi_euclid_ext_256





## bi_extend_128_64





## bi_extend_192_64





## bi_extend_192_128





## bi_extend_256_64





## bi_extend_256_128





## bi_extend_320_128





## bi_extend_384_64





## bi_extend_384_128





## bi_extend_448_64





## bi_extend_448_128





## bi_extend_512_64





## bi_extend_512_128





## bi_extend_512_256





## bi_extend_assign_128_64





## bi_extend_assign_192_64





## bi_extend_assign_384_64





## bi_extend_assign_448_64





## bi_inc_assign_128

Increments `bi128` value

Inputs: 

`rcx` - pointer to left `bi128` value. The modified value

Outputs: 

`rax`, `CF` - set to 1 if overflow

`CF` - set to 1 if overflow



## bi_inc_assign_192

Increments `bi192` value

Inputs: 

`rcx` - pointer to left `bi192` value. The modified value

Outputs: 

`rax`, `CF` - set to 1 if overflow

`CF` - set to 1 if overflow



## bi_inc_assign_256

Increments `bi256` value

Inputs: 

`rcx` - pointer to left `bi256` value. The modified value

Outputs: 

`rax`, `CF` - set to 1 if overflow

`CF` - set to 1 if overflow



## bi_inc_assign_320

Increments `bi320` value

Inputs: 

`rcx` - pointer to left `bi320` value. The modified value

Outputs: 

`rax`, `CF` - set to 1 if overflow

`CF` - set to 1 if overflow



## bi_inc_assign_384

Increments `bi384` value

Inputs: 

`rcx` - pointer to left `bi384` value. The modified value

Outputs: 

`rax`, `CF` - set to 1 if overflow

`CF` - set to 1 if overflow



## bi_inc_assign_448

Increments `bi448` value

Inputs: 

`rcx` - pointer to left `bi448` value. The modified value

Outputs: 

`rax`, `CF` - set to 1 if overflow

`CF` - set to 1 if overflow



## bi_inc_assign_512

Increments `bi512` value

Inputs: 

`rcx` - pointer to left `bi512` value. The modified value

Outputs: 

`rax`, `CF` - set to 1 if overflow

`CF` - set to 1 if overflow



## bi_is_zero_256

Checks if `bi256` value is zero

Inputs: 

`rcx` - pointer to `bi256` value

Outputs: 

`rax` - 1 if value is zero, 0 otherwise

`ZF` = 1 if value is zero, 0 otherwise



## bi_is_zero_512

Checks if `bi512` value is zero

Inputs: 

`rcx` - pointer to `bi512` value

Outputs: 

`rax` - 1 if value is zero, 0 otherwise



## bi_lzcnt_128

Counts leading zero bits of `bi128`

Inputs: 

`rcx` - pointer to `bi128`

Outputs: 

`rax` - leading zero bits count



## bi_lzcnt_192

Counts leading zero bits of `bi192`

Inputs: 

`rcx` - pointer to `bi192`

Outputs: 

`rax` - leading zero bits count



## bi_lzcnt_256

Counts leading zero bits of `bi256`

Inputs: 

`rcx` - pointer to `bi256`

Outputs: 

`rax` - leading zero bits count



## bi_lzcnt_320

Counts leading zero bits of `bi320`

Inputs: 

`rcx` - pointer to `bi320`

Outputs: 

`rax` - leading zero bits count



## bi_lzcnt_384

Counts leading zero bits of `bi384`

Inputs: 

`rcx` - pointer to `bi384`

Outputs: 

`rax` - leading zero bits count



## bi_lzcnt_448

Counts leading zero bits of `bi448`

Inputs: 

`rcx` - pointer to `bi448`

Outputs: 

`rax` - leading zero bits count



## bi_lzcnt_512

Counts leading zero bits of `bi512`

Inputs: 

`rcx` - pointer to `bi512`

Outputs: 

`rax` - leading zero bits count



## bi_mod_add_256_256





## bi_mod_add_assign_256_256





## bi_mod_cube_256





## bi_mod_div_256_256





## bi_mod_double_assign_256

Doubles `bi256` value

Inputs: 

`rcx` - pointer to left `bi256` value. The modified value

`rdx` - pointer to `bi256` modulus



## bi_mod_half_assign_256





## bi_mod_inverse_256

Calculates modular inverse of `bi256`

Inputs: 

`rcx` - pointer to `bi256` value.

`rdx` - pointer to `bi256` modulus

`r8` - pointer to `bi256` result



## bi_mod_inverse_512

Calculates modular inverse of `bi512`

Inputs: 

`rcx` - pointer to `bi512` value.

`rdx` - pointer to `bi512` modulus

`r8` - pointer to `bi512` result



## bi_mod_mul_256_256

Performs modular multiplication of two `bi256` values

Inputs: 

`rcx` - pointer to `bi256` value.

`rdx` - pointer to `bi256` modulus

`r8` - pointer to `bi256` result



## bi_mod_negate_256

Negates `bi256` value modulo

Inputs: 

`rcx` - pointer to left `bi256` value.

`rdx` - pointer to modulus `bi256` value

`r8` - pointer to `bi256` result



## bi_mod_negate_512

Negates `bi512` value modulo

Inputs: 

`rcx` - pointer to left `bi512` value.

`rdx` - pointer to modulus `bi512` value

`r8` - pointer to `bi512` result



## bi_mod_pow_256





## bi_mod_square_256

Squares `bi256` with modulus

Inputs: 

`rcx` - pointer to `bi256` value.

`rdx` - pointer to `bi256` modulus

`r8` - pointer to `bi256` result



## bi_mod_sub_256_256

Subtracts two `bi256` values

Inputs: 

`rcx` - pointer to left `bi256` value

`rdx` - pointer to right `bi256` value

`r8` - pointer to `bi256` modulus

`r9`  - pointer to result `bi256` value



## bi_mod_sub_assign_256_256

Subtracts two `bi256` values

Inputs: 

`rcx` - pointer to left `bi256` value. The modified value.

`rdx` - pointer to right `bi256` value

`r8` - pointer to `bi256` modulus



## bi_mod_tripple_assign_256





## bi_mont_ctx_256_add





## bi_mont_ctx_256_add_assign

Adds two `bi256` value in montgomery form

Inputs: 

`rcx` - pointer to `bi256` left montgomery value. Modified value

`rdx` - pointer to `bi256` right montgomery value.

`r8` - pointer to `MontgomeryContext256`



## bi_mont_ctx_256_convert





## bi_mont_ctx_256_cube

Cubes `bi256` value in montgomery form

Inputs: 

`rcx` - pointer to `bi256` montgomery value. Modified value

`rdx` - pointer to `MontgomeryContext256`

`r8` - pointer to `bi256` montgomery result



## bi_mont_ctx_256_double_assign

Doubles `bi256` value in montgomery form

Inputs: 

`rcx` - pointer to `bi256` montgomery value. Modified value

`rdx` - pointer to `MontgomeryContext256`



## bi_mont_ctx_256_init





## bi_mont_ctx_256_mul





## bi_mont_ctx_256_pow





## bi_mont_ctx_256_redc_256





## bi_mont_ctx_256_redc_512





## bi_mont_ctx_256_square





## bi_mont_ctx_256_sub





## bi_mont_ctx_256_sub_assign

Subtracts two `bi256` value in montgomery form

Inputs: 

`rcx` - pointer to `bi256` left montgomery value. Modified value

`rdx` - pointer to `bi256` right montgomery value.

`r8` - pointer to `MontgomeryContext256`



## bi_mont_ctx_256_tripple_assign





## bi_mul_192_64_low_192





## bi_mul_256_256_low_256





## bi_mul_64_64





## bi_mul_128_64





## bi_mul_128_128





## bi_mul_128_64_low_128





## bi_mul_128_128_low_128





## bi_mul_192_64

Multiplies `bi192` by `bi64`

Inputs: 

`rcx` - pointer to `bi192` left value

`rdx` - `bi64` right value

`r8` - pointer to `bi256` result value



## bi_mul_256_64

Multiplies `bi256` value by `bi64` value

Inputs: 

`rcx` - pointer to left `bi256` value

`rdx` - `bi64` value

`r8` - pointer to result `bi320` value



## bi_mul_256_128





## bi_mul_64_64_low_64





## bi_mul_256_128_low_256





## bi_mul_256_256

Multiplies two `bi256` values

Inputs: 

`rcx` - pointer to left `bi256` value

`rdx` - pointer to right `bi256` value

`r8` - pointer to result `bi512` value



## bi_mul_256_64_low_256





## bi_mul_320_64





## bi_mul_320_64_low_320





## bi_mul_384_64





## bi_mul_384_128





## bi_mul_384_64_low_384





## bi_mul_448_64





## bi_mul_448_128





## bi_mul_448_64_low_448





## bi_mul_512_64





## bi_mul_512_256





## bi_mul_512_512





## bi_mul_512_64_low_512





## bi_mul_512_512_low_512





## bi_one_128





## bi_one_256





## bi_one_512





## bi_one_1024





## bi_rem_128_64

Calculates remainder of `bi128` dividend by `bi64`

Inputs: 

`rcx` - pointer to `bi128` dividend

`rdx` - `bi64` divisor

`r8` - pointer to `bi64` remainder



## bi_rem_128_128





## bi_rem_192_64





## bi_rem_192_128





## bi_rem_192_192





## bi_rem_256_64





## bi_rem_256_128





## bi_rem_256_192





## bi_rem_256_256





## bi_rem_320_64





## bi_rem_320_128





## bi_rem_320_192





## bi_rem_320_256





## bi_rem_320_320





## bi_rem_384_64





## bi_rem_384_128





## bi_rem_384_192

Calculates remainder of `bi384` dividend by `bi192`

Inputs: 

`rcx` - pointer to `bi384` dividend

`rdx` - pointer to `bi192` divisor

`r8` - pointer to `bi192` remainder



## bi_rem_384_256

Calculates remainder of `bi384` dividend by `bi256`

Inputs: 

`rcx` - pointer to `bi384` dividend

`rdx` - pointer to `bi256` divisor

`r8` - pointer to `bi256` remainder



## bi_rem_384_320

Calculates remainder of `bi384` dividend by `bi320`

Inputs: 

`rcx` - pointer to `bi384` dividend

`rdx` - pointer to `bi320` divisor

`r8` - pointer to `bi320` remainder



## bi_rem_384_384

Calculates remainder of `bi384` dividend by `bi384`

Inputs: 

`rcx` - pointer to `bi384` dividend

`rdx` - pointer to `bi384` divisor

`r8` - pointer to `bi384` remainder



## bi_rem_448_64





## bi_rem_448_128





## bi_rem_448_192





## bi_rem_448_256





## bi_rem_448_320





## bi_rem_448_384





## bi_rem_448_448





## bi_rem_512_64





## bi_rem_512_128





## bi_rem_512_192





## bi_rem_512_256





## bi_rem_512_320





## bi_rem_512_384





## bi_rem_512_448





## bi_rem_512_512





## bi_rnd_64





## bi_rnd_128





## bi_rnd_192





## bi_rnd_256





## bi_rnd_320





## bi_rnd_384





## bi_rnd_448





## bi_rnd_512





## bi_rnd_1024





## bi_shl_128





## bi_shl_256





## bi_shl_384





## bi_shl_512





## bi_shl_assign_128





## bi_shl_assign_128_1





## bi_shl_assign_192





## bi_shl_assign_256





## bi_shl_assign_256_1





## bi_shl_assign_256_64





## bi_shl_assign_256_128





## bi_shl_assign_320





## bi_shl_assign_384





## bi_shl_assign_448





## bi_shl_assign_512





## bi_shl_assign_512_1





## bi_shl_assign_512_64





## bi_shl_assign_512_128





## bi_shl_assign_512_256





## bi_shr_128

Shifts right `bi128` value

Inputs: 

`rcx` - pointer to source `bi128` value

`rdx` - pointer to target `bi128` value

`r8` - bits



## bi_shr_256

Shifts right `bi256` value

Inputs: 

`rcx` - pointer to source `bi256` value

`rdx` - pointer to target `bi256` value

`r8` - bits



## bi_shr_512

Shifts right `bi512` value

Inputs: 

`rcx` - pointer to source `bi512` value

`rdx` - pointer to target `bi512` value

`r8` - bits



## bi_shr_assign_128





## bi_shr_assign_128_1





## bi_shr_assign_256





## bi_shr_assign_256_1





## bi_shr_assign_256_64





## bi_shr_assign_256_128





## bi_shr_assign_512





## bi_shr_assign_512_1





## bi_shr_assign_512_64





## bi_shr_assign_512_128





## bi_shr_assign_512_256





## bi_square_64

Squares `bi64` value

Inputs: 

`rcx` - left `bi64` value

`rdx` - pointer to result `bi128` value



## bi_square_128

Squares `bi128` value

Inputs: 

`rcx` - pointer to `bi128` value

`rdx` - pointer to `bi256` result



## bi_square_256

Squares `bi256` value

Inputs: 

`rcx` - pointer to `bi256` value

`rdx` - pointer to `bi512` result



## bi_sub_128_128





## bi_sub_192_192





## bi_sub_256_256





## bi_sub_512_512





## bi_sub_assign_128_128





## bi_sub_assign_192_128





## bi_sub_assign_192_192





## bi_sub_assign_256_128





## bi_sub_assign_256_192





## bi_sub_assign_256_256





## bi_sub_assign_320_128





## bi_sub_assign_320_192





## bi_sub_assign_320_256





## bi_sub_assign_320_320





## bi_sub_assign_384_128





## bi_sub_assign_384_192





## bi_sub_assign_384_256





## bi_sub_assign_384_320





## bi_sub_assign_384_384





## bi_sub_assign_448_128





## bi_sub_assign_448_192





## bi_sub_assign_448_256





## bi_sub_assign_448_320





## bi_sub_assign_448_384





## bi_sub_assign_448_448





## bi_sub_assign_512_128





## bi_sub_assign_512_192





## bi_sub_assign_512_256





## bi_sub_assign_512_320





## bi_sub_assign_512_384





## bi_sub_assign_512_448





## bi_sub_assign_512_512





## bi_try_read_hex_64





## bi_try_read_hex_128





## bi_try_read_hex_192





## bi_try_read_hex_256





## bi_try_read_hex_320





## bi_try_read_hex_384





## bi_try_read_hex_448





## bi_try_read_hex_512





## bi_try_read_hex_576





## bi_try_read_hex_768





## bi_try_read_hex_1024





## bi_zero_128

Zeroes `bi128` value

Inputs: 

`rcx` - pointer to `bi128` value



## bi_zero_192

Zeroes `bi192` value

Inputs: 

`rcx` - pointer to `bi192` result



## bi_zero_256

Zeroes `bi256` value

Inputs: 

`rcx` - pointer to `bi256` result



## bi_zero_320

Zeroes `bi320` value

Inputs: 

`rcx` - pointer to `bi320` result



## bi_zero_384

Zeroes `bi384` value

Inputs: 

`rcx` - pointer to `bi384` result



## bi_zero_448

Zeroes `bi448` value

Inputs: 

`rcx` - pointer to `bi448` result



## bi_zero_512

Zeroes `bi512` value

Inputs: 

`rcx` - pointer to `bi512` result



## bi_zero_576

Zeroes `bi576` value

Inputs: 

`rcx` - pointer to `bi576` result



## bi_zero_768

Zeroes `bi768` value

Inputs: 

`rcx` - pointer to `bi768` result



## bi_zero_1024

Zeroes `bi1024` value

Inputs: 

`rcx` - pointer to `bi1024` result



## ec_affine_point_256_add





## ec_affine_point_256_add_assign





## ec_affine_point_256_copy





## ec_affine_point_256_double





## ec_affine_point_256_double_assign





## ec_affine_point_256_is_infinity





## ec_affine_point_256_mul





## ec_affine_point_256_negate





## ec_affine_point_256_set_infinity

Sets `ECAffinePoint256` to infinity

Inputs: 

`rcx` - pointer to `ECAffinePoint256`



## ec_affine_point_256_shl





## ec_affine_point_256_shl_assign





## ec_affine_point_256_sub





## ec_affine_point_256_sub_assign





## ec_affine_point_256_try_read_hex





## ec_projective_mont_point_256_add





## ec_projective_mont_point_256_add_assign





## ec_projective_mont_point_256_copy





## ec_projective_mont_point_256_double





## ec_projective_mont_point_256_double_assign





## ec_projective_mont_point_256_from_affine_point

Converts `ECAffinePoint256` to `ECProjectiveMontgomeryPoint256`

Inputs: 

`rcx` - pointer to destination `ECProjectiveMontgomeryPoint256`

`rdx` - pointer to source `ECAffinePoint256`



## ec_projective_mont_point_256_from_projective_point

Converts `ECProjectivePoint256` to `ECProjectiveMontgomeryPoint256`

Inputs: 

`rcx` - pointer to destination `ECProjectiveMontgomeryPoint256`

`rdx` - pointer to source `ECProjectivePoint256`



## ec_projective_mont_point_256_is_infinity





## ec_projective_mont_point_256_mul





## ec_projective_mont_point_256_negate





## ec_projective_mont_point_256_set_infinity

Sets `ECProjectiveMontgomeryPoint256` to infinity

Inputs: 

`rcx` - pointer to `ECProjectiveMontgomeryPoint256`



## ec_projective_mont_point_256_shl





## ec_projective_mont_point_256_shl_assign





## ec_projective_mont_point_256_sub





## ec_projective_mont_point_256_sub_assign





## ec_projective_mont_point_256_to_affine_point

Converts `ECProjectiveMontgomeryPoint256` to `ECAffinePoint256`

Inputs: 

`rcx` - pointer to source `ECProjectiveMontgomeryPoint256`

`rdx` - pointer to destination `ECAffinePoint256`



## ec_projective_mont_point_256_to_projective_point

Converts `ECProjectiveMontgomeryPoint256` to `ECProjectivePoint256`

Inputs: 

`rcx` - pointer to source `ECProjectiveMontgomeryPoint256`

`rdx` - pointer to destination `ECProjectivePoint256`



## ec_projective_mont_point_256_try_read_hex





## ec_projective_point_256_add





## ec_projective_point_256_add_assign





## ec_projective_point_256_copy





## ec_projective_point_256_double





## ec_projective_point_256_double_assign





## ec_projective_point_256_from_affine_point

Converts `ECAffinePoint256` to `ECProjectivePoint256`

Inputs: 

`rcx` - pointer to destination `ECProjectivePoint256`

`rdx` - pointer to source `ECAffinePoint256`



## ec_projective_point_256_is_infinity





## ec_projective_point_256_mul





## ec_projective_point_256_negate





## ec_projective_point_256_set_infinity

Sets `ECProjectivePoint256` to infinity

Inputs: 

`rcx` - pointer to `ECProjectivePoint256`



## ec_projective_point_256_shl





## ec_projective_point_256_shl_assign





## ec_projective_point_256_sub





## ec_projective_point_256_sub_assign





## ec_projective_point_256_to_affine_point

Converts `ECProjectivePoint256` to `ECAffinePoint256`

Inputs: 

`rcx` - pointer to source `ECProjectivePoint256`

`rdx` - pointer to destination `ECAffinePoint256`



## ec_projective_point_256_try_read_hex





## secp256k1_get_affine_point

Calculates `ECAffinePoint256` from `bi256` multiplier

Inputs: 

`rcx` - pointer to `bi256` multiplier

`rdx` - pointer to result `ECAffinePoint256` value



