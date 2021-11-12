macro BigIntegerExtendU64 bits {

if bits >= 128
;Extends value from unsigned 64-bite value
;input
; rax - source value
; output
; rdi - pointer to destination value
__bi_extend_u64_#bits:
virtual at rdi
  .result BigInteger#bits
end virtual
        push    rdx

        mov     [.result], rax

        xor     rdx, rdx
        repeat  __BIG_INTEGER_QWORDS_#bits - 1
        mov     [.result + (% - 1) * 8 + 8], rdx
        end repeat

        pop     rdx
        ret
end if


}