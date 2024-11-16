;Multiplies two bi256 values
;input:
; rcx - pointer to left bi256 value
; rdx - pointer to right bi256 value
; r8 - pointer to result bi512 value

if CPU=CPU_INTEL
  include 'bi_mul_256_256.basic.inc'
else
  include 'bi_mul_256_256.bmi2.inc'
end if