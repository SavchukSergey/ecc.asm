rnd_u64:
.loop:
        rdseed  rax
        jnc     .loop
        ret
