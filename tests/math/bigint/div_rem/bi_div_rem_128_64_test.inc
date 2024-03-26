include '../src/math/bigint/div_rem/bi_div_rem_128_64.inc'

__bi_div_rem_128_64_test:
virtual at rsp
.locals_start:
  .dividend_hex rq 1
  .divisor_hex rq 1
  .expected_quotient_hex rq 1
  .expected_remainder_hex rq 1
  .dividend rb __BIG_INTEGER_BYTES_128
  .divisor rb __BIG_INTEGER_BYTES_128
  .quotient rb __BIG_INTEGER_BYTES_128
  .remainder rb __BIG_INTEGER_BYTES_128
.locals_end:
end virtual
        enter   .locals_end - .locals_start, 0

        lea     rbx, [.cases]
.loop:        
        lea     rcx, [rbx]
        lea     rdx, [rbx + 32]
        lea     r8, [rbx + 64]
        lea     r9, [rbx + 96]

        push    rbx
        
        mov     [.dividend_hex], rcx
        mov     [.divisor_hex], rdx
        mov     [.expected_quotient_hex], r8
        mov     [.expected_remainder_hex], r9

        mov     rcx, [.dividend_hex]
        lea     rdx, [.dividend]
        call    bi_try_read_hex_128

        mov     rcx, [.divisor_hex]
        lea     rdx, [.divisor]
        call    bi_try_read_hex_128

        lea     rcx, [.dividend]
        mov     rdx, qword [.divisor + 0] ; take low 64 bit
        lea     r8, [.quotient]
        lea     r9, [.remainder]
        call    test_context_start_measure
        call    bi_div_rem_128_64
        call    test_context_end_measure

        mov     rcx, [.expected_quotient_hex]
        lea     rdx, [.quotient]
        call    bi_assert_equal_hex_128
        jc      .fail

        mov     rcx, [.expected_remainder_hex]
        lea     rdx, [.remainder]
        call    bi_assert_equal_hex_128
        jc      .fail

        pop     rbx
        add     rbx, 128
        cmp     rbx, .cases_end
        jb      .loop
.pass:
        leave
        clc
        ret
.fail:
        leave
        stc
        ret


.cases:
db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '00000000000000000000000000000006'
db '223d2bb3ad4647eb58fe9bbec7364eca'
db '00000000000000000000000000000005'

db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '0000000000000000000000000000006e'
db '01de19a80e1b1b3212d160ee7a9340ce'
db '0000000000000000000000000000003d'

db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '000000000000000000000000000006e3'
db '001dd4962cbb8e6706d65222eb0ac8f1'
db '0000000000000000000000000000050e'

db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '00000000000000000000000000006e3b'
db '0001dd19c1cdb866d5ae2bd069bf8749'
db '00000000000000000000000000004cee'

db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '0000000000000000000000000006e3be'
db '00001dd15f8508b312d1fc883c9a748c'
db '000000000000000000000000000334d9'

db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '000000000000000000000000006e3be8'
db '000001dd15d5b0ede0a0f9fc6f86fa28'
db '000000000000000000000000001bec81'

db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '00000000000000000000000006e3be8a'
db '0000001dd15d2fc75cc84474a17f4f02'
db '000000000000000000000000053bc5ad'

db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '0000000000000000000000006e3be8ab'
db '00000001dd15d2ccda5838f4bc8c786e'
db '00000000000000000000000066f3b747'

db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '000000000000000000000006e3be8abd'
db '000000001dd15d2c956228b0abd80b30'
db '000000000000000000000003791db651'

db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '00000000000000000000006e3be8abd2'
db '0000000001dd15d2c94d7aa472669df6'
db '00000000000000000000000d6ea4f2f5'

db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '0000000000000000000006e3be8abd2e'
db '00000000001dd15d2c949b12f8fc0b40'
db '000000000000000000000546492d9341'

db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '000000000000000000006e3be8abd2e0'
db '000000000001dd15d2c949b12f8fc0b4'
db '000000000000000000000546492d9341'

db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '00000000000000000006e3be8abd2e08'
db '0000000000001dd15d2c949af05961a9'
db '000000000000000000063360e5296d79'

db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '0000000000000000006e3be8abd2e089'
db '00000000000001dd15d2c949aedea28c'
db '00000000000000000067b8f26d0e5bd5'

db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '000000000000000006e3be8abd2e089e'
db '000000000000001dd15d2c949aedad91'
db '00000000000000000377ffe6621a3143'

db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '00000000000000006e3be8abd2e089ed'
db '0000000000000001dd15d2c949aedaa0'
db '00000000000000005b96d87a5565d2a1'

db 'cd6f06360fa5af8415f7a678ab45d8c1'
db '0000000000000000ffffffffffffffff'
db '0000000000000000cd6f06360fa5af84'
db '0000000000000000e366acaebaeb8845'

.cases_end:

