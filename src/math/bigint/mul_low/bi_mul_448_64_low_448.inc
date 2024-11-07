if ~ definite bi_mul_448_64_low_448

if BMI2_ENABLED = 1
  include 'bi_mul_448_64_low_448.bmi2.inc'
  bi_mul_448_64_low_448 = bi_mul_448_64_low_448_bmi2
else
 ; include 'bi_mul_448_64_low_448.basic.inc'
 ; bi_mul_448_64_low_448 = bi_mul_448_64_low_448_basic
end if

end if
