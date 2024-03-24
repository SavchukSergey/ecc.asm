include '../src/math/bigint/div_rem/bi_div_rem_128_128.inc'

__bi_div_rem_128_128_test:
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

        lea     rbx, [__bi_div_rem_128_128_test_cases]
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
        lea     rdx, [.divisor]
        lea     r8, [.quotient]
        lea     r9, [.remainder]
        call    test_context_start_measure
        call    bi_div_rem_128_128
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
        cmp     rbx, __bi_div_rem_128_128_test_cases.end
        jb      .loop
.pass:
        leave
        clc
        ret
.fail:
        leave
        stc
        ret


__bi_div_rem_128_128_test_cases:
  db '00000000000000000000000000000000'
  db '00000000000000000000000000000001'
  db '00000000000000000000000000000000'
  db '00000000000000000000000000000000'

  db 'ffffffffffffffffffffffffffffffff'
  db '00000000000000000000000000000001'
  db 'ffffffffffffffffffffffffffffffff'
  db '00000000000000000000000000000000'

  db 'ffffffffffffffffffffffffffffffff'
  db 'ffffffffffffffffffffffffffffffff'
  db '00000000000000000000000000000001'
  db '00000000000000000000000000000000'

  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '00000000000000000000000000000001'
  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '00000000000000000000000000000000'

  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '00000000000000000000000000000006'
  db '223D2BB3AD4647EB58FE9BBEC7364ECA'
  db '00000000000000000000000000000005'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '0000000000000000000000000000006e'
  db '01DE19A80E1B1B3212D160EE7A9340CE'
  db '0000000000000000000000000000003D'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '000000000000000000000000000006e3'
  db '001DD4962CBB8E6706D65222EB0AC8F1'
  db '0000000000000000000000000000050E'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '00000000000000000000000000006e3b'
  db '0001DD19C1CDB866D5AE2BD069BF8749'
  db '00000000000000000000000000004CEE'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '0000000000000000000000000006e3be'
  db '00001DD15F8508B312D1FC883C9A748C'
  db '000000000000000000000000000334D9'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '000000000000000000000000006e3be8'
  db '000001DD15D5B0EDE0A0F9FC6F86FA28'
  db '000000000000000000000000001BEC81'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '00000000000000000000000006e3be8a'
  db '0000001DD15D2FC75CC84474A17F4F02'
  db '000000000000000000000000053BC5AD'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '0000000000000000000000006e3be8ab'
  db '00000001DD15D2CCDA5838F4BC8C786E'
  db '00000000000000000000000066F3B747'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '000000000000000000000006e3be8abd'
  db '000000001DD15D2C956228B0ABD80B30'
  db '000000000000000000000003791DB651'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '00000000000000000000006e3be8abda'
  db '0000000001DD15D2C92ADB0A110E3714'
  db '000000000000000000000056204095B9'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '0000000000000000000006e3be8abda2'
  db '00000000001DD15D2C92A508BA788DFA'
  db '00000000000000000000063D95666E8D'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '000000000000000000006e3be8abda2d'
  db '000000000001DD15D2C92A18484CAAB4'
  db '000000000000000000001D3D86328F1D'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '00000000000000000006e3be8abda2dd'
  db '0000000000001DD15D2C92A14C416FCD'
  db '00000000000000000000AB3E61AF9AC8'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '0000000000000000006e3be8abda2ddb'
  db '00000000000001DD15D2C92A14947B88'
  db '0000000000000000003C29A5ECB94369'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '000000000000000006e3be8abda2ddb6'
  db '000000000000001DD15D2C92A1492DC0'
  db '000000000000000005BB206821409241'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '00000000000000006e3be8abda2ddb6c'
  db '0000000000000001DD15D2C92A1492A8'
  db '00000000000000000CE081E2799A41E1'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '0000000000000006e3be8abda2ddb6ca'
  db '00000000000000001DD15D2C92A1492A'
  db '00000000000000025492238390BC419D'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '000000000000006e3be8abda2ddb6ca6'
  db '000000000000000001DD15D2C92A1492'
  db '00000000000000472ED50BFB3668EA15'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '00000000000006e3be8abda2ddb6ca68'
  db '0000000000000000001DD15D2C92A149'
  db '0000000000000123A5B7D8C62D8AB919'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '0000000000006e3be8abda2ddb6ca686'
  db '00000000000000000001DD15D2C92A14'
  db '0000000000003F25588D54FD0840DA49'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '000000000006e3be8abda2ddb6ca6869'
  db '000000000000000000001DD15D2C92A1'
  db '000000000001F814FB3BB1582F624CB8'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '00000000006e3be8abda2ddb6ca6869b'
  db '0000000000000000000001DD15D2C92A'
  db '000000000008DBD385F93FB5F61E1053'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '0000000006e3be8abda2ddb6ca6869bf'
  db '00000000000000000000001DD15D2C92'
  db '00000000045732EA3C7F0888F029B5D3'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '000000006e3be8abda2ddb6ca6869bf2'
  db '000000000000000000000001DD15D2C9'
  db '00000000121EAFFFB7C4C3F2CACEE3BF'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '00000006e3be8abda2ddb6ca6869bf27'
  db '0000000000000000000000001DD15D2C'
  db '00000003F239DE0A63617AC3D4D0D30D'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '0000006e3be8abda2ddb6ca6869bf272'
  db '00000000000000000000000001DD15D2'
  db '000000569F285EEE05C60C40B60B9D3D'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '000006e3be8abda2ddb6ca6869bf2727'
  db '000000000000000000000000001DD15D'
  db '0000013316F9B6A2617CE58DC272C896'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '00006e3be8abda2ddb6ca6869bf27271'
  db '0000000000000000000000000001DD15'
  db '00005AC3C40557E7A3C52CDB2125E87C'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '0006e3be8abda2ddb6ca6869bf272715'
  db '00000000000000000000000000001DD1'
  db '000281EF4F609ACCECE46D7C2CE18F9C'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '006e3be8abda2ddb6ca6869bf2727154'
  db '000000000000000000000000000001DD'
  db '000965ADDA1E3DAAA3AED5E5EC08AF3D'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '06e3be8abda2ddb6ca6869bf27271548'
  db '0000000000000000000000000000001D'
  db '05A2707E943291CF2823ABD13BD86F99'


  db 'cd6f06360fa5af8415f7a678ab45d8c1'
  db '6e3be8abda2ddb6ca6869bf272715487'
  db '00000000000000000000000000000001'
  db '5F331D8A3577D4176F710A8638D4843A'
.end:

