test_output_start:
    mov     rsi, .msg
    call    Console_WriteString

    ret

.msg db \
'<!doctype html>', 13, 10, \
'<html lang="en">', 13, 10, \
'<head>', 13, 10, \
'  <title>ecc.asm tests</title>', 13, 10, \
'  <meta name="viewport" content="width=device-width, initial-scale=1">', 13, 10, \
'  <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.2/dist/css/bootstrap.min.css" integrity="sha384-T3c6CoIi6uLrA9TneNEoa7RxnatzjcDSCmG1MXxSR1GAsXEV/Dwwykc2MPK8M2HN" crossorigin="anonymous">', 13, 10, \
'</head>', 13, 10, \
'<body data-bs-theme="dark">', 13, 10, 0