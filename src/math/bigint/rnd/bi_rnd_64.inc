if ~ definite bi_rnd_u64

bi_rnd_u64:
.loop:
        rdseed  rax
        jnc     .loop
        ret

end if