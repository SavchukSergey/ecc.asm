test_output_start_chapter_table:
    mov     rsi, .msg
    call    Console_WriteString

    ret

.msg db \
'<table class="table table-striped table-hover">', 13, 10, \
'  <colgroup>', 13, 10, \
'    <col />', 13, 10, \
'    <col style="width: 128px" />', 13, 10, \
'    <col style="width: 192px" />', 13, 10, \
'    <col style="width: 192px" />', 13, 10, \
'    <col style="width: 192px" />', 13, 10, \
'  </colgroup>', 13, 10, \
'  <thead>', 13, 10, \
'    <tr>', 13, 10, \
'      <th scope="col">', 13, 10, \
'        Name', 13, 10, \
'      </th>', 13, 10, \
'      <th scope="col" class="text-center">', 13, 10, \
'        Status', 13, 10, \
'      </th>', 13, 10, \
'      <th scope="col" class="text-end">', 13, 10, \
'        Min CPU ticks', 13, 10, \
'      </th>', 13, 10, \
'      <th scope="col" class="text-end">', 13, 10, \
'        Max CPU ticks', 13, 10, \
'      </th>', 13, 10, \
'      <th scope="col" class="text-end">', 13, 10, \
'        RPS', 13, 10, \
'      </th>', 13, 10, \
'    </tr>', 13, 10, \
'  </thead>', 13, 10, \
'  <tbody>', 13, 10, 0