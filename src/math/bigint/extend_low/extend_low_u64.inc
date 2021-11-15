include '../src/mem/zero_static.inc'

macro BigIntegerExtendLowU64 bits {

if bits >= 128
;Extends value from unsigned 64-bite value
;input
; rax - source value
; output
; rdi - pointer to destination value
__bi_extend_low_u64_#bits:
virtual at rdi
  .result BigInteger#bits
end virtual
        mov     [.result], rax
        MemoryZeroStatic rdi + 8, (bits - 64) / 8
        ret
end if


}