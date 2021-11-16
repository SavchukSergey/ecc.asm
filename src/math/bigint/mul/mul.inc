macro BigIntegerMul bits, dbits {

if ~ definite __bi_mul_#bits

;Divides two bi values
;input
; rax - left value
; rbx - right value
; rdi - result value
__bi_mul_#bits:
virtual at rsp
.locals_start:
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0
        leave
        ret

end if

}
