format pe64 console
entry start

include 'win64a.inc'

section '.text' code readable executable
start:
        sub     rsp, 0x28
        mov     rsi, .welcome
        call    Console_WriteString

        mov     rax, bi_test_256
        call    bi256_rnd

        mov     rax, bi_test_256
        mov     rdi, bi_test_256_string
        call    bi256_write_hex

        mov     rsi, bi_test_256_string
        call    Console_WriteString
        call    Console_WriteLine


        mov     rax, bi_test_512
        call    bi512_rnd

        mov     rax, bi_test_512
        mov     rdi, bi_test_512_string
        call    bi512_write_hex

        mov     rsi, bi_test_512_string
        call    Console_WriteString
        call    Console_WriteLine

        mov     rcx, 512
.add_loop:
        mov     rax, bi_test_512
        mov     rbx, bi_test_512
        mov     rdi, bi_test_512
        call    bi512_add_bi512

        mov     rax, bi_test_512
        mov     rdi, bi_test_512_string
        call    bi512_write_hex
        mov     rsi, bi_test_512_string
        call    Console_WriteString
        call    Console_WriteLine

        loop    .add_loop

        invoke  ExitProcess, 0
        add     rsp, 0x28
        ret
.welcome db 'ecc.js', 13, 10, 0

include 'math/rnd.inc'
include 'math/bigint.inc'
include 'console/console.inc'

section '.data' data readable writeable
align 16
bi_test_256 BigInteger256 <0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31>
bi_test_256_string BigIntegerHex256
db 0

align 16
bi_test_512 BigInteger512 <0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40>
bi_test_512_string BigIntegerHex512
db 0

section '.idata' import data readable writeable

  library kernel,'KERNEL32.DLL'

  import kernel,\
         ExitProcess,'ExitProcess', \
         GetStdHandle, 'GetStdHandle', \
         WriteFile, 'WriteFile'
