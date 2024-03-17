if ~ definite bi_extend_512_256

bi_extend_512_256:
        mov     rax, [rdx + 0]
        mov     [rcx + 0], rax
        mov     rax, [rdx + 8]
        mov     [rcx + 8], rax
        mov     rax, [rdx + 16]
        mov     [rcx + 16], rax
        mov     rax, [rdx + 24]
        mov     [rcx + 24], rax
        mov     qword [rcx + 32], 0
        mov     qword [rcx + 40], 0
        mov     qword [rcx + 48], 0
        mov     qword [rcx + 56], 0

        ret

end if

include '../../../mem/copy_static.inc'
include '../../../mem/zero_static.inc'

macro BigIntegerExtendLowCode source_bits, target_bits {
      if (source_bits) <= (target_bits)
        MemoryCopyStatic rax, rdi, (source_bits) / 8
        MemoryZeroStatic rdi + (source_bits) / 8, ((target_bits) - (source_bits)) / 8
        ret
      else
        display 'source_bits cannot be greater then target_bits'
      end if

}

