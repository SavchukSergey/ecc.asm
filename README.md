Full list of methods:

| Name                                        | Description                          |
|---------------------------------------------|--------------------------------------|
| [bi_zero_128](#bi_zero_128)                 | Zeroes `bi128` value                 |
| [bi_zero_192](#bi_zero_192)                 | Zeroes `bi192` value                 |
| [bi_zero_256](#bi_zero_256)                 | Zeroes `bi256` value                 |
| [bi_zero_512](#bi_zero_512)                 | Zeroes `bi512` value                                        |
| [bi_zero_1024](#bi_zero_1024)               | Zeroes `bi1024` value                |
| [bi_one_128](#bi_one_128)                   | Sets 1 to `bi128` value              |
| [bi_copy_128](#bi_copy_128)                 | Copies `bi128` value                 |
| [bi_add_128_128](#bi_add_128_128)           | Adds two `bi128` values              |
| [bi_add_192_192](#bi_add_192_192)           | Adds two `bi192` values              |
| [bi_add_256_256](#bi_add_256_256)           | Adds two `bi256` values              |
| [bi_add_512_512](#bi_add_512_512)           | Adds two `bi512` values              |
| [bi_sub_128_128](#bi_sub_128_128)           | Subtracts two `bi128` values         |
| [bi_sub_192_192](#bi_sub_192_192)           | Subtracts two `bi192` values         |
| [bi_sub_256_256](#bi_sub_256_256)           | Subtracts two `bi256` values         |
| [bi_sub_512_512](#bi_sub_512_512)           | Subtracts two `bi512` values         |
| [bi_mul_128_64](#bi_mul_128_64)             | Multiplies `bi128` by `bi64` value                          |
| [bi_mul_128_128](#bi_mul_128_128)           | Multiplies two `bi128` values                               |
| [bi_mul_low_128_128](#bi_mul_low_128_128)   | Multiplies two `bi128` values and returns low `bi128` value |
| [bi_shl_assign_128_1](#bi_shl_assign_128_1) | Shifts `bi128` to the left by 1 bit  |
| [bi_shr_assign_128_1](#bi_shr_assign_128_1) | Shifts `bi128` to the right by 1 bit |
| [bi_shl_assign_128](#bi_shl_assign_128)     | Shifts `bi128` to the left           |
| [bi_is_zero_256](#bi_is_zero_256)           | Check if `bi256` value is zero       |
| [bi_one_256](#bi_one_256)                   | Sets 1 to `bi256` value              |
| [bi_copy_256](#bi_copy_256)                 | Copies `bi256` value                 |
| [bi_mul_256_256](#bi_mul_256_256)           | Multiplies two `bi256` values        |
| [bi_mul_low_256_256](#bi_mul_low_256_256)               | Multiplies two `bi256` values and returns low `bi256` value |
| [bi_div_rem_128_64](#bi_div_rem_128_64)                 | Divides `bi128` by `bi64`                                   |
| [bi_div_rem_128_128](#bi_div_rem_128_128)               | Divides `bi128` by `bi128`                                  |
| [bi_div_rem_192_64](#bi_div_rem_192_64)                 | Divides `bi192` by `bi64`                                   |
| [bi_div_rem_256_64](#bi_div_rem_256_64)                 | Divides `bi256` by `bi64`                                   |
| [bi_div_rem_256_128](#bi_div_rem_256_128)               | Divides `bi256` by `bi128`                                  |
| [bi_div_rem_256_256](#bi_div_rem_256_256)               | Divides `bi256` by `bi256`                                  |
| [bi_div_rem_512_256](#bi_div_rem_512_256)               | Divides `bi512` by `bi256`                                  |
| [bi_div_rem_512_512](#bi_div_rem_512_512)               | Divides `bi512` by `bi512`                                  |
| [bi_rem_192_64](#bi_rem_192_64)                         | Remainder `bi192` by `64`                                   |
| [bi_rem_256_64](#bi_rem_256_64)                         | Remainder `bi256` by `64`                                   |
| [bi_lzcnt_128](#bi_lzcnt_128)                           | Counts leading zero bits of `bi128`                         |
| [bi_lzcnt_192](#bi_lzcnt_192)                           | Counts leading zero bits of `bi192`                         |
| [bi_lzcnt_256](#bi_lzcnt_256)                           | Counts leading zero bits of `bi256`                         |
| [bi_shl_assign_256_1](#bi_shl_assign_256_1)             | Shifts `bi256` to the left by 1 bit                         |
| [bi_shr_assign_256_1](#bi_shr_assign_256_1)             | Shifts `bi256` to the right by 1 bit                        |
| [bi_shl_assign_256](#bi_shl_assign_256)                 | Shifts `bi256` to the left                                  |
| [bi_cmp_128_128](#bi_cmp_128_128)                       | Compares two `bi128` values                                 |
| [bi_cmp_192_192](#bi_cmp_192_192)                       | Compares two `bi192` values                                 |
| [bi_cmp_256_256](#bi_cmp_256_256)                       | Compares two `bi256` values                                 |
| [bi_cmp_512_512](#bi_cmp_512_512)                       | Compares two `bi512` values                                 |
| [bi_cmp_1024_1024](#bi_cmp_1024_1024)                   | Compares two `bi1024` values                                |
| [bi_mod_add_assign_256_256](#bi_mod_add_assign_256_256) | Adds two `bi256` values with modulo                         |
| [bi_mod_sub_assign_256_256](#bi_mod_sub_assign_256_256) | Subtracts two `bi256` values with modulo                    |
| [bi_one_512](#bi_one_512)                               | Sets 1 to `bi512` value                                     |
| [bi_mul_512_512](#bi_mul_512_512)           | Multiplies two `bi512` values        |
| [bi_lzcnt_512](#bi_lzcnt_512)               | Counts leading zero bits of `bi512`  |
| [bi_shl_assign_512_1](#bi_shl_assign_512_1) | Shifts `bi512` to the left by 1 bit  |
| [bi_shr_assign_512_1](#bi_shr_assign_512_1) | Shifts `bi512` to the right by 1 bit |
| [bi_shl_assign_512](#bi_shl_assign_512)     | Shifts `bi512` to the left           |
| [bi_one_1024](#bi_one_1024)                 | Sets 1 to `bi1024` value             |

# Zero operations

## bi_zero_128
Zeroes `bi128` value

Input:
  * `rcx` - pointer to `bi128` value

## bi_zero_192
Zeroes `bi192` value

Input:
  * `rcx` - pointer to `bi192` value

## bi_zero_256
Zeroes `bi256` value

Input:
  * `rcx` - pointer to `bi256` value

## bi_zero_512
Zeroes `bi512` value

Input:
  * `rcx` - pointer to `bi512` value

## bi_zero_1024
Zeroes `bi1024` value

Input:
  * `rcx` - pointer to `bi1024` value
  
# bi128 operations

## bi_one_128
Sets 1 to `bi128` value

Input:
  * `rcx` - pointer to `bi128` value

## bi_copy_128
Copies `bi128` value

Input:
  * `rcx` - pointer to `bi128` target value
  * `rdx` - pointer to `bi128` source value

# Add operations

## bi_add_128_128
Adds two `bi128` values

Input:
  * `rcx` - pointer to `bi128` left value
  * `rdx` - pointer to `bi128` right value
  * `r8` - pointer to `bi128` result value

## bi_add_192_192
Adds two `bi192` values

Input:
  * `rcx` - pointer to `bi192` left value
  * `rdx` - pointer to `bi192` right value
  * `r8` - pointer to `bi192` result value

## bi_add_256_256
Adds two `bi256` values

Input:
  * `rcx` - pointer to `bi256` left value
  * `rdx` - pointer to `bi256` right value
  * `r8` - pointer to `bi256` result value

## bi_add_512_512
Adds two `bi512` values

Input:
  * `rcx` - pointer to `bi512` left value
  * `rdx` - pointer to `bi512` right value
  * `r8` - pointer to `bi512` result value

# Subtract operations

## bi_sub_128_128

Subtracts two `bi128` values

Input:
  * `rcx` - pointer to `bi128` left value
  * `rdx` - pointer to `bi128` right value
  * `r8` - pointer to `bi128` result value

## bi_sub_192_192

Subtracts two `bi192` values

Input:
  * `rcx` - pointer to `bi192` left value
  * `rdx` - pointer to `bi192` right value
  * `r8` - pointer to `bi192` result value

## bi_sub_256_256

Subtracts two `bi256` values

Input:
  * `rcx` - pointer to `bi256` left value
  * `rdx` - pointer to `bi256` right value
  * `r8` - pointer to `bi256` result value

## bi_sub_512_512

Subtracts two `bi512` values

Input:
  * `rcx` - pointer to `bi512` left value
  * `rdx` - pointer to `bi512` right value
  * `r8` - pointer to `bi512` result value

## bi_mul_128_64

Multiplies `bi128` by `bi64` value

Input:
  * `rcx` - pointer to `bi128` left value
  * `rdx` - `bi64` right value
  * `r8` - pointer to `bi256` result value

## bi_mul_128_128
Multiplies two `bi128` values

Input:
  * `rcx` - pointer to `bi128` left value
  * `rdx` - pointer to `bi128` right value
  * `r8` - pointer to `bi256` result value

## bi_mul_low_128_128
Multiplies two `bi128` values and returns low `bi128` value

Input:
  * `rcx` - pointer to `bi128` left value
  * `rdx` - pointer to `bi128` right value
  * `r8` - pointer to `bi128` result value

## bi_div_rem_128_64
Divides `bi128` by `bi64`

Input:
  * `rcx` - pointer to `bi128` dividend value
  * `rdx` - `bi64` divisor value
  * `r8` - pointer to `bi128` quotient value
  * `r9` - pointer to `bi128` remainder value (actual result will be `bi64` with zeroed upper half)

## bi_div_rem_128_128
Divides `bi128` by `bi128`

Input:
  * `rcx` - pointer to `bi128` dividend value
  * `rdx` - `bi128` divisor value
  * `r8` - pointer to `bi128` quotient value
  * `r9` - pointer to `bi128` remainder value

## bi_lzcnt_128
Counts leading zero bits of `bi128` value

Input:
  * `rcx` - pointer to `bi128` value

Output:
  * `rax` - count of leading zero bits

## bi_shl_assign_128_1
Shifts `bi128` to the left by 1 bit. Result is stored in left value.

Input:
  * `rcx` - pointer to `bi128` value

## bi_shr_assign_128_1
Shifts `bi128` to the right by 1 bit. Result is stored in left value.

Input:
  * `rcx` - pointer to `bi128` value

## bi_shl_assign_128
Shifts `bi128` to the right. Result is stored in left value.

Input:
* `rcx` - pointer to `bi128` value
* `rdx` - bits count to shift

# bi256 operations

## bi_is_zero_256
Check if `bi256` value is zero

Input:
  * `rcx` - pointer to `bi256` value

Output:
  * `rax` - 1 if value is zero, 0 otherwize
  * `ZF` - flag is set if value is zero

## bi_one_256
Sets 1 to `bi256` value

Input:
  * `rcx` - pointer to `bi256` value

## bi_copy_256
Copies `bi256` value

Input:
  * `rcx` - pointer to `bi256` target value
  * `rdx` - pointer to `bi256` source value

## bi_mul_256_256
Multiplies two `bi256` values

Input:
  * `rcx` - pointer to `bi256` left value
  * `rdx` - pointer to `bi256` right value
  * `r8` - pointer to `bi512` result value

## bi_mul_low_256_256
Multiplies two `bi256` values and returns low `bi256` value

Input:
  * `rcx` - pointer to `bi256` left value
  * `rdx` - pointer to `bi256` right value
  * `r8` - pointer to `bi256` result value

# Division and remainder operations

## bi_div_rem_192_64
Divides `bi192` by `bi64`

Input:
  * `rcx` - pointer to `bi192` dividend value
  * `rdx` - `bi64` divisor value
  * `r8` - pointer to `bi192` quotient value
  * `r9` - pointer to `bi192` remainder value (actual result will be `bi64` with zeroed upper half)

## bi_div_rem_256_64
Divides `bi256` by `bi64`

Input:
  * `rcx` - pointer to `bi256` dividend value
  * `rdx` - `bi64` divisor value
  * `r8` - pointer to `bi256` quotient value
  * `r9` - pointer to `bi256` remainder value (actual result will be `bi64` with zeroed upper half)

## bi_div_rem_256_128
Divides `bi256` by `bi128`

Input:
  * `rcx` - pointer to `bi256` dividend value
  * `rdx` - pointer to `bi128` divisor value
  * `r8` - pointer to `bi256` quotient value
  * `r9` - pointer to `bi256` remainder value (actual result will be `bi128` with zeroed upper half)

## bi_div_rem_256_256
Divides `bi256` by `bi256`

Input:
  * `rcx` - pointer to `bi256` dividend value
  * `rdx` - pointer to `bi256` divisor value
  * `r8` - pointer to `bi256` quotient value
  * `r9` - pointer to `bi256` remainder value

## bi_div_rem_512_256
Divides `bi512` by `bi256`

Input:
  * `rcx` - pointer to `bi512` dividend value
  * `rdx` - pointer to `bi256` divisor value
  * `r8` - pointer to `bi512` quotient value
  * `r9` - pointer to `bi512` remainder value

## bi_div_rem_512_512
Divides `bi512` by `bi512`

Input:
  * `rcx` - pointer to `bi512` dividend value
  * `rdx` - pointer to `bi512` divisor value
  * `r8` - pointer to `bi512` quotient value
  * `r9` - pointer to `bi512` remainder value

## bi_lzcnt_192
Counts leading zero bits of `bi192` value

Input:
  * `rcx` - pointer to `bi192` value

Output:
  * `rax` - count of leading zero bits

## bi_lzcnt_256
Counts leading zero bits of `bi256` value

Input:
  * `rcx` - pointer to `bi256` value

Output:
  * `rax` - count of leading zero bits
  
## bi_shl_assign_256_1

Shifts `bi256` to the left by 1 bit. Result is stored in left value.

Input:
  * `rcx` - pointer to `bi256` value

## bi_shr_assign_256_1

Shifts `bi256` to the right by 1 bit. Result is stored in left value.

Input:
  * `rcx` - pointer to `bi256` value

## bi_shl_assign_256

Shifts `bi256` to the right. Result is stored in left value.

Input:
* `rcx` - pointer to `bi256` value
* `rdx` - bits count to shift

# Compare operations 

## bi_cmp_128_128
Compares two `bi128` values
Input:
* `rcx` - pointer to left `bi128` value
* `rdx` - pointer to right `bi128` value

Output:
* `rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise

## bi_cmp_192_192
Compares two `bi192` values
Input:
* `rcx` - pointer to left `bi192` value
* `rdx` - pointer to right `bi192` value

Output:
* `rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise

## bi_cmp_256_256
Compares two `bi256` values
Input:
* `rcx` - pointer to left `bi256` value
* `rdx` - pointer to right `bi256` value

Output:
* `rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise

## bi_cmp_512_512
Compares two `bi512` values
Input:
* `rcx` - pointer to left `bi512` value
* `rdx` - pointer to right `bi512` value

Output:
* `rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise

## bi_cmp_1024_1024
Compares two `bi1024` values
Input:
* `rcx` - pointer to left `bi1024` value
* `rdx` - pointer to right `bi1024` value

Output:
* `rax` - sign: 0 values are equal, 1 left value is greater than right value, -1 otherwise

## bi_mod_add_assign_256_256

Adds two `bi256` values with modulo

Input:
* `rcx` - pointer to left `bi256` value. This value is modified.
* `rdx` - pointer to right `bi256` value
* `r8` - pointer to modulo `bi256` value

## bi_mod_sub_assign_256_256

Subtracts two `bi256` values with modulo

Input:
* `rcx` - pointer to left `bi256` value. This value is modified.
* `rdx` - pointer to right `bi256` value
* `r8` - pointer to modulo `bi256` value

# bi512 operations

## bi_one_512
Sets 1 to `bi512` value

Input:
  * `rcx` - pointer to `bi512` value

## bi_mul_512_512
Multiplies two `bi512` values

Input:
  * `rcx` - pointer to `bi512` left value
  * `rdx` - pointer to `bi512` right value
  * `r8` - pointer to `bi1024` result value

## bi_lzcnt_512
Counts leading zero bits of `bi512` value

Input:
  * `rcx` - pointer to `bi512` value

Output:
  * `rax` - count of leading zero bits
  
## bi_shl_assign_512_1

Shifts `bi512` to the left by 1 bit. Result is stored in left value.

Input:
  * `rcx` - pointer to `bi512` value

## bi_shr_assign_512_1

Shifts `bi512` to the right by 1 bit. Result is stored in left value.

Input:
  * `rcx` - pointer to `bi512` value


## bi_shl_assign_512

Shifts `bi512` to the right. Result is stored in left value.

Input:
* `rcx` - pointer to `bi512` value
* `rdx` - bits count to shift

# bi1024 operations

## bi_one_1024
Sets 1 to `bi1024` value

Input:
  * `rcx` - pointer to `bi1024` value


