if ~ definite __bi_mul_macro

__bi_mul_macro equ 0

include '../../../asserts/index.inc'
include '../../../../src/math/bigint/macro/call.try_read_hex.inc'
include '../../../../src/math/bigint/macro/call.inc'

macro BiMulTestCoreMacro left_bits, right_bits {
  result_bits = (left_bits + right_bits)

virtual at rsp
.locals_start:
  BigInteger .left, left_bits
  BigInteger .right, right_bits
  GuardPreField
  BigInteger .result, result_bits
  GuardPostField
  .left_hex rq 1
  .right_hex rq 1
  .expected_hex rq 1
  AlignLocalsStackFrame
.locals_end:
end virtual
        sub     rsp, .locals_end - .locals_start
    PrologCheckStackAligned '__bi_mul_test_performance_core_macro'
    CheckRegAligned rcx, '__bi_mul_test_performance_core_macro rcx'
    CheckRegAligned rdx, '__bi_mul_test_performance_core_macro rdx'
    CheckRegAligned r8, '__bi_mul_test_performance_core_macro r8'

        mov     [.left_hex], rcx
        mov     [.right_hex], rdx
        mov     [.expected_hex], r8

        mov     rcx, [.left_hex]
        lea     rdx, [.left]
        CallBiTryReadHex left_bits

        mov     rcx, [.right_hex]
        lea     rdx, [.right]
        CallBiTryReadHex right_bits

        GuardInit


        call    test_context_start_measure
.chunk_loop:
        lea     rcx, [.left]
  if right_bits > 64
        lea     rdx, [.right]
  else
        mov     rdx, [.right]
  end if
        lea     r8, [.result]
        Call_Mul left_bits, right_bits
        call    test_context_measure_dec_chunk
        jnz     .chunk_loop
        call    test_context_end_measure

        mov     rcx, [.expected_hex]
        lea     rdx, [.result]
        CallBiAssertEqualHex result_bits

        GuardCheck

        add     rsp, .locals_end - .locals_start
        ret
}

end if