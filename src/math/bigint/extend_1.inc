macro BigIntegerExtend1 bits {

if bits >= 128
;Extends value from smaller bi
;input
; rax - source value
; output
; rdi - destination value
__bi_extend_1_#bits:
virtual at rax
  .value BigInteger#bits
end virtual
virtual at rdi
  .result BigInteger#bits
end virtual
        push    rdx

        repeat  __BIG_INTEGER_QWORDS_#bits / 2
        mov     rdx, [.value + (% - 1) * 8]
        mov     [.result + (% - 1) * 8], rdx
        end repeat

        xor     rdx, rdx
        repeat  __BIG_INTEGER_QWORDS_#bits / 2
        mov     [.result + (% - 1) * 8 + (__BIG_INTEGER_BYTES_#bits / 2)], rdx
        end repeat

        pop     rdx
        ret
end if

}