test_output_start_chapter_table:
    mov     rsi, .msg
    call    Console_WriteString

    ret
.msg db \
'| Name                           | Status | Min CPU ticks | Max CPU ticks | RPS   |', 13, 10, \
'| :------------------------------| :----: | ------------: | ------------: |-----: |', 13, 10, \
0
