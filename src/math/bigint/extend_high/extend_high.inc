include '../src/mem/copy_static.inc'
include '../src/mem/zero_static.inc'

macro BigIntegerExtendHighCode source_bits, target_bits {
      if (source_bits) <= (target_bits)
        MemoryCopyStatic rax, rdi + ((target_bits) - (source_bits)) / 8, (source_bits) / 8
        MemoryZeroStatic rdi, ((target_bits) - (source_bits)) / 8
        ret
      else
        display 'source_bits cannot be greater then target_bits'
      end if

}

