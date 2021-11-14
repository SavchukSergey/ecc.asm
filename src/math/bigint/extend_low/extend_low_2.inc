macro BigIntegerExtend2 bits {

if bits >= 256
;Extends value from smaller bi
;input
; rax - pointer to source value
; output
; rdi - pointer to destination value
__bi_extend_2_#bits:
virtual at rax
  .value BigInteger#bits
end virtual
virtual at rdi
  .result BigInteger#bits
end virtual
        push    rdx

        repeat  __BIG_INTEGER_QWORDS_#bits / 4
        mov     rdx, [.value + (% - 1) * 8]
        mov     [.result + (% - 1) * 8], rdx
        end repeat

        xor     rdx, rdx
        repeat  3 * __BIG_INTEGER_QWORDS_#bits / 4
        mov     [.result + (% - 1) * 8 + (3 * __BIG_INTEGER_BYTES_#bits / 4)], rdx
        end repeat

        pop     rdx
        ret
end if

}