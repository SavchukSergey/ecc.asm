if ~ definite bi_rnd_64

bi_rnd_64:
.loop:
        rdseed  rax
        jnc     .loop
        ret

end if