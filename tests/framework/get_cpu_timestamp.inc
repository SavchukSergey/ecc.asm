if ~ definite get_cpu_timestamp

get_cpu_timestamp:
        push    rbx rcx rdx
        xor     rax, rax
        cpuid
        rdtsc
        shl     rdx, 32
        or      rax, rdx
        pop     rdx rcx rbx
        ret

end if