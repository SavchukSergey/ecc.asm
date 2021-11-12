if ~ definite rnd_u64

rnd_u64:
.loop:
        rdseed  rax
        jnc     .loop
        ret

end if