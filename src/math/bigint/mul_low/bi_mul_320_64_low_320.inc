if ~ definite bi_mul_320_64_low_320

if BMI2_ENABLED = 1
  include 'bi_mul_320_64_low_320.bmi2.inc'
  bi_mul_320_64_low_320 = bi_mul_320_64_low_320_bmi2
else
 ; include 'bi_mul_320_64_low_320.basic.inc'
 ; bi_mul_320_64_low_320 = bi_mul_320_64_low_320_basic
end if

end if
