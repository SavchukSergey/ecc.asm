ENABLE_VIRTUAL_TERMINAL_PROCESSING equ 4

enable_vt_processing:
        sub     rsp, 0x38

        mov     rcx, STD_OUTPUT_HANDLE
        call    [GetStdHandle]
        mov     [rsp + 0x28], rax

        mov     rcx, [rsp + 0x28]
        lea     rdx, [rsp + 0x30]
        call    [GetConsoleMode]

        mov     rcx, [rsp + 0x28]
        mov     rdx, rax
        or      rdx, ENABLE_VIRTUAL_TERMINAL_PROCESSING
        call    [SetConsoleMode]

        add     rsp, 0x38
        ret