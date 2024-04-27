
include 'ecpoint256.inc'

if ~ definite ecpoint256_is_infinity

;Checks if point is at infinity
;input:
;  rcx - pointer to left ecpoint256
;output:
;  rax - 1 if point is in infinity, 0 otherwise
;  ZF - 1 if point is in infinity, 0 otherwise

; same signature, same result
ecpoint256_is_infinity = bi_is_zero_512

end if