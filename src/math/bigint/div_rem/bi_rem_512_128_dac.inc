if ~ definite bi_rem_512_128_dac

include '../extend_low/bi_extend_512_128.inc'
include 'bi_rem_256_128.inc'

bi_rem_512_128_dac:
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .remainder rq 1

  .partial_remainder BigInteger256
  AlignLocalsStackFrame
  label .locals_end
end virtual
    sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'bi_rem_512_128_dac'
    CheckRegBi512Alignment rcx, 'bi_rem_512_128_dac rcx'
    CheckRegBi128Alignment rdx, 'bi_rem_512_128_dac rdx'
    CheckRegBi512Alignment r8, 'bi_rem_512_128_dac r8'

    mov     [.dividend], rcx
    mov     [.divisor], rdx
    mov     [.remainder], r8

    mov     rcx, [.remainder]
    mov     rdx, [.dividend]
    call    bi_copy_512

    mov     rcx, [.remainder]
    add     rcx, __BIG_INTEGER_BYTES_256
    mov     rdx, [.divisor]
    lea     r8, [.partial_remainder]
    call    bi_rem_256_128
    
    mov     rcx, [.remainder]
    add     rcx, __BIG_INTEGER_BYTES_256
    lea     rdx, [.partial_remainder]
    call    bi_copy_128

    mov     rcx, [.remainder]
    add     rcx, __BIG_INTEGER_BYTES_128
    mov     rdx, [.divisor]
    lea     r8, [.partial_remainder]
    call    bi_rem_256_128

    mov     rcx, [.remainder]
    add     rcx, __BIG_INTEGER_BYTES_128
    lea     rdx, [.partial_remainder]
    call    bi_copy_128

    mov     rcx, [.remainder]
    mov     rdx, [.divisor]
    lea     r8, [.partial_remainder]
    call    bi_rem_256_128

    mov     rcx, [.remainder]
    lea     rdx, [.partial_remainder]
    call    bi_extend_512_128

    add     rsp, .locals_end - .locals_start
    ret

end if