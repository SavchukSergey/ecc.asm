if ~ definite bi_div_rem_512_128_dac
; divide and conqueror

bi_div_rem_512_128_dac:
virtual at rsp
  label .locals_start
  .dividend rq 1
  .divisor rq 1
  .quotient rq 1
  .remainder rq 1

; partial quotient can be combined to reduce stack usage
  .q0 BigInteger256
  .q1 BigInteger256
  .q2 BigInteger256

  .partial_remainder BigInteger256
  AlignLocalsStackFrame
  label .locals_end
end virtual
    sub     rsp, .locals_end - .locals_start

    PrologCheckStackAligned 'bi_div_rem_512_128_dac'
    CheckRegBi512Alignment rcx, 'bi_div_rem_512_128_dac rcx'
    CheckRegBi128Alignment rdx, 'bi_div_rem_512_128_dac rdx'
    CheckRegBi512Alignment r8, 'bi_div_rem_512_128_dac r8'
    CheckRegBi512Alignment r9, 'bi_div_rem_512_128_dac r9'

    mov     [.dividend], rcx
    mov     [.divisor], rdx
    mov     [.quotient], r8
    mov     [.remainder], r9

    mov     rcx, [.remainder]
    mov     rdx, [.dividend]
    call    bi_copy_512

    mov     rcx, [.remainder]
    add     rcx, __BIG_INTEGER_BYTES_256
    mov     rdx, [.divisor]
    lea     r8, [.q2]
    lea     r9, [.partial_remainder]
    call    bi_div_rem_256_128
    
    mov     rcx, [.remainder]
    add     rcx, __BIG_INTEGER_BYTES_256
    lea     rdx, [.partial_remainder]
    call    bi_copy_128

    mov     rcx, [.remainder]
    add     rcx, __BIG_INTEGER_BYTES_128
    mov     rdx, [.divisor]
    lea     r8, [.q1]
    lea     r9, [.partial_remainder]
    call    bi_div_rem_256_128

    mov     rcx, [.remainder]
    add     rcx, __BIG_INTEGER_BYTES_128
    lea     rdx, [.partial_remainder]
    call    bi_copy_128

    mov     rcx, [.remainder]
    mov     rdx, [.divisor]
    lea     r8, [.q0]
    lea     r9, [.partial_remainder]
    call    bi_div_rem_256_128

    mov     rcx, [.remainder]
    lea     rdx, [.partial_remainder]
    call    bi_extend_512_128

    mov     rcx, [.quotient]
    lea     rdx, [.q0]
    call    bi_extend_512_256

    mov     rcx, [.quotient]
    add     rcx, __BIG_INTEGER_BYTES_128
    lea     rdx, [.q1]
    call    bi_add_assign_384_256

    mov     rcx, [.quotient]
    add     rcx, __BIG_INTEGER_BYTES_256
    lea     rdx, [.q2]
    call    bi_add_assign_256_256

    add     rsp, .locals_end - .locals_start
    ret

end if