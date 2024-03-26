include '../src/math/bigint/copy/bi_copy_256.inc'

__bi_copy_256_test:
virtual at rsp
.locals_start:
  .source rb __BIG_INTEGER_BYTES_256
  .target rb __BIG_INTEGER_BYTES_256
.locals_end:
end virtual
    enter   .locals_end - .locals_start, 0  
    lea     rcx, [.source_hex]
    lea     rdx, [.source]
    call    bi_try_read_hex_256

    call    test_context_start_measure
    lea     rcx, [.target]
    lea     rdx, [.source]
    call    bi_copy_256
    call    test_context_end_measure

    lea     rcx, [.source_hex]
    lea     rdx, [.target]
    call    bi_assert_equal_hex_256

    leave
    ret

.source_hex db '6f3401a7ecd9da0b8990cbb1a2f723b1079e1bb029e94621b5a1ebc753efcfae'
