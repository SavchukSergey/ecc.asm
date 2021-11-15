include '../src/mem/zero_static.inc'

macro BigIntegerExtendHighU64 bits {

if bits >= 128
;Extends value from unsigned 64-bite value
;input
; rax - source value
; output
; rdi - pointer to destination value
__bi_extend_high_u64_#bits:
virtual at rdi
  .result BigInteger#bits
end virtual
        mov     [.result + (bits - 64) / 8], rax
        MemoryZeroStatic rdi + 8, (bits - 8)
        ret
end if


}