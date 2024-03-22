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




;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db '0000000000000006e3be8abd2e089ed8'
;db '00000000000000001dd15d2c949aeda9'
;db '000000000000000650ca79d2de970429'

;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db '000000000000006e3be8abd2e089ed81'
;db '000000000000000001dd15d2c949aeda'
;db '000000000000004450a044a6b39aeae7'

;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db '00000000000006e3be8abd2e089ed812'
;db '0000000000000000001dd15d2c949aed'
;db '0000000000000492a77b58291fd4fc17'

;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db '0000000000006e3be8abd2e089ed8124'
;db '00000000000000000001dd15d2c949ae'
;db '0000000000005e23547f7f2844c0ce49'

;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db '000000000006e3be8abd2e089ed81247'
;db '000000000000000000001dd15d2c949a'
;db '000000000006656a0de436b64385ce0b'

;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db '00000000006e3be8abd2e089ed812475'
;db '0000000000000000000001dd15d2c949'
;db '00000000004b4adb7947f9bb0ad89664'

;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db '0000000006e3be8abd2e089ed812475b'
;db '00000000000000000000001dd15d2c94'
;db '00000000042b660983b1dd4c6561f425'

;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db '000000006e3be8abd2e089ed812475be'
;db '000000000000000000000001dd15d2c9'
;db '000000001fba60347869ffadae798a93'

;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db '00000006e3be8abd2e089ed812475be9'
;db '0000000000000000000000001dd15d2c'
;db '00000003ffd58e3ee24ed9062c6567b5'

;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db '0000006e3be8abd2e089ed812475be9b'
;db '00000000000000000000000001dd15d2'
;db '00000056acc40f1d0ab64b26f33dc69b'

;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db '000006e3be8abd2e089ed812475be9b5'
;db '000000000000000000000000001dd15d'
;db '00000133249566c2cbca26293b942d00'

;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db '00006e3be8abd2e089ed812475be9b51'
;db '0000000000000000000000000001dd15'
;db '00005ac3d1a102193bdb1f16db3d2e1c'

;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db '0006e3be8abd2e089ed812475be9b51c'
;db '00000000000000000000000000001dd1'
;db '000281ef5cfc207bed7ea4cd27f4d0e5'

;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db '006e3be8abd2e089ed812475be9b51c3'
;db '000000000000000000000000000001dd'
;db '000965ade7b94e848c56b71483de806a'

;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db '06e3be8abd2e089ed812475be9b51c3c'
;db '0000000000000000000000000000001d'
;db '05a2707ea16eb5859be5910f31c1a5f5'

;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db '6e3be8abd2e089ed812475be9b51c3cf'
;db '00000000000000000000000000000001'
;db '5f331d8a3cc5259694d330ba0ff414f2'

;db 'cd6f06360fa5af8415f7a678ab45d8c1'
;db 'e3be8abd2e089ed812475be9b51c3cfc'
;db '00000000000000000000000000000000'
;db 'cd6f06360fa5af8415f7a678ab45d8c1'

.cases_end:

